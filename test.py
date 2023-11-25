import subprocess
import os
import sys
import re


def run_command(command):
    """Executes a shell command and captures its output and error, regardless of the return code."""
    process = subprocess.run(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    return process.stdout.decode('utf-8'), process.stderr.decode('utf-8'), process.returncode

def clean_files(test_num):
    """Delete all .bc, .ll, and executable files for a given test number."""
    files_to_delete = [
        f"testcases/{test_num}.bc",
        f"testcases/{test_num}Ref.bc",
        f"testcases/{test_num}.ll",
        f"testcases/{test_num}Ref.ll",
        f"testcases/{test_num}",
        f"testcases/{test_num}Ref"
    ]
    for file in files_to_delete:
        if os.path.exists(file):
            os.remove(file)
            print(f"Deleted {file}")


def test_executable(file_name):
    input_file = f"testcases/{file_name}.sc"
    # to faciliate testing
    ref_input_file = f"testcases/{file_name}Ref.sc"
    output_file = f"testcases/{file_name}.bc"
    ref_output_file = f"testcases/{file_name}Ref.bc"
    executable_file = f"testcases/{file_name}"

    # Paths to the required tools and libraries
    llvm_dis = "/cad2/ece467f/llvm-project/build/bin/llvm-dis"
    clang = "/cad2/ece467f/llvm-project/build/bin/clang"
    libscio = "libscio.a"

    # Run A4Gen and A4Gen-reference on the input file
    _, _, exit_code = run_command(f"./A4Gen {input_file}")
    if exit_code != 0:
        print(f"Test {file_name}: FAIL - A4Gen returned an error.")
        return

    run_command(f"/cad2/ece467f/public/A4Gen-reference {ref_input_file}")

    # Disassemble both output files
    run_command(f"{llvm_dis} {output_file}")
    run_command(f"{llvm_dis} {ref_output_file}")

    # Compile the .ll files to executable
    run_command(f"{clang} {output_file[:-3]}.ll {libscio} -o {executable_file}")
    run_command(f"{clang} {ref_output_file[:-3]}.ll {libscio} -o {executable_file}Ref")

    # Execute both executables and capture their outputs
    test_output, _, _ = run_command(f"./{executable_file}")
    ref_output, _, _= run_command(f"./{executable_file}Ref")

    # Compare the outputs
    if test_output == ref_output:
        print(f"Test {file_name}: PASS")
    else:
        print(f"Test {file_name}: FAIL - Output differs")
        print("\n=== Testing Executable Output ===")
        print(test_output)
        print("\n=== Reference Executable Output ===")
        print(ref_output)

# List all testN.sc files in the testcases/folder
test_files = [f for f in os.listdir("testcases/") if re.match(r"test\d+\.sc$", f)]

# python3 test.py --clean
# Check for 'clean' flag
if "--clean" in sys.argv:
    for file in test_files:
        clean_files(file[:-3])
else:
    # Run tests on each file
    for file in test_files:
        test_executable(file[:-3])
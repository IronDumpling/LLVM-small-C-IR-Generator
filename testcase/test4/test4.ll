; ModuleID = 'testcase/test4/test4.bc'
source_filename = "testcase/test4/test4.bc"
target triple = "x86_64-unknown-linux-gnu"

@q = external global i32
@p = external global [4 x i1]

define void @foo(i1 zeroext %a, ptr %b) {
entry:
  %a1 = alloca i1, align 1
  store i1 %a, ptr %a1, align 1
  %b2 = alloca ptr, align 8
  store ptr %b, ptr %b2, align 8
  %c = alloca i32, align 4
  %0 = load i32, ptr %c, align 4
  %1 = load i32, ptr %c, align 4
  %2 = load i32, ptr %c, align 4
  %3 = load i1, ptr %a1, align 1
  %4 = load ptr, ptr %b2, align 8
  %5 = getelementptr i32, ptr %4, i32 1
  ret void
}

define void @main() {
entry:
  %b = alloca i1, align 1
  %d = alloca [10 x i32], align 4
  %0 = load i32, ptr @q, align 4
  %1 = getelementptr [10 x i32], ptr %d, i32 0, i32 3
  %2 = load i32, ptr %1, align 4
  %3 = load i32, ptr @q, align 4
  %4 = getelementptr [10 x i32], ptr %d, i32 0, i32 3
  %5 = load i32, ptr %4, align 4
  %6 = load i32, ptr @q, align 4
  %7 = getelementptr [10 x i32], ptr %d, i32 0, i32 %6
  %8 = load i32, ptr %7, align 4
  %9 = load i32, ptr @q, align 4
  %10 = getelementptr [10 x i32], ptr %d, i32 0, i32 3
  %11 = load i32, ptr %10, align 4
  %12 = getelementptr [10 x i32], ptr %d, i32 0, i32 %11
  %13 = load i32, ptr %12, align 4
  ret void
}

declare void @newLine()

declare i1 @readBool()

declare i32 @readInt()

declare void @writeBool(i1 zeroext)

declare void @writeInt(i32)

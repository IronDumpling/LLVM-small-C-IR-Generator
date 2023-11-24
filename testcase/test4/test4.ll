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
  %2 = add i32 1, %1
  %3 = load i32, ptr %c, align 4
  %4 = load i1, ptr %a1, align 1
  %5 = load ptr, ptr %b2, align 8
  %6 = getelementptr i32, ptr %5, i32 1
  %7 = load i32, ptr %6, align 4
  %8 = load i1, ptr %a1, align 1
  %9 = load ptr, ptr %b2, align 8
  call void @foo(i1 %8, ptr %9)
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
  %10 = add i32 %8, %9
  %11 = getelementptr [10 x i32], ptr %d, i32 0, i32 3
  %12 = load i32, ptr %11, align 4
  %13 = getelementptr [10 x i32], ptr %d, i32 0, i32 %12
  %14 = load i32, ptr %13, align 4
  %15 = load i32, ptr @q, align 4
  call void @writeInt(i32 %15)
  call void @newLine()
  %16 = load i1, ptr %b, align 1
  %17 = getelementptr [10 x i32], ptr %d, i32 0, i32 0
  call void @foo(i1 %16, ptr %17)
  ret void
}

declare void @newLine()

declare i1 @readBool()

declare i32 @readInt()

declare void @writeBool(i1 zeroext)

declare void @writeInt(i32)

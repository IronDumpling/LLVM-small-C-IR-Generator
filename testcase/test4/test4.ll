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
  %1 = load i1, ptr %a1, align 1
  ret void
}

define void @main() {
entry:
  %b = alloca i1, align 1
  %d = alloca [10 x i32], align 4
  %0 = load i32, ptr @q, align 4
  ret void
}

declare void @newLine()

declare i1 @readBool()

declare i32 @readInt()

declare void @writeBool(i1 zeroext)

declare void @writeInt(i32)

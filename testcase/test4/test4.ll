; ModuleID = 'testcase/test4/test4.bc'
source_filename = "testcase/test4/test4.bc"
target triple = "x86_64-unknown-linux-gnu"

@q = common global i32 0
@p = common global [4 x i1] zeroinitializer

define void @foo(i1 zeroext %a, ptr %b) {
entry:
  %a1 = alloca i1, align 1
  store i1 %a, ptr %a1, align 1
  %b2 = alloca ptr, align 8
  store ptr %b, ptr %b2, align 8
  store i1 true, ptr %a1, align 1
  %0 = load ptr, ptr %b2, align 8
  %1 = getelementptr i32, ptr %0, i32 1
  store i32 -10, ptr %1, align 4
  ret void
}

define i32 @main() {
entry:
  %b = alloca i1, align 1
  %d = alloca [10 x i32], align 4
  store i32 13, ptr @q, align 4
  %0 = load i32, ptr @q, align 4
  call void @writeInt(i32 %0)
  call void @newLine()
  %1 = load i1, ptr %b, align 1
  %2 = getelementptr [10 x i32], ptr %d, i32 0, i32 0
  call void @foo(i1 %1, ptr %2)
  %3 = load i32, ptr @q, align 4
  ret i32 %3
}

declare void @newLine()

declare i1 @readBool()

declare i32 @readInt()

declare void @writeBool(i1 zeroext)

declare void @writeInt(i32)

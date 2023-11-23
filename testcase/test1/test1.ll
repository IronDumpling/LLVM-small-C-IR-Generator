; ModuleID = 'testcase/test1.bc'
source_filename = "testcase/test1.bc"
target triple = "x86_64-unknown-linux-gnu"

define i32 @main() {
entry:
  %x = alloca i32, align 4
  %y = alloca i32, align 4
  %z = alloca i32, align 4
  store i32 1, ptr %x, align 4
  store i32 3, ptr %y, align 4
  store i32 11, ptr %z, align 4
  br label %while.cond

while.cond:                                       ; preds = %merge, %entry
  %0 = load i32, ptr %x, align 4
  %1 = icmp slt i32 %0, 5
  %2 = load i32, ptr %z, align 4
  %3 = icmp ne i32 %2, 1
  %4 = and i1 %1, %3
  br i1 %4, label %while.body, label %while.exit

while.body:                                       ; preds = %while.cond
  %5 = load i32, ptr %y, align 4
  %6 = icmp slt i32 %5, 5
  br i1 %6, label %then, label %else

while.exit:                                       ; preds = %while.cond
  ret i32 0

then:                                             ; preds = %while.body
  %7 = load i32, ptr %y, align 4
  call void @writeInt(i32 %7)
  call void @newLine()
  %8 = load i32, ptr %y, align 4
  %9 = add i32 %8, 1
  store i32 %9, ptr %y, align 4
  br label %merge

merge:                                            ; preds = %else, %then
  %10 = load i32, ptr %x, align 4
  call void @writeInt(i32 %10)
  call void @newLine()
  %11 = load i32, ptr %x, align 4
  %12 = add i32 %11, 1
  store i32 %12, ptr %x, align 4
  br label %while.cond

else:                                             ; preds = %while.body
  call void @writeInt(i32 -5)
  call void @newLine()
  br label %merge
}

declare void @newLine()

declare i1 @readBool()

declare i32 @readInt()

declare void @writeBool(i1 zeroext)

declare void @writeInt(i32)

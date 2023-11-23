; ModuleID = 'testcase/test4/test4.bc'
source_filename = "testcase/test4/test4.bc"
target triple = "x86_64-unknown-linux-gnu"

@q = external global i32
@p = external global [4 x [4 x i1]]

declare i32 @main()

declare void @newLine()

declare i1 @readBool()

declare i32 @readInt()

declare void @writeBool(i1 zeroext)

declare void @writeInt(i32)

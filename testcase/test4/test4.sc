#include "scio.h" // declare void @newLine()
                  // declare i1 @readBool()
                  // declare i32 @readInt()
                  // declare void @writeBool(i1 zeroext)
                  // declare void @writeInt(i32)

int q;            // @q = common global i32 0
bool p[4];

void foo(bool a, int b[]){
    a = true;
    b[1] = -10;
}

int main() {      // define i32 @main()
                  // entry:
   bool b;
   q = 13;        // store i32 13, ptr @q, align 4
   writeInt(q);   // %0 = load i32, ptr @q, align 4
                  // call void @writeInt(i32 %0)
   newLine();     // call void @newLine()
   return q;      // %1 = load i32, ptr @q, align 4
                  // ret i32 %1
}
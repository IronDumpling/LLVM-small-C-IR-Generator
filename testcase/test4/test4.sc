#include "scio.h" // declare void @newLine()
                  // declare i1 @readBool()
                  // declare i32 @readInt()
                  // declare void @writeBool(i1 zeroext)
                  // declare void @writeInt(i32)

int q;            // @q = common global i32 0
bool p[4];        // @p = common global [4 x i1] zeroinitializer

void foo(bool a, int b[]){ // define void @foo(i1 zeroext %a, ptr %b)
                           // entry: 
                           // %a1 = alloca i1, align 1
                           // store i1 %a, ptr %a1, align 1
                           // %b2 = alloca ptr, align 8
                           // store ptr %b, ptr %b2, align 8
   int c;                  // %c = alloca i32, align 4
   c = 0;                  // store i32 0, ptr %c, align 4
   c = 1 + c;              // %0 = load i32, ptr %c, align 4
                           // %1 = add i32 1, %0
                           // store i32 %1, ptr %c, align 4
   a = true;               // store i1 true, ptr %a1, align 1      
   b[1] = -10;             // %0 = load ptr, ptr %b2, align 8
                           // %1 = getelementptr i32, ptr %0, i32 1
                           // store i32 -10, ptr %1, align 4
   foo(a, b);              // %4 = load i1, ptr %a1, align 1
                           // %5 = load ptr, ptr %b2, align 8
                           // call void @foo(i1 %4, ptr %5)
                           // ret void
}

//int main()         // define i32 @main()
void main() {
                     // entry:
   bool b;           // %b = alloca i1, align 1
   int d[10];        // %d = alloca [10 x i32], align 4
   q = 13;           // store i32 13, ptr @q, align 4
   d[3] = 5;         // %0 = getelementptr [10 x i32], ptr %d, i32 0, i32 3
                     // store i32 5, ptr %0, align 4
   d[3] = q;         // %1 = load i32, ptr @q, align 4
                     // %2 = getelementptr [10 x i32], ptr %d, i32 0, i32 3
                     // store i32 %1, ptr %2, align 4
   d[d[3]] = d[q]+q; // %3 = load i32, ptr @q, align 4
                     // %4 = getelementptr [10 x i32], ptr %d, i32 0, i32 %3
                     // %5 = load i32, ptr %4, align 4
                     // %6 = load i32, ptr @q, align 4
                     // %7 = add i32 %5, %6
                     // %8 = getelementptr [10 x i32], ptr %d, i32 0, i32 3
                     // %9 = load i32, ptr %8, align 4
                     // %10 = getelementptr [10 x i32], ptr %d, i32 0, i32 %9
                     // store i32 %7, ptr %10, align 4
   writeInt(q);      // %11 = load i32, ptr @q, align 4
                     // call void @writeInt(i32 %0)
   newLine();        // call void @newLine()
   foo(b, d);        // %12 = load i1, ptr %b, align 1
                     // %13 = getelementptr [10 x i32], ptr %d, i32 0, i32 0 
                     // call void @foo(i1 %12, ptr %13)
   return;           // ret void
   // return q;      // %1 = load i32, ptr @q, align 4
                     // ret i32 %1
}
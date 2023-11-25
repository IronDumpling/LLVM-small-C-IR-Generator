#include "scio.h"
void abc();
void abc(){
    int x;
    x = 1+1;
    return;
}
void def();
int main();
int main() {
   int a[3];
   int b;
   bool c;

   c = false;
   b = 8;
   a[0] = 5;
   a[1] = 3;
   a[2] = 4;

   b = a[0];
   a[1] = a[2];

   abc();

   writeInt(b);
   newLine();
   writeInt(a[0]);
   newLine();
   writeInt(a[1]);
   newLine();
   writeInt(a[2]);
   newLine();

   c = true || readBool();
   a[0] = readInt();
   writeBool(c);
   writeInt(b);
   newLine();

   return 0;
}
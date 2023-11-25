#include "scio.h"

int main() {
   int a[3];
   int b;

   b = 8;
   a[0] = 5;
   a[1] = 3;
   a[2] = 4;

   b = a[0];
   a[1] = a[2];

   writeInt(b);
   newLine();
   writeInt(a[0]);
   newLine();
   writeInt(a[1]);
   newLine();
   writeInt(a[2]);
   newLine();

   return 0;
}
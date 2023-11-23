#include "scio.h"
int main() {

   bool t;
   bool t2;
   bool t3;
   int x;
   int y;
   int z;

   y = 5;

   t = false;
   t2 = false;
   t3 = true;
   if ((t2 && t3) || t2 || t) writeInt(y);
   else writeInt(0);
   newLine();
  
   return 0;
}
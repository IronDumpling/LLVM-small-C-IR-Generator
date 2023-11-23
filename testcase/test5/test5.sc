#include "scio.h"

int q;
void foo(int a, bool b[]);

int main() {
   int b[10];
   q = 13;

   foo(q, b);
   return q;
}

void foo(int a, bool b[]){
   int i;
   i = 0;
   a = 1;
   while(i < 10){
      b[i] = false;
   }
}
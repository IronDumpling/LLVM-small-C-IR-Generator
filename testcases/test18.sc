#include "scio.h"

// tangyuan's case

void foo(int a, bool b[], int c[]){
   int i;
   i = 0;
   a = 1;
   while(i < 10){
      b[i] = false;
      writeInt(c[i]);
      if(!b[i]){
         c[c[i]+c[i+3]] = 5;
         writeInt(c[i]);
         return;
       }
   }
}

int main() {
      bool a[10];
      int d[10];
      int q;
      int i;

      q = -1;
      i = 0;

      while(i < 10){
              a[i] = true;
              d[i] = 1;
              q = q + d[i];
              i = i + 1;
       }

       if(q <= 10 * d[q]){
             d[d[3]+1] = d[q]+q;
             writeInt(d[d[q]]);
      }

       foo(q, a, d);
       return q;
}




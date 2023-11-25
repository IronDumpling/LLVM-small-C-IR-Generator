#include "scio.h"

int function1(){
    return -1;
}

bool function2(){
    return false;
}

void main(){
    bool x[10];
    bool y;
    int a;
    int b;
    int c[1000];
    int i;
    i = 0;
    while (i < 100) {
        c[i] = i; 
        i = i + 1;
    }

    x[3] = y;
    y = x[4];
    b = 1 * 6 / c[3];
    a = b;
    b = c[20 + a];

    a = function1();
    y = function2();

    if (a == -1) a = b;

    writeInt(a);
    writeBool(y);
    newLine();


}
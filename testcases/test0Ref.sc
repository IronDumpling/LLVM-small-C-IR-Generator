// no output, just to see if we can compile
#include "scio.h"

int x;
int y;
bool a;

int b[2];
bool c[5];

int foo(int a);
int foo(int a){
    return 1;
}

int global;

void func0(){

}

void func1(int a, bool b){
    -a;
    !b;
}

void func2(int a[], bool b[]){
    a[3]+a[4];
    !b[1];
}

int func4(){
    return 0;
}

bool func5(){
    return false;
}

void main(int a, int b[]) {
    int x;
    int z[4];
    bool y[3];
    {
        int x[5];
    }

    func0();
    func1(a,y[1]);
    func1(x,y[3]);
    func2(z,y);
    func2(b,y);

    return;
}

void bar(int d) {
    int x;
    int tmp;
    x = (tmp + 1) + x;
    foo(x);

    return;
}

bool barArray(int y[]) {
    int x[2];
    int n[5];
    int f;
    int d;


    x[2] = n[7] + y[3];
    y[d + f];

    return 8 < n[1];
}

void ifTest() {
    int x;
    x = 1;
    if (x > 1) x = 2;
    else x = 3;
    
    x = 4;

    return;
}

int arth() {
    int a;
    int b;
    bool c;
    bool d;
    
    a + b;
    a - b;
    a * b;
    a / b;
    c && d;
    c || d;
    a == b;
    a != b;
    a < b;
    a <= b;
    a > b;
    a >= b;
    -a;
    !c;

    return global + a;
}
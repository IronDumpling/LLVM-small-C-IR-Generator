#include "scio.h"
int func0(){
    int i;
    i = 3;

    while(i < 4){
        i = i + 1;
        if(i > 1000) return 0;
        else i + 2;

        // super nested if
        if (i > 1) {
            if (i > 1) {
                i = i + 1;
                if (i > 2) {
                    i = i + 2;
                    i = i * 2;
                    if (i < 0) {
                        i = 0;
                    } else {
                        writeInt(i);
                    }
                } else {
                    i = i + 1;
                }
            }else {
                i = 1 + 1;
                i = 1 * 1;
                i = -4;
            }
        } else {
            return i * i + (i);
        }
        return -1;
    }

    if(i != 0) i = i+1;
    else return -4;

    return -3;
}

void func1(){
    while(true){
        return;
    }
}

void func2(){
    while(true){
        return;
    }
    return;
}

void func3(){
    if(1 >= 3) return;
}


void main() {
    int a;
    a = func0();
    func1();
    func2();

    if(a > 3){

    } else {

    }

    while (false) {

    }

    while(true) {
        return;
    }
}
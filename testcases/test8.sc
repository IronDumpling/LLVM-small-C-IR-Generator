#include "scio.h"

int global[10];

void arrayInit(int arr[]){
    int i;
    if (arr[0] == 2) return;
    i = 0;
    while (i < 10) {
        arr[i] = arr[i] + 1 + i;
        i = i + 1;
    }

    arrayInit(arr);
}


int arrayPass(int a, int b[]) {
    int i;
    i = 1;
    while (i < 10) {
        b[i] = a + i + b[i - 1];
        i = i + 1;
    }

    return a + b[9];
}

int writeTest(int a, int b[]) {
    int i;
    i = 0;
    while (i < 10) {
        writeInt(b[i]);
        i = i + 1;
    }

    return  0;
}


int main() {
    int test[10];
    int i;
    i = 0;
    while (i < 10) {
        test[i] = 0;
        i = i + 1;
    }

    arrayInit(test);
    arrayInit(global);
    writeInt(global[5]);

    writeInt(arrayPass(5 / 1, test));

    writeTest( 1-1, test);

    return 0;
}
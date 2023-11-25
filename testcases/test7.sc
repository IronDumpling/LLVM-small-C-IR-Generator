#include "scio.h"
void main() {
    int x[10];
    int y[10];
    int i;
    int j;

    i = 0;
    j = 1;
    while (i < 10) {
        x[i] = i;
        i = i + 1;
    }
    while (j < 10) {
        y[j] = j * j;
        j = j + 1;
    } 
    writeInt(y[x[5]]);
}
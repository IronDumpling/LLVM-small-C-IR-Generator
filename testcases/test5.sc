#include "scio.h"
int main() {
    int x;
    int y;
    int z;
    x = 1;
    y = 3;
    z = 11;

    while (x < 5 && z != 1) {
        if (y < 5) {
            writeInt(y);
            newLine();
            y = y + 1;
        }
        else {
            writeInt(-5);
            newLine();
        }
        writeInt(x);
        newLine();
        x = x + 1;
    }
    return 0;
}
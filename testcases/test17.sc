#include "scio.h"

// leo's case
bool gloablBool;
int a;
int array[4];


int main() {
	bool z;
        z = false;
        writeBool(z);
        newLine();
        writeBool(!z);
        writeBool(!gloablBool);
        writeInt(-a);
        writeInt(-a-a);
        writeInt(-array[0]);
        return 0;
 }




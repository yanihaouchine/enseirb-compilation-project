// PCode Header
#include "PCode.h"

void pcode_main();
void init_glob_var();

int main() {
init_glob_var();
pcode_main();
return stack[sp-1].int_value;
}


void init_glob_var(){
// Declare x of type int with offset 0 at depth 0
LOADI(0)

// Declare y of type float with offset 1 at depth 0
LOADF(0.0)

}

LOADI(3)
LOADI(0)
STORE
LOADI(5)
I2F2
LOADI(1)
STORE
LOADI(0)
LOAD
LOADI(1)
LOAD
I2F1
ADDF

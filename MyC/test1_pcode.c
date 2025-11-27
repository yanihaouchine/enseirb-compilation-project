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
}

int pcode_min() {
LOADBP
LOAD
SHIFT(-2)
LOAD
LOADBP
LOAD
SHIFT(-1)
LOAD
LTI
IFN(False_0)
SAVEBP 
LOADBP
LOAD
SHIFT(-2)
LOAD
LOADBP
SHIFT(-3)
STORE
RESTOREBP 
GOTO(End_0)
False_0:
SAVEBP 
LOADBP
LOAD
SHIFT(-1)
LOAD
LOADBP
SHIFT(-3)
STORE
RESTOREBP 
End_0:
}
void pcode_main() {
LOADF(0.0)

LOADI(0)
LOADI(1)
LOADI(2)
SAVEBP
CALL(pcode_min)
RESTOREBP
DROP(2)
I2F2
LOADBP
SHIFT(1) 
STORE
}

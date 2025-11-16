

int make_code_arith(int Exp1, int op, int Exp2) {
  int a = FLOAT;
  if (Exp1 == INT && Exp2 == FLOAT) {
        printf("I2F1\n");
        a = FLOAT;
    } else if (Exp1 == FLOAT && Exp2 == INT) {
        printf("I2F2\n");
        a = FLOAT;
    } else if (Exp1 == FLOAT && Exp2 == FLOAT) {
        a = FLOAT;
    } else {
        a = INT;
    }


  switch (op) {
  case PLUS:
    printf("ADD");
    break;
  case STAR:
    printf("MULT");
    break;
  case MOINS:
    printf("SUB");
    break;
  case DIV:
    printf("DIV");
    break;
  default:
    printf("Other operation...");
    break;
  }

  if (a == INT) printf("I\n");
  else printf("F\n");

  return a;
}

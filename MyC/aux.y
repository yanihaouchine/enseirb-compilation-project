type_value make_code_arith(type_value Exp1, int op, type_value Exp2){
  type_value a = FLOAT;
  if(Exp1 == FlOAT) Exp2 = FLOAT;
  if(Exp2 == FLOAT) Exp1 = FLOAT;
  else a = INT;
  switch(op){
  case PLUS :
    printf("ADD");
    break;
  case MULT:
    printf("MULT");
    break;
  default :
    printf("Other operation...");
    break;
  }
  if(a == INT) printf("I\n");
  else printf("F\n");
  return a;
}
  

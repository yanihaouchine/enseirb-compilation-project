%{


#include "Table_des_symboles.h"
#include <stdio.h>
#include <stdlib.h>
  int make_code_arith(int exp1, int op, int exp2);
extern int yylex();
extern int yyparse();

void yyerror (char* s) {
  printf ("%s\n",s);
  exit(0);
  }
int makeNum ()
{
  static int n = -1;
  return ++n;
}

int depth=0; // block depth
int current_type = 0; // type courant pour add_global_variable() //Modifier par yasmine
int current_offset = 0; // compteur global pour les offsets

#define MAX_LABELS 100
static int current_loop = -1;
static int cond_stack[MAX_LABELS];
static int cond_sp = 0;
static int cond_count = 0;

void push_cond(int v) { cond_stack[cond_sp++] = v; }
int  pop_cond() { return cond_stack[--cond_sp]; }
int  top_cond() { return cond_stack[cond_sp-1]; }


%}

%union { 
  struct ATTRIBUTE * symbol_value;
  char * string_value;
  int int_value;
  float float_value;
  int type_value; //pour stocker le type de exp
  int label_value;
  int offset_value;
}

%token <int_value> NUM
%token <float_value> DEC


%token INT FLOAT VOID

%token <string_value> ID
%token AO AF PO PF PV VIR
%token RETURN  EQ
%token <label_value> IF ELSE WHILE

%token <label_value> AND OR NOT DIFF EQUAL SUP INF
%token PLUS MOINS STAR DIV
%token DOT ARR

%nonassoc IFX
%left OR                       // higher priority on ||
%left AND                      // higher priority on &&
%left DIFF EQUAL SUP INF       // higher priority on comparison
%left PLUS MOINS               // higher priority on + - 
%left STAR DIV                 // higher priority on * /
%left DOT ARR                  // higher priority on . and -> 
%nonassoc UNA                  // highest priority on unary operator
%nonassoc ELSE


%{
char * type2string (int c) {
  switch (c)
    {
    case INT:
      return("int");
    case FLOAT:
      return("float");
    case VOID:
      return("void");
    default:
      return("type error");
    }  
};

 // dirty trick to end function init_glob_var() definition (see rule po : PO)
void end_glob_var_decl(){
  static int unfinished=1;
  if (unfinished) {
    unfinished = 0;
    printf("}\n\n");
  }
}

// Votre code C peut aller ci-dessous pour factoriser (un peu) le code des actions semantiques
 
  %}


%start prog  

// liste de tous les type des attributs des non terminaux que vous voulez manipuler l'attribut (il faudra en ajouter plein ;-) )
%type <type_value> type exp  typename
%type <string_value> fun_head

%%

 // O. Déclaration globale

prog : glob_decl_list              {}
;

glob_decl_list : glob_var_list glob_fun_list {}
;

glob_var_list : glob_var_list decl PV {}
| {printf("void init_glob_var(){\n"); // starting  function init_glob_var() definition in target code
   current_offset = 0;
 }
;

glob_fun_list : glob_fun_list fun {}
| fun {}
;

// I. Functions

fun : type fun_head fun_body   {}
;

po: PO {end_glob_var_decl();}  // dirty trick to end function init_glob_var() definition in target code
  
fun_head : ID po PF            {
  // Pas de déclaration de fonction à l'intérieur de fonctions !
  if (depth>0) yyerror("Function must be declared at top level~!\n");
  }

| ID po params PF              {
   // Pas de déclaration de fonction à l'intérieur de fonctions !
  if (depth>0) yyerror("Function must be declared at top level~!\n");
 }
;

params: type ID vir params     {} // récursion droite pour numéroter les paramètres du dernier au premier
| type ID                      {}


vir : VIR                      {}
;

fun_body : fao block faf       {}
;

fao : AO                       {}
;
faf : AF                       {}
;


// II. Block
block:
decl_list inst_list            {}
;

// III. Declarations

decl_list : decl_list decl PV   {} 
|                               {}
;

decl: var_decl                  {}
;

var_decl : type vlist          {}
;

vlist: vlist vir ID { //MODIFER pae Yasmine
attribute a = new_attribute();
a->type = current_type;
a->depth = depth;
a->offset = current_offset++;
set_symbol_value($<string_value>3, a);
printf("// Declare %s of type %s with offset %d at depth %d\n",
       $<string_value>3, type2string(a->type), a->offset, a->depth);


if (a->type == INT) {
    printf("LOADI(0)\n\n");
} else if (a->type == FLOAT) {
    printf("LOADF(0.0)\n\n");
}

}
| ID {
attribute a = new_attribute();
a->type = current_type;
a->depth = depth;
a->offset = current_offset++;
set_symbol_value($<string_value>1, a);

printf("// Declare %s of type %s with offset %d at depth %d\n",
       $<string_value>1, type2string(a->type), a->offset, a->depth);

if (a->type == INT) {
    printf("LOADI(0)\n\n");
} else if (a->type == FLOAT) {
    printf("LOADF(0.0)\n\n");
}


}
;



type
: typename     { $$ = $1; current_type = $1;} //Modifier
;

;

typename // Utilisation des terminaux comme codage (entier) du type !!!
: INT                          {$$=INT;} 
| FLOAT                        {$$=FLOAT;}
| VOID                         {$$=VOID;}
;

// IV. Intructions

inst_list: inst_list inst   {} 
| inst                      {}
;

pv : PV                       {}
;
 
inst:
ao block af                   {depth++;
                                }
| exp pv                      {}
| aff pv                      {}
| ret pv                      {}
| cond                        {}
| loop                        {}
| pv                          {}
;

// Accolades explicites pour gerer l'entrée et la sortie d'un sous-bloc

ao : AO                       {printf("SAVEBP \n");
}
;

af : AF                       {printf("RESTOREBP \n");
}
;


// IV.1 Affectations

// Affectation : aff //MODIFER par Yasmine
aff : ID EQ exp {
attribute a = get_symbol_value($1);
if (!a) yyerror("Variable non déclarée");
if(a->type == FLOAT && $3 == INT) {
    printf("I2F2\n");   // conversion de l'exp vers float
} else if(a->type == INT && $3 == FLOAT) {
    printf("F2I1\n");   // conversion de l'exp vers int
}

printf("LOADI(%d)\n", a->offset);
printf("STORE\n");


};




// IV.2 Return
ret : RETURN exp              {}
| RETURN PO PF                {}
;

// IV.3. Conditionelles
//           N.B. ces rêgles génèrent un conflit déclage reduction
//           qui est résolu comme on le souhaite par un décalage (shift)
//           avec ELSE en entrée (voir y.output)

cond :
if bool_cond inst  elsop       {

pop_cond();

}
;

elsop : else inst              {   printf("End_%d:\n", top_cond());
}
|                  %prec IFX   {
    printf("False_%d:\n", top_cond());
 } // juste un "truc" pour éviter le message de conflit shift / reduce
;

bool_cond : PO exp PF         {
printf("IFN(False_%d)\n", top_cond());}
;

if : IF { 
  int label = cond_count++;
    push_cond(label);
}


else : ELSE                   {
 printf("GOTO(End_%d)\n", top_cond());
printf("False_%d:\n", top_cond());

  

}
;

// IV.4. Iterations

loop : while while_cond inst  {printf("GOTO(StartLoop_%i)\n",top_cond());
printf(" EndLoop_%i :\n",top_cond());

pop_cond();
}
;

while_cond : PO exp PF        {printf("IFN(EndLoop_%i ):\n",top_cond());}

while : WHILE                 {
 int label = cond_count++;
    push_cond(label);
      printf("StartLoop_%i :\n",top_cond());}
;


// V. Expressions

exp //MODIFIER PAR Yas
// V.1 Exp. arithmetiques
: MOINS exp %prec UNA         {}
         // -x + y lue comme (- x) + y  et pas - (x + y)
| exp PLUS exp                {$$ = make_code_arith($1, PLUS, $3);}
| exp MOINS exp               {$$ = make_code_arith($1, MOINS, $3);}
| exp STAR exp                { $$ = make_code_arith($1, STAR, $3);}
| exp DIV  exp                {$$ = make_code_arith($1, DIV, $3);}
| PO exp PF                   {$$ = $2;}
| ID                          {attribute a = get_symbol_value($1);
    if (!a) yyerror("Variable non déclarée");
    printf("LOADI(%d)\n", a->offset);
    printf("LOAD\n");
    $$ = a->type;}
| app                         {}
| NUM  { printf("LOADI(%d)\n",$<int_value>1); $$=INT; }
| DEC  { printf("LOADF(%f)\n",$<float_value>1); $$=FLOAT; }



// V.2. Booléens

| NOT exp %prec UNA           {printf("NOT\n"); $$=$2;}
| exp INF exp                 {printf("LTI\n"); $$=INT;}
| exp SUP exp                 {printf("GTI\n"); $$=INT;}
| exp EQUAL exp               {printf("EQI\n"); $$=INT;}
| exp DIFF exp                {printf("NEI\n"); $$=INT;}
| exp AND exp                 {printf("AND\n"); $$=INT;}
| exp OR exp                  {printf("OR\n"); $$=INT;}

;

// V.3 Applications de fonctions


app : fid PO args PF          {}
;

fid : ID                      {}

args :  arglist               {}
|                             {}
;

arglist : arglist VIR exp     {} // récursion gauche pour empiler les arguements de la fonction de gauche à droite
| exp                         {}
;



%% 
int main () {

  /* Ici on peut ouvrir le fichier source, avec les messages 
     d'erreur usuel si besoin, et rediriger l'entrée standard 
     sur ce fichier pour lancer dessus la compilation.
   */

char * header=
"// PCode Header\n\
#include \"PCode.h\"\n\
\n\
void pcode_main();\n\
void init_glob_var();\n\
\n\
int main() {\n\
init_glob_var();\n\
pcode_main();\n\
return stack[sp-1].int_value;\n\
}\n\
\n";  

printf("%s\n",header); // ouput header
  
return yyparse (); // output your compilation
 
 
} 

#include "aux.y"

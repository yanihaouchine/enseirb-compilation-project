%{


#include "Table_des_symboles.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  int make_code_arith(int exp1, int op, int exp2);
extern int yylex();
extern int yyparse();

void yyerror (char* s) {
  printf ("%s\n",s);
  exit(0);
  }


int depth=0; // block depth
int current_type = 0; // type courant pour add_global_variable() //Modifier par yasmine
int current_offset = 0; // compteur global pour les offsets
static int cond_count = 0;
#define MAX_LABELS 100


int current_function_arg_count = 0;
int current_return_offset = -1;//pour loffset de retour de l fonction
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
%type <string_value> fid
%type <int_value> args arglist
%type <type_value> app
%type <label_value> if while cond loop if_head

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

fun : type fun_head fun_body {
  
};



po: PO {end_glob_var_decl();}  // dirty trick to end function init_glob_var() definition in target code
  
fun_head : ID po PF            {
 
    attribute a = new_attribute();
a->type = current_type;
    a->depth = 0;
    a->offset = 0;
    set_symbol_value($1, a);
    current_function_arg_count = 0;  
    current_return_offset = -1;      

 
    current_offset = 1; 
depth=0;
    if (strcmp($1, "main") == 0) {
        printf("void pcode_main() {\n");
        
    } else {
        printf("%s pcode_%s() {\n", type2string(a->type), $1);
        


    }    


}

| ID po params PF              {
   if (depth > 0) yyerror("Function must be declared at top level~!\n");

    attribute a = new_attribute();
    a->type = current_type;
    a->depth = 0;
    a->offset = 0;
    set_symbol_value($1, a);
depth=0;
    current_return_offset = -(current_function_arg_count + 1);
    current_offset = 1;
    printf("%s pcode_%s(", type2string(a->type), $1);
    printf(") {\n");
    
 } 
;

params
: type ID VIR params {
    attribute a = new_attribute();
    a->type = $1;
    a->depth = 1; 
    a->offset = - (current_function_arg_count + 1); 
    current_function_arg_count++; 
    set_symbol_value($2, a);

}
| type ID {
    attribute a = new_attribute();
    a->type = $1;
    a->depth = 1;
    a->offset = - (current_function_arg_count + 1);
    current_function_arg_count++;
    set_symbol_value($2, a);

}
;




vir : VIR                      {}
;

fun_body :fao {
}
block
faf {
   // printf("}\n");
};


fao : AO                       {
  //printf("%i\n",depth);
depth++;
//printf("%i\n",depth);
}
;
faf : AF                       {     

    remove_symbols_at_depth(depth);
    depth = 0;
    current_function_arg_count = 0;
    current_return_offset = -1;
    printf("}\n");
}
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

vlist: vlist vir ID { 
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
ao block af                   {
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
depth++;
current_offset=1;
}
;

af : AF                       {printf("RESTOREBP \n");
    remove_symbols_at_depth(depth);

    depth--;

}
;


// IV.1 Affectations

// Affectation : aff //MODIFER par Yasmine
aff : ID EQ exp {
    attribute a = get_symbol_value($1);
    if (!a) yyerror("Variable non déclarée");


    if (a->type == FLOAT && $3 == INT)
        printf("I2F2\n");
    else if (a->type == INT && $3 == FLOAT)
        printf("F2I1\n");

    if (a->depth != depth) {// VARIABLE GLOBALE
      if(a->depth<depth  ){
        if(a->depth !=0){
        printf("LOADBP\n");
        int d = depth - a->depth;// Remonter les blocs 
        for (int i = 0; i < d; i++)
             printf("LOAD\n");        
        printf("SHIFT(%d)\n",a->offset);
        }else{
          printf("LOADI(%i)\n",a->offset);
        }
        
      }
    } else {// VARIABLE LOCALE
        printf("LOADBP\n");
        int d = depth - a->depth;// Remonter les blocs 
        for (int i = 0; i < d; i++)
            printf("LOAD\n ");
        printf("SHIFT(%d) \n",
               a->offset);
    }

    printf("STORE\n");
}
;





// IV.2 Return
ret
: RETURN exp {
    

        int d = depth-1;   //nbre de bloc a remonter 

        printf("LOADBP\n");
        for (int i = 0; i < d; i++) {
            printf("LOAD\n");
        }


        printf("SHIFT(%d)\n", current_return_offset);

        /* STORE la valeur de retour */
        printf("STORE\n");
  
     
}
| RETURN PO PF { 
   /* return sans expression : rien à faire ici si tu veux mettre 0 par défaut */ }

// IV.3. Conditionelles
//           N.B. ces rêgles génèrent un conflit déclage reduction
//           qui est résolu comme on le souhaite par un décalage (shift)
//           avec ELSE en entrée (voir y.output)

cond :
if_head
ELSE { printf("GOTO(End_%d)\n", $1);
       printf("False_%d:\n", $1); }
inst {printf("End_%d:\n", $1);
                     }

|if_head %prec IFX { printf("False_%d:\n", $1);
                          }
;
if_head : 


  if bool_cond          { printf("IFN(False_%d)\n", $1); }
  inst
                        {$$ = $1;}
;


bool_cond : PO exp PF         {}
;

if : IF {
  $$ = cond_count++;
  
}
;
// IV.4. Iterations

loop : while while_cond  {printf("IFN(EndLoop_%i ):\n",$1);} inst  {
  printf("GOTO(StartLoop_%i)\n",$1);
printf(" EndLoop_%i :\n",$1);

}
;

while_cond : PO exp PF        {}

while : WHILE                 {
 
 $$ = cond_count++;
      printf("StartLoop_%i :\n",$$);}
;


// V. Expressions

exp //MODIFIER PAR Yas
// V.1 Exp. arithmetiques
: MOINS exp %prec UNA         {if ($2 == INT) {
        printf("MINUSI\n");   /* négation entière */
        $$ = INT;
    } else if ($2 == FLOAT) {
        printf("MINUSF\n");   /* négation flottante */
        $$ = FLOAT;
    } }
         // -x + y lue comme (- x) + y  et pas - (x + y)
| exp PLUS exp                {$$ = make_code_arith($1, PLUS, $3);}
| exp MOINS exp               {$$ = make_code_arith($1, MOINS, $3);}
| exp STAR exp                { $$ = make_code_arith($1, STAR, $3);}
| exp DIV  exp                {$$ = make_code_arith($1, DIV, $3);}
| PO exp PF                   {$$ = $2;}
|  ID {
    attribute a = get_symbol_value($1);
    if (!a) yyerror("Variable non déclarée");

if(a->offset<0){
  if(a->depth<depth){
  printf("LOADBP\n");
  int d = depth - a->depth;// Remonter les blocs 
        for (int i = 0; i < d; i++)
             printf("LOAD\n");       
        printf("SHIFT(%i)\n",a->offset);
printf("LOAD\n");

  }else{
    printf("LOADBP\n");
int d = depth - a->depth;// Remonter les blocs 
            
        printf("SHIFT(%i)\n",a->offset);
printf("LOAD\n");
  }
        


}else{
  if(a->depth==0){
if(a->type==INT) printf("LOADI(%i)\n",a->offset);
else printf("LOADI(%i)\n",a->offset);
printf("LOAD\n");
  }else{
if(a->depth<depth){
    printf("LOADBP\n");
int d = depth - a->depth;// Remonter les blocs 
        for (int i = 0; i < d; i++)
             printf("LOAD\n");       
        printf("SHIFT(%i)\n",a->offset);
printf("LOAD\n");

}
if(a->depth==depth){
      printf("LOADBP\n");
      printf("SHIFT(%i)\n",a->offset);
      printf("LOAD\n");



}}
}


    $$ = a->type;
}


| app                         {}
| NUM  { printf("LOADI(%d)\n",$<int_value>1); $$=INT; }
| DEC  { printf("LOADF(%f)\n",$<float_value>1); $$=FLOAT; }



// V.2. Booléens

| NOT exp %prec UNA           {printf("NOT\n"); $$=$2;}
| exp INF exp                 {printf("LTI\n"); $$=INT;}
| exp SUP exp                 {printf("GTI\n"); $$=INT;}
| exp EQUAL exp               {printf("EQI\n"); $$=INT;}
| exp DIFF exp                {printf("NEI\n"); $$=INT;}

| exp AND
{
  $<label_value>$ = cond_count++;
  printf("IFN(BoolFalse_%d)\n",$<label_value>$);
}
exp{
  printf("IFN(BoolFalse_%d)\n",$<label_value>3);
  printf("LOADI(1)\n"); //ICI 1 fait office de true...
  printf("GOTO(BoolEnd_%d)\n",$<label_value>3);
  printf("BoolFalse_%d :\n",$<label_value>3);
  printf("LOADI(0)\n"); // Symétriqument à ci dessus...
  printf("BoolEnd_%d :\n",$<label_value>3);
  $$ = INT;
};

| exp OR
{
  $<label_value>$ = cond_count++;
  printf("IF(BoolTrue_%d)\n",$<label_value>$);
}
exp{
  printf("IF(BoolTrue_%d)\n",$<label_value>3);
  printf("LOADI(0)\n"); //ICI 0 fait office de false...
  printf("GOTO(BoolEnd_%d)\n",$<label_value>3);
  printf("BoolTrue_%d :\n",$<label_value>3);
  printf("LOADI(1)\n"); // Symétriqument à ci dessus...
  printf("BoolEnd_%d :\n",$<label_value>3);
  $<label_value>$ = INT;
};


// V.3 Applications de fonctions


app
: fid{// Génération du code pour empiler les arguments
        attribute a = get_symbol_value($1);
if (!a) yyerror("Function non déclarée");

        /* Si la fonction est VOID → empiler 0 comme valeur de retour */
        if (a->type == INT) {
            printf("LOADI(0)\n");
        }else {
          if(a->type == FLOAT) printf("LOADF(0)\n");
          
        }

    } PO args PF {
    attribute a = get_symbol_value($1);
    if (!a) yyerror("Function non déclarée");

    /* arguments sont déjà évalués par 'args' et empilés (arglist produit les LOADI/LOAD/...) */
    printf("SAVEBP\n");
    printf("CALL(pcode_%s)\n", $1);
    printf("RESTOREBP\n");

    /* supprimer les arguments empilés */
    if ($4 > 0) printf("DROP(%d)\n", $4);

    $$ = a->type;
}
;



fid : ID                      {$$ = $1; }//nom de la fonction

args :  arglist               { $$ = $1;}
|                             {$$=0;}
;

arglist : arglist VIR exp     {$$ = $1 + 1; } // récursion gauche pour empiler les arguements de la fonction de gauche à droite
| exp                         {$$=1;}
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

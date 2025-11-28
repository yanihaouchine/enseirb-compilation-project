/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lang.y"



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

#line 100 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM = 258,                     /* NUM  */
    DEC = 259,                     /* DEC  */
    INT = 260,                     /* INT  */
    FLOAT = 261,                   /* FLOAT  */
    VOID = 262,                    /* VOID  */
    ID = 263,                      /* ID  */
    AO = 264,                      /* AO  */
    AF = 265,                      /* AF  */
    PO = 266,                      /* PO  */
    PF = 267,                      /* PF  */
    PV = 268,                      /* PV  */
    VIR = 269,                     /* VIR  */
    RETURN = 270,                  /* RETURN  */
    EQ = 271,                      /* EQ  */
    IF = 272,                      /* IF  */
    ELSE = 273,                    /* ELSE  */
    WHILE = 274,                   /* WHILE  */
    AND = 275,                     /* AND  */
    OR = 276,                      /* OR  */
    NOT = 277,                     /* NOT  */
    DIFF = 278,                    /* DIFF  */
    EQUAL = 279,                   /* EQUAL  */
    SUP = 280,                     /* SUP  */
    INF = 281,                     /* INF  */
    PLUS = 282,                    /* PLUS  */
    MOINS = 283,                   /* MOINS  */
    STAR = 284,                    /* STAR  */
    DIV = 285,                     /* DIV  */
    DOT = 286,                     /* DOT  */
    ARR = 287,                     /* ARR  */
    IFX = 288,                     /* IFX  */
    UNA = 289                      /* UNA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUM 258
#define DEC 259
#define INT 260
#define FLOAT 261
#define VOID 262
#define ID 263
#define AO 264
#define AF 265
#define PO 266
#define PF 267
#define PV 268
#define VIR 269
#define RETURN 270
#define EQ 271
#define IF 272
#define ELSE 273
#define WHILE 274
#define AND 275
#define OR 276
#define NOT 277
#define DIFF 278
#define EQUAL 279
#define SUP 280
#define INF 281
#define PLUS 282
#define MOINS 283
#define STAR 284
#define DIV 285
#define DOT 286
#define ARR 287
#define IFX 288
#define UNA 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "lang.y"
 
  struct ATTRIBUTE * symbol_value;
  char * string_value;
  int int_value;
  float float_value;
  int type_value; //pour stocker le type de exp
  int label_value;
  int offset_value;

#line 231 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_DEC = 4,                        /* DEC  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_FLOAT = 6,                      /* FLOAT  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_ID = 8,                         /* ID  */
  YYSYMBOL_AO = 9,                         /* AO  */
  YYSYMBOL_AF = 10,                        /* AF  */
  YYSYMBOL_PO = 11,                        /* PO  */
  YYSYMBOL_PF = 12,                        /* PF  */
  YYSYMBOL_PV = 13,                        /* PV  */
  YYSYMBOL_VIR = 14,                       /* VIR  */
  YYSYMBOL_RETURN = 15,                    /* RETURN  */
  YYSYMBOL_EQ = 16,                        /* EQ  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_NOT = 22,                       /* NOT  */
  YYSYMBOL_DIFF = 23,                      /* DIFF  */
  YYSYMBOL_EQUAL = 24,                     /* EQUAL  */
  YYSYMBOL_SUP = 25,                       /* SUP  */
  YYSYMBOL_INF = 26,                       /* INF  */
  YYSYMBOL_PLUS = 27,                      /* PLUS  */
  YYSYMBOL_MOINS = 28,                     /* MOINS  */
  YYSYMBOL_STAR = 29,                      /* STAR  */
  YYSYMBOL_DIV = 30,                       /* DIV  */
  YYSYMBOL_DOT = 31,                       /* DOT  */
  YYSYMBOL_ARR = 32,                       /* ARR  */
  YYSYMBOL_IFX = 33,                       /* IFX  */
  YYSYMBOL_UNA = 34,                       /* UNA  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_prog = 36,                      /* prog  */
  YYSYMBOL_glob_decl_list = 37,            /* glob_decl_list  */
  YYSYMBOL_glob_var_list = 38,             /* glob_var_list  */
  YYSYMBOL_glob_fun_list = 39,             /* glob_fun_list  */
  YYSYMBOL_fun = 40,                       /* fun  */
  YYSYMBOL_po = 41,                        /* po  */
  YYSYMBOL_fun_head = 42,                  /* fun_head  */
  YYSYMBOL_params = 43,                    /* params  */
  YYSYMBOL_vir = 44,                       /* vir  */
  YYSYMBOL_fun_body = 45,                  /* fun_body  */
  YYSYMBOL_46_1 = 46,                      /* $@1  */
  YYSYMBOL_fao = 47,                       /* fao  */
  YYSYMBOL_faf = 48,                       /* faf  */
  YYSYMBOL_block = 49,                     /* block  */
  YYSYMBOL_decl_list = 50,                 /* decl_list  */
  YYSYMBOL_decl = 51,                      /* decl  */
  YYSYMBOL_var_decl = 52,                  /* var_decl  */
  YYSYMBOL_vlist = 53,                     /* vlist  */
  YYSYMBOL_type = 54,                      /* type  */
  YYSYMBOL_typename = 55,                  /* typename  */
  YYSYMBOL_inst_list = 56,                 /* inst_list  */
  YYSYMBOL_pv = 57,                        /* pv  */
  YYSYMBOL_inst = 58,                      /* inst  */
  YYSYMBOL_ao = 59,                        /* ao  */
  YYSYMBOL_af = 60,                        /* af  */
  YYSYMBOL_aff = 61,                       /* aff  */
  YYSYMBOL_ret = 62,                       /* ret  */
  YYSYMBOL_cond = 63,                      /* cond  */
  YYSYMBOL_64_2 = 64,                      /* $@2  */
  YYSYMBOL_if_head = 65,                   /* if_head  */
  YYSYMBOL_66_3 = 66,                      /* $@3  */
  YYSYMBOL_bool_cond = 67,                 /* bool_cond  */
  YYSYMBOL_if = 68,                        /* if  */
  YYSYMBOL_loop = 69,                      /* loop  */
  YYSYMBOL_70_4 = 70,                      /* $@4  */
  YYSYMBOL_while_cond = 71,                /* while_cond  */
  YYSYMBOL_while = 72,                     /* while  */
  YYSYMBOL_exp = 73,                       /* exp  */
  YYSYMBOL_74_5 = 74,                      /* @5  */
  YYSYMBOL_75_6 = 75,                      /* @6  */
  YYSYMBOL_app = 76,                       /* app  */
  YYSYMBOL_77_7 = 77,                      /* $@7  */
  YYSYMBOL_fid = 78,                       /* fid  */
  YYSYMBOL_args = 79,                      /* args  */
  YYSYMBOL_arglist = 80                    /* arglist  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 66 "lang.y"

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
 
  

#line 366 "y.tab.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   219

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  132

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   109,   109,   112,   115,   116,   121,   122,   127,   133,
     135,   161,   179,   188,   202,   205,   205,   213,   219,   232,
     237,   238,   241,   244,   247,   263,   284,   290,   291,   292,
     297,   298,   301,   305,   307,   308,   309,   310,   311,   312,
     317,   323,   335,   377,   395,   405,   404,   410,   416,   416,
     422,   425,   432,   432,   439,   441,   452,   460,   461,   462,
     463,   464,   465,   518,   519,   520,   526,   527,   528,   529,
     530,   533,   532,   548,   547,   567,   567,   597,   599,   600,
     603,   604
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "DEC", "INT",
  "FLOAT", "VOID", "ID", "AO", "AF", "PO", "PF", "PV", "VIR", "RETURN",
  "EQ", "IF", "ELSE", "WHILE", "AND", "OR", "NOT", "DIFF", "EQUAL", "SUP",
  "INF", "PLUS", "MOINS", "STAR", "DIV", "DOT", "ARR", "IFX", "UNA",
  "$accept", "prog", "glob_decl_list", "glob_var_list", "glob_fun_list",
  "fun", "po", "fun_head", "params", "vir", "fun_body", "$@1", "fao",
  "faf", "block", "decl_list", "decl", "var_decl", "vlist", "type",
  "typename", "inst_list", "pv", "inst", "ao", "af", "aff", "ret", "cond",
  "$@2", "if_head", "$@3", "bool_cond", "if", "loop", "$@4", "while_cond",
  "while", "exp", "@5", "@6", "app", "$@7", "fid", "args", "arglist", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-51)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-78)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -51,    10,   -51,    36,   -51,   -51,   -51,   -51,    36,   -51,
     -12,   -51,     6,   -51,   -51,    12,   -51,     7,    13,    11,
       7,   -51,    23,   -51,   -51,   -51,   -51,    25,   -51,    19,
      26,   -51,   -51,   -51,    22,    29,    72,    36,   -51,   -51,
     -51,   -51,     0,   -51,    95,   -51,   105,   -51,   -51,    95,
      95,    39,    46,     4,   -51,   -51,   -51,    49,    49,   -51,
      38,    71,   -51,    73,   170,   -51,   -51,   -51,    95,    77,
     114,    93,   181,   -51,   -51,   -51,   -51,   -51,    80,   -51,
     -51,   -51,    95,   -51,    95,   -51,   -51,   -51,    95,    95,
      95,    95,    95,    95,    95,    95,   -51,    84,   181,   -51,
     -51,   -51,   -51,     4,   133,     4,   152,     4,    95,    95,
      31,    31,    31,    31,    63,    63,   -51,   -51,    95,   -51,
     -51,   -51,   -51,   -51,   189,    43,   181,    90,    96,   -51,
      95,   181
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     2,     0,     1,    27,    28,    29,     3,     7,
       0,    22,     0,    26,     6,     0,     4,    25,     0,    23,
       0,     9,     0,    17,     8,    15,    14,     0,    10,     0,
       0,    21,    24,    11,    13,     0,     0,     0,    18,    16,
      64,    65,    62,    40,     0,    32,     0,    51,    55,     0,
       0,     0,     0,    19,    39,    31,    21,     0,     0,    37,
      47,     0,    38,     0,     0,    63,    75,    12,     0,    62,
       0,     0,    43,    66,    56,    20,    25,    30,     0,    35,
      36,    45,     0,    48,     0,    52,    71,    73,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,    42,    61,
      44,    41,    33,     0,     0,     0,     0,     0,     0,     0,
      70,    69,    68,    67,    57,    58,    59,    60,    79,    46,
      50,    49,    54,    53,    72,    74,    81,     0,    78,    76,
       0,    80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,   -51,   -51,   -51,    99,   -51,   -51,    82,   -51,
     -51,   -51,   -51,   -51,    58,   -51,    86,   -51,   -51,     1,
     -51,   -51,    54,   -50,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -44,   -51,
     -51,   -51,   -51,   -51,   -51,   -51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     3,     8,     9,    22,    18,    29,    27,
      24,    31,    25,    39,    35,    36,    10,    11,    19,    30,
      13,    53,    54,    55,    56,   102,    57,    58,    59,   103,
      60,   105,    83,    61,    62,   107,    85,    63,    64,   108,
     109,    65,    97,    66,   127,   128
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,    16,    72,    77,    12,    73,    74,    40,    41,    15,
       4,   -77,    42,    43,    17,    44,    68,    45,    21,    46,
      20,    47,    23,    48,    98,    26,    49,    70,     5,     6,
       7,    33,    50,    32,    34,    28,    37,    52,   104,    38,
     106,     5,     6,     7,   110,   111,   112,   113,   114,   115,
     116,   117,    75,   119,    76,   121,    81,   123,    92,    93,
      94,    95,    45,    86,   124,   125,    88,    89,    90,    91,
      92,    93,    94,    95,   126,    40,    41,     5,     6,     7,
      42,    43,    82,    44,    84,    45,   131,    46,   -77,    47,
     101,    48,    94,    95,    49,   118,    40,    41,    40,    41,
      50,    69,   129,    69,    44,   100,    44,    14,    40,    41,
     130,    79,    80,    69,    78,    49,    71,    49,    96,    67,
       0,    50,    51,    50,     0,     0,    99,    49,     0,     0,
       0,     0,     0,    50,    86,    87,     0,    88,    89,    90,
      91,    92,    93,    94,    95,   120,     0,     0,     0,     0,
       0,     0,     0,    86,    87,     0,    88,    89,    90,    91,
      92,    93,    94,    95,   122,     0,     0,     0,     0,     0,
       0,     0,    86,    87,     0,    88,    89,    90,    91,    92,
      93,    94,    95,    45,     0,     0,     0,     0,     0,     0,
      86,    87,     0,    88,    89,    90,    91,    92,    93,    94,
      95,    86,    87,     0,    88,    89,    90,    91,    92,    93,
      94,    95,    88,    89,    90,    91,    92,    93,    94,    95
};

static const yytype_int16 yycheck[] =
{
      44,    13,    46,    53,     3,    49,    50,     3,     4,     8,
       0,    11,     8,     9,     8,    11,    16,    13,    11,    15,
       8,    17,     9,    19,    68,    14,    22,    71,     5,     6,
       7,    12,    28,     8,     8,    12,    14,    36,    82,    10,
      84,     5,     6,     7,    88,    89,    90,    91,    92,    93,
      94,    95,    13,   103,     8,   105,    18,   107,    27,    28,
      29,    30,    13,    20,   108,   109,    23,    24,    25,    26,
      27,    28,    29,    30,   118,     3,     4,     5,     6,     7,
       8,     9,    11,    11,    11,    13,   130,    15,    11,    17,
      10,    19,    29,    30,    22,    11,     3,     4,     3,     4,
      28,     8,    12,     8,    11,    12,    11,     8,     3,     4,
      14,    57,    58,     8,    56,    22,    11,    22,    64,    37,
      -1,    28,    36,    28,    -1,    -1,    12,    22,    -1,    -1,
      -1,    -1,    -1,    28,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    20,    21,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    23,    24,    25,    26,    27,    28,    29,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    37,    38,     0,     5,     6,     7,    39,    40,
      51,    52,    54,    55,    40,    54,    13,     8,    42,    53,
       8,    11,    41,     9,    45,    47,    14,    44,    12,    43,
      54,    46,     8,    12,     8,    49,    50,    14,    10,    48,
       3,     4,     8,     9,    11,    13,    15,    17,    19,    22,
      28,    51,    54,    56,    57,    58,    59,    61,    62,    63,
      65,    68,    69,    72,    73,    76,    78,    43,    16,     8,
      73,    11,    73,    73,    73,    13,     8,    58,    49,    57,
      57,    18,    11,    67,    11,    71,    20,    21,    23,    24,
      25,    26,    27,    28,    29,    30,    57,    77,    73,    12,
      12,    10,    60,    64,    73,    66,    73,    70,    74,    75,
      73,    73,    73,    73,    73,    73,    73,    73,    11,    58,
      12,    58,    12,    58,    73,    73,    73,    79,    80,    12,
      14,    73
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    38,    38,    39,    39,    40,    41,
      42,    42,    43,    43,    44,    46,    45,    47,    48,    49,
      50,    50,    51,    52,    53,    53,    54,    55,    55,    55,
      56,    56,    57,    58,    58,    58,    58,    58,    58,    58,
      59,    60,    61,    62,    62,    64,    63,    63,    66,    65,
      67,    68,    70,    69,    71,    72,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    74,    73,    75,    73,    77,    76,    78,    79,    79,
      80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     0,     2,     1,     3,     1,
       3,     4,     4,     2,     1,     0,     4,     1,     1,     2,
       3,     0,     1,     2,     3,     1,     1,     1,     1,     1,
       2,     1,     1,     3,     2,     2,     2,     1,     1,     1,
       1,     1,     3,     2,     3,     0,     4,     1,     0,     4,
       3,     1,     0,     4,     3,     1,     2,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     2,     3,     3,     3,
       3,     0,     4,     0,     4,     0,     5,     1,     1,     0,
       3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* prog: glob_decl_list  */
#line 109 "lang.y"
                                   {}
#line 1431 "y.tab.c"
    break;

  case 3: /* glob_decl_list: glob_var_list glob_fun_list  */
#line 112 "lang.y"
                                             {}
#line 1437 "y.tab.c"
    break;

  case 4: /* glob_var_list: glob_var_list decl PV  */
#line 115 "lang.y"
                                      {}
#line 1443 "y.tab.c"
    break;

  case 5: /* glob_var_list: %empty  */
#line 116 "lang.y"
  {printf("void init_glob_var(){\n"); // starting  function init_glob_var() definition in target code
   current_offset = 0;
 }
#line 1451 "y.tab.c"
    break;

  case 6: /* glob_fun_list: glob_fun_list fun  */
#line 121 "lang.y"
                                  {}
#line 1457 "y.tab.c"
    break;

  case 7: /* glob_fun_list: fun  */
#line 122 "lang.y"
      {}
#line 1463 "y.tab.c"
    break;

  case 8: /* fun: type fun_head fun_body  */
#line 127 "lang.y"
                             {
  
}
#line 1471 "y.tab.c"
    break;

  case 9: /* po: PO  */
#line 133 "lang.y"
       {end_glob_var_decl();}
#line 1477 "y.tab.c"
    break;

  case 10: /* fun_head: ID po PF  */
#line 135 "lang.y"
                               {
 
    attribute a = new_attribute();
a->type = current_type;
    a->depth = 0;
    a->offset = 0;
    set_symbol_value((yyvsp[-2].string_value), a);
    current_function_arg_count = 0;  
    current_return_offset = -1;      

 
    current_offset = 1; 
depth=0;
    if (strcmp((yyvsp[-2].string_value), "main") == 0) {
        printf("void pcode_main() {\n");
        
    } else {
        printf("%s pcode_%s() {\n", type2string(a->type), (yyvsp[-2].string_value));
        


    }    


}
#line 1507 "y.tab.c"
    break;

  case 11: /* fun_head: ID po params PF  */
#line 161 "lang.y"
                               {
   if (depth > 0) yyerror("Function must be declared at top level~!\n");

    attribute a = new_attribute();
    a->type = current_type;
    a->depth = 0;
    a->offset = 0;
    set_symbol_value((yyvsp[-3].string_value), a);
depth=0;
    current_return_offset = -(current_function_arg_count + 1);
    current_offset = 1;
    printf("%s pcode_%s(", type2string(a->type), (yyvsp[-3].string_value));
    printf(") {\n");
    
 }
#line 1527 "y.tab.c"
    break;

  case 12: /* params: type ID VIR params  */
#line 179 "lang.y"
                     {
    attribute a = new_attribute();
    a->type = (yyvsp[-3].type_value);
    a->depth = 1; 
    a->offset = - (current_function_arg_count + 1); 
    current_function_arg_count++; 
    set_symbol_value((yyvsp[-2].string_value), a);

}
#line 1541 "y.tab.c"
    break;

  case 13: /* params: type ID  */
#line 188 "lang.y"
          {
    attribute a = new_attribute();
    a->type = (yyvsp[-1].type_value);
    a->depth = 1;
    a->offset = - (current_function_arg_count + 1);
    current_function_arg_count++;
    set_symbol_value((yyvsp[0].string_value), a);

}
#line 1555 "y.tab.c"
    break;

  case 14: /* vir: VIR  */
#line 202 "lang.y"
                               {}
#line 1561 "y.tab.c"
    break;

  case 15: /* $@1: %empty  */
#line 205 "lang.y"
              {
}
#line 1568 "y.tab.c"
    break;

  case 16: /* fun_body: fao $@1 block faf  */
#line 208 "lang.y"
    {
   // printf("}\n");
}
#line 1576 "y.tab.c"
    break;

  case 17: /* fao: AO  */
#line 213 "lang.y"
                               {
  //printf("%i\n",depth);
depth++;
//printf("%i\n",depth);
}
#line 1586 "y.tab.c"
    break;

  case 18: /* faf: AF  */
#line 219 "lang.y"
                               {     

    remove_symbols_at_depth(depth);
    depth = 0;
    current_function_arg_count = 0;
    current_return_offset = -1;
    printf("}\n");
}
#line 1599 "y.tab.c"
    break;

  case 19: /* block: decl_list inst_list  */
#line 232 "lang.y"
                               {}
#line 1605 "y.tab.c"
    break;

  case 20: /* decl_list: decl_list decl PV  */
#line 237 "lang.y"
                                {}
#line 1611 "y.tab.c"
    break;

  case 21: /* decl_list: %empty  */
#line 238 "lang.y"
                                {}
#line 1617 "y.tab.c"
    break;

  case 22: /* decl: var_decl  */
#line 241 "lang.y"
                                {}
#line 1623 "y.tab.c"
    break;

  case 23: /* var_decl: type vlist  */
#line 244 "lang.y"
                               {}
#line 1629 "y.tab.c"
    break;

  case 24: /* vlist: vlist vir ID  */
#line 247 "lang.y"
                    { 
attribute a = new_attribute();
a->type = current_type;
a->depth = depth;
a->offset = current_offset++;
set_symbol_value((yyvsp[0].string_value), a);
printf("// Declare %s of type %s with offset %d at depth %d\n",
       (yyvsp[0].string_value), type2string(a->type), a->offset, a->depth);


if (a->type == INT) {
    printf("LOADI(0)\n\n");
} else if (a->type == FLOAT) {
    printf("LOADF(0.0)\n\n");
}
}
#line 1650 "y.tab.c"
    break;

  case 25: /* vlist: ID  */
#line 263 "lang.y"
     {
attribute a = new_attribute();
a->type = current_type;
a->depth = depth;
a->offset = current_offset++;
set_symbol_value((yyvsp[0].string_value), a);


if (a->type == INT) {
    printf("LOADI(0)\n\n");
} else if (a->type == FLOAT) {
    printf("LOADF(0.0)\n\n");
}


}
#line 1671 "y.tab.c"
    break;

  case 26: /* type: typename  */
#line 284 "lang.y"
               { (yyval.type_value) = (yyvsp[0].type_value); current_type = (yyvsp[0].type_value);}
#line 1677 "y.tab.c"
    break;

  case 27: /* typename: INT  */
#line 290 "lang.y"
                               {(yyval.type_value)=INT;}
#line 1683 "y.tab.c"
    break;

  case 28: /* typename: FLOAT  */
#line 291 "lang.y"
                               {(yyval.type_value)=FLOAT;}
#line 1689 "y.tab.c"
    break;

  case 29: /* typename: VOID  */
#line 292 "lang.y"
                               {(yyval.type_value)=VOID;}
#line 1695 "y.tab.c"
    break;

  case 30: /* inst_list: inst_list inst  */
#line 297 "lang.y"
                            {}
#line 1701 "y.tab.c"
    break;

  case 31: /* inst_list: inst  */
#line 298 "lang.y"
                            {}
#line 1707 "y.tab.c"
    break;

  case 32: /* pv: PV  */
#line 301 "lang.y"
                              {}
#line 1713 "y.tab.c"
    break;

  case 33: /* inst: ao block af  */
#line 305 "lang.y"
                              {
                                }
#line 1720 "y.tab.c"
    break;

  case 34: /* inst: exp pv  */
#line 307 "lang.y"
                              {}
#line 1726 "y.tab.c"
    break;

  case 35: /* inst: aff pv  */
#line 308 "lang.y"
                              {}
#line 1732 "y.tab.c"
    break;

  case 36: /* inst: ret pv  */
#line 309 "lang.y"
                              {}
#line 1738 "y.tab.c"
    break;

  case 37: /* inst: cond  */
#line 310 "lang.y"
                              {}
#line 1744 "y.tab.c"
    break;

  case 38: /* inst: loop  */
#line 311 "lang.y"
                              {}
#line 1750 "y.tab.c"
    break;

  case 39: /* inst: pv  */
#line 312 "lang.y"
                              {}
#line 1756 "y.tab.c"
    break;

  case 40: /* ao: AO  */
#line 317 "lang.y"
                              {printf("SAVEBP \n");
depth++;
current_offset=1;
}
#line 1765 "y.tab.c"
    break;

  case 41: /* af: AF  */
#line 323 "lang.y"
                              {printf("RESTOREBP \n");
    remove_symbols_at_depth(depth);

    depth--;

}
#line 1776 "y.tab.c"
    break;

  case 42: /* aff: ID EQ exp  */
#line 335 "lang.y"
                {
    attribute a = get_symbol_value((yyvsp[-2].string_value));
    if (!a) yyerror("Variable non déclarée");


    if (a->type == FLOAT && (yyvsp[0].type_value) == INT)
        printf("I2F2\n");
    else if (a->type == INT && (yyvsp[0].type_value) == FLOAT)
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
#line 1815 "y.tab.c"
    break;

  case 43: /* ret: RETURN exp  */
#line 377 "lang.y"
             {
    

        int d = depth-1;   //nbre de bloc a remonter 

        printf("LOADBP\n");
        for (int i = 0; i < d; i++) {
            printf("LOAD\n");
        }


        printf("SHIFT(%d)\n", current_return_offset);

        /* STORE la valeur de retour */
        printf("STORE\n");
  
     
}
#line 1838 "y.tab.c"
    break;

  case 44: /* ret: RETURN PO PF  */
#line 395 "lang.y"
               { 
   /* return sans expression : rien à faire ici si tu veux mettre 0 par défaut */ }
#line 1845 "y.tab.c"
    break;

  case 45: /* $@2: %empty  */
#line 405 "lang.y"
     { printf("GOTO(End_%d)\n", (yyvsp[-1].label_value));
       printf("False_%d:\n", (yyvsp[-1].label_value)); }
#line 1852 "y.tab.c"
    break;

  case 46: /* cond: if_head ELSE $@2 inst  */
#line 407 "lang.y"
     {printf("End_%d:\n", (yyvsp[-3].label_value));
                     }
#line 1859 "y.tab.c"
    break;

  case 47: /* cond: if_head  */
#line 410 "lang.y"
                   { printf("False_%d:\n", (yyvsp[0].label_value));
                          }
#line 1866 "y.tab.c"
    break;

  case 48: /* $@3: %empty  */
#line 416 "lang.y"
                        { printf("IFN(False_%d)\n", (yyvsp[-1].label_value)); }
#line 1872 "y.tab.c"
    break;

  case 49: /* if_head: if bool_cond $@3 inst  */
#line 418 "lang.y"
                        {(yyval.label_value) = (yyvsp[-3].label_value);}
#line 1878 "y.tab.c"
    break;

  case 50: /* bool_cond: PO exp PF  */
#line 422 "lang.y"
                              {}
#line 1884 "y.tab.c"
    break;

  case 51: /* if: IF  */
#line 425 "lang.y"
        {
  (yyval.label_value) = cond_count++;
  
}
#line 1893 "y.tab.c"
    break;

  case 52: /* $@4: %empty  */
#line 432 "lang.y"
                         {printf("IFN(EndLoop_%i ):\n",(yyvsp[-1].label_value));}
#line 1899 "y.tab.c"
    break;

  case 53: /* loop: while while_cond $@4 inst  */
#line 432 "lang.y"
                                                                   {
  printf("GOTO(StartLoop_%i)\n",(yyvsp[-3].label_value));
printf(" EndLoop_%i :\n",(yyvsp[-3].label_value));

}
#line 1909 "y.tab.c"
    break;

  case 54: /* while_cond: PO exp PF  */
#line 439 "lang.y"
                              {}
#line 1915 "y.tab.c"
    break;

  case 55: /* while: WHILE  */
#line 441 "lang.y"
                              {
 
 (yyval.label_value) = cond_count++;
      printf("StartLoop_%i :\n",(yyval.label_value));}
#line 1924 "y.tab.c"
    break;

  case 56: /* exp: MOINS exp  */
#line 452 "lang.y"
                              {if ((yyvsp[0].type_value) == INT) {
        printf("MINUSI\n");   /* négation entière */
        (yyval.type_value) = INT;
    } else if ((yyvsp[0].type_value) == FLOAT) {
        printf("MINUSF\n");   /* négation flottante */
        (yyval.type_value) = FLOAT;
    } }
#line 1936 "y.tab.c"
    break;

  case 57: /* exp: exp PLUS exp  */
#line 460 "lang.y"
                              {(yyval.type_value) = make_code_arith((yyvsp[-2].type_value), PLUS, (yyvsp[0].type_value));}
#line 1942 "y.tab.c"
    break;

  case 58: /* exp: exp MOINS exp  */
#line 461 "lang.y"
                              {(yyval.type_value) = make_code_arith((yyvsp[-2].type_value), MOINS, (yyvsp[0].type_value));}
#line 1948 "y.tab.c"
    break;

  case 59: /* exp: exp STAR exp  */
#line 462 "lang.y"
                              { (yyval.type_value) = make_code_arith((yyvsp[-2].type_value), STAR, (yyvsp[0].type_value));}
#line 1954 "y.tab.c"
    break;

  case 60: /* exp: exp DIV exp  */
#line 463 "lang.y"
                              {(yyval.type_value) = make_code_arith((yyvsp[-2].type_value), DIV, (yyvsp[0].type_value));}
#line 1960 "y.tab.c"
    break;

  case 61: /* exp: PO exp PF  */
#line 464 "lang.y"
                              {(yyval.type_value) = (yyvsp[-1].type_value);}
#line 1966 "y.tab.c"
    break;

  case 62: /* exp: ID  */
#line 465 "lang.y"
      {
    attribute a = get_symbol_value((yyvsp[0].string_value));
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


    (yyval.type_value) = a->type;
}
#line 2022 "y.tab.c"
    break;

  case 63: /* exp: app  */
#line 518 "lang.y"
                              {}
#line 2028 "y.tab.c"
    break;

  case 64: /* exp: NUM  */
#line 519 "lang.y"
       { printf("LOADI(%d)\n",(yyvsp[0].int_value)); (yyval.type_value)=INT; }
#line 2034 "y.tab.c"
    break;

  case 65: /* exp: DEC  */
#line 520 "lang.y"
       { printf("LOADF(%f)\n",(yyvsp[0].float_value)); (yyval.type_value)=FLOAT; }
#line 2040 "y.tab.c"
    break;

  case 66: /* exp: NOT exp  */
#line 526 "lang.y"
                              {printf("NOT\n"); (yyval.type_value)=(yyvsp[0].type_value);}
#line 2046 "y.tab.c"
    break;

  case 67: /* exp: exp INF exp  */
#line 527 "lang.y"
                              {printf("LTI\n"); (yyval.type_value)=INT;}
#line 2052 "y.tab.c"
    break;

  case 68: /* exp: exp SUP exp  */
#line 528 "lang.y"
                              {printf("GTI\n"); (yyval.type_value)=INT;}
#line 2058 "y.tab.c"
    break;

  case 69: /* exp: exp EQUAL exp  */
#line 529 "lang.y"
                              {printf("EQI\n"); (yyval.type_value)=INT;}
#line 2064 "y.tab.c"
    break;

  case 70: /* exp: exp DIFF exp  */
#line 530 "lang.y"
                              {printf("NEI\n"); (yyval.type_value)=INT;}
#line 2070 "y.tab.c"
    break;

  case 71: /* @5: %empty  */
#line 533 "lang.y"
{
  (yyval.label_value) = cond_count++;
  printf("IFN(BoolFalse_%d)\n",(yyval.label_value));
}
#line 2079 "y.tab.c"
    break;

  case 72: /* exp: exp AND @5 exp  */
#line 537 "lang.y"
   {
  printf("IFN(BoolFalse_%d)\n",(yyvsp[-1].label_value));
  printf("LOADI(1)\n"); //ICI 1 fait office de true...
  printf("GOTO(BoolEnd_%d)\n",(yyvsp[-1].label_value));
  printf("BoolFalse_%d :\n",(yyvsp[-1].label_value));
  printf("LOADI(0)\n"); // Symétriqument à ci dessus...
  printf("BoolEnd_%d :\n",(yyvsp[-1].label_value));
  (yyval.type_value) = INT;
}
#line 2093 "y.tab.c"
    break;

  case 73: /* @6: %empty  */
#line 548 "lang.y"
{
  (yyval.label_value) = cond_count++;
  printf("IF(BoolTrue_%d)\n",(yyval.label_value));
}
#line 2102 "y.tab.c"
    break;

  case 74: /* exp: exp OR @6 exp  */
#line 552 "lang.y"
   {
  printf("IF(BoolTrue_%d)\n",(yyvsp[-1].label_value));
  printf("LOADI(0)\n"); //ICI 0 fait office de false...
  printf("GOTO(BoolEnd_%d)\n",(yyvsp[-1].label_value));
  printf("BoolTrue_%d :\n",(yyvsp[-1].label_value));
  printf("LOADI(1)\n"); // Symétriqument à ci dessus...
  printf("BoolEnd_%d :\n",(yyvsp[-1].label_value));
  (yyval.label_value) = INT;
}
#line 2116 "y.tab.c"
    break;

  case 75: /* $@7: %empty  */
#line 567 "lang.y"
     {// Génération du code pour empiler les arguments
        attribute a = get_symbol_value((yyvsp[0].string_value));
if (!a) yyerror("Function non déclarée");

        /* Si la fonction est VOID → empiler 0 comme valeur de retour */
        if (a->type == INT) {
            printf("LOADI(0)\n");
        }else {
          if(a->type == FLOAT) printf("LOADF(0)\n");
          
        }

    }
#line 2134 "y.tab.c"
    break;

  case 76: /* app: fid $@7 PO args PF  */
#line 579 "lang.y"
                 {
    attribute a = get_symbol_value((yyvsp[-4].string_value));
    if (!a) yyerror("Function non déclarée");

    /* arguments sont déjà évalués par 'args' et empilés (arglist produit les LOADI/LOAD/...) */
    printf("SAVEBP\n");
    printf("CALL(pcode_%s)\n", (yyvsp[-4].string_value));
    printf("RESTOREBP\n");

    /* supprimer les arguments empilés */
    if ((yyvsp[-1].int_value) > 0) printf("DROP(%d)\n", (yyvsp[-1].int_value));

    (yyval.type_value) = a->type;
}
#line 2153 "y.tab.c"
    break;

  case 77: /* fid: ID  */
#line 597 "lang.y"
                              {(yyval.string_value) = (yyvsp[0].string_value); }
#line 2159 "y.tab.c"
    break;

  case 78: /* args: arglist  */
#line 599 "lang.y"
                              { (yyval.int_value) = (yyvsp[0].int_value);}
#line 2165 "y.tab.c"
    break;

  case 79: /* args: %empty  */
#line 600 "lang.y"
                              {(yyval.int_value)=0;}
#line 2171 "y.tab.c"
    break;

  case 80: /* arglist: arglist VIR exp  */
#line 603 "lang.y"
                              {(yyval.int_value) = (yyvsp[-2].int_value) + 1; }
#line 2177 "y.tab.c"
    break;

  case 81: /* arglist: exp  */
#line 604 "lang.y"
                              {(yyval.int_value)=1;}
#line 2183 "y.tab.c"
    break;


#line 2187 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 609 "lang.y"
 
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

/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<ctype.h>

    #define YYDEBUG 1
    extern FILE *yyin;

    void yyerror(const char *s);
    int yylex();
    int yywrap();

    typedef struct no{
        char *nome;
        int qtdFilhos; //Tamanho da lista de filhos
        struct no **filhos;
    } no;

    // Funções da arvore
    no* criaNo(char *nome);
    no* addFilhos(no *no_, no **novosFilhos, int qtdFilhos);
    void printArvore(no *arvore);

    // Variaveis da árvore
    no *raiz;
    no **filhos;


#line 101 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_CHAR = 5,                       /* CHAR  */
  YYSYMBOL_IDENTIFIER = 6,                 /* IDENTIFIER  */
  YYSYMBOL_FOR = 7,                        /* FOR  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_ASSIGN = 11,                    /* ASSIGN  */
  YYSYMBOL_EQ = 12,                        /* EQ  */
  YYSYMBOL_LT = 13,                        /* LT  */
  YYSYMBOL_GT = 14,                        /* GT  */
  YYSYMBOL_GTE = 15,                       /* GTE  */
  YYSYMBOL_LTE = 16,                       /* LTE  */
  YYSYMBOL_NEQ = 17,                       /* NEQ  */
  YYSYMBOL_PLUS = 18,                      /* PLUS  */
  YYSYMBOL_MINUS = 19,                     /* MINUS  */
  YYSYMBOL_ASTERISK = 20,                  /* ASTERISK  */
  YYSYMBOL_SLASH = 21,                     /* SLASH  */
  YYSYMBOL_SEMICOLON = 22,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 23,                     /* COMMA  */
  YYSYMBOL_OPENPARENTHESIS = 24,           /* OPENPARENTHESIS  */
  YYSYMBOL_CLOSEPARENTHESIS = 25,          /* CLOSEPARENTHESIS  */
  YYSYMBOL_OPENBRACKETS = 26,              /* OPENBRACKETS  */
  YYSYMBOL_CLOSEBRACKETS = 27,             /* CLOSEBRACKETS  */
  YYSYMBOL_NUMBER = 28,                    /* NUMBER  */
  YYSYMBOL_FLOATNUMBER = 29,               /* FLOATNUMBER  */
  YYSYMBOL_CHARACTER = 30,                 /* CHARACTER  */
  YYSYMBOL_NOELSE = 31,                    /* NOELSE  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_Program = 33,                   /* Program  */
  YYSYMBOL_FunctionList = 34,              /* FunctionList  */
  YYSYMBOL_Function = 35,                  /* Function  */
  YYSYMBOL_ArgList = 36,                   /* ArgList  */
  YYSYMBOL_ArgListLinha = 37,              /* ArgListLinha  */
  YYSYMBOL_Arg = 38,                       /* Arg  */
  YYSYMBOL_Declaration = 39,               /* Declaration  */
  YYSYMBOL_Type = 40,                      /* Type  */
  YYSYMBOL_IdentList = 41,                 /* IdentList  */
  YYSYMBOL_Stmt = 42,                      /* Stmt  */
  YYSYMBOL_ForStmt = 43,                   /* ForStmt  */
  YYSYMBOL_OptExpr = 44,                   /* OptExpr  */
  YYSYMBOL_WhileStmt = 45,                 /* WhileStmt  */
  YYSYMBOL_IfStmt = 46,                    /* IfStmt  */
  YYSYMBOL_ElsePart = 47,                  /* ElsePart  */
  YYSYMBOL_CompoundStmt = 48,              /* CompoundStmt  */
  YYSYMBOL_StmtList = 49,                  /* StmtList  */
  YYSYMBOL_StmtListLinha = 50,             /* StmtListLinha  */
  YYSYMBOL_Expr = 51,                      /* Expr  */
  YYSYMBOL_Rvalue = 52,                    /* Rvalue  */
  YYSYMBOL_Compare = 53,                   /* Compare  */
  YYSYMBOL_Mag = 54,                       /* Mag  */
  YYSYMBOL_Term = 55,                      /* Term  */
  YYSYMBOL_Factor = 56                     /* Factor  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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
typedef yytype_int8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   94

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  100

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    55,    55,    64,    71,    79,    92,   101,   109,   117,
     126,   136,   143,   150,   158,   167,   175,   182,   189,   197,
     204,   211,   218,   226,   242,   248,   256,   269,   283,   290,
     298,   309,   316,   324,   331,   339,   348,   356,   365,   374,
     381,   388,   395,   402,   409,   417,   426,   435,   443,   452,
     461,   469,   478,   486,   494,   501,   507,   514
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
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "CHAR",
  "IDENTIFIER", "FOR", "WHILE", "IF", "ELSE", "ASSIGN", "EQ", "LT", "GT",
  "GTE", "LTE", "NEQ", "PLUS", "MINUS", "ASTERISK", "SLASH", "SEMICOLON",
  "COMMA", "OPENPARENTHESIS", "CLOSEPARENTHESIS", "OPENBRACKETS",
  "CLOSEBRACKETS", "NUMBER", "FLOATNUMBER", "CHARACTER", "NOELSE",
  "$accept", "Program", "FunctionList", "Function", "ArgList",
  "ArgListLinha", "Arg", "Declaration", "Type", "IdentList", "Stmt",
  "ForStmt", "OptExpr", "WhileStmt", "IfStmt", "ElsePart", "CompoundStmt",
  "StmtList", "StmtListLinha", "Expr", "Rvalue", "Compare", "Mag", "Term",
  "Factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
#endif

#define YYPACT_NINF (-52)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       1,   -52,   -52,   -52,     7,   -52,     1,    19,   -52,   -52,
       4,     1,    17,     9,    24,    15,     1,   -52,   -52,     5,
     -52,     9,    32,    30,    31,    35,    20,    20,   -52,    34,
     -52,   -52,   -52,   -52,    54,     5,   -52,   -52,   -52,   -52,
      39,    55,    57,    -3,    16,   -52,   -52,    34,    34,    34,
      34,   -52,   -52,   -52,    51,    58,    56,     5,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,    20,    20,    20,
      20,    20,   -52,    60,    59,    61,   -52,    54,   -52,   -52,
      -3,    16,    16,   -52,   -52,    34,     5,     5,   -52,    63,
     -52,   -52,    70,    34,     5,   -52,    62,   -52,     5,   -52
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    11,    12,    13,     0,     2,     4,     0,     1,     3,
       0,     0,     0,     8,     0,     0,     0,     6,     9,    32,
       5,     8,    54,     0,     0,     0,     0,     0,    22,     0,
      55,    56,    57,    21,     0,    34,    16,    17,    19,    20,
       0,     0,    36,    38,    47,    50,     7,     0,     0,     0,
       0,    54,    53,    52,     0,    15,     0,    34,    31,    30,
      18,    39,    40,    41,    43,    42,    44,     0,     0,     0,
       0,     0,    35,     0,     0,     0,    51,     0,    10,    33,
      37,    45,    46,    48,    49,    25,     0,     0,    14,     0,
      24,    26,    29,    25,     0,    27,     0,    28,     0,    23
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -52,   -52,    77,   -52,   -52,    67,    73,   -52,    45,    13,
     -19,   -52,    -2,   -52,   -52,   -52,    78,   -52,    37,   -28,
     -52,   -52,    25,   -51,   -24
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    12,    17,    13,    33,    34,    56,
      57,    36,    89,    37,    38,    95,    39,    40,    58,    41,
      42,    67,    43,    44,    45
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      35,    54,    52,    53,     1,     2,     3,     8,     1,     2,
       3,    22,    23,    24,    25,    68,    69,    81,    82,    72,
      73,    74,    75,    26,    27,    10,    51,    28,    11,    29,
      18,    19,    16,    30,    31,    32,    70,    71,    26,    27,
      22,    19,    15,    47,    29,     7,    83,    84,    30,    31,
      32,     7,    26,    27,    48,    49,    14,    90,    29,    50,
      55,    14,    30,    31,    32,    90,    59,    91,    92,    61,
      62,    63,    64,    65,    66,    97,    76,    60,    78,    99,
      94,    77,    85,     9,    86,    93,    87,    98,    46,    21,
      88,    96,    80,    20,    79
};

static const yytype_int8 yycheck[] =
{
      19,    29,    26,    27,     3,     4,     5,     0,     3,     4,
       5,     6,     7,     8,     9,    18,    19,    68,    69,    47,
      48,    49,    50,    18,    19,     6,     6,    22,    24,    24,
       6,    26,    23,    28,    29,    30,    20,    21,    18,    19,
       6,    26,    25,    11,    24,     0,    70,    71,    28,    29,
      30,     6,    18,    19,    24,    24,    11,    85,    24,    24,
       6,    16,    28,    29,    30,    93,    27,    86,    87,    12,
      13,    14,    15,    16,    17,    94,    25,    22,    22,    98,
      10,    23,    22,     6,    25,    22,    25,    25,    21,    16,
      77,    93,    67,    15,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    33,    34,    35,    40,     0,    34,
       6,    24,    36,    38,    40,    25,    23,    37,     6,    26,
      48,    38,     6,     7,     8,     9,    18,    19,    22,    24,
      28,    29,    30,    39,    40,    42,    43,    45,    46,    48,
      49,    51,    52,    54,    55,    56,    37,    11,    24,    24,
      24,     6,    56,    56,    51,     6,    41,    42,    50,    27,
      22,    12,    13,    14,    15,    16,    17,    53,    18,    19,
      20,    21,    51,    51,    51,    51,    25,    23,    22,    50,
      54,    55,    55,    56,    56,    22,    25,    25,    41,    44,
      51,    42,    42,    22,    10,    47,    44,    42,    25,    42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    36,    37,    37,    38,
      39,    40,    40,    40,    41,    41,    42,    42,    42,    42,
      42,    42,    42,    43,    44,    44,    45,    46,    47,    47,
      48,    49,    49,    50,    50,    51,    51,    52,    52,    53,
      53,    53,    53,    53,    53,    54,    54,    54,    55,    55,
      55,    56,    56,    56,    56,    56,    56,    56
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     6,     2,     3,     0,     2,
       3,     1,     1,     1,     3,     1,     1,     1,     2,     1,
       1,     1,     1,     9,     1,     0,     5,     6,     2,     0,
       3,     2,     0,     2,     0,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     3,     3,
       1,     3,     2,     2,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* Program: FunctionList  */
#line 55 "parser.y"
                     {raiz = criaNo("Program"); 
                      filhos = malloc(sizeof(no *));
                      filhos[0] = (yyvsp[0].tkn1).no_; 
                      raiz = addFilhos(raiz,filhos, 1);
                      free(filhos);
                    }
#line 1208 "parser.tab.c"
    break;

  case 3: /* FunctionList: Function FunctionList  */
#line 64 "parser.y"
                                  {(yyval.tkn1).no_ = criaNo("FunctionList");
                                   filhos = malloc(2 * sizeof(no *));
                                   filhos[0] = (yyvsp[-1].tkn1).no_; 
                                   filhos[1] = (yyvsp[0].tkn1).no_;
                                   addFilhos((yyval.tkn1).no_,filhos,2);
                                   free(filhos);
                                   }
#line 1220 "parser.tab.c"
    break;

  case 4: /* FunctionList: Function  */
#line 71 "parser.y"
                     {(yyval.tkn1).no_ = criaNo("FunctionList");
                                   filhos = malloc(sizeof(no *));
                                   filhos[0] = (yyvsp[0].tkn1).no_; 
                                   addFilhos((yyval.tkn1).no_,filhos,1);
                                   free(filhos);
                                   }
#line 1231 "parser.tab.c"
    break;

  case 5: /* Function: Type IDENTIFIER OPENPARENTHESIS ArgList CLOSEPARENTHESIS CompoundStmt  */
#line 79 "parser.y"
                                                                                {(yyval.tkn1).no_ = criaNo("Function");
                                                                                 filhos = malloc(6 * sizeof(no *));
                                                                                 filhos[0] = (yyvsp[-5].tkn1).no_; 
                                                                                 filhos[1] = criaNo("IDENTIFIER");
                                                                                 filhos[2] = criaNo("(");
                                                                                 filhos[3] = (yyvsp[-2].tkn1).no_;
                                                                                 filhos[4] = criaNo(")");
                                                                                 filhos[5] = (yyvsp[0].tkn1).no_;
                                                                                 addFilhos((yyval.tkn1).no_,filhos,6);
                                                                                 free(filhos);                                                                                
                                                                                }
#line 1247 "parser.tab.c"
    break;

  case 6: /* ArgList: Arg ArgListLinha  */
#line 92 "parser.y"
                         {(yyval.tkn1).no_ = criaNo("ArgList");
                          filhos = malloc(2 * sizeof(no *));
                          filhos[0] = (yyvsp[-1].tkn1).no_; 
                          filhos[1] = (yyvsp[0].tkn1).no_;
                          addFilhos((yyval.tkn1).no_,filhos,2);
                          free(filhos);    
}
#line 1259 "parser.tab.c"
    break;

  case 7: /* ArgListLinha: COMMA Arg ArgListLinha  */
#line 101 "parser.y"
                                     {(yyval.tkn1).no_ = criaNo("ArgListLinha");
                                      filhos = malloc(3 * sizeof(no *));
                                      filhos[0] = (yyvsp[-2].tkn1).no_; 
                                      filhos[1] = criaNo(",");
                                      filhos[2] = (yyvsp[0].tkn1).no_;
                                      addFilhos((yyval.tkn1).no_,filhos,3);
                                      free(filhos);
                                    }
#line 1272 "parser.tab.c"
    break;

  case 8: /* ArgListLinha: %empty  */
#line 109 "parser.y"
   {(yyval.tkn1).no_ = criaNo("ArgListLinha");
    filhos = malloc(1 * sizeof(no *));
    filhos[0] = criaNo("ε"); 
    addFilhos((yyval.tkn1).no_,filhos,1);
    free(filhos);
    }
#line 1283 "parser.tab.c"
    break;

  case 9: /* Arg: Type IDENTIFIER  */
#line 117 "parser.y"
                     {(yyval.tkn1).no_ = criaNo("Arg");
                      filhos = malloc(2 * sizeof(no *));
                      filhos[0] = (yyvsp[-1].tkn1).no_;
                      filhos[1] = criaNo("IDENTIFIER"); 
                      addFilhos((yyval.tkn1).no_,filhos,2);
                      free(filhos);
                    }
#line 1295 "parser.tab.c"
    break;

  case 10: /* Declaration: Type IdentList SEMICOLON  */
#line 126 "parser.y"
                                     {(yyval.tkn1).no_ = criaNo("Declaration");
                                      filhos = malloc(3 * sizeof(no *));
                                      filhos[0] = (yyvsp[-2].tkn1).no_; 
                                      filhos[1] = (yyvsp[-1].tkn1).no_;
                                      filhos[2] = criaNo(";"); 
                                      addFilhos((yyval.tkn1).no_,filhos,3);
                                      free(filhos);
                                    }
#line 1308 "parser.tab.c"
    break;

  case 11: /* Type: INT  */
#line 136 "parser.y"
            {(yyval.tkn1).no_ = criaNo("Type");
               filhos = malloc(1 * sizeof(no *));
               filhos[0] = criaNo("INT"); 
               addFilhos((yyval.tkn1).no_,filhos,1);
               free(filhos);
            }
#line 1319 "parser.tab.c"
    break;

  case 12: /* Type: FLOAT  */
#line 143 "parser.y"
          {(yyval.tkn1).no_ = criaNo("Type");
               filhos = malloc(1 * sizeof(no *));
               filhos[0] = criaNo("FLOAT"); 
               addFilhos((yyval.tkn1).no_,filhos,1);
               free(filhos);
          }
#line 1330 "parser.tab.c"
    break;

  case 13: /* Type: CHAR  */
#line 150 "parser.y"
          {(yyval.tkn1).no_ = criaNo("Type");
               filhos = malloc(1 * sizeof(no *));
               filhos[0] =  criaNo("CHAR"); 
               addFilhos((yyval.tkn1).no_,filhos,1);
               free(filhos);
          }
#line 1341 "parser.tab.c"
    break;

  case 14: /* IdentList: IDENTIFIER COMMA IdentList  */
#line 158 "parser.y"
                                      {(yyval.tkn1).no_ = criaNo("IdentList");
                                       filhos = malloc(3 * sizeof(no *));
                                       filhos[0] = criaNo("IDENTIFIER"); 
                                       filhos[1] = criaNo(","); 
                                       filhos[2] = (yyvsp[0].tkn1).no_; 
                                       addFilhos((yyval.tkn1).no_,filhos,3);
                                       free(filhos);
                                    }
#line 1354 "parser.tab.c"
    break;

  case 15: /* IdentList: IDENTIFIER  */
#line 167 "parser.y"
               {(yyval.tkn1).no_ = criaNo("IdentList");
                filhos = malloc(1 * sizeof(no *));
                filhos[0] = criaNo("IDENTIFIER"); 
                addFilhos((yyval.tkn1).no_,filhos,1);
                free(filhos);
            }
#line 1365 "parser.tab.c"
    break;

  case 16: /* Stmt: ForStmt  */
#line 175 "parser.y"
                {(yyval.tkn1).no_ = criaNo("Stmt");
                 filhos = malloc(1 * sizeof(no *));
                 filhos[0] = (yyvsp[0].tkn1).no_; 
                 addFilhos((yyval.tkn1).no_,filhos,1);
                 free(filhos);   
            }
#line 1376 "parser.tab.c"
    break;

  case 17: /* Stmt: WhileStmt  */
#line 182 "parser.y"
                  {(yyval.tkn1).no_ = criaNo("Stmt");
                  filhos = malloc(1 * sizeof(no *));
                  filhos[0] = (yyvsp[0].tkn1).no_; 
                  addFilhos((yyval.tkn1).no_,filhos,1);
                  free(filhos);
            }
#line 1387 "parser.tab.c"
    break;

  case 18: /* Stmt: Expr SEMICOLON  */
#line 189 "parser.y"
                       {(yyval.tkn1).no_ = criaNo("Stmt");
                  filhos = malloc(2 * sizeof(no *));
                  filhos[0] = (yyvsp[-1].tkn1).no_; 
                  filhos[1] = criaNo(";"); 
                  addFilhos((yyval.tkn1).no_,filhos,2);
                  free(filhos);    
            }
#line 1399 "parser.tab.c"
    break;

  case 19: /* Stmt: IfStmt  */
#line 197 "parser.y"
               {(yyval.tkn1).no_ = criaNo("Stmt");
                filhos = malloc(1 * sizeof(no *));
                filhos[0] = (yyvsp[0].tkn1).no_; 
                addFilhos((yyval.tkn1).no_,filhos,1);
                free(filhos);
            }
#line 1410 "parser.tab.c"
    break;

  case 20: /* Stmt: CompoundStmt  */
#line 204 "parser.y"
                     {(yyval.tkn1).no_ = criaNo("Stmt");
                     filhos = malloc(1 * sizeof(no *));
                     filhos[0] = (yyvsp[0].tkn1).no_; 
                     addFilhos((yyval.tkn1).no_,filhos,1);
                     free(filhos);
                }
#line 1421 "parser.tab.c"
    break;

  case 21: /* Stmt: Declaration  */
#line 211 "parser.y"
                    {(yyval.tkn1).no_ = criaNo("Stmt");
                     filhos = malloc(1 * sizeof(no *));
                     filhos[0] = (yyvsp[0].tkn1).no_; 
                     addFilhos((yyval.tkn1).no_,filhos,1);
                     free(filhos);
                }
#line 1432 "parser.tab.c"
    break;

  case 22: /* Stmt: SEMICOLON  */
#line 218 "parser.y"
                  {(yyval.tkn1).no_ = criaNo("Stmt");
                   filhos = malloc(1 * sizeof(no *));
                   filhos[0] = criaNo(";"); 
                   addFilhos((yyval.tkn1).no_,filhos,1);
                   free(filhos);
                }
#line 1443 "parser.tab.c"
    break;

  case 23: /* ForStmt: FOR OPENPARENTHESIS Expr SEMICOLON OptExpr SEMICOLON OptExpr CLOSEPARENTHESIS Stmt  */
#line 226 "parser.y"
                                                                                            {(yyval.tkn1).no_ = criaNo("ForStmt");
                                                                                            filhos = malloc(9 * sizeof(no *));
                                                                                            filhos[0] = criaNo("FOR"); 
                                                                                            filhos[1] = criaNo("(");
                                                                                            filhos[2] = (yyvsp[-6].tkn1).no_; 
                                                                                            filhos[3] = criaNo(";");
                                                                                            filhos[4] = (yyvsp[-4].tkn1).no_; 
                                                                                            filhos[5] = criaNo(";");
                                                                                            filhos[6] = (yyvsp[-2].tkn1).no_; 
                                                                                            filhos[7] = criaNo(")");
                                                                                            filhos[8] = (yyvsp[0].tkn1).no_; 
                                                                                            addFilhos((yyval.tkn1).no_,filhos,9);
                                                                                            free(filhos);
                                                                                        }
#line 1462 "parser.tab.c"
    break;

  case 24: /* OptExpr: Expr  */
#line 242 "parser.y"
                 {(yyval.tkn1).no_ = criaNo("OptExpr");
                   filhos = malloc(1 * sizeof(no *));
                   filhos[0] = (yyvsp[0].tkn1).no_; 
                   addFilhos((yyval.tkn1).no_,filhos,1);
                   free(filhos);
            }
#line 1473 "parser.tab.c"
    break;

  case 25: /* OptExpr: %empty  */
#line 248 "parser.y"
    {(yyval.tkn1).no_ = criaNo("OptExpr");
     filhos = malloc(1 * sizeof(no *));
     filhos[0] = criaNo("ε"); 
     addFilhos((yyval.tkn1).no_,filhos,1);
     free(filhos);
     }
#line 1484 "parser.tab.c"
    break;

  case 26: /* WhileStmt: WHILE OPENPARENTHESIS Expr CLOSEPARENTHESIS Stmt  */
#line 256 "parser.y"
                                                            {(yyval.tkn1).no_ = criaNo("WhileStmt");
                                                             filhos = malloc(5 * sizeof(no *));
                                                             filhos[0] = criaNo("WHILE");
                                                             filhos[1] = criaNo("(");
                                                             filhos[2] = (yyvsp[-2].tkn1).no_; 
                                                             filhos[3] = criaNo(")");
                                                             filhos[4] = (yyvsp[0].tkn1).no_; 
                                                             addFilhos((yyval.tkn1).no_,filhos,5);
                                                             free(filhos);
                                                            }
#line 1499 "parser.tab.c"
    break;

  case 27: /* IfStmt: IF OPENPARENTHESIS Expr CLOSEPARENTHESIS Stmt ElsePart  */
#line 269 "parser.y"
                                                               {(yyval.tkn1).no_ = criaNo("IfStmt");
                                                             filhos = malloc(6 * sizeof(no *));
                                                             filhos[0] = criaNo("IF");
                                                             filhos[1] = criaNo("(");
                                                             filhos[2] = (yyvsp[-3].tkn1).no_; 
                                                             filhos[3] = criaNo(")");
                                                             filhos[4] = (yyvsp[-1].tkn1).no_; 
                                                             filhos[5] = (yyvsp[0].tkn1).no_; 
                                                             addFilhos((yyval.tkn1).no_,filhos,6);
                                                             free(filhos);
                                                        }
#line 1515 "parser.tab.c"
    break;

  case 28: /* ElsePart: ELSE Stmt  */
#line 283 "parser.y"
                       {(yyval.tkn1).no_ = criaNo("ElsePart");
                        filhos = malloc(2 * sizeof(no *));
                        filhos[0] = criaNo("ELSE");
                        filhos[1] = (yyvsp[0].tkn1).no_; 
                        addFilhos((yyval.tkn1).no_,filhos,2);
                        free(filhos);
                    }
#line 1527 "parser.tab.c"
    break;

  case 29: /* ElsePart: %empty  */
#line 290 "parser.y"
                          {(yyval.tkn1).no_ = criaNo("ElsePart");
                           filhos = malloc(1 * sizeof(no *));
                           filhos[0] = criaNo("ε"); 
                           addFilhos((yyval.tkn1).no_,filhos,1);
                           free(filhos);
                           }
#line 1538 "parser.tab.c"
    break;

  case 30: /* CompoundStmt: OPENBRACKETS StmtList CLOSEBRACKETS  */
#line 298 "parser.y"
                                                  { (yyval.tkn1).no_ = criaNo("CompoundStmt");
                                                    filhos = malloc(3 * sizeof(no *));
                                                    filhos[0] = criaNo("[");
                                                    filhos[1] = (yyvsp[-1].tkn1).no_;
                                                    filhos[2] = criaNo("]");
                                                    addFilhos((yyval.tkn1).no_,filhos,3);
                                                    free(filhos);
}
#line 1551 "parser.tab.c"
    break;

  case 31: /* StmtList: Stmt StmtListLinha  */
#line 309 "parser.y"
                               {(yyval.tkn1).no_ = criaNo("StmtList");
                                filhos = malloc(2 * sizeof(no *));
                                filhos[0] = (yyvsp[-1].tkn1).no_; 
                                filhos[1] = (yyvsp[0].tkn1).no_;
                                addFilhos((yyval.tkn1).no_,filhos,2);
                                free(filhos);
                            }
#line 1563 "parser.tab.c"
    break;

  case 32: /* StmtList: %empty  */
#line 316 "parser.y"
   {(yyval.tkn1).no_ = criaNo("StmtList");
    filhos = malloc(1 * sizeof(no *));
    filhos[0] = criaNo("ε"); 
    addFilhos((yyval.tkn1).no_,filhos,1);
    free(filhos);
    }
#line 1574 "parser.tab.c"
    break;

  case 33: /* StmtListLinha: Stmt StmtListLinha  */
#line 324 "parser.y"
                                   {(yyval.tkn1).no_ = criaNo("StmtListLinha");
                                    filhos = malloc(2 * sizeof(no *));
                                    filhos[0] = (yyvsp[-1].tkn1).no_; 
                                    filhos[1] = (yyvsp[0].tkn1).no_;
                                    addFilhos((yyval.tkn1).no_,filhos,2);
                                    free(filhos);
                                }
#line 1586 "parser.tab.c"
    break;

  case 34: /* StmtListLinha: %empty  */
#line 331 "parser.y"
   {(yyval.tkn1).no_ = criaNo("StmtListLinha");
    filhos = malloc(1 * sizeof(no *));
    filhos[0] = criaNo("ε"); 
    addFilhos((yyval.tkn1).no_,filhos,1);
    free(filhos);
    }
#line 1597 "parser.tab.c"
    break;

  case 35: /* Expr: IDENTIFIER ASSIGN Expr  */
#line 339 "parser.y"
                             {(yyval.tkn1).no_ = criaNo("Expr");
                                    filhos = malloc(3 * sizeof(no *));
                                    filhos[0] = criaNo("IDENTIFIER");
                                    filhos[1] = criaNo("=");
                                    filhos[2] = (yyvsp[0].tkn1).no_;
                                    addFilhos((yyval.tkn1).no_,filhos,3);
                                    free(filhos);
                            }
#line 1610 "parser.tab.c"
    break;

  case 36: /* Expr: Rvalue  */
#line 348 "parser.y"
           {(yyval.tkn1).no_ = criaNo("Expr");
          filhos = malloc(1 * sizeof(no *));
          filhos[0] = (yyvsp[0].tkn1).no_;
          addFilhos((yyval.tkn1).no_,filhos,1);
          free(filhos);
        }
#line 1621 "parser.tab.c"
    break;

  case 37: /* Rvalue: Rvalue Compare Mag  */
#line 356 "parser.y"
                           {(yyval.tkn1).no_ = criaNo("Rvalue");
                            filhos = malloc(3 * sizeof(no *));
                            filhos[0] = (yyvsp[-2].tkn1).no_;
                            filhos[1] = (yyvsp[-1].tkn1).no_;
                            filhos[2] = (yyvsp[0].tkn1).no_;
                            addFilhos((yyval.tkn1).no_,filhos,3);
                            free(filhos);
                        }
#line 1634 "parser.tab.c"
    break;

  case 38: /* Rvalue: Mag  */
#line 365 "parser.y"
            {(yyval.tkn1).no_ = criaNo("Rvalue");
            filhos = malloc(1 * sizeof(no *));
            filhos[0] = (yyvsp[0].tkn1).no_;
            addFilhos((yyval.tkn1).no_,filhos,1);
            free(filhos);
        }
#line 1645 "parser.tab.c"
    break;

  case 39: /* Compare: EQ  */
#line 374 "parser.y"
               {(yyval.tkn1).no_ = criaNo("Compare");
                 filhos = malloc(1 * sizeof(no *));
                 filhos[0] = criaNo("==");
                 addFilhos((yyval.tkn1).no_,filhos,1);
                 free(filhos);
            }
#line 1656 "parser.tab.c"
    break;

  case 40: /* Compare: LT  */
#line 381 "parser.y"
               {(yyval.tkn1).no_ = criaNo("Compare");
                 filhos = malloc(1 * sizeof(no *));
                 filhos[0] = criaNo("<");
                 addFilhos((yyval.tkn1).no_,filhos,1);
                 free(filhos);
            }
#line 1667 "parser.tab.c"
    break;

  case 41: /* Compare: GT  */
#line 388 "parser.y"
               {(yyval.tkn1).no_ = criaNo("Compare");
                 filhos = malloc(1 * sizeof(no *));
                 filhos[0] = criaNo(">");
                 addFilhos((yyval.tkn1).no_,filhos,1);
                 free(filhos);
            }
#line 1678 "parser.tab.c"
    break;

  case 42: /* Compare: LTE  */
#line 395 "parser.y"
                {(yyval.tkn1).no_ = criaNo("Compare");
                 filhos = malloc(1 * sizeof(no *));
                 filhos[0] = criaNo("<=");
                 addFilhos((yyval.tkn1).no_,filhos,1);
                 free(filhos);
            }
#line 1689 "parser.tab.c"
    break;

  case 43: /* Compare: GTE  */
#line 402 "parser.y"
                {(yyval.tkn1).no_ = criaNo("Compare");
                 filhos = malloc(1 * sizeof(no *));
                 filhos[0] = criaNo(">=");
                 addFilhos((yyval.tkn1).no_,filhos,1);
                 free(filhos);
            }
#line 1700 "parser.tab.c"
    break;

  case 44: /* Compare: NEQ  */
#line 409 "parser.y"
                {(yyval.tkn1).no_ = criaNo("Compare");
                 filhos = malloc(1 * sizeof(no *));
                 filhos[0] = criaNo("!=");
                 addFilhos((yyval.tkn1).no_,filhos,1);
                 free(filhos);
            }
#line 1711 "parser.tab.c"
    break;

  case 45: /* Mag: Mag PLUS Term  */
#line 417 "parser.y"
                      {(yyval.tkn1).no_ = criaNo("Mag");
                       filhos = malloc(3 * sizeof(no *));
                       filhos[0] = (yyvsp[-2].tkn1).no_;
                       filhos[1] = criaNo("+");
                       filhos[2] = (yyvsp[0].tkn1).no_;
                       addFilhos((yyval.tkn1).no_,filhos,3);
                       free(filhos);
                    }
#line 1724 "parser.tab.c"
    break;

  case 46: /* Mag: Mag MINUS Term  */
#line 426 "parser.y"
                       {(yyval.tkn1).no_ = criaNo("Mag");
                        filhos = malloc(3 * sizeof(no *));
                        filhos[0] = (yyvsp[-2].tkn1).no_;
                        filhos[1] = criaNo("-");
                        filhos[2] = (yyvsp[0].tkn1).no_;
                        addFilhos((yyval.tkn1).no_,filhos,3);
                        free(filhos);
                    }
#line 1737 "parser.tab.c"
    break;

  case 47: /* Mag: Term  */
#line 435 "parser.y"
             {(yyval.tkn1).no_ = criaNo("Mag");
              filhos = malloc(1 * sizeof(no *));
              filhos[0] = (yyvsp[0].tkn1).no_;
              addFilhos((yyval.tkn1).no_,filhos,1);
              free(filhos);
            }
#line 1748 "parser.tab.c"
    break;

  case 48: /* Term: Term ASTERISK Factor  */
#line 443 "parser.y"
                             {(yyval.tkn1).no_ = criaNo("Term");
                              filhos = malloc(3 * sizeof(no *));
                              filhos[0] = (yyvsp[-2].tkn1).no_;
                              filhos[1] = criaNo("*");
                              filhos[2] = (yyvsp[0].tkn1).no_;
                              addFilhos((yyval.tkn1).no_,filhos,3);
                              free(filhos);
                            }
#line 1761 "parser.tab.c"
    break;

  case 49: /* Term: Term SLASH Factor  */
#line 452 "parser.y"
                          {(yyval.tkn1).no_ = criaNo("Term");
                           filhos = malloc(3 * sizeof(no *));
                           filhos[0] = (yyvsp[-2].tkn1).no_;
                           filhos[1] = criaNo("/");
                           filhos[2] = (yyvsp[0].tkn1).no_;
                           addFilhos((yyval.tkn1).no_,filhos,3);
                           free(filhos);
                        }
#line 1774 "parser.tab.c"
    break;

  case 50: /* Term: Factor  */
#line 461 "parser.y"
               {(yyval.tkn1).no_ = criaNo("Term");
                filhos = malloc(1 * sizeof(no *));
                filhos[0] = (yyvsp[0].tkn1).no_;
                addFilhos((yyval.tkn1).no_,filhos,1);
                free(filhos);
            }
#line 1785 "parser.tab.c"
    break;

  case 51: /* Factor: OPENPARENTHESIS Expr CLOSEPARENTHESIS  */
#line 469 "parser.y"
                                               {(yyval.tkn1).no_ = criaNo("Factor");
                                                filhos = malloc(3 * sizeof(no *));
                                                filhos[0] = criaNo("(");
                                                filhos[1] = (yyvsp[-1].tkn1).no_;
                                                filhos[2] = criaNo(")");
                                                addFilhos((yyval.tkn1).no_,filhos,3);
                                                free(filhos);
                                            }
#line 1798 "parser.tab.c"
    break;

  case 52: /* Factor: MINUS Factor  */
#line 478 "parser.y"
                     {(yyval.tkn1).no_ = criaNo("Factor");
                      filhos = malloc(2 * sizeof(no *));
                      filhos[0] = criaNo("-");
                      filhos[1] = (yyvsp[0].tkn1).no_;
                      addFilhos((yyval.tkn1).no_,filhos,2);
                      free(filhos);
                }
#line 1810 "parser.tab.c"
    break;

  case 53: /* Factor: PLUS Factor  */
#line 486 "parser.y"
                    {(yyval.tkn1).no_ = criaNo("Factor");
                     filhos = malloc(2 * sizeof(no *));
                     filhos[0] = criaNo("+");
                     filhos[1] = (yyvsp[0].tkn1).no_;
                     addFilhos((yyval.tkn1).no_,filhos,2);
                     free(filhos);
                }
#line 1822 "parser.tab.c"
    break;

  case 54: /* Factor: IDENTIFIER  */
#line 494 "parser.y"
                   {(yyval.tkn1).no_ = criaNo("Factor");
                    filhos = malloc(1 * sizeof(no *));
                    filhos[0] = criaNo("IDENTIFIER");
                    addFilhos((yyval.tkn1).no_,filhos,1);
                    free(filhos);
                }
#line 1833 "parser.tab.c"
    break;

  case 55: /* Factor: NUMBER  */
#line 501 "parser.y"
               {(yyval.tkn1).no_ = criaNo("Factor");
                filhos = malloc(1 * sizeof(no *));
                filhos[0] = criaNo("NUMBER");
                addFilhos((yyval.tkn1).no_,filhos,1);
                free(filhos);}
#line 1843 "parser.tab.c"
    break;

  case 56: /* Factor: FLOATNUMBER  */
#line 507 "parser.y"
                    {(yyval.tkn1).no_ = criaNo("Factor");
                     filhos = malloc(1 * sizeof(no *));
                     filhos[0] = criaNo("FLOATNUMBER");
                     addFilhos((yyval.tkn1).no_,filhos,1);
                     free(filhos);
                }
#line 1854 "parser.tab.c"
    break;

  case 57: /* Factor: CHARACTER  */
#line 514 "parser.y"
                   {(yyval.tkn1).no_ = criaNo("Factor");
                    filhos = malloc(1 * sizeof(no *));
                    filhos[0] = criaNo("CHARACTER");
                    addFilhos((yyval.tkn1).no_,filhos,1);
                    free(filhos);
                }
#line 1865 "parser.tab.c"
    break;


#line 1869 "parser.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 522 "parser.y"


int main(){ 
    //yydebug = 1;

    yyin = fopen("entrada.txt", "r");

    do
    {
        yyparse();
    }while (!feof(yyin)); 

    printf("\nArvore: \n");
    printArvore(raiz);
    return 0;
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}

no* criaNo(char *nome){
    no *novoNo;
    novoNo = malloc(sizeof(no));
    novoNo->nome = nome; 
    novoNo->filhos = malloc(sizeof(no)); //Adiciona uma lista vazia
    novoNo->qtdFilhos = 0;

    return novoNo;
} 

no* addFilhos(no *no_, no **novosFilhos, int qtdFilhos){
    int j = no_->qtdFilhos; //Variável para salvar a quantidade original de filhos 
    no_->qtdFilhos += qtdFilhos;
    no_->filhos = realloc(no_->filhos, (no_->qtdFilhos ) * sizeof(no));

    for(int i=0; i<qtdFilhos; i++, j++ ){
        no_->filhos[j] = novosFilhos[i];
    }

    return no_;
}

void printArvore_(no *arvore, int cont){
    char *nivel=malloc((cont)*sizeof(char));
    memset(nivel,'|',cont);
    printf("%.*s %s \n",cont,nivel,arvore->nome);
    free(nivel);

    for(int i=0; i < arvore->qtdFilhos; i++){
        printArvore_(arvore->filhos[i], cont+1);
    }
}

void printArvore(no *arvore){
    printArvore_(arvore, 1);
}

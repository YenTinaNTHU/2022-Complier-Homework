/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylex();
int yyerror(char *s);


char* itoa(int x) {
    int y = x;
    int l = 1;
    while (y > 9) {
        y /= 10;
        l += 1;
    }
    char* t = malloc(sizeof(char) * l);
    sprintf(t, "%d", x);
    return t;
}

char* ftoa(double x) {
    char* s = malloc(sizeof(char) * 30);
    sprintf(s, "%f", x);
    return s;
}

char* add_tag(char* tag, char* str){
  size_t n = strlen(tag) * 2 + strlen(str) + 5 + 1;
  char *tag_str = (char*) malloc(n*sizeof(char));
  strcat(tag_str, "<"); strcat(tag_str, tag); strcat(tag_str, ">");
  strcat(tag_str, str);
  strcat(tag_str, "</"); strcat(tag_str, tag); strcat(tag_str, ">");
  return tag_str;
}

#line 102 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT_NUM = 258,
    POS_INT_NUM = 259,
    NEG_INT_NUM = 260,
    FLOAT_NUM = 261,
    POS_FLOAT_NUM = 262,
    NEG_FLOAT_NUM = 263,
    ID = 264,
    INC = 265,
    DEC = 266,
    LEQ = 267,
    GEQ = 268,
    EQL = 269,
    NEQ = 270,
    LAND = 271,
    LOR = 272,
    CONST = 273,
    SIGNED = 274,
    UNSIGNED = 275,
    SHORT = 276,
    LONG = 277,
    LONGLONG = 278,
    INT = 279,
    CHAR = 280,
    DOUBLE = 281,
    VOID = 282,
    FLOAT = 283,
    STRUCT = 284,
    RETURN = 285,
    LSHIFT = 286,
    RSHIFT = 287,
    STR = 288,
    NUL = 289,
    FOR = 290,
    DO = 291,
    WHILE = 292,
    BREAK = 293,
    CONTINUE = 294,
    IF = 295,
    ELSE = 296,
    SWITCH = 297,
    CASE = 298,
    DEFAULT = 299,
    CHAR_START = 300,
    CHAR_END = 301,
    ESCAPE_START = 302,
    ESCAPE_CHAR = 303,
    STRING_START = 304,
    STRING_END = 305,
    UMINUS = 306,
    UPLUS = 307,
    DEREF = 308,
    ADDR = 309
  };
#endif
/* Tokens.  */
#define INT_NUM 258
#define POS_INT_NUM 259
#define NEG_INT_NUM 260
#define FLOAT_NUM 261
#define POS_FLOAT_NUM 262
#define NEG_FLOAT_NUM 263
#define ID 264
#define INC 265
#define DEC 266
#define LEQ 267
#define GEQ 268
#define EQL 269
#define NEQ 270
#define LAND 271
#define LOR 272
#define CONST 273
#define SIGNED 274
#define UNSIGNED 275
#define SHORT 276
#define LONG 277
#define LONGLONG 278
#define INT 279
#define CHAR 280
#define DOUBLE 281
#define VOID 282
#define FLOAT 283
#define STRUCT 284
#define RETURN 285
#define LSHIFT 286
#define RSHIFT 287
#define STR 288
#define NUL 289
#define FOR 290
#define DO 291
#define WHILE 292
#define BREAK 293
#define CONTINUE 294
#define IF 295
#define ELSE 296
#define SWITCH 297
#define CASE 298
#define DEFAULT 299
#define CHAR_START 300
#define CHAR_END 301
#define ESCAPE_START 302
#define ESCAPE_CHAR 303
#define STRING_START 304
#define STRING_END 305
#define UMINUS 306
#define UPLUS 307
#define DEREF 308
#define ADDR 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 39 "parser.y" /* yacc.c:355  */

  int int_v;
  float float_v;
  char char_v;
  char* string_v;  

#line 254 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 271 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1317

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  180
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  304

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    18,     2,     2,     2,    15,    20,     2,
      37,    38,    13,    11,    33,    12,    34,    14,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    31,    32,
      16,    10,    17,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,    22,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,    21,    40,    19,     2,     2,     2,
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
       5,     6,     7,     8,     9,    23,    24,    25,    26,    27,
      28,    29,    30,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    92,    99,   106,   110,   115,   123,   129,
     137,   147,   157,   167,   168,   169,   170,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   241,   245,   253,   260,   267,
     274,   281,   288,   295,   302,   309,   316,   323,   330,   337,
     344,   351,   358,   365,   372,   379,   386,   393,   400,   407,
     414,   421,   428,   435,   442,   449,   456,   463,   470,   471,
     472,   476,   477,   485,   493,   494,   502,   510,   517,   527,
     531,   538,   542,   546,   553,   557,   561,   571,   575,   585,
     592,   602,   608,   614,   615,   619,   629,   636,   643,   650,
     660,   667,   677,   684,   691,   701,   708,   715,   722,   727,
     734,   741,   748,   755,   762,   769,   773,   780,   784,   788,
     792,   799,   806,   810,   817,   827,   834,   841,   848,   855,
     862,   869,   876,   886,   887,   897,   906,   910,   911,   915,
     920
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_NUM", "POS_INT_NUM", "NEG_INT_NUM",
  "FLOAT_NUM", "POS_FLOAT_NUM", "NEG_FLOAT_NUM", "ID", "'='", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'<'", "'>'", "'!'", "'~'", "'&'", "'|'", "'^'",
  "INC", "DEC", "LEQ", "GEQ", "EQL", "NEQ", "LAND", "LOR", "':'", "';'",
  "','", "'.'", "'['", "']'", "'('", "')'", "'{'", "'}'", "CONST",
  "SIGNED", "UNSIGNED", "SHORT", "LONG", "LONGLONG", "INT", "CHAR",
  "DOUBLE", "VOID", "FLOAT", "STRUCT", "RETURN", "LSHIFT", "RSHIFT", "STR",
  "NUL", "FOR", "DO", "WHILE", "BREAK", "CONTINUE", "IF", "ELSE", "SWITCH",
  "CASE", "DEFAULT", "CHAR_START", "CHAR_END", "ESCAPE_START",
  "ESCAPE_CHAR", "STRING_START", "STRING_END", "UMINUS", "UPLUS", "DEREF",
  "ADDR", "$accept", "program", "program_ingredients",
  "program_ingredient", "global_variable_decl", "func_decl", "func_def",
  "func", "type", "int_type", "char_type", "other_type", "ident",
  "init_ident", "expr", "literal", "char", "string", "variable", "exprs",
  "scalar_decl", "idents", "array_decl", "arrays", "array", "arr_dim",
  "arr_content", "parameters", "stmt", "switch_clauses", "switch_clause",
  "for_stmt", "compound_stmt", "stmt_or_decls", "stmt_or_decl",
  "variable_decl", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      61,    43,    45,    42,    47,    37,    60,    62,    33,   126,
      38,   124,    94,   265,   266,   267,   268,   269,   270,   271,
     272,    58,    59,    44,    46,    91,    93,    40,    41,   123,
     125,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF -236

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-236)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1254,   165,    12,   180,     0,    57,    73,  -236,  -236,  -236,
    -236,  -236,    78,  1254,  -236,  -236,  -236,  -236,    -3,   105,
    -236,  -236,  -236,  -236,  -236,   185,   199,    92,    99,   104,
    -236,  -236,  -236,  -236,  -236,   111,   113,   116,  -236,  -236,
     118,   120,   122,  -236,  -236,  -236,  -236,  -236,  -236,  -236,
    -236,   129,    81,   107,     2,  -236,    -5,    90,   137,   124,
     126,   127,  -236,  -236,   128,   131,   132,  -236,  -236,  -236,
    -236,  -236,  -236,  -236,  -236,  -236,  -236,  -236,  -236,  -236,
    -236,  -236,  -236,  -236,  -236,   730,   730,   730,   730,   730,
     730,   730,   730,   730,   730,   247,   387,  -236,   143,   129,
     144,   151,   152,   148,   161,   -30,   146,   164,   793,  -236,
    -236,   160,  -236,  -236,   730,  -236,    44,   730,  1254,     6,
    -236,   107,  -236,   194,  -236,  -236,  -236,  -236,  -236,  -236,
    -236,  -236,  -236,   101,   101,  -236,   101,   101,   816,   852,
    -236,   105,  -236,  -236,  -236,   178,   317,  -236,  -236,   888,
     428,   145,   730,  -236,  -236,   730,   730,  -236,   133,   150,
     168,   149,   200,   730,   730,   730,   730,   730,   730,   730,
     730,   730,   730,   730,  -236,  -236,   730,   730,   730,   730,
     730,   730,  -236,   730,   730,  -236,  1149,  -236,  -236,   911,
     106,    -8,   201,   730,  -236,  -236,   164,  -236,  -236,  -236,
     164,  -236,  -236,  -236,   469,    96,   202,   947,   983,  1019,
    -236,  -236,   170,  -236,  1149,    31,    31,   101,   101,   101,
       9,     9,  1239,  1194,  1217,     9,     9,  1262,  1262,  1172,
     757,    38,    38,   730,  -236,   194,  -236,  1254,  -236,   505,
    -236,  1055,   545,    98,   586,   730,   129,   218,   222,   206,
    1149,  -236,  -236,    35,    59,   201,  -236,   129,    41,   622,
     658,   112,  1091,  -236,   204,    88,  -236,  -236,  -236,  -236,
    -236,   129,   129,    69,   129,    75,   694,   231,   218,   730,
     233,   229,    88,  -236,  -236,   129,  -236,   129,   129,    79,
    -236,  -236,  1127,   129,  -236,  -236,  -236,  -236,  -236,   129,
     129,  -236,  -236,  -236
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    16,    70,    71,    63,    62,    61,    40,    64,    73,
      74,    72,     0,     2,     4,     5,     6,     7,     0,     0,
      13,    14,    15,     8,     9,    65,    66,    51,    50,    49,
      28,    52,    68,    69,    67,    55,    54,    53,    32,    56,
      59,    58,    57,    36,    60,    39,    38,    37,     1,     3,
      10,     0,    75,     0,   133,   134,     0,     0,   137,    43,
      42,    41,    20,    44,    47,    46,    45,    24,    48,    27,
      26,    25,    31,    30,    29,    35,    34,    33,   111,   112,
     113,   114,   115,   116,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,     0,     0,
       0,     0,     0,     0,     0,   121,   124,   125,     0,   108,
     109,     0,   155,   160,     0,   133,     0,     0,   148,   138,
     129,     0,   135,     0,    19,    18,    17,    23,    22,    21,
     105,   104,   106,    95,    96,   107,    84,    85,     0,     0,
     173,     0,   179,   180,   177,     0,   176,   178,   157,     0,
       0,     0,     0,   158,   159,     0,     0,   119,     0,     0,
     122,     0,   126,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,    83,     0,     0,     0,     0,
       0,     0,   149,     0,     0,    11,   127,    76,   130,     0,
       0,     0,     0,     0,   131,   132,     0,   136,   102,   103,
     133,   174,   175,   156,     0,     0,     0,     0,     0,     0,
     120,   117,     0,   118,    92,    77,    78,    79,    80,    81,
      86,    88,    98,    99,    97,    87,    89,    90,    91,    93,
      94,   100,   101,     0,   140,     0,   145,   148,    12,     0,
     139,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,   146,   147,     0,     0,     0,   141,     0,     0,     0,
       0,     0,     0,   153,   150,   162,   123,   142,   143,   144,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   162,   169,   170,     0,   171,     0,     0,     0,
     154,   151,     0,     0,   152,   161,   168,   167,   166,     0,
       0,   164,   165,   163
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -236,  -236,  -236,   259,  -236,  -236,  -236,  -236,   -80,  -236,
    -236,  -236,   -18,   153,   -83,  -236,  -236,  -236,  -236,  -133,
     -81,   220,   -76,   154,  -236,   169,  -213,    42,   -51,    -7,
    -236,  -236,  -235,   134,  -236,  -236
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,   107,    55,   108,   109,   159,   161,   110,   187,
      23,    56,    24,    57,    58,   119,   240,   191,   144,   281,
     282,   112,   113,   145,   146,   147
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     111,    54,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   264,   149,   142,   141,   192,   205,   157,   143,
     164,   165,   166,   167,   168,   237,   254,   120,   121,    50,
     238,   186,   174,   175,   189,   115,    51,   117,   190,   118,
     158,   193,   269,   291,   166,   167,   168,    45,   151,   164,
     165,   166,   167,   168,   174,   175,    35,    36,    37,    38,
      39,   174,   175,   183,   184,   142,   141,   186,   233,   207,
     143,   243,   208,   209,   233,   267,   188,   121,    48,   271,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   114,   255,   225,   226,   227,   228,   229,   230,   268,
     231,   232,   233,   194,    46,   196,   253,   285,   233,   258,
     241,   261,   233,   287,    52,    84,    52,   299,    53,   235,
      47,   186,   122,   200,   174,   175,   273,   275,   244,   233,
     259,   233,    78,    79,    80,    81,    82,    83,    84,    69,
      85,    86,    87,   289,   276,   233,    70,    88,    89,    90,
     250,    71,    91,    92,   279,   280,   186,   190,    72,   186,
      73,   186,   262,    74,    93,    75,    94,    76,    95,    77,
     123,   124,   236,   125,   126,   127,   186,   186,   128,   129,
     150,   152,    96,   153,   154,   155,    97,    98,    99,   100,
     101,   102,   103,   186,   104,   263,   292,   105,   156,   117,
     185,   106,   160,    84,   210,   206,   270,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,   251,   201,   211,
     283,   284,   213,   286,    40,    41,    42,    43,    44,    59,
      60,    61,    62,    63,   296,   193,   297,   298,   212,   245,
     239,   249,   301,    64,    65,    66,    67,    68,   302,   303,
      78,    79,    80,    81,    82,    83,    84,    95,    85,    86,
      87,   265,   266,   290,   293,    88,    89,    90,   278,   294,
      91,    92,    49,   116,   195,   295,   162,   197,     0,   252,
     202,     0,    93,     0,    94,     0,    95,   140,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     0,
      96,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,     0,   104,     0,     0,   105,     0,     0,     0,   106,
      78,    79,    80,    81,    82,    83,    84,     0,    85,    86,
      87,     0,     0,     0,     0,    88,    89,    90,     0,     0,
      91,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,    94,     0,    95,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     0,
      96,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,     0,   104,     0,     0,   105,     0,     0,     0,   106,
      78,    79,    80,    81,    82,    83,    84,     0,    85,    86,
      87,     0,     0,     0,     0,    88,    89,    90,     0,     0,
      91,    92,     0,     0,     0,     0,     0,     0,     0,   148,
       0,     0,    93,     0,    94,     0,     0,     0,     0,     0,
       0,    78,    79,    80,    81,    82,    83,    84,     0,    85,
      86,    87,     0,     0,    97,     0,    88,    89,    90,     0,
       0,    91,    92,     0,     0,   105,     0,     0,     0,   106,
     204,     0,     0,    93,     0,    94,     0,     0,     0,     0,
       0,     0,    78,    79,    80,    81,    82,    83,    84,     0,
      85,    86,    87,     0,     0,    97,     0,    88,    89,    90,
       0,     0,    91,    92,     0,     0,   105,     0,     0,     0,
     106,   242,     0,     0,    93,     0,    94,     0,    78,    79,
      80,    81,    82,    83,    84,     0,    85,    86,    87,     0,
       0,     0,     0,    88,    89,    90,    97,     0,    91,    92,
       0,     0,     0,     0,     0,     0,     0,   105,     0,     0,
      93,   106,    94,     0,   239,     0,     0,     0,    78,    79,
      80,    81,    82,    83,    84,     0,    85,    86,    87,     0,
       0,     0,    97,    88,    89,    90,     0,     0,    91,    92,
       0,     0,     0,   105,     0,     0,     0,   106,     0,     0,
      93,     0,    94,   257,     0,     0,     0,     0,     0,    78,
      79,    80,    81,    82,    83,    84,     0,    85,    86,    87,
       0,     0,    97,     0,    88,    89,    90,     0,     0,    91,
      92,     0,     0,   105,     0,     0,     0,   106,   260,     0,
       0,    93,     0,    94,     0,    78,    79,    80,    81,    82,
      83,    84,     0,    85,    86,    87,     0,     0,     0,     0,
      88,    89,    90,    97,     0,    91,    92,     0,     0,     0,
       0,     0,     0,     0,   105,     0,     0,    93,   106,    94,
     272,    78,    79,    80,    81,    82,    83,    84,     0,    85,
      86,    87,     0,     0,     0,     0,    88,    89,    90,    97,
       0,    91,    92,     0,     0,     0,     0,     0,     0,     0,
     105,     0,     0,    93,   106,    94,   274,    78,    79,    80,
      81,    82,    83,    84,     0,    85,    86,    87,     0,     0,
       0,     0,    88,    89,    90,    97,     0,    91,    92,     0,
       0,     0,     0,     0,     0,     0,   105,     0,     0,    93,
     106,    94,   288,    78,    79,    80,    81,    82,    83,    84,
       0,    85,    86,    87,     0,     0,     0,     0,    88,    89,
      90,    97,     0,    91,    92,     0,     0,     0,     0,     0,
       0,     0,   105,     0,     0,    93,   106,    94,   164,   165,
     166,   167,   168,   169,   170,     0,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    97,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,     0,
       0,     0,   106,   163,   164,   165,   166,   167,   168,   169,
     170,   183,   184,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,     0,   182,   163,   164,   165,   166,
     167,   168,   169,   170,     0,     0,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   183,   184,     0,
       0,     0,   198,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   163,   164,   165,   166,   167,   168,   169,   170,
     183,   184,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,     0,     0,     0,     0,     0,     0,     0,
     199,     0,     0,     0,     0,     0,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   183,   184,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,     0,
     203,   163,   164,   165,   166,   167,   168,   169,   170,     0,
       0,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   183,   184,     0,     0,     0,   234,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   163,   164,   165,
     166,   167,   168,   169,   170,   183,   184,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,     0,     0,
       0,     0,     0,     0,     0,   246,     0,     0,     0,     0,
       0,     0,     0,   163,   164,   165,   166,   167,   168,   169,
     170,   183,   184,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,     0,     0,     0,     0,     0,     0,
       0,   247,     0,     0,     0,     0,     0,     0,     0,   163,
     164,   165,   166,   167,   168,   169,   170,   183,   184,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
       0,     0,     0,     0,     0,     0,     0,   248,     0,     0,
       0,     0,     0,     0,     0,   163,   164,   165,   166,   167,
     168,   169,   170,   183,   184,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,     0,     0,     0,     0,
       0,   256,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   163,   164,   165,   166,   167,   168,   169,   170,   183,
     184,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,     0,     0,     0,     0,     0,     0,     0,   277,
       0,     0,     0,     0,     0,     0,     0,   163,   164,   165,
     166,   167,   168,   169,   170,   183,   184,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   300,   163,
     164,   165,   166,   167,   168,   169,   170,     0,     0,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
       0,   183,   184,   164,   165,   166,   167,   168,   169,   170,
       0,     0,   171,   172,   173,   174,   175,   176,   177,   178,
     179,     0,     0,   183,   184,   164,   165,   166,   167,   168,
     169,   170,     0,     0,   171,     0,   173,   174,   175,   176,
     177,   178,   179,     0,     0,     0,   183,   184,   164,   165,
     166,   167,   168,   169,   170,     0,     0,   171,     0,     0,
     174,   175,   176,   177,   178,   179,     0,     0,   183,   184,
     164,   165,   166,   167,   168,   169,   170,     0,     0,     0,
       0,     0,   174,   175,   176,   177,   178,   179,     0,     0,
       0,   183,   184,   164,   165,   166,   167,   168,   169,   170,
       0,     0,     0,     0,     0,   174,   175,   176,   177,     0,
       0,     0,     0,   183,   184,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   183,   184
};

static const yytype_int16 yycheck[] =
{
      51,    19,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,   247,    96,    95,    95,    10,   150,    48,    95,
      11,    12,    13,    14,    15,    33,   239,    32,    33,    32,
      38,   114,    23,    24,   117,    53,    39,    35,   118,    37,
      70,    35,   255,   278,    13,    14,    15,    47,    99,    11,
      12,    13,    14,    15,    23,    24,    44,    45,    46,    47,
      48,    23,    24,    54,    55,   146,   146,   150,    33,   152,
     146,   204,   155,   156,    33,    40,    32,    33,     0,    38,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    10,    33,   176,   177,   178,   179,   180,   181,    40,
     183,   184,    33,   121,    47,   123,   239,    38,    33,   242,
     193,   244,    33,    38,     9,     9,     9,    38,    13,    13,
      47,   204,    32,   141,    23,    24,   259,   260,    32,    33,
      32,    33,     3,     4,     5,     6,     7,     8,     9,    47,
      11,    12,    13,   276,    32,    33,    47,    18,    19,    20,
     233,    47,    23,    24,    66,    67,   239,   237,    47,   242,
      47,   244,   245,    47,    35,    47,    37,    47,    39,    47,
      33,    47,   190,    47,    47,    47,   259,   260,    47,    47,
      37,    37,    53,    32,    32,    37,    57,    58,    59,    60,
      61,    62,    63,   276,    65,   246,   279,    68,    37,    35,
      40,    72,    56,     9,    71,    60,   257,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,   235,    40,    69,
     271,   272,    73,   274,    44,    45,    46,    47,    48,    44,
      45,    46,    47,    48,   285,    35,   287,   288,    70,    37,
      39,    71,   293,    44,    45,    46,    47,    48,   299,   300,
       3,     4,     5,     6,     7,     8,     9,    39,    11,    12,
      13,    39,    56,    32,    31,    18,    19,    20,    64,    40,
      23,    24,    13,    53,   121,   282,   107,   123,    -1,   237,
     146,    -1,    35,    -1,    37,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    -1,    -1,    -1,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    72,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      13,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    37,    -1,    39,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    -1,    -1,    -1,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    72,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      13,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    35,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    13,    -1,    -1,    57,    -1,    18,    19,    20,    -1,
      -1,    23,    24,    -1,    -1,    68,    -1,    -1,    -1,    72,
      32,    -1,    -1,    35,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    13,    -1,    -1,    57,    -1,    18,    19,    20,
      -1,    -1,    23,    24,    -1,    -1,    68,    -1,    -1,    -1,
      72,    32,    -1,    -1,    35,    -1,    37,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    13,    -1,
      -1,    -1,    -1,    18,    19,    20,    57,    -1,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      35,    72,    37,    -1,    39,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    13,    -1,
      -1,    -1,    57,    18,    19,    20,    -1,    -1,    23,    24,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    72,    -1,    -1,
      35,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    13,
      -1,    -1,    57,    -1,    18,    19,    20,    -1,    -1,    23,
      24,    -1,    -1,    68,    -1,    -1,    -1,    72,    32,    -1,
      -1,    35,    -1,    37,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    13,    -1,    -1,    -1,    -1,
      18,    19,    20,    57,    -1,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    35,    72,    37,
      38,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    13,    -1,    -1,    -1,    -1,    18,    19,    20,    57,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    35,    72,    37,    38,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    13,    -1,    -1,
      -1,    -1,    18,    19,    20,    57,    -1,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    35,
      72,    37,    38,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    13,    -1,    -1,    -1,    -1,    18,    19,
      20,    57,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    35,    72,    37,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    72,    10,    11,    12,    13,    14,    15,    16,
      17,    54,    55,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    32,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    54,    55,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      54,    55,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    54,    55,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      32,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    54,    55,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    54,    55,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    54,    55,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    54,    55,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    54,    55,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    54,
      55,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    54,    55,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    54,    55,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    54,    55,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,    20,    -1,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    54,    55,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,    20,    -1,    -1,
      23,    24,    25,    26,    27,    28,    -1,    -1,    54,    55,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    54,    55,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    54,    55,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    98,   100,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    44,    45,    46,    47,    48,
      44,    45,    46,    47,    48,    47,    47,    47,     0,    81,
      32,    39,     9,    13,    90,    91,    99,   101,   102,    44,
      45,    46,    47,    48,    44,    45,    46,    47,    48,    47,
      47,    47,    47,    47,    47,    47,    47,    47,     3,     4,
       5,     6,     7,     8,     9,    11,    12,    13,    18,    19,
      20,    23,    24,    35,    37,    39,    53,    57,    58,    59,
      60,    61,    62,    63,    65,    68,    72,    90,    92,    93,
      96,   106,   109,   110,    10,    90,    99,    35,    37,   103,
      32,    33,    32,    33,    47,    47,    47,    47,    47,    47,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      40,    86,    98,   100,   106,   111,   112,   113,    32,    92,
      37,   106,    37,    32,    32,    37,    37,    48,    70,    94,
      56,    95,   103,    10,    11,    12,    13,    14,    15,    16,
      17,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    32,    54,    55,    40,    92,    97,    32,    92,
      86,   105,    10,    35,    90,    91,    90,   101,    36,    38,
      90,    40,   111,    32,    32,    97,    60,    92,    92,    92,
      71,    69,    70,    73,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    33,    36,    13,    90,    33,    38,    39,
     104,    92,    32,    97,    32,    37,    38,    38,    38,    71,
      92,    90,   105,    97,   104,    33,    36,    38,    97,    32,
      32,    97,    92,   106,   110,    39,    56,    40,    40,   104,
     106,    38,    38,    97,    38,    97,    32,    38,    64,    66,
      67,   107,   108,   106,   106,    38,   106,    38,    38,    97,
      32,   110,    92,    31,    40,   107,   106,   106,   106,    38,
      31,   106,   106,   106
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    78,    79,    80,    80,    81,    81,    81,    82,    82,
      83,    84,    85,    86,    86,    86,    86,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    90,    91,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    93,    93,    93,    93,    93,    93,    93,    93,    94,
      94,    94,    95,    95,    95,    96,    96,    97,    97,    98,
      98,    99,    99,    99,    99,   100,   101,   101,   102,   102,
     103,   103,   104,   104,   104,   105,   105,   105,   105,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   107,   107,   108,   108,   109,   109,   109,   109,   109,
     109,   109,   109,   110,   110,   111,   111,   112,   112,   113,
     113
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       2,     4,     5,     1,     1,     1,     1,     4,     4,     4,
       3,     4,     4,     4,     3,     3,     3,     3,     2,     3,
       3,     3,     2,     3,     3,     3,     2,     2,     2,     2,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       2,     0,     1,     4,     0,     1,     2,     1,     3,     3,
       4,     3,     3,     1,     1,     3,     3,     1,     2,     4,
       3,     4,     3,     3,     3,     2,     3,     3,     0,     2,
       5,     7,     7,     5,     7,     1,     3,     2,     2,     2,
       1,     2,     0,     4,     3,     9,     8,     8,     8,     7,
       7,     7,     6,     2,     3,     2,     1,     1,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 86 "parser.y" /* yacc.c:1646  */
    {
      printf("%s", (yyvsp[0].string_v));
    }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 93 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 100 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string_v) = (yyvsp[0].string_v);
    }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 107 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string_v) = (yyvsp[0].string_v);
    }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 111 "parser.y" /* yacc.c:1646  */
    {
      char* tag_str = add_tag("func_decl", (yyvsp[0].string_v));
      (yyval.string_v) = tag_str;
    }
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 116 "parser.y" /* yacc.c:1646  */
    {
      char* tag_str = add_tag("func_def", (yyvsp[0].string_v));
      (yyval.string_v) = tag_str;
    }
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 124 "parser.y" /* yacc.c:1646  */
    {
      char* tag_str = add_tag("scalar_decl", (yyvsp[0].string_v));
      (yyval.string_v) = tag_str;
      // printf("\n\n%s\n\n", $$);
    }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 130 "parser.y" /* yacc.c:1646  */
    {
      char* tag_str = add_tag("array_decl", (yyvsp[0].string_v));
      (yyval.string_v) = tag_str;
    }
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 138 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 148 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 158 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-4].string_v)) + strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v))  + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-4].string_v)); strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 167 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = (yyvsp[0].string_v); }
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 168 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = (yyvsp[0].string_v); }
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = (yyvsp[0].string_v); }
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "const"; }
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedlonglongint"; }
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 175 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedlongint"; }
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedshortint"; }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedint"; }
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedlonglongint"; }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedlongint"; }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedshortint"; }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 181 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedint"; }
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constlonglongint"; }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 183 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constlongint"; }
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 184 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constshortint"; }
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 185 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constint"; }
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 186 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedlonglongint"; }
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 187 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedlongint"; }
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 188 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedshortint"; }
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 189 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedint"; }
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 190 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedlonglongint"; }
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 191 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedlongint"; }
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 192 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedshortint"; }
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 193 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedint"; }
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 194 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "longlongint"; }
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 195 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "longint"; }
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 196 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "shortint"; }
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 197 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "int"; }
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 201 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedlonglong"; }
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 202 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedlong"; }
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 203 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedshort"; }
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 204 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedchar"; }
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 205 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedlonglong"; }
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedlong"; }
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 207 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedshort"; }
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 208 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedchar"; }
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constlonglong"; }
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 210 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constlong"; }
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 211 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constshort"; }
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constchar"; }
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedlonglong"; }
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 214 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedlong"; }
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 215 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedshort"; }
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 216 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedchar"; }
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 217 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedlonglong"; }
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 218 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedlong"; }
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 219 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedshort"; }
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 220 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedshar"; }
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 221 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "longlong"; }
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "long"; }
#line 2175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 223 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "short"; }
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 224 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "char"; }
#line 2187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 228 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsigned"; }
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 229 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "ocnstunsigned"; }
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 230 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constfloat"; }
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 231 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constdouble"; }
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 232 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constvoid"; }
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 233 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signed"; }
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 234 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsigned"; }
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 235 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "float"; }
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 236 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "double"; }
#line 2241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 237 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "void"; }
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 241 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = (yyvsp[0].string_v);}
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 245 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 254 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 261 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 268 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 275 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 282 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 289 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 296 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 303 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 310 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 317 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 324 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 331 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2396 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 338 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 345 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 352 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 359 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 366 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 373 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 380 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 387 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 394 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 401 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 408 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 415 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 422 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 429 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 436 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 443 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 450 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 457 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 464 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 470 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = add_tag("expr", (yyvsp[0].string_v)); }
#line 2611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 471 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = add_tag("expr", (yyvsp[0].string_v)); }
#line 2617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 472 "parser.y" /* yacc.c:1646  */
    {(yyval.string_v) = add_tag("expr", "0");}
#line 2623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 476 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = itoa((yyvsp[0].int_v)); }
#line 2629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 478 "parser.y" /* yacc.c:1646  */
    {
      char* s1 = itoa((yyvsp[0].int_v));
      size_t n = strlen(s1) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, "+"); strcat(str, add_tag("expr", s1));
      (yyval.string_v) = str;
    }
#line 2641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 486 "parser.y" /* yacc.c:1646  */
    {
      char* s1 = itoa(-(yyvsp[0].int_v));
      size_t n = strlen(s1) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, "-"); strcat(str, add_tag("expr", s1));
      (yyval.string_v) = str;
    }
#line 2653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 493 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = ftoa((yyvsp[0].float_v)); }
#line 2659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 495 "parser.y" /* yacc.c:1646  */
    {
      char* s1 = ftoa((yyvsp[0].float_v));
      size_t n = strlen(s1) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, "+"); strcat(str, add_tag("expr", s1));
      (yyval.string_v) = str;
    }
#line 2671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 503 "parser.y" /* yacc.c:1646  */
    {
      char* s1 = ftoa(-(yyvsp[0].float_v));
      size_t n = strlen(s1) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, "-"); strcat(str, add_tag("expr", s1));
      (yyval.string_v) = str;
    }
#line 2683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 511 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 518 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 528 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string_v) = strdup((yyvsp[0].string_v));
    }
#line 2713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 532 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 538 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = ""; }
#line 2730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 543 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string_v) = strdup((yyvsp[0].string_v));
    }
#line 2738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 547 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 553 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = ""; }
#line 2755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 558 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string_v) = strdup((yyvsp[0].string_v));
    }
#line 2763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 562 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 572 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string_v) = strdup((yyvsp[0].string_v));
    }
#line 2782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 576 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 586 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 593 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v));
      (yyval.string_v) = str;
    }
#line 2815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 602 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
  }
#line 2826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 608 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
  }
#line 2837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 614 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = strdup((yyvsp[0].string_v));}
#line 2843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 615 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = strdup((yyvsp[0].string_v));}
#line 2849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 620 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v));
      (yyval.string_v) = str;
    }
#line 2860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 630 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 637 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string_v) = strdup((yyvsp[0].string_v));
    }
#line 2879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 644 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 651 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 661 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 668 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 678 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 685 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 692 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 702 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));;
      (yyval.string_v) = str;
    }
#line 2967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 709 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 716 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 722 "parser.y" /* yacc.c:1646  */
    {(yyval.string_v) = "";}
#line 2995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 728 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("stmt", str);
    }
#line 3006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 735 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-4].string_v)) + strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-4].string_v)); strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("stmt", str);
    }
#line 3017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 742 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-6].string_v)) + strlen((yyvsp[-5].string_v)) + strlen((yyvsp[-4].string_v)) + strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-6].string_v)); strcat(str, (yyvsp[-5].string_v)); strcat(str, (yyvsp[-4].string_v)); strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("stmt", str);
    }
#line 3028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 749 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-6].string_v)) + strlen((yyvsp[-5].string_v)) + strlen((yyvsp[-4].string_v)) + strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-6].string_v)); strcat(str, (yyvsp[-5].string_v)); strcat(str, (yyvsp[-4].string_v)); strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("stmt", str);
    }
#line 3039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 756 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-4].string_v)) + strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-4].string_v)); strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("stmt", str);
    }
#line 3050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 763 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-6].string_v)) + strlen((yyvsp[-5].string_v)) + strlen((yyvsp[-4].string_v)) + strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-6].string_v)); strcat(str, (yyvsp[-5].string_v)); strcat(str, (yyvsp[-4].string_v)); strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("stmt", str);
    }
#line 3061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 770 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string_v) = add_tag("stmt", (yyvsp[0].string_v));
    }
#line 3069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 774 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("stmt", str);
    }
#line 3080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 781 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string_v) = add_tag("stmt", "return;");
    }
#line 3088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 785 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string_v) = add_tag("stmt", "break;");
    }
#line 3096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 789 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string_v) = add_tag("stmt", "continue;");
    }
#line 3104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 793 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string_v) = (yyvsp[0].string_v);
    }
#line 3112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 800 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 3123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 806 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = ""; }
#line 3129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 811 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 3140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 818 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 3151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 828 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-8].string_v)) + strlen((yyvsp[-7].string_v)) + strlen((yyvsp[-6].string_v)) + strlen((yyvsp[-5].string_v)) + strlen((yyvsp[-4].string_v)) + strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-8].string_v)); strcat(str, (yyvsp[-7].string_v)); strcat(str, (yyvsp[-6].string_v)); strcat(str, (yyvsp[-5].string_v)); strcat(str, (yyvsp[-4].string_v)); strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 3162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 835 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-7].string_v)) + strlen((yyvsp[-6].string_v)) + strlen((yyvsp[-5].string_v)) + strlen((yyvsp[-4].string_v)) + strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-7].string_v)); strcat(str, (yyvsp[-6].string_v)); strcat(str, (yyvsp[-5].string_v)); strcat(str, (yyvsp[-4].string_v)); strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 3173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 842 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-7].string_v)) + strlen((yyvsp[-6].string_v)) + strlen((yyvsp[-5].string_v)) + strlen((yyvsp[-4].string_v)) + strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-7].string_v)); strcat(str, (yyvsp[-6].string_v)); strcat(str, (yyvsp[-5].string_v)); strcat(str, (yyvsp[-4].string_v)); strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 3184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 849 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-7].string_v)) + strlen((yyvsp[-6].string_v)) + strlen((yyvsp[-5].string_v)) + strlen((yyvsp[-4].string_v)) + strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-7].string_v)); strcat(str, (yyvsp[-6].string_v)); strcat(str, (yyvsp[-5].string_v)); strcat(str, (yyvsp[-4].string_v)); strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 3195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 856 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-6].string_v)) + strlen((yyvsp[-5].string_v)) + strlen((yyvsp[-4].string_v)) + strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-6].string_v)); strcat(str, (yyvsp[-5].string_v)); strcat(str, (yyvsp[-4].string_v)); strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 3206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 863 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-6].string_v)) + strlen((yyvsp[-5].string_v)) + strlen((yyvsp[-4].string_v)) + strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-6].string_v)); strcat(str, (yyvsp[-5].string_v)); strcat(str, (yyvsp[-4].string_v)); strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 3217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 870 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-6].string_v)) + strlen((yyvsp[-5].string_v)) + strlen((yyvsp[-4].string_v)) + strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-6].string_v)); strcat(str, (yyvsp[-5].string_v)); strcat(str, (yyvsp[-4].string_v)); strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 3228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 877 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-5].string_v)) + strlen((yyvsp[-4].string_v)) + strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-5].string_v)); strcat(str, (yyvsp[-4].string_v)); strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 3239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 886 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "{}"; }
#line 3245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 888 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 3256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 898 "parser.y" /* yacc.c:1646  */
    {
      {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v)) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
    }
#line 3269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 906 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = (yyvsp[0].string_v); }
#line 3275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 910 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = (yyvsp[0].string_v); }
#line 3281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 911 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = (yyvsp[0].string_v); }
#line 3287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 916 "parser.y" /* yacc.c:1646  */
    {
      char* tag_str = add_tag("scalar_decl", (yyvsp[0].string_v));
      (yyval.string_v) = tag_str;
    }
#line 3296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 921 "parser.y" /* yacc.c:1646  */
    {
      char* tag_str = add_tag("array_decl", (yyvsp[0].string_v));
      (yyval.string_v) = tag_str;
    }
#line 3305 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3309 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 927 "parser.y" /* yacc.c:1906  */

int main(void)
{
  yyparse();
  return 0;
}

int yyerror(char *s)
{ 
  fprintf(stderr, "%s\n", s);
  return 0;
}

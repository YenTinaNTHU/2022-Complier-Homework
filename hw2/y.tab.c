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
  size_t n = strlen(tag) * 2 + strlen(str) + 5;
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
#define YYLAST   515

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

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
       0,    85,    85,    92,    99,   109,   110,   115,   123,   128,
     136,   146,   156,   166,   167,   168,   169,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   240,   244,   251,   258,   265,
     272,   279,   286,   293,   300,   307,   314,   321,   328,   335,
     342,   349,   356,   363,   370,   377,   384,   391,   398,   405,
     412,   419,   426,   433,   440,   447,   454,   461,   462,   463,
     467,   468,   476,   484,   485,   493,   501,   508,   518,   522,
     529,   533,   537,   544,   548,   552,   562,   566,   576,   583,
     593,   599,   605,   609,   619,   626,   633,   640,   650,   657,
     667,   674,   681,   691,   698,   705,   712
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
  "func", "type", "int_type", "char_type", "other_type", "ident", "expr",
  "literal", "char", "string", "variable", "exprs", "scalar_decl",
  "idents", "array_decl", "arrays", "array", "arr_dim", "arr_content",
  "parameters", YY_NULLPTR
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

#define YYPACT_NINF -167

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-167)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     307,   454,   108,   121,   -32,   -29,   -21,  -167,  -167,  -167,
    -167,  -167,    59,   307,  -167,  -167,  -167,  -167,    -9,    19,
    -167,  -167,  -167,  -167,  -167,   163,   193,    13,    14,    24,
    -167,  -167,  -167,  -167,  -167,    25,    27,    34,  -167,  -167,
      36,    53,    70,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,    81,  -167,   113,     6,    91,    92,    95,    82,    85,
      86,  -167,  -167,    94,   110,   116,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,    12,   140,
     107,   113,   107,   307,     7,  -167,  -167,   113,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,  -167,   -37,   117,   139,   350,  -167,  -167,  -167,   170,
      73,    47,   137,   107,   139,  -167,  -167,  -167,  -167,    23,
      23,  -167,    23,    23,   206,   242,  -167,   118,   119,   133,
     131,   177,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,  -167,  -167,   107,   107,   107,   107,   107,
     107,   107,   107,  -167,   113,  -167,   307,  -167,     1,  -167,
     278,  -167,  -167,  -167,  -167,   134,  -167,   350,    64,    64,
      23,    23,    23,   147,   147,   440,   415,   123,   147,   147,
     460,   460,   395,   370,    52,    52,  -167,  -167,   314,   173,
       4,   137,  -167,   158,   107,  -167,  -167,  -167,  -167,  -167
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
      10,     0,    75,     0,   132,     0,     0,   135,    43,    42,
      41,    20,    44,    47,    46,    45,    24,    48,    27,    26,
      25,    31,    30,    29,    35,    34,    33,    11,   132,     0,
       0,     0,     0,   146,   136,   128,   133,     0,    19,    18,
      17,    23,    22,    21,   129,   110,   111,   112,   113,   114,
     115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,   120,   123,   124,   131,   107,   108,   130,     0,
       0,     0,     0,     0,     0,   134,   104,   103,   105,    94,
      95,   106,    83,    84,     0,     0,   118,     0,     0,   121,
       0,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,    82,     0,     0,     0,     0,     0,
       0,     0,     0,   138,     0,   143,   146,    12,     0,   137,
       0,   101,   102,   119,   116,     0,   117,    91,    76,    77,
      78,    79,    80,    85,    87,    97,    98,    96,    86,    88,
      89,    90,    92,    93,    99,   100,   144,   145,   126,     0,
       0,     0,   139,     0,     0,   140,   141,   142,   122,   127
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -167,  -167,  -167,   202,  -167,  -167,  -167,  -167,   -82,  -167,
    -167,  -167,   -19,   -53,  -167,  -167,  -167,  -167,    39,  -167,
     -50,  -167,   157,  -167,   132,  -166,    79
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,   114,   198,   116,   138,   140,   117,   199,    23,
      55,    24,    56,    57,    84,   169,   121
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      54,   120,   200,    79,    95,    96,    97,    98,    99,   100,
      52,   136,   101,   102,   103,    45,    80,   122,    46,   104,
     105,   106,    80,    50,   107,   108,    47,   115,    52,   119,
      51,   118,    53,   137,    78,   207,   109,   201,   110,    81,
     168,    82,   123,    83,   206,    81,   153,   154,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   111,    48,
      68,    69,    78,   143,   144,   145,   146,   147,   124,   112,
     170,    70,    71,   113,    72,   153,   154,   145,   146,   147,
     166,    73,    52,    74,   120,   167,   164,   153,   154,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      75,   165,   188,   189,   190,   191,   192,   193,   194,   195,
      95,    96,    97,    98,    99,   100,    52,    76,   101,   102,
     103,    77,    52,    85,    86,   104,   105,   106,    87,    88,
     107,   108,    89,    90,   143,   144,   145,   146,   147,   148,
     149,    91,   109,   150,   110,   196,   153,   154,   155,   156,
     157,   158,    35,    36,    37,    38,    39,    92,   143,   144,
     145,   146,   147,    93,   111,    40,    41,    42,    43,    44,
     153,   154,    94,   139,    82,   112,   168,   161,   162,   113,
     142,   143,   144,   145,   146,   147,   148,   149,   174,   173,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   175,   176,   203,   163,    58,    59,    60,
      61,    62,   123,   205,   208,    49,   142,   143,   144,   145,
     146,   147,   148,   149,   161,   162,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,    63,    64,    65,
      66,    67,   171,   209,   125,   197,   141,     0,     0,     0,
       0,     0,   142,   143,   144,   145,   146,   147,   148,   149,
     161,   162,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,     0,     0,     0,     0,     0,     0,
     172,     0,     0,     0,     0,     0,     0,     0,   142,   143,
     144,   145,   146,   147,   148,   149,   161,   162,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     0,
       0,     0,     0,     0,   202,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   143,   144,   145,   146,   147,
     148,   149,   161,   162,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,     0,     0,   204,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     0,
     142,   143,   144,   145,   146,   147,   148,   149,   161,   162,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   143,   144,   145,   146,   147,   148,   149,     0,     0,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
       0,     0,     0,     0,   161,   162,   143,   144,   145,   146,
     147,   148,   149,     0,     0,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   161,   162,   143,   144,   145,   146,
     147,   148,   149,     0,     0,   150,     0,   152,   153,   154,
     155,   156,   157,   158,     0,     0,     0,     0,     0,   161,
     162,   143,   144,   145,   146,   147,   148,   149,     0,     0,
       0,     0,     0,   153,   154,   155,   156,   157,   158,   161,
     162,   143,   144,   145,   146,   147,   148,   149,     0,     0,
       0,     0,     0,   153,   154,   155,   156,     0,     0,     0,
       0,     0,     0,     0,   161,   162,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     0,     0,     0,     0,
       0,     0,     0,     0,   161,   162
};

static const yytype_int16 yycheck[] =
{
      19,    83,   168,    53,     3,     4,     5,     6,     7,     8,
       9,    48,    11,    12,    13,    47,    10,    10,    47,    18,
      19,    20,    10,    32,    23,    24,    47,    80,     9,    82,
      39,    81,    13,    70,    53,   201,    35,    33,    37,    33,
      39,    35,    35,    37,    40,    33,    23,    24,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    57,     0,
      47,    47,    81,    11,    12,    13,    14,    15,    87,    68,
     123,    47,    47,    72,    47,    23,    24,    13,    14,    15,
      33,    47,     9,    47,   166,    38,    13,    23,    24,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      47,   120,   155,   156,   157,   158,   159,   160,   161,   162,
       3,     4,     5,     6,     7,     8,     9,    47,    11,    12,
      13,    40,     9,    32,    32,    18,    19,    20,    33,    47,
      23,    24,    47,    47,    11,    12,    13,    14,    15,    16,
      17,    47,    35,    20,    37,   164,    23,    24,    25,    26,
      27,    28,    44,    45,    46,    47,    48,    47,    11,    12,
      13,    14,    15,    47,    57,    44,    45,    46,    47,    48,
      23,    24,    32,    56,    35,    68,    39,    54,    55,    72,
      10,    11,    12,    13,    14,    15,    16,    17,    69,    71,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    54,    55,    70,    73,    71,    36,    44,    45,    46,
      47,    48,    35,    40,    56,    13,    10,    11,    12,    13,
      14,    15,    16,    17,    54,    55,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    44,    45,    46,
      47,    48,    36,   204,    87,   166,   114,    -1,    -1,    -1,
      -1,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      54,    55,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    54,    55,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    54,    55,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    33,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    54,    55,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    54,    55,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    54,    55,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    20,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    54,
      55,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    54,
      55,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    97,    99,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    44,    45,    46,    47,    48,
      44,    45,    46,    47,    48,    47,    47,    47,     0,    81,
      32,    39,     9,    13,    90,    98,   100,   101,    44,    45,
      46,    47,    48,    44,    45,    46,    47,    48,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    40,    90,    98,
      10,    33,    35,    37,   102,    32,    32,    33,    47,    47,
      47,    47,    47,    47,    32,     3,     4,     5,     6,     7,
       8,    11,    12,    13,    18,    19,    20,    23,    24,    35,
      37,    57,    68,    72,    90,    91,    92,    95,    98,    91,
      86,   104,    10,    35,    90,   100,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    48,    70,    93,    56,
      94,   102,    10,    11,    12,    13,    14,    15,    16,    17,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    54,    55,    36,    13,    90,    33,    38,    39,   103,
      91,    36,    38,    71,    69,    70,    73,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    90,   104,    91,    96,
     103,    33,    36,    71,    33,    40,    40,   103,    56,    96
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
      89,    89,    89,    89,    89,    90,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      92,    92,    92,    92,    92,    92,    92,    92,    93,    93,
      93,    94,    94,    94,    95,    95,    96,    96,    97,    97,
      98,    98,    98,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   103,   104,   104,   104,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       2,     3,     5,     1,     1,     1,     1,     4,     4,     4,
       3,     4,     4,     4,     3,     3,     3,     3,     2,     3,
       3,     3,     2,     3,     3,     3,     2,     2,     2,     2,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     2,
       0,     1,     4,     0,     1,     2,     1,     3,     3,     4,
       3,     3,     1,     3,     3,     1,     2,     4,     3,     4,
       3,     3,     3,     2,     3,     3,     0
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
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 93 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 100 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 111 "parser.y" /* yacc.c:1646  */
    {
      char* tag_str = add_tag("func_decl", (yyvsp[0].string_v));
      (yyval.string_v) = tag_str;
    }
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 116 "parser.y" /* yacc.c:1646  */
    {
      char* tag_str = add_tag("func_def", (yyvsp[0].string_v));
      (yyval.string_v) = tag_str;
    }
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 124 "parser.y" /* yacc.c:1646  */
    {
      char* tag_str = add_tag("scalar_decl", (yyvsp[0].string_v));
      (yyval.string_v) = tag_str;
    }
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 129 "parser.y" /* yacc.c:1646  */
    {
      char* tag_str = add_tag("array_decl", (yyvsp[0].string_v));
      (yyval.string_v) = tag_str;
    }
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 137 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 147 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 157 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-4].string_v)) + strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v))  + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-4].string_v)); strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = (yyvsp[0].string_v); }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 167 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = (yyvsp[0].string_v); }
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 168 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = (yyvsp[0].string_v); }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "const"; }
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 173 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedlonglongint"; }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedlongint"; }
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 175 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedshortint"; }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedint"; }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedlonglongint"; }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedlongint"; }
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedshortint"; }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedint"; }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 181 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constlonglongint"; }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constlongint"; }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 183 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constshortint"; }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 184 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constint"; }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 185 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedlonglongint"; }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 186 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedlongint"; }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 187 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedshortint"; }
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 188 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedint"; }
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 189 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedlonglongint"; }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 190 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedlongint"; }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 191 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedshortint"; }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 192 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedint"; }
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 193 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "longlongint"; }
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 194 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "longint"; }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 195 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "shortint"; }
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 196 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "int"; }
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 200 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedlonglong"; }
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 201 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedlong"; }
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 202 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedshort"; }
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 203 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedchar"; }
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 204 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedlonglong"; }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 205 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedlong"; }
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedshort"; }
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 207 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedchar"; }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 208 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constlonglong"; }
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constlong"; }
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 210 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constshort"; }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 211 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constchar"; }
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedlonglong"; }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedlong"; }
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 214 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedshort"; }
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 215 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedchar"; }
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 216 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedlonglong"; }
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 217 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedlong"; }
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 218 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedshort"; }
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 219 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedshar"; }
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 220 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "longlong"; }
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 221 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "long"; }
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "short"; }
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 223 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "char"; }
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 227 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsigned"; }
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 228 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "ocnstunsigned"; }
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 229 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constfloat"; }
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 230 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constdouble"; }
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 231 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constvoid"; }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 232 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signed"; }
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 233 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsigned"; }
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 234 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "float"; }
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 235 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "double"; }
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 236 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "void"; }
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 240 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = (yyvsp[0].string_v);}
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 245 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 252 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 259 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 266 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 273 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 280 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 287 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 294 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 301 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 308 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 315 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 322 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 329 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 336 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 343 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 350 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 357 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 364 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 371 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 378 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 385 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 392 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 399 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2294 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 406 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 413 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 420 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 427 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 434 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2349 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 441 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 448 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 455 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 461 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = add_tag("expr", (yyvsp[0].string_v)); }
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 462 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = add_tag("expr", (yyvsp[0].string_v)); }
#line 2394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 463 "parser.y" /* yacc.c:1646  */
    {(yyval.string_v) = add_tag("expr", "0");}
#line 2400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 467 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = itoa((yyvsp[0].int_v)); }
#line 2406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 469 "parser.y" /* yacc.c:1646  */
    {
      char* s1 = itoa((yyvsp[0].int_v));
      size_t n = strlen(s1) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, "+"); strcat(str, add_tag("expr", s1));
      (yyval.string_v) = str;
    }
#line 2418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 477 "parser.y" /* yacc.c:1646  */
    {
      char* s1 = itoa(-(yyvsp[0].int_v));
      size_t n = strlen(s1) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, "-"); strcat(str, add_tag("expr", s1));
      (yyval.string_v) = str;
    }
#line 2430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 484 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = ftoa((yyvsp[0].float_v)); }
#line 2436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 486 "parser.y" /* yacc.c:1646  */
    {
      char* s1 = ftoa((yyvsp[0].float_v));
      size_t n = strlen(s1) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, "+"); strcat(str, add_tag("expr", s1));
      (yyval.string_v) = str;
    }
#line 2448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 494 "parser.y" /* yacc.c:1646  */
    {
      char* s1 = ftoa(-(yyvsp[0].float_v));
      size_t n = strlen(s1) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, "-"); strcat(str, add_tag("expr", s1));
      (yyval.string_v) = str;
    }
#line 2460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 502 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 509 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 519 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string_v) = strdup((yyvsp[0].string_v));
    }
#line 2490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 523 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 529 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = ""; }
#line 2507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 534 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string_v) = strdup((yyvsp[0].string_v));
    }
#line 2515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 538 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 544 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = ""; }
#line 2532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 549 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string_v) = strdup((yyvsp[0].string_v));
    }
#line 2540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 553 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 563 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string_v) = strdup((yyvsp[0].string_v));
    }
#line 2559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 567 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 577 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v));
      (yyval.string_v) = str;
    }
#line 2581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 584 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v));
      (yyval.string_v) = str;
    }
#line 2592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 593 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 599 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 605 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = (yyvsp[0].string_v);}
#line 2620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 610 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v));
      (yyval.string_v) = str;
    }
#line 2631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 620 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 627 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string_v) = strdup((yyvsp[0].string_v));
    }
#line 2650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 634 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 641 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 651 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 658 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 668 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 675 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 682 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 692 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));;
      (yyval.string_v) = str;
    }
#line 2738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 699 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 706 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 712 "parser.y" /* yacc.c:1646  */
    {(yyval.string_v) = "";}
#line 2766 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2770 "y.tab.c" /* yacc.c:1646  */
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
#line 715 "parser.y" /* yacc.c:1906  */

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

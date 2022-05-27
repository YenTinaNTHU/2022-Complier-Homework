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
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   535

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  145
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  207

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
       0,    85,    85,    88,    89,    92,    95,   101,   107,   113,
     122,   123,   124,   125,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   196,   200,   207,   214,   221,   228,   235,   242,
     249,   256,   263,   270,   277,   284,   291,   298,   305,   312,
     319,   326,   333,   340,   347,   354,   361,   368,   375,   382,
     389,   396,   403,   410,   417,   418,   419,   423,   424,   432,
     440,   441,   449,   457,   464,   474,   478,   485,   489,   493,
     500,   504,   508,   518,   522,   532,   539,   549,   555,   561,
     565,   575,   582,   589,   596,   606,   613,   623,   630,   637,
     647,   657,   664,   671,   675,   684
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
  "ADDR", "$accept", "program", "statements", "statement",
  "global_variable_decls", "type", "int_type", "char_type", "other_type",
  "ident", "expr", "literal", "char", "string", "variable", "exprs",
  "scalar_decl", "idents", "array_decl", "arrays", "array", "arr_dim",
  "arr_content", "func_decl", "parameters", "func_def", "compound_stmt", YY_NULLPTR
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

#define YYPACT_NINF -150

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-150)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     347,   163,   197,   203,   -39,   -14,    -1,  -150,  -150,  -150,
    -150,  -150,    47,  -150,   347,  -150,    60,  -150,  -150,  -150,
      23,    24,    29,  -150,   233,   239,    10,    25,    41,  -150,
    -150,  -150,  -150,  -150,    42,    52,    54,  -150,  -150,    55,
      56,    61,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,
      89,    -6,  -150,  -150,    37,  -150,  -150,  -150,    77,  -150,
      74,    75,    76,  -150,  -150,    81,    82,    85,  -150,  -150,
    -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,    -3,
    -150,   147,    89,   147,   347,    -7,    89,  -150,  -150,  -150,
    -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
    -150,   -16,    20,    98,   390,  -150,  -150,  -150,   210,    89,
      86,    95,   147,    98,  -150,  -150,  -150,  -150,   -18,   -18,
    -150,   -18,   -18,   246,   282,  -150,    69,    72,    73,    84,
     110,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,  -150,  -150,   147,   147,   147,   147,   147,   147,
     147,   147,  -150,   116,  -150,   107,  -150,   318,  -150,  -150,
    -150,  -150,    90,  -150,   390,    36,    36,   -18,   -18,   -18,
      51,    51,   455,    -2,   435,    51,    51,   480,   480,   410,
     174,   124,   124,   347,   354,   122,    67,    95,  -150,   112,
    -150,   147,  -150,  -150,  -150,  -150,  -150
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    13,    67,    68,    60,    59,    58,    37,    61,    70,
      71,    69,     0,     2,     4,     5,     0,    10,    11,    12,
       0,     0,     0,     9,    62,    63,    48,    47,    46,    25,
      49,    65,    66,    64,    52,    51,    50,    29,    53,    56,
      55,    54,    33,    57,    36,    35,    34,     1,     3,    72,
       0,   129,   125,   130,   132,     6,     7,     8,     0,   144,
      40,    39,    38,    17,    41,    44,    43,    42,    21,    45,
      24,    23,    22,    28,    27,    26,    32,    31,    30,   129,
     126,     0,     0,     0,   143,   133,     0,   145,    16,    15,
      14,    20,    19,    18,   107,   108,   109,   110,   111,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     106,   117,   120,   121,   128,   104,   105,   127,     0,     0,
       0,     0,     0,     0,   131,   101,   100,   102,    91,    92,
     103,    80,    81,     0,     0,   115,     0,     0,   118,     0,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,    79,     0,     0,     0,     0,     0,     0,
       0,     0,   135,   141,   140,     0,   134,     0,    98,    99,
     116,   113,     0,   114,    88,    73,    74,    75,    76,    77,
      82,    84,    94,    95,    93,    83,    85,    86,    87,    89,
      90,    96,    97,   143,   123,     0,     0,     0,   136,     0,
     142,     0,   137,   138,   139,   119,   124
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,   149,  -150,  -150,   -84,  -150,  -150,  -150,   -15,
     -64,  -150,  -150,  -150,  -150,   -32,  -150,   -48,  -150,    87,
    -150,    59,  -149,  -150,   -19,  -150,  -150
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    16,    17,    18,    19,   113,
     194,   115,   137,   139,   116,   195,    20,    52,    21,    53,
      54,    85,   166,    22,   120,    23,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     119,    51,    80,   121,    81,   152,   153,    81,    44,   142,
     143,   144,   145,   146,   147,   148,   196,   114,   149,   118,
     151,   152,   153,   154,   155,   156,   157,    82,   122,    83,
      82,    84,   135,    45,   117,    79,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,    46,    47,   204,   144,
     145,   146,   160,   161,   136,    55,    56,    70,   167,   152,
     153,    57,   142,   143,   144,   145,   146,    79,    58,    49,
      86,   123,    71,    50,   152,   153,   138,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,    72,    73,
     185,   186,   187,   188,   189,   190,   191,   192,    49,    74,
     197,    75,    76,    77,   163,   160,   161,   203,    78,   119,
      94,    95,    96,    97,    98,    99,    49,    87,   100,   101,
     102,    88,    89,    90,   164,   103,   104,   105,    91,    92,
     106,   107,    93,    83,   165,   142,   143,   144,   145,   146,
     170,   171,   108,   172,   109,   122,   165,   152,   153,   193,
      94,    95,    96,    97,    98,    99,    49,   173,   100,   101,
     102,   199,   202,    48,   110,   103,   104,   105,   205,   206,
     106,   107,   140,   124,   200,   111,     0,     0,     0,   112,
       0,     0,   108,     0,   109,   142,   143,   144,   145,   146,
     147,   148,     0,     0,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   110,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,   111,     0,     0,     0,   112,
     141,   142,   143,   144,   145,   146,   147,   148,   160,   161,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,    34,    35,    36,    37,    38,   162,    39,    40,    41,
      42,    43,     0,     0,     0,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   160,   161,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,    60,    61,    62,
      63,    64,   168,    65,    66,    67,    68,    69,     0,     0,
       0,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     160,   161,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,     0,     0,     0,     0,     0,     0,     0,
     169,     0,     0,     0,     0,     0,     0,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   160,   161,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,     0,
       0,     0,     0,     0,   198,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   160,   161,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,     0,     0,   201,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   160,   161,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   142,   143,   144,   145,   146,   147,   148,     0,     0,
     149,   150,   151,   152,   153,   154,   155,   156,   157,     0,
       0,     0,     0,     0,   160,   161,   142,   143,   144,   145,
     146,   147,   148,     0,     0,   149,     0,     0,   152,   153,
     154,   155,   156,   157,   160,   161,   142,   143,   144,   145,
     146,   147,   148,     0,     0,     0,     0,     0,   152,   153,
     154,   155,   156,   157,     0,     0,     0,     0,     0,   160,
     161,   142,   143,   144,   145,   146,   147,   148,     0,     0,
       0,     0,     0,   152,   153,   154,   155,     0,     0,   160,
     161,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   160,   161
};

static const yytype_int16 yycheck[] =
{
      84,    16,    50,    10,    10,    23,    24,    10,    47,    11,
      12,    13,    14,    15,    16,    17,   165,    81,    20,    83,
      22,    23,    24,    25,    26,    27,    28,    33,    35,    35,
      33,    37,    48,    47,    82,    50,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,    47,     0,   197,    13,
      14,    15,    54,    55,    70,    32,    32,    47,   122,    23,
      24,    32,    11,    12,    13,    14,    15,    82,    39,     9,
      33,    86,    47,    13,    23,    24,    56,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    47,    47,
     154,   155,   156,   157,   158,   159,   160,   161,     9,    47,
      33,    47,    47,    47,   119,    54,    55,    40,    47,   193,
       3,     4,     5,     6,     7,     8,     9,    40,    11,    12,
      13,    47,    47,    47,    38,    18,    19,    20,    47,    47,
      23,    24,    47,    35,    39,    11,    12,    13,    14,    15,
      71,    69,    35,    70,    37,    35,    39,    23,    24,    33,
       3,     4,     5,     6,     7,     8,     9,    73,    11,    12,
      13,    71,    40,    14,    57,    18,    19,    20,    56,   201,
      23,    24,   113,    86,   193,    68,    -1,    -1,    -1,    72,
      -1,    -1,    35,    -1,    37,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    57,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    68,    -1,    -1,    -1,    72,
      10,    11,    12,    13,    14,    15,    16,    17,    54,    55,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    44,    45,    46,    47,    48,    36,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    54,    55,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    44,    45,    46,
      47,    48,    36,    44,    45,    46,    47,    48,    -1,    -1,
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
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,    54,    55,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    20,    -1,    -1,    23,    24,
      25,    26,    27,    28,    54,    55,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    54,
      55,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    79,    80,    81,    82,    83,    84,    85,    86,
      94,    96,   101,   103,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    44,    45,    46,    47,    48,    44,
      45,    46,    47,    48,    47,    47,    47,     0,    80,     9,
      13,    87,    95,    97,    98,    32,    32,    32,    39,   104,
      44,    45,    46,    47,    48,    44,    45,    46,    47,    48,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    87,
      95,    10,    33,    35,    37,    99,    33,    40,    47,    47,
      47,    47,    47,    47,     3,     4,     5,     6,     7,     8,
      11,    12,    13,    18,    19,    20,    23,    24,    35,    37,
      57,    68,    72,    87,    88,    89,    92,    95,    88,    83,
     102,    10,    35,    87,    97,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    48,    70,    90,    56,    91,
      99,    10,    11,    12,    13,    14,    15,    16,    17,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      54,    55,    36,    87,    38,    39,   100,    88,    36,    38,
      71,    69,    70,    73,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    33,    88,    93,   100,    33,    36,    71,
     102,    33,    40,    40,   100,    56,    93
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    78,    79,    80,    80,    81,    82,    82,    82,    82,
      83,    83,    83,    83,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    87,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    89,    89,    89,
      89,    89,    89,    89,    89,    90,    90,    90,    91,    91,
      91,    92,    92,    93,    93,    94,    94,    95,    95,    95,
      96,    97,    97,    98,    98,    99,    99,   100,   100,   100,
     101,   102,   102,   102,   103,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     2,     2,     1,
       1,     1,     1,     1,     4,     4,     4,     3,     4,     4,
       4,     3,     3,     3,     3,     2,     3,     3,     3,     2,
       3,     3,     3,     2,     2,     2,     2,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     2,     0,     1,     4,
       0,     1,     2,     1,     3,     2,     3,     3,     3,     1,
       2,     3,     1,     2,     4,     3,     4,     3,     3,     3,
       5,     2,     4,     0,     2,     2
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
        case 6:
#line 96 "parser.y" /* yacc.c:1646  */
    {
      printf("<scalar_decl>");
      printf("%s;",(yyvsp[-1].string_v));
      printf("</scalar_decl>");
    }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 102 "parser.y" /* yacc.c:1646  */
    {
      printf("<array_decl>");
      printf("%s;", (yyvsp[-1].string_v));
      printf("</array_decl>");
    }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 108 "parser.y" /* yacc.c:1646  */
    {
      printf("<func_decl>");
      printf("%s;", (yyvsp[-1].string_v));
      printf("</func_decl>");
    }
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 114 "parser.y" /* yacc.c:1646  */
    {
      printf("<func_def>");
      printf("%s;", (yyvsp[0].string_v));
      printf("</func_def>");
    }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 122 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = (yyvsp[0].string_v); }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 123 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = (yyvsp[0].string_v); }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 124 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = (yyvsp[0].string_v); }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 125 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "const"; }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 129 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedlonglongint"; }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 130 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedlongint"; }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 131 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedshortint"; }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 132 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedint"; }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 133 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedlonglongint"; }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 134 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedlongint"; }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedshortint"; }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 136 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedint"; }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 137 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constlonglongint"; }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constlongint"; }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 139 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constshortint"; }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constint"; }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedlonglongint"; }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedlongint"; }
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 143 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedshortint"; }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 144 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedint"; }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedlonglongint"; }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedlongint"; }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedshortint"; }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 148 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedint"; }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 149 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "longlongint"; }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 150 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "longint"; }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "shortint"; }
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "int"; }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedlonglong"; }
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedlong"; }
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedshort"; }
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 159 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsignedchar"; }
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedlonglong"; }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedlong"; }
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 162 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedshort"; }
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 163 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constunsignedchar"; }
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constlonglong"; }
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constlong"; }
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constshort"; }
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 167 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constchar"; }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 168 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedlonglong"; }
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedlong"; }
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedshort"; }
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signedchar"; }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 172 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedlonglong"; }
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 173 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedlong"; }
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedshort"; }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 175 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsignedshar"; }
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "longlong"; }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "long"; }
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "short"; }
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "char"; }
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 183 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constsigned"; }
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 184 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "ocnstunsigned"; }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 185 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constfloat"; }
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 186 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constdouble"; }
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 187 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "constvoid"; }
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 188 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "signed"; }
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 189 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "unsigned"; }
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 190 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "float"; }
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 191 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "double"; }
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 192 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "void"; }
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 196 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = (yyvsp[0].string_v);}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 201 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 208 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 215 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 222 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 229 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 236 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 243 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 250 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 257 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 264 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 271 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 278 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 285 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 292 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 299 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 306 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 313 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 320 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 327 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 334 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 341 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 348 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 355 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2238 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 362 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 369 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 376 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 383 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 390 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 397 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 404 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 411 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = add_tag("expr", str);
    }
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 417 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = add_tag("expr", (yyvsp[0].string_v)); }
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 418 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = add_tag("expr", (yyvsp[0].string_v)); }
#line 2338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 419 "parser.y" /* yacc.c:1646  */
    {(yyval.string_v) = add_tag("expr", "0");}
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 423 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = itoa((yyvsp[0].int_v)); }
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 425 "parser.y" /* yacc.c:1646  */
    {
      char* s1 = itoa((yyvsp[0].int_v));
      size_t n = strlen(s1) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, "+"); strcat(str, add_tag("expr", s1));
      (yyval.string_v) = str;
    }
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 433 "parser.y" /* yacc.c:1646  */
    {
      char* s1 = itoa(-(yyvsp[0].int_v));
      size_t n = strlen(s1) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, "-"); strcat(str, add_tag("expr", s1));
      (yyval.string_v) = str;
    }
#line 2374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 440 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = ftoa((yyvsp[0].float_v)); }
#line 2380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 442 "parser.y" /* yacc.c:1646  */
    {
      char* s1 = ftoa((yyvsp[0].float_v));
      size_t n = strlen(s1) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, "+"); strcat(str, add_tag("expr", s1));
      (yyval.string_v) = str;
    }
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 450 "parser.y" /* yacc.c:1646  */
    {
      char* s1 = ftoa(-(yyvsp[0].float_v));
      size_t n = strlen(s1) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, "-"); strcat(str, add_tag("expr", s1));
      (yyval.string_v) = str;
    }
#line 2404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 458 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 465 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 475 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string_v) = strdup((yyvsp[0].string_v));
    }
#line 2434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 479 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 485 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = ""; }
#line 2451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 490 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string_v) = strdup((yyvsp[0].string_v));
    }
#line 2459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 494 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 500 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = ""; }
#line 2476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 505 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string_v) = strdup((yyvsp[0].string_v));
    }
#line 2484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 509 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 519 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string_v) = strdup((yyvsp[0].string_v));
    }
#line 2503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 523 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 533 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 540 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 549 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 555 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 561 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = (yyvsp[0].string_v);}
#line 2564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 566 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 576 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 583 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string_v) = strdup((yyvsp[0].string_v));
    }
#line 2594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 590 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 597 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 607 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 614 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 624 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 631 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 638 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 648 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-4].string_v)) + strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v))  + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-4].string_v)); strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 658 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));;
      (yyval.string_v) = str;
    }
#line 2693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 665 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-3].string_v)) + strlen((yyvsp[-2].string_v)) + strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-3].string_v)); strcat(str, (yyvsp[-2].string_v)); strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));
      (yyval.string_v) = str;
    }
#line 2704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 671 "parser.y" /* yacc.c:1646  */
    {(yyval.string_v) = "";}
#line 2710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 676 "parser.y" /* yacc.c:1646  */
    {
      size_t n = strlen((yyvsp[-1].string_v)) + strlen((yyvsp[0].string_v));
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, (yyvsp[-1].string_v)); strcat(str, (yyvsp[0].string_v));;
      (yyval.string_v) = str;
    }
#line 2721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 685 "parser.y" /* yacc.c:1646  */
    { (yyval.string_v) = "{compound_stmt}";}
#line 2727 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2731 "y.tab.c" /* yacc.c:1646  */
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
#line 688 "parser.y" /* yacc.c:1906  */

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

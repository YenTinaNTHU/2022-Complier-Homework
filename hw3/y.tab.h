/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    CHAR4 = 281,
    CHAR8 = 282,
    DOUBLE = 283,
    VOID = 284,
    FLOAT = 285,
    STRUCT = 286,
    RETURN = 287,
    LSHIFT = 288,
    RSHIFT = 289,
    STR = 290,
    NUL = 291,
    FOR = 292,
    DO = 293,
    WHILE = 294,
    BREAK = 295,
    CONTINUE = 296,
    IF = 297,
    ELSE = 298,
    SWITCH = 299,
    CASE = 300,
    DEFAULT = 301,
    CHAR_START = 302,
    CHAR_END = 303,
    ESCAPE_START = 304,
    ESCAPE_CHAR = 305,
    STRING_START = 306,
    STRING_END = 307,
    CODEGEN = 308,
    DIGITALWRITE = 309,
    DELAY = 310,
    HIGH = 311,
    LOW = 312
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
#define CHAR4 281
#define CHAR8 282
#define DOUBLE 283
#define VOID 284
#define FLOAT 285
#define STRUCT 286
#define RETURN 287
#define LSHIFT 288
#define RSHIFT 289
#define STR 290
#define NUL 291
#define FOR 292
#define DO 293
#define WHILE 294
#define BREAK 295
#define CONTINUE 296
#define IF 297
#define ELSE 298
#define SWITCH 299
#define CASE 300
#define DEFAULT 301
#define CHAR_START 302
#define CHAR_END 303
#define ESCAPE_START 304
#define ESCAPE_CHAR 305
#define STRING_START 306
#define STRING_END 307
#define CODEGEN 308
#define DIGITALWRITE 309
#define DELAY 310
#define HIGH 311
#define LOW 312

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "parser.y" /* yacc.c:1909  */

  int int_v;
  float float_v;
  char char_v;
  char* string_v;  

#line 175 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

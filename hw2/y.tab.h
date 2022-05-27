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
#line 39 "parser.y" /* yacc.c:1909  */

  int int_v;
  float float_v;
  char char_v;
  char* string_v;  

#line 169 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

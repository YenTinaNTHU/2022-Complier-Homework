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
    FLOAT_NUM = 259,
    ID = 260,
    INC = 261,
    DEC = 262,
    LEQ = 263,
    GEQ = 264,
    EQL = 265,
    NEQ = 266,
    LAND = 267,
    LOR = 268,
    CONST = 269,
    SIGNED = 270,
    UNSIGNED = 271,
    SHORT = 272,
    LONG = 273,
    LONGLONG = 274,
    INT = 275,
    CHAR = 276,
    DOUBLE = 277,
    VOID = 278,
    FLOAT = 279,
    STRUCT = 280,
    RETURN = 281,
    LSHIFT = 282,
    RSHIFT = 283,
    STR = 284,
    FOR = 285,
    DO = 286,
    WHILE = 287,
    BREAK = 288,
    CONTINUE = 289,
    IF = 290,
    ELSE = 291,
    SWITCH = 292,
    CASE = 293,
    DEFAULT = 294,
    CHAR_START = 295,
    CHAR_END = 296,
    ESCAPE_START = 297,
    ESCAPE_CHAR = 298,
    STRING_START = 299,
    STRING_END = 300,
    UMINUS = 301,
    UPLUS = 302
  };
#endif
/* Tokens.  */
#define INT_NUM 258
#define FLOAT_NUM 259
#define ID 260
#define INC 261
#define DEC 262
#define LEQ 263
#define GEQ 264
#define EQL 265
#define NEQ 266
#define LAND 267
#define LOR 268
#define CONST 269
#define SIGNED 270
#define UNSIGNED 271
#define SHORT 272
#define LONG 273
#define LONGLONG 274
#define INT 275
#define CHAR 276
#define DOUBLE 277
#define VOID 278
#define FLOAT 279
#define STRUCT 280
#define RETURN 281
#define LSHIFT 282
#define RSHIFT 283
#define STR 284
#define FOR 285
#define DO 286
#define WHILE 287
#define BREAK 288
#define CONTINUE 289
#define IF 290
#define ELSE 291
#define SWITCH 292
#define CASE 293
#define DEFAULT 294
#define CHAR_START 295
#define CHAR_END 296
#define ESCAPE_START 297
#define ESCAPE_CHAR 298
#define STRING_START 299
#define STRING_END 300
#define UMINUS 301
#define UPLUS 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 39 "parser.y" /* yacc.c:1909  */

  int int_v;
  float float_v;
  char char_v;
  char* string_v;  

#line 155 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VOID = 258,
     INT = 259,
     BYTE = 260,
     B = 261,
     BOOL = 262,
     CONST = 263,
     TRUE = 264,
     FALSE = 265,
     RETURN = 266,
     WHILE = 267,
     BREAK = 268,
     CONTINUE = 269,
     SC = 270,
     COMMA = 271,
     LBRACE = 272,
     RBRACE = 273,
     ID = 274,
     NUM = 275,
     STRING = 276,
     LPAREN = 277,
     RPAREN = 278,
     NOT = 279,
     MULT = 280,
     DIV = 281,
     PLUS = 282,
     MINUS = 283,
     RELOPNONASSOC = 284,
     RELOPLEFT = 285,
     AND = 286,
     OR = 287,
     IF = 288,
     ELSE = 289,
     ASSIGN = 290
   };
#endif
/* Tokens.  */
#define VOID 258
#define INT 259
#define BYTE 260
#define B 261
#define BOOL 262
#define CONST 263
#define TRUE 264
#define FALSE 265
#define RETURN 266
#define WHILE 267
#define BREAK 268
#define CONTINUE 269
#define SC 270
#define COMMA 271
#define LBRACE 272
#define RBRACE 273
#define ID 274
#define NUM 275
#define STRING 276
#define LPAREN 277
#define RPAREN 278
#define NOT 279
#define MULT 280
#define DIV 281
#define PLUS 282
#define MINUS 283
#define RELOPNONASSOC 284
#define RELOPLEFT 285
#define AND 286
#define OR 287
#define IF 288
#define ELSE 289
#define ASSIGN 290




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


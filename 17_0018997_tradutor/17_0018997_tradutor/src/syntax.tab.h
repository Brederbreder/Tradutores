/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SRC_SYNTAX_TAB_H_INCLUDED
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
    INT = 258,                     /* INT  */
    FLOAT = 259,                   /* FLOAT  */
    LIST = 260,                    /* LIST  */
    TYPE = 261,                    /* TYPE  */
    READ = 262,                    /* READ  */
    WRITE = 263,                   /* WRITE  */
    STRING = 264,                  /* STRING  */
    ID = 265,                      /* ID  */
    NIL_RW = 266,                  /* NIL_RW  */
    REL_OP = 267,                  /* REL_OP  */
    ASSIGN_OP = 268,               /* ASSIGN_OP  */
    LIST_CONSTRUC = 269,           /* LIST_CONSTRUC  */
    FOR_RW = 270,                  /* FOR_RW  */
    IF_RW = 271,                   /* IF_RW  */
    RETURN_RW = 272,               /* RETURN_RW  */
    ELSE_RW = 273,                 /* ELSE_RW  */
    LIST_BIN_OP = 274,             /* LIST_BIN_OP  */
    LIST_UN_OP = 275,              /* LIST_UN_OP  */
    ADD_OP = 276,                  /* ADD_OP  */
    MUL_OP = 277,                  /* MUL_OP  */
    LOG_OP = 278                   /* LOG_OP  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 72 "src/syntax.y"

    struct TreeNode* node;
    struct Token{
        char id[100];
        int line;
        int column;
    } token;

#line 96 "src/syntax.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_SYNTAX_TAB_H_INCLUDED  */

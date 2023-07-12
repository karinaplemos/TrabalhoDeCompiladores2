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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    CHAR = 260,                    /* CHAR  */
    FOR = 261,                     /* FOR  */
    WHILE = 262,                   /* WHILE  */
    IF = 263,                      /* IF  */
    ELSE = 264,                    /* ELSE  */
    ASSIGN = 265,                  /* ASSIGN  */
    EQ = 266,                      /* EQ  */
    LT = 267,                      /* LT  */
    GT = 268,                      /* GT  */
    GTE = 269,                     /* GTE  */
    LTE = 270,                     /* LTE  */
    NEQ = 271,                     /* NEQ  */
    PLUS = 272,                    /* PLUS  */
    MINUS = 273,                   /* MINUS  */
    ASTERISK = 274,                /* ASTERISK  */
    SLASH = 275,                   /* SLASH  */
    SEMICOLON = 276,               /* SEMICOLON  */
    COMMA = 277,                   /* COMMA  */
    OPENPARENTHESIS = 278,         /* OPENPARENTHESIS  */
    CLOSEPARENTHESIS = 279,        /* CLOSEPARENTHESIS  */
    OPENBRACKETS = 280,            /* OPENBRACKETS  */
    CLOSEBRACKETS = 281,           /* CLOSEBRACKETS  */
    NUMBER = 282,                  /* NUMBER  */
    FLOATNUMBER = 283,             /* FLOATNUMBER  */
    CHARACTER = 284,               /* CHARACTER  */
    IDENTIFIER = 285,              /* IDENTIFIER  */
    NOELSE = 286                   /* NOELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 88 "parser.y"
 
    struct token1{
        //char nome[20];
        struct no *no_;
    } tkn1;
    struct token2{
        char *valor;
        //int tipo;
    }tkn2;
    struct token3{
        struct no *no_;
        int tipo;
    }tkn3;

#line 110 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

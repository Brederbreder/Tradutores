%option noyywrap
%option noinput nounput

%{

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "syntax.tab.h"
    #include "../lib/structures.h"
    int lines = 1, columns = 1;
    int errors = 0;

%}

TYPE                    "int"|"float"

LIST                    "list"

DIGIT                   [0-9]

LETTER                  [_a-zA-Z]

ID                      [a-zA-Z_][a-z0-9A-Z_]* 

ADD_OP                  [+-]

MUL_OP                  [*/]

OP_BIN_RELATIVE         "<"|"<="|">"|">="|"=="|"!="      

OP_LOGIC                "&&"|"||"

OP_BIN_LIST             ">>"|"<<"

OP_UN_LIST              "?"|"%"|":"|"!"

RESERVED_WORDS          for|if|return|else|NIL

STRING                  \"([^"\n\\]|\\.)*\"

INTEGER                 {DIGIT}+

FLOAT                   {DIGIT}+"."{DIGIT}+

OP_ASSIGN               =  

READ                    "read"

WRITE                   "write"|"writeln"

%%

\n {
    lines++;
    columns = 1;
}

[ \t\r]+ {
    columns += yyleng;
}

{TYPE} {
    yylval.token.line = lines;
    yylval.token.column = columns;
    strcpy(yylval.token.id, yytext);
    columns += yyleng;
    return TYPE;
}

{RESERVED_WORDS} {
    if(!strcmp(yytext, "for")){
        yylval.token.line = lines;
        yylval.token.column = columns;
        strcpy(yylval.token.id, yytext);
        columns += yyleng;
        return FOR_RW;
    }
    else if(!strcmp(yytext, "if")){
        yylval.token.line = lines;
        yylval.token.column = columns;
        strcpy(yylval.token.id, yytext);
        columns += yyleng;
        return IF_RW;
    }
    else if(!strcmp(yytext, "return")){
        yylval.token.line = lines;
        yylval.token.column = columns;
        strcpy(yylval.token.id, yytext);
        columns += yyleng;
        return RETURN_RW;
    }
    else if(!strcmp(yytext, "else")){
        yylval.token.line = lines;
        yylval.token.column = columns;
        strcpy(yylval.token.id, yytext);
        columns += yyleng;
        return ELSE_RW;
    }
    else if(!strcmp(yytext, "NIL")){
        yylval.token.line = lines;
        yylval.token.column = columns;
        strcpy(yylval.token.id, yytext);
        columns += yyleng;
        return NIL_RW;
    }
}

{LIST} {
    yylval.token.line = lines;
    yylval.token.column = columns;
    strcpy(yylval.token.id, yytext);
    columns += yyleng;
    return LIST;
}

{READ} {
    yylval.token.line = lines;
    yylval.token.column = columns;
    strcpy(yylval.token.id, yytext);
    columns += yyleng;
    return READ;
}

{WRITE} {
    yylval.token.line = lines;
    yylval.token.column = columns;
    strcpy(yylval.token.id, yytext);
    columns += yyleng;
    return WRITE;
}

{ID} {
    yylval.token.line = lines;
    yylval.token.column = columns;
    strcpy(yylval.token.id, yytext);
    columns += yyleng;
    return ID;
}

{INTEGER} {
    yylval.token.line = lines;
    yylval.token.column = columns;
    strcpy(yylval.token.id, yytext);
    columns += yyleng;
    return INT;
}

{FLOAT} {
    yylval.token.line = lines;
    yylval.token.column = columns;
    strcpy(yylval.token.id, yytext);
    columns += yyleng;
    return FLOAT;
}

{ADD_OP} {
    yylval.token.line = lines;
    yylval.token.column = columns;
    strcpy(yylval.token.id, yytext);
    columns += yyleng;
    return ADD_OP;
}

{MUL_OP} {
    yylval.token.line = lines;
    yylval.token.column = columns;
    strcpy(yylval.token.id, yytext);
    columns += yyleng;
    return MUL_OP;
}

{OP_BIN_RELATIVE} {
    yylval.token.line = lines;
    yylval.token.column = columns;
    strcpy(yylval.token.id, yytext);
    columns += yyleng;
    return REL_OP;
}

{OP_LOGIC} {
    yylval.token.line = lines;
    yylval.token.column = columns;
    strcpy(yylval.token.id, yytext);
    columns += yyleng;
    return LOG_OP;
}

{OP_ASSIGN} {
    yylval.token.line = lines;
    yylval.token.column = columns;
    strcpy(yylval.token.id, yytext);
    columns += yyleng;
    return ASSIGN_OP;
}

{OP_BIN_LIST} {
    yylval.token.line = lines;
    yylval.token.column = columns;
    strcpy(yylval.token.id, yytext);
    columns += yyleng;
    return LIST_BIN_OP;
}

{OP_UN_LIST} {
    yylval.token.line = lines;
    yylval.token.column = columns;
    strcpy(yylval.token.id, yytext);
    columns += yyleng;
    if(!strcmp(yytext, ":")){
        return LIST_CONSTRUC;
    }
    return LIST_UN_OP;
}

{STRING} {
    yylval.token.line = lines;
    yylval.token.column = columns;
    strcpy(yylval.token.id, yytext);
    columns += yyleng;
    return STRING;
}

"}" {
    yylval.token.line = lines;
    yylval.token.column = columns;
    strcpy(yylval.token.id, yytext);
    columns += yyleng;
    return '}';
}

"{" {
    yylval.token.line = lines;
    yylval.token.column = columns;
    strcpy(yylval.token.id, yytext);
    columns += yyleng;
    return '{';
}

"(" {
    yylval.token.line = lines;
    yylval.token.column = columns;
    strcpy(yylval.token.id, yytext);
    columns += yyleng;
    return '(';
}

")" {
    yylval.token.line = lines;
    yylval.token.column = columns;
    strcpy(yylval.token.id, yytext);
    columns += yyleng;
    return ')';
}

";" {
    yylval.token.line = lines;
    yylval.token.column = columns;
    strcpy(yylval.token.id, yytext);
    columns += yyleng;
    return ';';
}

"," {
    yylval.token.line = lines;
    yylval.token.column = columns;
    strcpy(yylval.token.id, yytext);
    columns += yyleng;
    return ',';
}

.   {
    if(*yytext == '"'){
        printf("Error on program because of string without closing quotation mark\n");
        errors += 1;
        return -1;
    }else{
        printf("ERROR line = %d, Colum = %d, Unidentified Character = %s\n", lines, columns, yytext);
        errors += 1;
        columns += yyleng;
    }
}

%%
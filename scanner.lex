%{
/* Declarations section */
#include <stdio.h>
#include "Semantics.h"
#include "hw3_output.hpp"
#include "parser.tab.hpp"
#include <iostream>

%}

%option yylineno
%option noyywrap
whitespace		([\t\n\r  ])
string  (\"([^\n\r\"\\]|\\[rnt"\\])+\")

%%
void                        yylval = new Node(yytext, yylineno);return VOID;
int                         yylval = new Node(yytext, yylineno);return INT;
byte                        yylval = new Node(yytext, yylineno);return BYTE;
b                           yylval = new Node(yytext, yylineno);std::cout<<yytext<<std::endl;return B;
bool                        yylval = new Node(yytext, yylineno);return BOOL;
const                       yylval = new Node(yytext, yylineno);return CONST;
and                         yylval = new Node(yytext, yylineno);return AND;
or                          yylval = new Node(yytext, yylineno);return OR;
not                         yylval = new Node(yytext, yylineno);return NOT;
true                        yylval = new Node(yytext, yylineno);return TRUE;
false                       yylval = new Node(yytext, yylineno);return FALSE;
return                      yylval = new Node(yytext, yylineno);return RETURN;
if                          yylval = new Node(yytext, yylineno);return IF;
else                        yylval = new Node(yytext, yylineno);return ELSE;
while                       yylval = new Node(yytext, yylineno);return WHILE;
break                       yylval = new Node(yytext, yylineno);return BREAK;
continue                    yylval = new Node(yytext, yylineno);return CONTINUE;
;                           yylval = new Node(yytext, yylineno);return SC;
,                           yylval = new Node(yytext, yylineno);return COMMA;
"("                         yylval = new Node(yytext, yylineno);return LPAREN;
")"                         yylval = new Node(yytext, yylineno);return RPAREN;
"{"                         yylval = new Node(yytext, yylineno);return LBRACE;
"}"                         yylval = new Node(yytext, yylineno);return RBRACE;
"="                         yylval = new Node(yytext, yylineno);return ASSIGN;
"<"|">"|"<="|">="           yylval = new Node(yytext, yylineno);return RELOPLEFT;
"=="|"!="                   yylval = new Node(yytext, yylineno);return RELOPNONASSOC;
"+"                         yylval = new Node(yytext, yylineno);return PLUS;
"-"                         yylval = new Node(yytext, yylineno);return MINUS;
"/"                         yylval = new Node(yytext, yylineno);return DIV;
"*"                         yylval = new Node(yytext, yylineno);return MULT;
0|[1-9][0-9]*               yylval = new Node(yytext, yylineno);std::cout<<yytext<<std::endl;return NUM;
[a-zA-Z][0-9a-zA-Z]*        yylval = new Node(yytext, yylineno);std::cout<<yytext<<std::endl;return ID;
{string}                    yylval = new Node(yytext, yylineno);return STRING;
\/\/[^\r\n]*[\r|\n|\r\n]?   {};
{whitespace}				{};
.                       	{output::errorLex(yylineno); exit(0);};
%%
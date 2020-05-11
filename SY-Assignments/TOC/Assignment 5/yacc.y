%{
#include <stdio.h>
int yylex();
int yyerror(); 
%}

%token COMPOUND
%token WORD
%token DOT

%%
S1: S S1
| S
;

S: WORD_LIST COMPOUND WORD_LIST DOT         { printf("Compound Statement!\n"); }
| WORD_LIST DOT                             { printf("Simple Statement\n"); }
;

WORD_LIST: WORD WORD_LIST
| WORD
;
%%

extern FILE *yyin;

int main(void)
{
    yyin = fopen("input.txt", "r");
    yyparse();
    return 0;
}

int yyerror()
{
    return 0;
}
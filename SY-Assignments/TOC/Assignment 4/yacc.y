%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(char *err);
int yylex();
%}

%token SCOPE
%token DATA_TYPES
%token id
%token O_Square_B
%token C_Square_B
%token EQUAL
%token NEW
%token COMMA
%token DELIMITER
%token DIGIT

%%
start: DATA_TYPES varList DELIMITER { printf("[VALID]\n"); }
     | SCOPE DATA_TYPES varList DELIMITER { printf("[VALID]\n"); }
     | DATA_TYPES O_Square_B DIGIT C_Square_B id DELIMITER { printf("[VALID]\n"); }
     | SCOPE DATA_TYPES O_Square_B DIGIT C_Square_B id DELIMITER { printf("[VALID]\n"); }
     | DATA_TYPES O_Square_B DIGIT C_Square_B id EQUAL NEW DATA_TYPES O_Square_B DIGIT C_Square_B DELIMITER { printf("[VALID]\n"); }
     | SCOPE DATA_TYPES O_Square_B DIGIT C_Square_B id EQUAL NEW DATA_TYPES O_Square_B DIGIT C_Square_B DELIMITER { printf("[VALID]\n"); }
     ;

varList: varList COMMA id 
       | id
       ;

%%

int main(void)
{
    printf("Enter Declaration to check validity: ");
    return yyparse();
}

void yyerror (char *err)
{
    fprintf(stderr, "[ERROR]: %s\n", err);
}
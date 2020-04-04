#include <stdio.h>

extern int yylex();
extern int nword;
extern int nchar;
extern int yylineno;

int main (void)
{
    int token;
    token = yylex();
    while (token)
    {
        printf("%d\n", token);
        token = yylex();
    }
    printf("\n\nCHAR: %d\nWORD: %d\nLINES: %d\n", nchar, nword, yylineno);
    return 0;
}
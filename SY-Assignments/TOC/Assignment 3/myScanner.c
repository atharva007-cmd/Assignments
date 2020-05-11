#include <stdio.h>
extern int yylex();

int main (void)
{
    int token;
    token = yylex();
    while (token)
    {
        switch (token)
        {
        case 1:
            printf(" COMMENT\n");
            break;

        case 2:
            printf(" ACCESS_SPECIFIER ");
            break;

        case 3:
            printf(" SEPERATOR ");
            break;

        case 4:
            printf(" KEY_WORD ");
            break;

        case 5:
            printf(" DELIMITER ");
            break;
        }
        token = yylex();
    }
    printf("\n");
    return 0;
}
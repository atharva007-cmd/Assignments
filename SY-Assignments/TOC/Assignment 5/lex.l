%{
    #include "y.tab.h"
%}


%%
(""[aA][nN][dD]"")|(""[oO][rR]"")|(""[bB][uU][tT]"")        return COMPOUND;
[a-zA-Z]+                                                   return WORD;
"."                                                         return DOT;
\t|\n|" "                                                   ;
.                                                           return yytext[0];
%%

int yywrap()
{
    return 1;
}
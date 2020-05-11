%{
    int nword=0;
    int nchar=0;
%}

%%
[\n]            { nchar++; yylineno++; }
[^ \t\n]+       { nword++; nchar += yyleng; }
.               { nchar++; }
%%

int yywrap (void)
{
    printf ("\nNCHAR: %d\nNWORD: %d\nNLINE: %d\n", nchar, nword, yylineno);
    return 1;
}
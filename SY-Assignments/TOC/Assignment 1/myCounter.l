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
    return 1;
}
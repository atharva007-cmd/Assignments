%{
    // no declarations
%}


%%

[\t]+ ;     /* ignore whitespace */

is      |
am      |
are     |
were    |
was     |
be      |
being   |
been    |
do      |
does    |
did     |
will    |
would   |
should  |
can     |
could   |
has     |
have    |
had     |
go      { printf ("%s: verb\n", yytext); } /* recognize verbs */

very    |
shrPly  |
gently  |
quietly |
calmly  |
angrily { printf ("%s: adverb\n", yytext); } /* recognize adverb */

to      |
frcm    |
behind  |
above   |
between |
below   { printf ("%s: preposition\n", yytext); } /* recognize preposition */

if      |
then    |
and     |
but     |
or      { printf ("%s: conjunction\n", yytext); } /* recognize conjunction */

their   |
my      |
mine    |
your    |
his     |
her     { printf ("%s: adjective\n", yytext); } /* recognize adjective */

I       |
you     |
he      |
she     |
we      |
they    { printf ("%s: pronoun\n", yytext); } /* recognize pronoun */

[a-zA-Z]+   { printf ("%s: noun\n", yytext); } /* recognize noun */

.|\n        { ECHO; } /* normal default anyway */
%%

main () {
    yylex();
}
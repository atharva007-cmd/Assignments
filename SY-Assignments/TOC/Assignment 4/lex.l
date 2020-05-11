%{
    #include "y.tab.h"
%}


%%
\n return 0;

[ ]*static[ ]  return SCOPE;

[ ]*int[ ]  return DATA_TYPES;
[ ]*char[ ] return DATA_TYPES;
[ ]*float[ ]  return DATA_TYPES;
[ ]*String[ ]  return DATA_TYPES;
[ ]*bool[ ]  return DATA_TYPES;
[ ]*void[ ]  return DATA_TYPES;

"[" return O_Square_B;
"]" return C_Square_B;
"=" return EQUAL;
"," return COMMA;
";" return DELIMITER;

[a-zA-Z][_a-zA-Z0-9]* return id;
[0-9]+ return DIGIT;
%%

int yywrap (void)
{
    return 1;
}
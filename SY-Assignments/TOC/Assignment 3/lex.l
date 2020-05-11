%{
    enum LEXICAL_TOKENS{COMMENTS=1, ACCESS_SPECIFIERS, SEPERATORS, KEYWORDS, DELIMITER};
%}

%%
[ ]*public[ ]  return ACCESS_SPECIFIERS;
[ ]*private[ ]  return ACCESS_SPECIFIERS;
[ ]*protected[ ]  return ACCESS_SPECIFIERS;

[ ]*int[ ]  return KEYWORDS;
[ ]*float[ ]  return KEYWORDS;
[ ]*String[ ]  return KEYWORDS;
[ ]*bool[ ]  return KEYWORDS;
[ ]*void[ ]  return KEYWORDS;
[ ]*import[ ]  return KEYWORDS;
[ ]*class[ ]  return KEYWORDS;
[ ]*main[ ]  return KEYWORDS;
[ ]*static[ ]  return KEYWORDS;

["]+.*["]+     printf(" \"STRING\" ");

"("|")"|"{"|"}"|"["|"]" return SEPERATORS;
(,|:|".") return SEPERATORS;
";" return DELIMITER;

"/*" {
    char c;
    while(c=input() != '*');
    if (c=input() == '/')
    return COMMENTS;
}

"//" {
    char c;
    while (c=input() != '\n');
    return COMMENTS;
}

. ECHO;
%%

int yywrap (void)
{
    return 1;
}
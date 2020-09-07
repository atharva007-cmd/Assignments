%{
void yyerror (char* error);
int yylex();
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int symbols[52];
int getSymbolValue(char symbol);
void updateSymbolValue(char symbol, int value);
%}

%union			{int num; char id;}
%start			line
%token			print
%token			exit_command
%token <num> 	number
%token <id> 	identifier
%type <num> 	line exp term 
%type <id>		assignment

%%

line    : assignment ';'		{;}
		| exit_command ';'		{exit(EXIT_SUCCESS);}
		| print exp ';'			{printf("Printing %d\n", $2);}
		| line assignment ';'	{;}
		| line print exp ';'	{printf("Printing %d\n", $3);}
		| line exit_command ';'	{exit(EXIT_SUCCESS);}
        ;

assignment : identifier '=' exp  { updateSymbolValue($1,$3); }
			;
exp    	: term                  {$$ = $1;}
       	| exp '+' term          {$$ = $1 + $3;}
       	| exp '-' term          {$$ = $1 - $3;}
       	| exp '*' term          {$$ = $1 * $3;}
       	| exp '/' term          {$$ = $1 / $3;}
       	;
term   	: number                {$$ = $1;}
		| identifier			{$$ = getSymbolValue($1);} 
        ;

%%

int computeSymbolIndex(char token)
{
	int idx = -1;
	if(islower(token)) {
		idx = token - 'a' + 26;
	} else if(isupper(token)) {
		idx = token - 'A';
	}
	return idx;
} 

/* returns the value of a given symbol */
int getSymbolValue(char symbol)
{
	int bucket = computeSymbolIndex(symbol);
	return symbols[bucket];
}

/* updates the value of a given symbol */
void updateSymbolValue(char symbol, int value)
{
	int bucket = computeSymbolIndex(symbol);
	symbols[bucket] = value;
}

int main (void) {
	/* init symbol table */
	int i;
	for(i=0; i<52; i++) {
		symbols[i] = 0;
	}

	return yyparse ( );
}

void yyerror (char *error) {fprintf (stderr, "%s\n", error);} 

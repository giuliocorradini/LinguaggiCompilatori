%{
#include <iostream>
#include <list>
#include <string>
using namespace std;

list<string> files;
%}

DIG         [0-9]
DIG1        [1-9]
ID          [_[:alpha:]][_[:alnum:]]*
OPERATOR    "+"|"-"|"*"|"/"|"="

%%

OPERATOR                        { cout << "op <" << yytext[0] << ">" << endl; }
{DIG}+(\.{DIG}+)?               { cout << "num <" << yytext << ">" << endl; }
"("|")"                         { cout << yytext[0] << endl; }
def				{ cout << "function definition" << endl; }
extern				{ cout << "external symbol" << endl; }
ID                              { cout << "id <" << yytext << ">" << endl; }
.                               { cout << "altro operatore" << endl; }

int yyFlexLexer::wrap() {

	if (files.length() > 0) {
		this->sub
	}

	return 1;
}

%%

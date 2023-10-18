%{
#include <iostream>
using namespace std;

%}

WS          \s
DIG         [0-9]
DIG1        [1-9]
ID          (_|[:alpha:])[_[:alnum:]]*
OPERATOR    "+"|"-"|"*"|"/"|"="

%option noyywrap C++

%%

{WS}                            //ignore whitespaces
OPERATOR                        { cout << "op <" << yytext[0] << ">" << endl; }
{DIG}+(\.{DIG}+)?               { cout << "num <" << yytext << ">" << endl; }
"("|")"                         { cout << yytext[0] << endl; }
def				                { cout << "function definition" << endl; }
extern				            { cout << "external symbol" << endl; }
ID                              { cout << "id <" << yytext << ">" << endl; }
.                               { cout << "altro operatore" << endl; }

%%

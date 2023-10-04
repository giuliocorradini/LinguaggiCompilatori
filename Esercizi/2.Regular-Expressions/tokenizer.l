%{
#include <iostream>
using namespace std;
%}

DIG         [0-9]
DIG1        [1-9]
ID          [_[:alpha:]][_[:alnum:]]*
OPERATOR    "+"|"-"|"*"|"/"|"="

%option noyywrap C++

%%

OPERATOR                        { cout << "operatore <" << yytext[0] << ">" << endl; }
{DIG1}{DIG}*                    { cout << "numero <" << yytext << ">" << endl; }
"("|")"                         { cout << "parentesi <" << yytext[0] << ">" << endl; }
for                             { cout << "keyword for" << endl; }
ID                              { cout << "identificatore <" << yytext << ">" << endl; }
.                               { cout << "altro operatore" << endl; }

%%

int main(int argc, char **argv) {
    FlexLexer *lexer = new yyFlexLexer();
    lexer->yylex();
    return 0;
}

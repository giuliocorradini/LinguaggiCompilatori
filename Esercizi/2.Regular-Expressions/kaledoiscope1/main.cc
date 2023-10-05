#include <iostream>
#include <FlexLexer.h>
using namespace std;

int main(int argc, char **argv) {
    FlexLexer *lexer = new yyFlexLexer();
    lexer->yylex();
    return 0;
}

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <FlexLexer.h>
using namespace std;

int main(int argc, char **argv) {
    if(argc < 2) {
        cerr << "provide at least a source file" << endl;
        return -1;
    }

    FlexLexer *lexer = new yyFlexLexer();
    list<string> files;

    for(int i=1; i<argc; i++) {
        string filename(argv[i]);
        files.push_back(filename);
    }

    for(auto f: files) {
        cout << f << endl;

        ifstream *input = new ifstream(f);
        lexer->yylex(input);
        input->close();
        delete input;
    }

    delete lexer;
    
    return 0;
}

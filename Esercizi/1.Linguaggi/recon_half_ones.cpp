/**
 * Esercizi sui linguaggi formali
 * 
 * Riconoscitore di stringhe sull'alfabeto B in cui almeno la metà dei caratteri è 1 
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {

    if(argc < 2) {
        cerr << "Please provide an input string" << endl;
        return -1;
    }

    string input(argv[1]);

    int ones_counter = 0;
    for(auto tc = input.begin(); tc < input.end(); tc++) {
        if(*tc == '1')
            ones_counter++;
    }

    printf(ones_counter * 2 >= input.length() ? "true\n" : "false\n");
    
    return 0;
}

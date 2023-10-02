/**
 * Esercizi sui linguaggi formali
 * 
 * Riconoscitore di stringhe palindrome
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

    
    auto p1 = input.begin();
    auto p2 = input.end() - 1;

    bool palindrome = true;

    while(p1 < p2) {
        if (*p1 != *p2) {
            palindrome = false;
            break;
        }

        p1++;
        p2--;
    }

    printf(palindrome ? "true\n" : "false\n");
    
    return 0;
}
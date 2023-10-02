/**
 * Esercizi sui linguaggi formali
 * 
 * Riconoscitore di stringhe β su un qualsiasi alfabeto Σ tali che β = αα, per una qualche altra stringa α ∈ Σ
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {

    if(argc < 2) {
        cerr << "Please provide an input string" << endl;
        return -1;
    }

    string beta(argv[1]);

    if (beta.length() & 1) {
        printf("false\n");
        return -1;
    }

    auto p1 = beta.begin();
    auto p2 = beta.begin() + (beta.length() / 2);

    bool alpha_alpha = true;

    while(p2 < beta.end()) {
        if (*p1 != *p2) {
            alpha_alpha = false;
            break;
        }

        p1++;
        p2++;
    }

    printf(alpha_alpha ? "true\n" : "false\n");
    
    return 0;
}
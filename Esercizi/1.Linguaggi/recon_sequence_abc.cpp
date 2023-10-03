/**
 * Esercizi sui linguaggi formali
 * 
 * Riconoscitore di stringhe sull'alfabeto A = {a, b, c} della forma a^n b^n c^n, n ≥ 0;
*/

#include <iostream>
#include <string>

using namespace std;

enum state_t {
    INITIAL_STATE,
    ENCOUNTERED_A,
    ENCOUNTERED_B,
    ENCOUNTERED_C,
    INVALID
};

int main(int argc, const char * argv[]) {

    if(argc < 2) {
        cerr << "Please provide an input string" << endl;
        return -1;
    }

    string input(argv[1]);

    int na = 0;
    int nb = 0;
    int nc = 0;
    state_t state = INITIAL_STATE;

    for(auto tc = input.begin(); tc < input.end() && state != INVALID; tc++) {
        switch(state) {
            case INITIAL_STATE:
                if (*tc != 'a')
                    state = INVALID;
                else
                    na++;
                    state = ENCOUNTERED_A;
                break;

            case ENCOUNTERED_A:
                if (*tc == 'a')
                    na++;
                else if (*tc == 'b') {
                    nb++;
                    state = ENCOUNTERED_B;
                } else
                    state = INVALID;
                break;

            case ENCOUNTERED_B:
                if (*tc == 'b')
                    nb++;
                else if (*tc == 'c') {
                    nc++;
                    state = ENCOUNTERED_C;
                } else
                    state = INVALID;
                break;

            case ENCOUNTERED_C:
                if (*tc == 'c')
                    nc++;
                else
                    state = INVALID;
        }
    }

    if(state != INVALID && na == nb && nb == nc)
        printf("true\n");
    else
        printf("false\n");
    
    return 0;
}

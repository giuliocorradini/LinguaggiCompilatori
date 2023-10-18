/**
 * Scrivere un'e.r. per il linguaggio sull'alfabeto {a, b}, delle stringhe contenenti al più due a
*/

#include <iostream>
#include <string>
using namespace std;

enum state_t {
    EMPTY,
    ONE_A,
    TWO_A,
    MORE_THAN_TWO_A,
    INVALID_CHAR
};

int main(int argc, const char *argv[]) {
    if(argc < 2) {
        cerr << "Provide a string to analyze over the alphabet {a, b}" << endl;
        return -1;
    }

    string input(argv[1]);

    state_t engine_state = EMPTY;

    for(auto c=input.begin(); c < input.end(); c++) {
        switch(engine_state) {
            case EMPTY:
                if(*c == 'a')
                    engine_state = ONE_A;
                else if(*c != 'b')
                    engine_state = INVALID_CHAR;
                break;

            case ONE_A:
                if(*c == 'a')
                    engine_state = TWO_A;
                else if(*c != 'b')
                    engine_state = INVALID_CHAR;
                break;

            case TWO_A:
                if(*c == 'a')
                    engine_state = MORE_THAN_TWO_A;
                else if(*c != 'b')
                    engine_state = INVALID_CHAR;

            case MORE_THAN_TWO_A:
            case INVALID_CHAR:
                break;
        }
    }

    if(engine_state == MORE_THAN_TWO_A || engine_state == INVALID_CHAR)
        cout << "not valid" << endl;
    else
        cout << "valid" << endl;

    return 0;
}
/**
 * Scrivere un'e.r. per il linguaggio sull'alfabeto {a, b, c} così definito {a^n b^m c^k|m = 0 ⇒ k = 3}
*/

#include <iostream>
#include <string>
using namespace std;

enum state_t {
    A,  // < a^n    f.s.
    B,  // < b^m    f.s.
    C,  // < c^k    f.s.
    C1, // < branch taken when m=0
    C2,
    C3, // f.s.
    FAIL
};

int main(int argc, const char *argv[]) {
    if(argc < 2) {
        cerr << "Provide a string to analyze over the alphabet {a, b, c}" << endl;
        return -1;
    }

    string input(argv[1]);

    state_t engine_state = A;

    for(auto c=input.begin(); c < input.end(); c++) {
        char ch = toupper(*c);

        switch(engine_state) {
            case A:
                if(ch == 'B')
                    engine_state = B;
                else if(ch == 'C')
                    engine_state = C1;  //that means no B
                break;
            
            case B:
                if(ch == 'C')
                    engine_state = C;
                else if(ch != 'B')
                    engine_state = FAIL;
                break;

            case C:
                if(ch != 'C')
                    engine_state = FAIL;
                break;

            case C1:
                if(ch == 'C')
                    engine_state = C2;
                else
                    engine_state = FAIL;
                break;

            case C2:
                if(ch == 'C')
                    engine_state = C3;
                else
                    engine_state = FAIL;
                break;

            case C3:
                engine_state = FAIL;
                break;

            case FAIL:
                engine_state = FAIL;
                break;
        }
    }

    if(engine_state == A || engine_state == B || engine_state == C || engine_state == C3)
        cout << "valid" << endl;
    else
        cout << "not valid" << endl;

    return 0;
}
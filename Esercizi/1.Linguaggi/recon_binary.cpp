/**
 * Esercizi sui linguaggi formali
 * 
 * Riconoscitore di stringhe sull'alfabeto B, in cui ogni carattere 0 è seguito da un 1
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int state = 0;

    if(argc < 2) {
        cerr << "Please provide an input string" << endl;
        return -1;
    }

    string input(argv[1]);

    for(auto this_char = input.begin(); this_char < input.end(); this_char++) {
        switch(state) {
            case 0:
                if (*this_char == '0')
                    state = 1;
                break;
            case 1:
                if (*this_char == '1')
                    state = 0;
                else if (*this_char == '0')
                    state = 2;
                break;
            case 2:
                break;
        }
    }

    if(state == 0)
        printf("true\n");
    else
        printf("false\n");
    
    return 0;
}
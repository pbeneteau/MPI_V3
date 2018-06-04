#include <iostream>
#include <algorithm>
#include "Automate.h"

using namespace std;



// on note * les transitions epsilons

bool Automate::est_asynchrone() {
    t_tr temp;
    char    label;
    Etat*   source;
    Etat*   target;
    bool status(false);
    
    for(int unsigned i=0; i<_Etats.size(); i++) {
        temp = _Etats[i]->get_transition();
        for(int unsigned i=0; i<temp.size(); i++) {
            tie(source, label, target) = temp[i];
            if (label == '*') {
                
                status = true;
            }
        }
    }
    
    if (status)
        cout << "Cet automate est asynchrone ! " << endl;
    else
        cout << "Cet automate est synchrone ! " << endl;
    return (status);
}

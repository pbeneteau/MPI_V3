#include <iostream>
#include <algorithm>
#include "Automate.h"

using namespace std;

Automate::Automate() {
}

// on note * les transitions epsilons

bool Automate::est_asynchrone() {
    
    vector<string> row; // Žtats
    
    for(int unsigned i=0; i<_nb_etats; i++) {
        row = Ttable[i];
        
        for(int j=0; j<_nb_symboles; j++) {
            
            if(row[j+2].compare("*") > 0) {
                cout << "Cet automate est asynchrone" << endl;
                return true;
            }
        }
    }
    cout << "Cet automate est synchrone" << endl;
    return false;
}


bool Automate::est_deterministe()
{
    
    vector<string> row; // Žtats
    
    if(_nb_etats_initiaux != 1) {
        return true;
    }
    
    for(int unsigned i=0; i<Ttable.size(); i++) {
        
        row = Ttable[i];
        
        for(int j=0; j<_nb_symboles; j++) {
            
            string label = row[j+2];
            
            if(label.find(",") != string::npos) {
                return true;
            }
        }
    }
    return false;
}


bool Automate::est_complet()
{
    vector<string> row; // Žtats
    
    for(int unsigned i=0; i<Ttable.size(); i++) {
        
        row = Ttable[i];
        
        for(int j=0; j<_nb_symboles; j++) {
            
            string label = row[j+2];
            
            int count = 0;
            
            for (int n = 0; i < label.size(); n++)
                if (label[n] == ',') count++;
            
            if (count == _nb_symboles - 1) {
                return true;
            }
        }
    }
    return false;
}


void Automate::completion() {
    
    vector<string> row; // Žtats
    
    for(int unsigned i=0; i<Ttable.size(); i++) {
        
        row = Ttable[i];

        for(int j=0; j<_nb_symboles; j++) {
            
            string label = row[j+2];
            
            if(label.find("-") != string::npos) {
            }
        }
    }
    vector<string> row_P;
    
    row_P.push_back("N/A");
    row_P.push_back("P");
    
    for (int i = 0; i<_nb_symboles; i++) {
        row_P.push_back("P");
    }
}



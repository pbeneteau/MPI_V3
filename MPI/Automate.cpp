#include <iostream>
#include <algorithm>
#include "Automate.h"

using namespace std;

Automate::Automate() {
}

// on note * les transitions epsilons

bool Automate::est_un_automate_asynchrone() {
    
    vector<string> row; // Žtats
        
    for(int unsigned i=0; i<_nb_etats; i++) {
        row = Ttable[i];
        
        for(int j=0; j<_nb_symboles; j++) {
            
            if(row[j+2] == "*") {
                return true;
            }
        }
    }
    return false;
}


bool Automate::est_un_automate_deterministe()
{
    
    vector<string> row; // Žtats
    
    if(_nb_etats_initiaux != 1) {
        return false;
    }
    
    for(int unsigned i=0; i<Ttable.size(); i++) {
        
        row = Ttable[i];
        
        for(int j=0; j<_nb_symboles; j++) {
            
            string label = row[j+2];
            
            if(label.find(",") != string::npos) {
                return false;
            }
        }
    }
    return true;
}


bool Automate::est_un_automate_complet()
{
    vector<string> row; // Žtats
    
    for(int unsigned i=0; i<Ttable.size(); i++) {
        
        row = Ttable[i];
        
        for(int j=0; j<_nb_symboles; j++) {
            
            string label = row[j+2];
            
            int count = 0;
            
            for(auto c : label) {
                if (c == ',') count++;
            }
            
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
                Ttable[i][j+2] = "P";
            }
        }
    }
    vector<string> row_P;
    
    row_P.push_back("N/A");
    row_P.push_back("P");
    
    for (int i = 0; i<_nb_symboles; i++) {
        row_P.push_back("P");
    }
    Ttable.push_back(row_P);
}



void Automate::determination_et_completion_automate_synchrone() {
    
    vector<vector<string>> nouvel_automate;
    
    vector<int> etats_initiaux;
    
    vector<string> nouvel_etat_initial;

    
    for (int i=0; i<_nb_etats; i++) {
        
        if (Ttable[i][0] == "ES" || Ttable[i][0] == "E") {

            if (nouvel_etat_initial.empty()) {
                nouvel_etat_initial = Ttable[i];
            } else {
                nouvel_etat_initial[1] = nouvel_etat_initial[1] + "," + Ttable[i][1];
                
                for(int j=0; j<_nb_symboles; j++) {
                    nouvel_etat_initial[j+2] = nouvel_etat_initial[j+2] + "," + Ttable[i][j+2];
                }
            }
            if (Ttable[i][0] == "ES")
                nouvel_etat_initial[0] = "ES";
        }
    }

    for (int i = 0; i<nouvel_etat_initial.size(); i++) {
        cout << nouvel_etat_initial[i] << " ";
    }
}



void Automate::determination_et_completion_automate_asynchrone() {
    
}

void Automate::determination_et_completion() {
    
    if (est_un_automate_deterministe()) {
        cout << "Cet automate est deja deterministe !" << endl;
    } else {
        if (est_un_automate_asynchrone()) {
            determination_et_completion_automate_asynchrone();
        } else {
            determination_et_completion_automate_synchrone();
        }
    }
}



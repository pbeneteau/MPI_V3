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

void extractIntegerWords(string ligne, vector<string> &etats)
{
    size_t pos = ligne.find(",");
    size_t initialPos = 0;
    
    // Decompose statement
    while(pos != string::npos) {
        etats.push_back(ligne.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;
        pos = ligne.find(" ", initialPos);
    }
    // Add the last one
    //cout << "AL :" << ligne.substr(initialPos, min(pos, ligne.size()) - initialPos - 1).size() << endl;
    etats.push_back(ligne.substr(initialPos, min(pos, ligne.size()) - initialPos + 1));
    //EStab.push_back(ligne.substr(initialPos, ligne.size() - initialPos - 1)); //OUI ?
}

void Automate::fusion_etats_initiaux(vector<string> &nouvel_etat) {
    
    for (int i=0; i<_nb_etats; i++) {
        
        if (Ttable[i][0] == "ES" || Ttable[i][0] == "E") {
            
            if (nouvel_etat.empty()) {
                nouvel_etat = Ttable[i];
            } else {
                nouvel_etat[1] = nouvel_etat[1] + "," + Ttable[i][1];
                
                for(int j=2; j<_nb_symboles+2; j++) {
                    nouvel_etat[j] = nouvel_etat[j] + "," + Ttable[i][j];
                }
            }
            if (Ttable[i][0] == "ES")
                nouvel_etat[0] = "ES";
        }
    }
}


int Automate::trouver_index_etat(string etat) {
    
    for (int v = 0; v < Ttable.size(); v++) {
        
        if (Ttable[v][1] == etat) { // On cherche l'index v de l'Žtat
            
            return v;
        }
    }
    return 404;
}


void afficher_etat(vector<string> etat) {
    
    cout << "Etat " << etat[1] << " : " << endl;
    for (int i=0; i<etat.size(); i++) {
        cout << etat[i] << " ";
    }
    
    cout << "\n" << endl;
}

bool Automate::etat_est_connu(string etat, vector<vector<string>> nouvel_automate) {
    
    sort(etat.begin(), etat.end());
    
    for (int i=0; i<nouvel_automate.size(); i++) {
        
        sort(nouvel_automate[i][1].begin(), nouvel_automate[i][1].end());
        
        if (etat == nouvel_automate[i][1]) {
            
            return true;
        }
    }
    return false;
}

void Automate::fusion_etats(vector<vector<string>> &nouvel_automate, int &k) {
    
    vector<string> etat_precedent = nouvel_automate[k];
    vector<string> nouvel_etat;
    
    for (int i = 2; i<etat_precedent.size(); i++) { // On boucle dans les etats cible
        
        vector<string> etats; // etats a fusionner
        
        extractIntegerWords(etat_precedent[i], etats); // ex {2,5}
        
        if (etat_est_connu(etat_precedent[i], nouvel_automate) == false) {

            for (int j=0; j<etats.size(); j++) { // boucle dans {2,5}
                
                int index = trouver_index_etat(etats[j]);  // On cherche l'index v de l'Žtat
                
                if (nouvel_etat.empty()) {
                    nouvel_etat = Ttable[index];
                } else {
                    for(int n=1; n<_nb_symboles+2; n++) { // loop des symboles
                        if (nouvel_etat[0] == "N/A") { nouvel_etat[0] = Ttable[index][0]; }
                        if (Ttable[index][0] == "ES") { nouvel_etat[0] = Ttable[index][0]; }
                        
                        if (nouvel_etat[n] == "-" && Ttable[index][n] == "-") {
                            nouvel_etat[n] = "-";
                        } else if (nouvel_etat[n] == "-" && Ttable[index][n] != "-") {
                            nouvel_etat[n] = Ttable[index][n];
                        } else if (nouvel_etat[n] != "-" && Ttable[index][n] == "-") {
                        } else {
                            nouvel_etat[n] = nouvel_etat[n] + "," + Ttable[index][n];
                        }
                    }
                }
            }

            afficher_etat(nouvel_etat);
            nouvel_automate.push_back(nouvel_etat);
            nouvel_etat.clear();
        }
        k++;
    }
}

void Automate::determination_et_completion_automate_synchrone() {
    
    vector<vector<string>> nouvel_automate;
    
    vector<string> nouvel_etat;
    
    fusion_etats_initiaux(nouvel_etat);
    
    nouvel_automate.push_back(nouvel_etat); // ok
    
    int k = 0;
    
    while (k != nouvel_automate.size()) { // tant que determinisation possible
        
        cout << (k) << " vs " << nouvel_automate.size() << endl;
        
        fusion_etats(nouvel_automate, k);
        
        for(int k=0; k<nouvel_automate.size(); k++) {
            afficher_etat(nouvel_automate[k]);
        }
    }
    
    Ttable = nouvel_automate;
    
    if (!est_un_automate_complet()) {
        completion();
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



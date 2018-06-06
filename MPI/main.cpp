#include <iostream>
#include <cstdlib>
#include "Automate.h"

using namespace std;

/*
/Users/maxence/Documents/Prog/EFREI/MPI/MPI/MPI/automates/#03.txt
*/
int main()
{
	string chemin;
	Automate    AF;
	
	cout << "Siaisr le numero du fichier : ";
	chemin = "/Users/paulbeneteau/Documents/automates_copy/#05.txt";

	AF.lecture_fichier(chemin);
	cout << "Lecture du fichier : OK !" << endl;
	
	AF.afficher();
    
    
    if (AF.est_un_automate_deterministe()) { cout << "Deterministe" << endl; } else {
        cout << "Non deterministe" << endl;
    }
    if (AF.est_un_automate_asynchrone()) { cout << "Asynchrone" << endl; } else { cout << "Synchrone" << endl; }
    if (AF.est_un_automate_complet()) { cout << "Complet" << endl; } else {
        cout << "Non complet" << endl;
    }
    
    AF.determination_et_completion();
    
   
    
}

#include <iostream>
#include <cstdlib>
#include "Automate.h"

using namespace std;

/*
/Users/maxence/Documents/Prog/EFREI/MPI/MPI/MPI/automates/#03.txt
/Users/paulbeneteau/Documents/automates_copy/#05.txt
*/
int main()
{
	string chemin;
	string Anumber;
	int choix;
	
	Automate    AF;
	
	cout << "Siaisr le numero du fichier : ";
	cin >> Anumber;
	chemin = "#" + Anumber + ".txt";
	//chemin = "/Users/maxence/Documents/Prog/EFREI/MPI/MPI/MPI/automates/#03.txt";
	
	AF.lecture_fichier(chemin);
	cout << "Lecture du fichier : OK !" << endl;
	
	do {
		cout << "Choix d'action :" << endl;
		cout << "1 : Afficher AF" << endl;
		cout << "2 : Tester si AF est synchrone" << endl;
		cout << "3 : Déterminisation et complétion AF synchrone" << endl;
		cout << "4 : Tester si AF est déterministe" << endl;
		cout << "5 : Tester si AF est déterministe complet" << endl;
		cout << "6 : Complétion d’un AF déterministe" << endl;
		cout << "7 : Production de l’AFDC pour le langage complémentaire" << endl;
		cout << "8 : Standardisation" << endl;
		cout << "9 : Quitter" << endl;
		
		cout << "Numero du choix ?" << endl;
		cin >> choix;
		
		if (choix == 1) {
			AF.afficher();
		}
		else if (choix ==  2) {
			if (AF.est_un_automate_asynchrone())
				cout << "Cet automate est asynchrone" << endl;
			else
				cout << "Cet automate n'est pas asynchrone" << endl;
		}
		else if (choix == 3) {
			if (AF.est_un_automate_complet())
				cout << "Cet automate est complet" << endl;
			else
				cout << "Cet automate n'est pas complet" << endl;
		}
		else if (choix == 4) {
			if (AF.est_un_automate_deterministe())
				cout << "Cet automate est deterministe" << endl;
			else
				cout << "Cet automate n'est pas deterministe" << endl;
		}
		else if (choix == 5) {
			if (AF.est_un_automate_deterministe())
				cout << "Cet automate est deterministe" << endl;
			else
				cout << "Cet automate n'est pas deterministe" << endl;
			if (AF.est_un_automate_complet())
				cout << "Cet automate est complet" << endl;
			else
				cout << "Cet automate n'est pas complet" << endl;
		}
		else if (choix == 6) {
			AF.completion();
		}
		else if (choix == 7) {
			AF.langage_compl();
		}
		else if (choix == 8) {
			AF.standardiser_automate();
		}
		else if (choix == 9) {
			exit(1);
		}
		
	} while (1);
}

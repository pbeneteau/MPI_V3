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
	
	cout << "Siaisr le numero du fichier : " << endl;
	cin >> chemin;

	AF.lecture_fichier(chemin);
	cout << "Lecture du fichier : OK !" << endl;
}

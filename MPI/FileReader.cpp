//
//  FileReader.cpp
//  MPI
//
//  Created by Maxence on 04/06/2018.
//  Copyright © 2018 Maxence. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <cstdlib>
#include "FileReader.hpp"
#include "Automate.h"

using namespace std;

void    Automate::lecture_fichier(string chemin)
{
	string      line;
	
	ifstream file(chemin, ios::in); // Ouverture du fichier en lecture
	if (!file)
	{
		cout << "Erreur lors de la lecture du fichier ! Le ficher n'existe pas." << endl;
		file.close();
		exit(1);
	}
	cout << "Lecture du fichier " << chemin << " en cours !" << endl;
	/*
	 **  Definiton des symboles
	 */
	if (!getline(file, line))
	{
		cout << "Erreur lors de la lecture du fichier ! " << endl;
		exit(1);
	}
	set_nb_symboles(line);
	if (_nb_symboles < 1 || _nb_symboles > 26)
	{
		cout << "Erreur dans le nombre de symboles" << endl;
		exit(1);
	}
	/*
	 **  Definiton des etats
	 */
	if (!getline(file, line))
	{
		cout << "Erreur lors de la lecture du fichier ! " << endl;
		exit(1);
	}
	set_nb_etats(line);
	if (_nb_etats == 0)
	{
		cout << "0 etats dans le fichier" << endl;
		exit(1);
	}
	/*
	 **  Definiton des etats initiaux
	 */
	if (getline(file, line) && line.find_first_not_of("0123456789") != string::npos)
		set_etats_initiaux(line);
	else
	{
		cout << "Pas d'etat initiaux" << endl;
		exit(1);
	}
	/*
	 **  Definiton des etats terminaux
	 */
	if (getline(file, line) && line.find_first_not_of("0123456789") != string::npos)
		set_etats_terminaux(line);
	else
	{
		cout << "Pas d'etat initiaux" << endl;
		exit(1);
	}
	/*
	 **  Definiton du nombre de transitions
	 */
	if (!getline(file, line))
	{
		cout << "Erreur lors de la lecture du file ! " << endl;
		exit(1);
	}
	set_nb_transitions(line);
	if (_nb_transitions == 0)
	{
		cout << "0 transitions dans le file" << endl;
		exit(1);
	}

	while (getline(file, line))
	{
		set_Ttable(line);
	}
}

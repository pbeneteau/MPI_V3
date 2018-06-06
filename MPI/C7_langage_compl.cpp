//
//  langage_compl.cpp
//  MPI
//
//  Created by Maxence on 06/06/2018.
//  Copyright © 2018 Maxence. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <cstdlib>
#include "C7_Automate.h"

using namespace std;


void	Automate::langage_compl()
{
	completion(); //On commence par completer
	
	for (int i=0; i<Ttable.size(); i++) //A travers la table de transition on inverse les etats terminaux et non T
	{
		if (Ttable[i][0] == "S")
			Ttable[i][0] = "N/A";
		else if (Ttable[i][0] == "ES")
			Ttable[i][0] = "E";
		else if (Ttable[i][0] == "N/A")
			Ttable[i][0] = "S";
		else if (Ttable[i][0] == "E")
			Ttable[i][0] = "ES";
	}
}

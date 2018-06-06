//
//  standardisation.cpp
//  MPI
//
//  Created by Maxence on 06/06/2018.
//  Copyright © 2018 Maxence. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <cstdlib>
#include "Automate.h"

using namespace std;

void	Automate::standardiser_automate()
{
	vector<string> Ei;
	bool isS = false;
	
	for (int i=0; i<Ttable.size(); i++) //On lit la table de transition
	{
		if ((Ttable[i][0] == "E" || Ttable[i][0] == "ES") && Ttable[i][1] != "i") //Si on est sur une entrée
		{
			//On modifie pour que ce ne soit plus une entree
			if (Ttable[i][0] == "E")
				Ttable[i][0] = "N/A";
			else if (Ttable[i][0] == "ES") {
				Ttable[i][0] = "S";
				isS = true;
			}
			
			Ei = Ttable[i];
			if (isS == true)
				Ei[0] = "ES";
			else
				Ei[0] = "E";
			Ei[1] = "i";
			
			//On crée et ajoute le nouvel état i
			if (Ttable.back()[1] == "i")
			{
				Ttable.back()[0] = Ei[0];
				for (int j=2; j<Ei.size(); j++) {
					if (Ttable.back()[j] == "-")
						Ttable.back()[j] = Ei[j];
					else
						Ttable.back()[j] += "," + Ei[j];
				}
			}
			else
				Ttable.push_back(Ei);
		}
	}
}

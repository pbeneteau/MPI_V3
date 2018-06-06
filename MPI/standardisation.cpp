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
	
	for (int i=0; i<Ttable.size(); i++)
	{
		if (Ttable[i][0] == "E" || Ttable[i][0] == "ES")
		{
			if (Ttable[i][0] == "E")
				Ttable[i][0] = "N/A";
			else if (Ttable[i][0] == "ES") {
				Ttable[i][0] = "S";
				isS = true;
			}
			
			Ei = Ttable[i];
			
		}
	}
}

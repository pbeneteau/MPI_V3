#include <iostream>
#include <algorithm>
#include "Automate.h"

using namespace std;

void	Automate::initTtable()
{	
	for(int i = 0; i < _nb_etats; i++)
	{
		vector<string> row;
		
		row.push_back("N/A"); //type
		row.push_back("N/A"); // nom
		
		for(int j = 0; j < _nb_symboles; j++)
		{
			row.push_back("-");
		}
		
		Ttable.push_back(row);
	}
}


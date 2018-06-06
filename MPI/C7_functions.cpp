#include <iostream>
#include <cstdlib>
#include "C7_Automate.h"

void    Automate::set_nb_symboles(string ligne)
{
	_nb_symboles = atoi(ligne.c_str());
}

void    Automate::set_nb_etats(string ligne)
{
	_nb_etats = atoi(ligne.c_str());
}

void    Automate::set_nb_transitions(string ligne)
{
	_nb_transitions = atoi(ligne.c_str());
}

void    Automate::set_etats_initiaux(string ligne)
{
	handle_ES(ligne, E);
	_nb_etats_initiaux = atoi(E[0].c_str());
}

void    Automate::set_etats_terminaux(string ligne)
{
	handle_ES(ligne, S);
	_nb_etats_terminaux = atoi(S[0].c_str());
}

void	Automate::handle_ES(string ligne, vector<string> &EStab)
{
	size_t pos = ligne.find(" ");
	size_t initialPos = 0;
	
	// Decompose statement
	while(pos != string::npos) {
		EStab.push_back(ligne.substr(initialPos, pos - initialPos));
		initialPos = pos + 1;
		pos = ligne.find(" ", initialPos);
	}
	EStab.push_back(ligne.substr(initialPos, min(pos, ligne.size()) - initialPos - 1));
}

void 	Automate::afficher() {
	
	cout << "Automate : " << endl;
	
	cout << "Nombre de symboles : " << _nb_symboles << endl;
	cout << "Nombre d'etats : " << _nb_etats << endl;
	cout << "Nombre de transitions : " << _nb_transitions << endl;
	cout << "Nombre d'etats initiaux : " << _nb_etats_initiaux << endl;
	cout << "Liste des etats initiaux E : ";
	for (int i = 1; i < E.size(); i++)
	{
		cout << E[i] << endl;
	}
	cout << "Nombre d'etats terminaux : " << _nb_etats_terminaux << endl;
	cout << "Liste des etats terminaux S : ";
	for (int i = 1; i < S.size(); i++)
	{
		cout << S[i] << " ";
	}
	cout << endl;
	cout << "Table de verite : " << endl;
	
	cout << endl;
	cout << "................. ";
	for (int jsp=0; jsp<labelOrder.size(); jsp++)
		cout << labelOrder[jsp] << " ..... ";
	cout << endl;
	cout << endl;
	for (int i = 0; i < Ttable.size(); i++)
	{
		for (int j = 0; j < Ttable[i].size(); j++)
		{
			cout << Ttable[i][j];
			cout << " ..... ";
		}
		cout << endl;
	}
}

void	Automate::set_Ttable(string line)
{
	//oui
	
	string src = "";
	string label = "";
	string dest = "";
	bool isDest = false;
	
	int labelPos;
	
	for(auto c:line)
	{
		if(isdigit(c) && isDest == false)
			src.push_back(c);
		else if(isalpha(c))
		{
			isDest = true;
			label.push_back(c);
		}
		else if (isdigit(c))
			dest.push_back(c);
	}
	
	if(find(labelOrder.begin(), labelOrder.end(), label) != labelOrder.end()) {
		/* v contains x */
	} else {
		/* v does not contain x */
		labelOrder.push_back(label);
	}
	labelPos = (int)(find(labelOrder.begin(), labelOrder.end(), label) - labelOrder.begin());
	
	// si src existe déja, on rajoute juste une nouvelle dest
	
	bool alreadyInSrc = false;
	for (int i = 0; i < Ttable.size(); i++)
	{
		if (Ttable[i][1] == src) {
			alreadyInSrc = true;
			if (Ttable[i][labelPos+2] == "-")
				Ttable[i][labelPos+2] = dest;
			else
				Ttable[i][labelPos+2] += "," + dest;
			break;
		}
	}
	//sinon
	if (alreadyInSrc == false) {
		vector<string> row;
		
		row.push_back("N/A"); //type
		row.push_back(src); // nom
		
		for(int j = 0; j < _nb_symboles; j++)
		{
			if (j == labelPos)
				row.push_back(dest);
			else
				row.push_back("-");
		}
		Ttable.push_back(row);
	}
	
	bool alreadyInDest = false;
	for (int i = 0; i < Ttable.size(); i++)
	{
		if (Ttable[i][1] == dest)
			alreadyInDest = true;
	}
	
	if (alreadyInDest == false) {
		vector<string> row;
		
		row.push_back("N/A"); //type
		row.push_back(dest); // nom
		
		for(int j = 0; j < _nb_symboles; j++)
		{
			row.push_back("-");
		}
		Ttable.push_back(row);
	}
}

void	Automate::set_ES()
{
	bool isE = false;
	bool isS = false;

	for (int i = 0; i < Ttable.size(); i++)
	{
		for (int j = 1; j < max(E.size(), S.size()); j++)
		{
			if (j < E.size() && Ttable[i][1] == E[j])
				isE = true;
			if (j < S.size() && Ttable[i][1] == S[j])
				isS = true;

			if (isE == true && isS == true)
				Ttable[i][0] = "ES";
			if (isE == true)
				Ttable[i][0] = "E";
			if (isS == true)
				Ttable[i][0] = "S";
			isS = false;
			isE = false;
		}
	}
}

#ifndef MPI_AUTOMATE_H
#define MPI_AUTOMATE_H

using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

class Automate
{
    
    private :
    int             _nb_symboles;
    int             _nb_etats;
	int             _nb_transitions;
	int				_nb_etats_initiaux;
	int 			_nb_etats_terminaux;
	string			initiaux;
	string			terminaux;
	
	vector<vector<string>>	Ttable;
	vector<string>			labelOrder;
	vector<string>			E;
	vector<string>			S;
	
    public :
    void            lecture_fichier(string chemin);
    void            afficher();
	
	
	bool			est_un_automate_asynchrone();
	bool			est_un_automate_deterministe();
	bool			est_un_automate_complet();
	void			completion();
    
    void            determination_et_completion();
    void            determination_et_completion_automate_asynchrone();
	void            determination_et_completion_automate_synchrone();
    
    void            fusion_etats_initiaux(vector<string> &nouvel_etat);
    void            fusion_etats(vector<vector<string>> &nouvel_automate, int n);
    /*
     **  GETTEURS & SETTEURS
     */
	
    Automate();
	
	void			initTtable();
	void			set_Ttable(string line);
	
    void            set_nb_symboles(std::string ligne);
    void            set_nb_etats(string ligne);
    void            set_nb_transitions(string ligne);
    void            set_etats_initiaux(string ligne);
    void            set_etats_terminaux(string ligne);
	void			handle_ES(string ligne, vector<string> &ES);
	void			set_ES();
	
	void			handle_initiaux(string ligne);
	void			handle_terminaux(string ligne);
    string          handle_comma(string &line);
	
};

#endif //MPI_Automate_H

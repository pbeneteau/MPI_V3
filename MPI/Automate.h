#ifndef MPI_AUTOMATE_H
#define MPI_AUTOMATE_H

using namespace std;
#include <string>
#include <vector>


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
	
	vector<vector<string>> Ttable;
	vector<string> labelOrder;
	
    public :
    void            lecture_fichier(string chemin);
    void            afficher();
	
	
	bool			est_asynchrone();
	bool			est_deterministe();
	bool			est_complet();
	void			completion();
	
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
	
};

#endif //MPI_Automate_H

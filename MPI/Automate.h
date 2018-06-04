#ifndef MPI_AUTOMATE_H
#define MPI_AUTOMATE_H

#include "Etat.h"
using namespace std;
#include <string>
#include <vector>


class Automate
{
    
    private :
    int             _nb_symboles;
    int             _nb_etats;
    int             _nb_etats_initiaux;
    int             _nb_etats_finaux;
    int             _nb_transitions;
    
    std::vector<Etat*> _Etats;
    std::vector<Etat*> _Etats_initiaux;
    std::vector<Etat*> _Etats_terminaux;
    public :
    void            lecture_fichier(char *chemin);
    void            afficher();
    /*
     **  GETTEURS & SETTEURS
     */
    Automate();
    Automate(int nb_etats);
    void            set_nb_symboles(std::string ligne);
    void            set_nb_etats(string ligne);
    void            set_nb_transitions(string ligne);
    void            set_etats(string ligne);
    void            set_etat(Etat *new_Etat);
    void            set_etats_initiaux(string ligne);
    void            set_etats_terminaux(string ligne);
    void            set_transitions(string ligne);
    int             get_nb_etats();
    Etat*           get_etat(int id);
    Etat*           get_etat_determinsite(string nom_deterministe);
    void            set_transition_etat(int id, Etat *source, char mid, Etat *dest);
    bool            is_unique(string comp);
    void            remove_doublon(string &content);
    void            update_deterministe(vector<Etat*> old_terminaux);
    /*
     **  ANALYSE
     */
    bool est_asynchrone();
    bool            est_un_automate_deterministe();
    bool            est_un_automate_complet();
    void            completion();
    void            determinisation_et_completion_automate_synchrone();
    Automate        determinisation_et_completion_automate_asynchrone();
};

#endif //MPI_Automate_H

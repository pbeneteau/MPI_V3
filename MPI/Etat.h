//
// Created by anton on 14/05/2018.
//

#ifndef MPI_ETAT_H
#define MPI_ETAT_H
#include <vector>
#include <tuple>



class Etat
{
private :
    int _id;
    std::string _nom_determinisation;
    std::vector<std::tuple<Etat*, char, Etat*>> _transitions;

public :
    
    Etat(int _id);
    int get_id();
    void set_id(int id);

    void increment_transition();
    void afficher();
    void set_transition(Etat* source, const char *mid, Etat* dest);
    void set_nom_determinisation(std::string nom_etat);
    std::string get_nom_determinisation();
    std::vector<std::tuple<Etat*, char, Etat*>> get_transition();

};
typedef std::vector<std::tuple<Etat*,  char, Etat*>> t_tr;

#endif //MPI_ETAT_H

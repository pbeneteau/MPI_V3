#include <iostream>
#include <cstring>
#include "Etat.h"

using namespace std;

Etat::Etat(int id) : _id(id)
{

}

void    Etat::afficher()
{
    Etat *start;
    char    mid;
    Etat*   end;

    cout << endl << "========" << endl;
    cout << "Etat : " << _id << endl;
    cout << "Transitions sortantes : " << endl;
    if (_nom_determinisation.size())
    {
        cout << "Nom determinisation " << _nom_determinisation << endl;
        for(int unsigned i=0;i<_transitions.size();i++)
        {
            tie(start, mid, end) = _transitions[i];
            if(end->get_id() == -1 && start->get_id() == -1)
                cout << "   poubelle" << "-" << mid << "-poubelle" << endl;
            else if(end->get_id() == -1)
                cout << "   "<< start->get_nom_determinisation() << "-" << mid << "-poubelle" << endl;
            else if(start->get_id() == -1)
                cout << "   poubelle"<< start->get_nom_determinisation() << "-" << mid << "-" << end->get_nom_determinisation() << endl;
            else
                cout << "   "<< start->get_nom_determinisation() << "-" << mid << "-" << end->get_nom_determinisation() << endl;
        }
    }

    else
    {
        for(int unsigned i=0;i<_transitions.size();i++)
        {
            tie(start, mid, end) = _transitions[i];
            if(end->get_id() == -1 && start->get_id() == -1)
                cout << "   poubelle" << "-" << mid << "-poubelle" << endl;
            else if(end->get_id() == -1)
                cout << "   "<< start->get_id() << "-" << mid << "-poubelle" << endl;
            else if(start->get_id() == -1)
                cout << "   poubelle"<< start->get_id() << "-" << mid << "-" << end->get_id() << endl;
            else
                cout << "   "<< start->get_id() << "-" << mid << "-" << end->get_id() << endl;
        }
    }
    cout << "========" << endl;
}

int Etat::get_id()
{
    return (_id);
}

void Etat::set_id(int id)
{
    _id = id;
}

void Etat::set_nom_determinisation(string nom_etat)
{
    _nom_determinisation = nom_etat;
}

t_tr    Etat::get_transition()
{
    return (_transitions);
}

void    Etat::set_transition(Etat* source, const char *mid, Etat* dest)
{
    char test(mid[0]);

    if (isdigit(test))
    {
        cout << "Erreur lors de la lecture du fichier (mid != alphabet) \n" << endl;
        exit(1);
    }
    auto nouvelle_transition = std::make_tuple(source, test, dest);
    _transitions.push_back(nouvelle_transition);
}

string  Etat::get_nom_determinisation()
{
    return (_nom_determinisation);
}

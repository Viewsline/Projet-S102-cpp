#ifndef TUILE_H
#define TUILE_H

#include <string>

using namespace std;

class Tuile {
    private:
        //Q.2
        string _nom;
        int _x, _y;
        string _propriete;
    public:
        Tuile(string, int, int, string); // initaliser la tuile
        Tuile();

        void afficher() const;

        string getName() const; // ça c'est juste pour la recherche dans le Dictionnaire
        int getX() const; // le reste n'est pas nécessaire mais bon
        int getY() const;
        string getPropriety() const;

};

#endif
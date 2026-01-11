#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#include <vector>

#include "Tuile.h"

using namespace std;

class Dictionnaire {
private:
    // contient vecteur d'objets Tuile lus
    vector<Tuile> _tuiles;
public:
    Dictionnaire(const string& nomFichier); // va lire le fichier
    void afficher() const; //Q.5
    bool recherche(const string& nomCible, Tuile& tuile) const; //Q.7
};

#endif // DICTIONNAIRE_H
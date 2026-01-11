#include <iostream>

#include "Tuile.h"

using namespace std;

Tuile::Tuile(string nom, int x, int y, string propriete) {
    _nom = nom;
    _x = x;
    _y = y;
    _propriete = propriete;
} // initaliser la tuile

Tuile::Tuile() {}

void Tuile::afficher() const {
    // c'est plus joli et lisible
    // d'écrire comme ça
    cout << _nom << ": "
    << "x=" << _x << ", "
    << "y=" << _y << ", "
    << "objet " << _propriete
    << endl;
}

string Tuile::getName() const {
    return _nom;
}

int Tuile::getX() const {
    return _x;
}

int Tuile::getY() const {
    return _y;
}

string Tuile::getPropriety() const {
    return _propriete;
}
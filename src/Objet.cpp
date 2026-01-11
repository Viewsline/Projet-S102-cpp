#include "Objet.h"


Objet::Objet(const Image& img, const string& nom, const Dictionnaire& dictionnaire, int x, int y) {
    _x = x;
    _y = y;
    _img = img;
    dictionnaire.recherche(nom,_tuile);
};

void Objet::dessiner() const {
    _img.dessiner(_x, _y, _tuile.getX() * TAILLE_CASE, _tuile.getY() * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
}

bool Objet::estSolide() const {
    return (_tuile.getPropriety() == "solide");
}

int Objet::getX() const {
    return _x;
}

int Objet::getY() const {
    return _y;
}
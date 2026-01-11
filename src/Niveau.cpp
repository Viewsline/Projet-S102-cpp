#include "Niveau.h"
#include "Tuile.h"

Niveau::Niveau(Image img, const string &nomfichier, const Dictionnaire &dictionnaire) {
    ifstream fichier(nomfichier);
    int objetListe;
    fichier >> objetListe;
    for (int i = 0; i < objetListe; i++) {
        string nomObjet;
        int caseX, caseY;
        fichier >> nomObjet >> caseX >> caseY;
        int posX = caseX * TAILLE_CASE;
        int posY = caseY * TAILLE_CASE;

        _objets.push_back(Objet(img, nomObjet, dictionnaire, posX, posY));
    }
}

void Niveau::dessiner() const {
    for (int i = 0; i < _objets.size(); i++) {
        _objets[i].dessiner();
    }
}

bool Niveau::caseEstLibre(int x, int y) const {
    for (int i = 0; i < _objets.size(); i++) {
        if (_objets[i].estSolide()) {
            if (_objets[i].getX()==x && _objets[i].getY()==y) {
                return false;
            }
        }
    }
    return true;
}

#include <fstream>

#include "Dictionnaire.h"

Dictionnaire::Dictionnaire(const string& nomFichier) {
    int nbElements;

    string nom, propriete;
    int x, y;
    /// parcours du fichier (code extrait du TP3 - ClassePromotion)
    ifstream ific(nomFichier, ios::in); /// ouvrir le fichier en lecture
    if(!ific.is_open())   /// si pb ouverture
        throw string ("l'ouverture du fichier a echoue : " + nomFichier);
    ific >> nbElements; /// 1Ëre info lue est le nombre d'éléments
    while(!ific.eof()) /// tant qu'on n'a pas atteint la  fin du fichier
    {
        ific >> nom;
        ific >> x >> y;
        ific >> propriete;
        _tuiles.push_back(Tuile(nom, x, y, propriete));
    }
    ific.close(); /// fermer le fichier
}

void Dictionnaire::afficher() const {
    for (int i = 0; i < _tuiles.size(); i++) {
        _tuiles[i].afficher();
    }
}

bool Dictionnaire::recherche(const string& nomCible, Tuile& tuile) const {
    int debut = 0, millieu;
    int fin = _tuiles.size()-1;
    bool trouve = false;

    // recherche dichotomique
    while(!trouve && debut <= fin) {
        millieu = (debut+fin)/2;
        trouve = _tuiles[millieu].getName() == nomCible;
        
        if (_tuiles[millieu].getName() < nomCible) {
            debut = millieu+1;
        } else {
            fin = millieu-1;
        }
    }

    // on va quand même passer la tuile même
    // si elle n'était pas trouvée
    // il ne reste qu'à vérifier si
    // valeur bool est true
    tuile = _tuiles[millieu];

    return trouve;

}
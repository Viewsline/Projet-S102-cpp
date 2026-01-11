//
// Created by charl on 11/01/2026.
//

#ifndef NIVEAU_H
#define NIVEAU_H
#include <vector>
#include <fstream>
#include "Objet.h"
using namespace std;

class Niveau {
private:
    vector<Objet> _objets;
public:
    Niveau(Image img, const string& nomfichier, const Dictionnaire& dictionnaire);
    void dessiner() const;
    bool caseEstLibre(int x, int y) const;
};


#endif //NIVEAU_H
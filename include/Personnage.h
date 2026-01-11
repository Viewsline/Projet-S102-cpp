#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include "Image.h"

enum Direction { HAUT, DROITE, BAS, GAUCHE };

class Personnage {
private:
    int _x;
    int _y;
    Image _img;
    int _dirc;
    int _skin_x;
    int _skin_y;
public:
    Personnage(int x, int y, Image img, int dircourante, int skin_x, int skin_y);
    Personnage();
    void dessiner() const;
    void regarderGauche();
    void regarderDroite();
    void regarderHaut();
    void regarderBas();

};


#endif // PERSONNAGE_H_INCLUDED

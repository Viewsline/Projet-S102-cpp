#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include "Image.h"

enum Direction { HAUT, DROITE, BAS, GAUCHE };
enum Personnages {NU, HOMME, FEMME, SQUELETTE, BLOB, BAT, FANTOME, SPIDER};

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
    void deplacer(int dx, int dy);

};

class Avatar {
private :
    Personnage _perso;

public :
    Avatar(int x, int y, Image img, int dircourante, int skin_x, int skin_y);

    void dessiner() const;
    void allerDroite();
    void allerGauche();
    void allerBas();
    void allerHaut();
};

class Ennemi {
private :
    Personnage _perso;

public :
    Ennemi(int x, int y, Image img, int dircourante, int skin_x, int skin_y);

    void dessiner() const;
};

#endif // PERSONNAGE_H_INCLUDED

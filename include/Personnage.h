#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include "Image.h"
#include "Niveau.h"

enum Direction { HAUT, DROITE, BAS, GAUCHE };
enum Personnages {NU, HOMME, FEMME, SQUELETTE, BLOB, BAT, FANTOME, SPIDER};

class Personnage {
private:
    int _x;
    int _y;
    Image _img;
    Direction _dirc;
    int _skin_x;
    int _skin_y;
public:
    Personnage(int x, int y, const Image& img, const Direction& dircourante, int skin_x, int skin_y);
    Personnage();
    void dessiner() const;
    void regarderGauche();
    void regarderDroite();
    void regarderHaut();
    void regarderBas();
    void deplacer(int dx, int dy);

    //Q.23
    Direction getDirection() const;
    void inverserDirection();
    //Q.25
    int getX() const;
    int getY() const;

    bool peutBougerVers(const Direction& dir, const Niveau& niveau) const; //Q.20

};

class Ennemi {
private :
    Personnage _perso;

public :
    Ennemi(int x, int y, const Image& img, const Direction& dircourante, int skin_x, int skin_y);

    void dessiner() const;
    void avancer(const Niveau& niveau);

    Personnage getPersonnage() const; // Pour pouvoir accéder aux attributs de l'exterieur (Q.25)
};

class Avatar {
private :
    Personnage _perso;

public :
    Avatar(int x, int y, const Image& img, const Direction& dircourante, int skin_x, int skin_y);

    void dessiner() const;
    void allerDroite(const Niveau& niveau);
    void allerGauche(const Niveau& niveau);
    void allerBas(const Niveau& niveau);
    void allerHaut(const Niveau& niveau);

    bool touche(const Ennemi& ennemi) const; //Q.25

};



#endif // PERSONNAGE_H_INCLUDED

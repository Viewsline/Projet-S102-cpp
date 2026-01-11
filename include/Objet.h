#ifndef OBJET_H
#define OBJET_H
#include "Image.h"
#include "Dictionnaire.h"
#include "Tuile.h"

class Objet {
private :
    int _x;
    int _y;
    Image _img;
    Tuile _tuile;
public :
    Objet( const Image& img, const string& nom, const Dictionnaire& dictionnaire, int x, int y);
    void dessiner() const;
    bool estSolide() const;
    int getX() const;
    int getY() const;
};

#endif // OBJET_H

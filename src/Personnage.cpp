#include "Personnage.h"

Personnage::Personnage(int x, int y, Image image, int dircourante, int skin_x, int skin_y){
    _x = x;
    _y = y;
    _img = image;
    _dirc = dircourante;
    _skin_x = skin_x;
    _skin_y = skin_y;
}

Personnage::Personnage(){
    _x = 0;
    _y = 0;
    _img = Image();
    _dirc = 1;
    _skin_x = 0;
    _skin_y = 0;
}

void Personnage::dessiner() const{
    switch (_dirc){
        case HAUT :
            _img.dessiner(_x, _y, _skin_x * TAILLE_CASE, _skin_y * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
            //on est cense utiliser les variable skin pour faire un cas general et aussi (_skin_x+1,skin_y+2)
            break;
        case DROITE :
            _img.dessiner(_x, _y, 4 * TAILLE_CASE, 2 * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
            break;
        case BAS :
            _img.dessiner(_x, _y, 4 * TAILLE_CASE, 0 * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
            break;
        case GAUCHE :
            _img.dessiner(_x, _y, 4 * TAILLE_CASE, 1 * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
            break;
        default :
            _img.dessiner(_x, _y, 4 * TAILLE_CASE, 3 * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
    }
}

void Personnage::regarderHaut() {
    _dirc = HAUT ;//1;
}

void Personnage::regarderDroite() {
    _dirc = DROITE;
}

void Personnage::regarderBas() {
    _dirc = BAS;
}

void Personnage::regarderGauche() {
    _dirc = GAUCHE;
}

//fgrefzr


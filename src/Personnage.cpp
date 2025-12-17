#include "Personnage.h"

Personnage::Personnage(int x, int y, Image image, int dircourante, int skin_x, int skin_y){
    _x = x * TAILLE_CASE;
    _y = y * TAILLE_CASE;
    _img = image;
    _dirc = dircourante;
    _skin_x = (skin_x *3)+1;
    _skin_y = (skin_y * 4);
}

Personnage::Personnage(){
    _x = 0;
    _y = 0;
    _img = Image();
    _dirc = 1;
}

void Personnage::dessiner() const{
    switch (_dirc){
        case HAUT :
            _img.dessiner(_x, _y, (_skin_x) * TAILLE_CASE, (_skin_y+3) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
            //on est cense utiliser les variable skin pour faire un cas general et aussi (_skin_x+1,skin_y+2)
            break;
        case DROITE :
            _img.dessiner(_x, _y, (_skin_x) * TAILLE_CASE, (_skin_y+2) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
            break;
        case BAS :
            _img.dessiner(_x, _y, (_skin_x) * TAILLE_CASE, _skin_y * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
            break;
        case GAUCHE :
            _img.dessiner(_x, _y, (_skin_x) * TAILLE_CASE, (_skin_y+1) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
            break;
        default :
            _img.dessiner(_x, _y, (_skin_x) * TAILLE_CASE, _skin_y * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
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

void Personnage::deplacer(int dx, int dy){
    _x += dx;
    _y += dy;
}

Avatar::Avatar(int x, int y, Image img, int dircourante, int skin_x, int skin_y){
    _perso=Personnage(x, y, img, dircourante, skin_x, skin_y);

}

void Avatar::dessiner() const {
    _perso.dessiner();
}

void Avatar::allerDroite(){
    //d'abord regarder dans quelle direction il se tourne puis en fonctions du cas (a l'aide d'un case)
    //il va se deplacer sur l'axe des x ou des y et faire -1 ou +1
}

void Avatar::allerBas(){

}

void Avatar::allerGauche(){

}

void Avatar::allerHaut(){

}

Ennemi::Ennemi(int x, int y, Image img, int dircourante, int skin_x, int skin_y){
    _perso=Personnage(x, y, img, dircourante, skin_x, skin_y);
    }

void Ennemi::dessiner() const {
    _perso.dessiner();
}





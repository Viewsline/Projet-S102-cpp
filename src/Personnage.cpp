#include "Personnage.h"

Personnage::Personnage(int x, int y, const Image& image, const Direction& dircourante, int skin_x, int skin_y){
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
    _dirc = BAS;
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

bool Personnage::peutBougerVers(const Direction& direction, const Niveau &niveau) const {
    if (direction == DROITE && _x < LARGEUR_FENETRE - TAILLE_CASE && niveau.caseEstLibre(_x + TAILLE_CASE, _y)) {
        return true;
    }

    if (direction == GAUCHE && _x > 0 && niveau.caseEstLibre(_x - TAILLE_CASE, _y)) {
        return true;
    }

    if (direction == BAS && _y < HAUTEUR_FENETRE - TAILLE_CASE && niveau.caseEstLibre(_x, _y + TAILLE_CASE)) {
        return true;
    }

    if (direction == HAUT && _y > 0 && niveau.caseEstLibre(_x, _y - TAILLE_CASE)) {
        return true;
    }

    return false;
}

Direction Personnage::getDirection() const {
    return _dirc;
}
void Personnage::inverserDirection() {
    switch (_dirc) {
        case DROITE:
            _dirc = GAUCHE;
            break;
        case GAUCHE:
            _dirc = DROITE;
            break;
        case HAUT:
            _dirc = BAS;
            break;
        case BAS:
            _dirc = HAUT;
    }
}

int Personnage::getX() const {
    return _x;
}

int Personnage::getY() const {
    return _y;
}

Avatar::Avatar(int x, int y, const Image& img, const Direction& dircourante, int skin_x, int skin_y){
    _perso=Personnage(x, y, img, dircourante, skin_x, skin_y);
}

void Avatar::dessiner() const {
    _perso.dessiner();
}

void Avatar::allerDroite(const Niveau& niveau){
    //d'abord regarder dans quelle direction il se tourne puis en fonctions du cas (a l'aide d'un case)
    //il va se deplacer sur l'axe des x ou des y et faire -1 ou +1
    _perso.regarderDroite();

    // vérifions s'il peut bouger à droite, il a droit de regarder dans cette direction
    if (!_perso.peutBougerVers(DROITE, niveau)) return;

    // une case fait TAILLE_CASE pixels
    _perso.deplacer(1*TAILLE_CASE, 0);
}

void Avatar::allerBas(const Niveau& niveau){
    _perso.regarderBas();

    if (!_perso.peutBougerVers(BAS, niveau)) return;

    // une case fait TAILLE_CASE pixels
    _perso.deplacer(0, 1*TAILLE_CASE);
}

void Avatar::allerGauche(const Niveau& niveau){
    _perso.regarderGauche();

    if (!_perso.peutBougerVers(GAUCHE, niveau)) return;
    // une case fait TAILLE_CASE pixels
    _perso.deplacer(-1*TAILLE_CASE, 0);
}

void Avatar::allerHaut(const Niveau& niveau){
    _perso.regarderHaut();

    if (!_perso.peutBougerVers(HAUT, niveau)) return;
    // une case fait TAILLE_CASE pixels
    _perso.deplacer(0, -1*TAILLE_CASE);
}

bool Avatar::touche(const Ennemi& e) const {
    //Comparons les coordonnées avec ennemi
    return _perso.getX() == e.getPersonnage().getX()
    && _perso.getY() == e.getPersonnage().getY();
}

Ennemi::Ennemi(int x, int y, const Image& img, const Direction& dircourante, int skin_x, int skin_y){
    _perso=Personnage(x, y, img, dircourante, skin_x, skin_y);
}

void Ennemi::dessiner() const {
    _perso.dessiner();
}

void Ennemi::avancer(const Niveau& niveau) {
    // On inverse la direction dès que l'ennemi ne peut plus avancer
    // dans sa direction.
    if (!_perso.peutBougerVers(_perso.getDirection(),niveau)) {
        _perso.inverserDirection();
    }

    // On fait bouger l'ennemi
    switch (_perso.getDirection()) {
        case DROITE:
            _perso.regarderDroite();
            _perso.deplacer(1*TAILLE_CASE, 0);
        break;
        case GAUCHE:
            _perso.regarderGauche();
            _perso.deplacer(-1*TAILLE_CASE, 0);
        break;
        case HAUT:
            _perso.regarderHaut();
            _perso.deplacer(0, -1*TAILLE_CASE);
        break;
        case BAS:
            _perso.regarderBas();
            _perso.deplacer(0, 1*TAILLE_CASE);
        break;
    }
}

Personnage Ennemi::getPersonnage() const {
    return _perso;
}

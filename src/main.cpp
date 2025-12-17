#include <vector>

#include "Moteur.h"
#include "Image.h"
#include "Personnage.h"

using namespace std;

int main(int, char**) // Version special du main, ne pas modifier
{
  // Initialisation du jeu
  Moteur moteur("Mon super jeu vidéo");

  // TODO: charger images, creer personnages, etc.
  Image background(moteur,"./assets/fond.png");
  Image coffre_ferme(moteur,"./assets/coffre_ferme.png");
  Image coffre_ouvert(moteur,"./assets/coffre_ouvert.png");
  Image personnage_simple(moteur,"assets/personnages.png");

  Avatar chevalier(0,0, personnage_simple,4, 1, 0);
  Ennemi squelette(5,0, personnage_simple,4, 3, 0);
  Ennemi spider(0,5, personnage_simple,4, 3, 1);

  bool coffre_etat = false; // false si coffre ferme et true si coffre ouvert
  bool quitter = false;
  int x = 0;
  int y = 0;

  // Boucle de jeu, appelee a chaque fois que l'ecran doit etre mis a jour
  // (en general, 60 fois par seconde)
  while (!quitter)
  {
    // I. Gestion des evenements
    Evenement evenement = moteur.evenementRecu();
    while (evenement != AUCUN)
    {
      switch (evenement)
      {
        // QUITTER = croix de la fenetre ou Echap
        case QUITTER_APPUYE:
          quitter = true;
          break;
        /*case ESPACE_APPUYE:
            // coffre_etat = true;
            break;
        case ESPACE_RELACHE:
            coffre_etat = false;
            break;*/
        case BAS_APPUYE:
            //chevalier.regarderBas();
            break;
        case HAUT_APPUYE:
            //chevalier.regarderHaut();
            break;
        case DROITE_APPUYE:
            //chevalier.regarderDroite();
            break;
        case GAUCHE_APPUYE:
            //chevalier.regarderGauche();
            break;

        // TODO: gerer les autres evenements
        default:
          break;
      }

      evenement = moteur.evenementRecu();
    }

    // II. Mise à jour de l'état du jeu

    // TODO: faire bouger vos personnages, etc.

    // III. Generation de l'image à afficher

    moteur.initialiserRendu(); // efface ce qui avait ete affiche precedemment et reinitalise en ecran noir

    // TODO: afficher vos personnages, objets, etc.
    background.dessiner(0,0);
    /*if (coffre_etat){
        coffre_ouvert.dessiner(x,y++);
    }else{
        coffre_ferme.dessiner(x,y++);
    }*/

    chevalier.dessiner();
    squelette.dessiner();
    spider.dessiner();

    /*if (y==120){       // quest 9 pas fini
        while (y!=0){  // car litteralement il fait la meme chose que la question 8 a cause de la boucle while
            y--;
        }
    }*/

    /*if (y>=120 ){ // le coffre bouge et réapparait en haut du plateau dès qu'il touche le bas du plateau
        y=0;
    }*/

    /*coffre_ferme.dessiner(2,5);  -> en faisant ca le coffre se decale de 2 PIXELs SUR LA DROITE
     ET DE 5 pixels en bas et la partie prise en compte pour le
     placement est le coin en haut a gauche de l'image*/


    /*
      Affiche l'image en se cadencant sur la frequence de
      rafraichissement de l'ecran (donc va en general mettre le
      programme en pause jusqu'a ce que l'ecran soit rafraichi). En
      general, 60 images fois par seconde, mais ca peut dependre du
      materiel
    */
    moteur.finaliserRendu();
  }

  return 0;
}

#include <vector>

#include "Moteur.h"
#include "Image.h"
#include "Personnage.h"
#include "Dictionnaire.h"
#include "Niveau.h"

using namespace std;

void tests() { // Test des cas de recherche du Q.7
  Dictionnaire dict("./assets/dictionnaire.txt");
  bool ok;
  Tuile cible;
  ok = dict.recherche("Arbre_1", cible);

  if (!ok) {
    cout << "Erreur: Arbre_1 existe, alors que l'algo dit le contraire" << endl;
    return;
  }
  cout << "Test Arbre_1 PASSÉ" << endl;
  cible.afficher();

  ok = dict.recherche("Blahblahblah", cible);

  if (ok) {
    cout << "Erreur: Blahblahblah n'existe pas, alors que l'algo dit le contraire" << endl;
    return;
  }
  cout << "Test Blahblahblah PASSÉ" << endl;

}

// Q.8
/*
Le nom de l'algo de recherche est une recherche dichotomique
*/

int main(int, char**) // Version special du main, ne pas modifier
{

  tests();

  // Initialisation du jeu
  Moteur moteur("Mon super jeu vidéo", 4); //Q.24

  // TODO: charger images, creer personnages, etc.
  Image background(moteur,"./assets/fond.png");
  Image coffre_ferme(moteur,"./assets/coffre_ferme.png");
  Image coffre_ouvert(moteur,"./assets/coffre_ouvert.png");
  Image personnage_simple(moteur,"./assets/personnages.png");
  Image imgObjets(moteur, "./assets/objets.png");

  Avatar chevalier(1,1, personnage_simple,BAS, 1, 0);
  Ennemi squelette(5,2, personnage_simple, DROITE, 3, 0);
  Ennemi spider(8,5, personnage_simple,HAUT, 3, 1);

  Dictionnaire dict("./assets/dictionnaire.txt");
  Niveau niveau(imgObjets, "assets/niveau.txt", dict);

  dict.afficher();

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
            chevalier.allerBas(niveau);
            //chevalier.regarderBas();
            break;
        case HAUT_APPUYE:
            chevalier.allerHaut(niveau);
            //chevalier.regarderHaut();
            break;
        case DROITE_APPUYE:
            chevalier.allerDroite(niveau);
            //chevalier.regarderDroite();
            break;
        case GAUCHE_APPUYE:
            chevalier.allerGauche(niveau);
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
    niveau.dessiner();
    /*if (coffre_etat){
        coffre_ouvert.dessiner(x,y++);
    }else{
        coffre_ferme.dessiner(x,y++);
    }*/

    //Q.24
    if (moteur.animationsAmettreAjour()) {
      squelette.avancer(niveau);
      spider.avancer(niveau);
    }

    if (chevalier.touche(squelette) || chevalier.touche(spider)) {
      //C'est perdu, Q.25
      quitter = true;
    }

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

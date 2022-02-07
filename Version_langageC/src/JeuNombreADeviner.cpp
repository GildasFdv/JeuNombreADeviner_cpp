/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud, Gildas FEDEVIEILLE
// Date de création : 21/01/2022
// Rôle du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              stdio
//                              ctime, cstdlib
// Historique du fichier:
//24/01/22 Gildas FEDEVIEILLE --> codage de la fonction jouerPartie et demander_nombre, ajout des commentaires
//26/01/22 Gildas FEDEVIEILLE --> ajout de la fonction changerCouleur
//27/01/22 Gildas FEDEVIEILLE --> modification de la fonction jouerPartie ( passage d'un joueur en paramètre )
//29/01/22 Gildas FEDEVIEILLE --> modification de la fonction jouerPartie ( passage de la sortie en paramètre pour pouvoir modifier les couleurs à l'intérieur )
//31/01/22 Gildas FEDEVIEILLE --> adaptation du code et des commentaires
/*************************************************/
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include "../include/JeuNombreAdeviner.h"
#include <windows.h>




// Nom :tirerNombreMystere
// Rôle : Tire aléatoirement un nombre à deviner entre nbMin et nbMAx
// Paramètres d'entrée: nbMin, nbMAx : limites du nombre à deviner
// Valeur de retour : nombre à deviner
int tirerNombreMystere(int nbMin, int nbMax)
{

    int nb = 0; // Nombre aleatoire

    // Initialisation du générateur aléatoire avec l'heure
    // pour obtenir une série de nombres differents à chaque execution
    srand((int)time(NULL));

    nb = rand()%(nbMax - nbMin+1) + nbMin; // compris entre nbMin et nbMax inclus

    return nb;
}


// Nom : jouerPartie
// Rôle : Fait jouer une partie à un joueur
// Paramètres d'entrée/sortie : un joueur et une partie
// Paramètres d'entrée: aucun
// Paramètres de sortie: aucun
// Valeur de retour : aucune
void jouerPartie(HANDLE h,TJoueur* joueur,TPartie* partie)
{
    int entree ;
    partie->nb_tentative_utilise = 0;

    int nb_a_deviner = tirerNombreMystere(partie->min,partie->max);

    joueur->nb_partie++;

    printf("C'est \x85 %s de jouer\n", joueur->prenom);

    do{
        partie->nb_tentative_utilise++;
        printf("Essai num\x82ro : %d\n",partie->nb_tentative_utilise );
        entree = demander_nombre(partie->min,partie->max);

        if (entree < nb_a_deviner)
        {
            changerCouleur(h,BLUE,LIGHTGRAY);
            printf("C'est plus !\n");
            changerCouleur(h,LIGHTGRAY,BLACK);
        }
        else if(entree > nb_a_deviner)
        {
            changerCouleur(h,BLUE,LIGHTGRAY);
            printf("C'est moins !\n");
            changerCouleur(h,LIGHTGRAY,BLACK);
        }
    }while(entree != nb_a_deviner && partie->nb_tentative_utilise < partie->nb_tentative_max );

    joueur->nb_tentative += partie->nb_tentative_utilise;

    if (entree == nb_a_deviner)
    {
        changerCouleur(h,GREEN,BLACK);
        
        changerCouleur(h,LIGHTGRAY,BLACK);
        joueur->nb_partie_gagne++;
        partie->etat_partie = GAGNE;
    }
    else
    {
        partie->etat_partie = PERDU;
    }
}

// Nom : demander_nombre
// Rôle : Faire saisir un nombre à l'utilisateur en s'assurant que ce nombre est bien compris entre le minimum et le maximum
//Paramètres d'entrée/sortie : 
// Paramètres d'entrée: le minimum et maximum du nombre qui peut etre saisi l'utilisateur 
// Paramètres de sortie: aucun
// Valeur de retour : le nombre saisi par l'utilisateur 
int demander_nombre(int min, int max)
{
    int reponse;
    int i = 0;
    do{
        if (i > 0)
        {
            printf("Erreur ! Votre num\x82ro doit \x88tre compris entre %d et %d\n",min,max);
        }
        printf("Saisir un num\x82ro:");
        scanf("%d",&reponse);
        i++;
    }while(reponse < min || reponse > max);

    return reponse;
}


// Nom : changerCouleur
// Rôle : changer la couleur d'écriture à l'écran
//Paramètres d'entrée/sortie : la sortie
// Paramètres d'entrée: la couleur à définir pour le texte et celle pour l'écran
// Paramètres de sortie: 
// Valeur de retour : aucune
void changerCouleur(HANDLE h, int texte,int fond)
{
    SetConsoleTextAttribute(h,fond*16+texte);
}

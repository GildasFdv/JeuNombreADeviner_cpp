/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud, Gildas FEDEVIEILLE
// Date de création : 21/01/2022
// Rôle du fichier: Contient le code jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              stdio.h
// Historique du fichier:
//24/01/22 Gildas FEDEVIEILLE --> codage du main 
//26/01/22 Gildas FEDEVIEILLE --> codage du main 
//27/01/22 Gildas FEDEVIEILLE --> adaptation du main par rapport au changement de la fonction jouerPartie
//29/01/22 Gildas FEDEVIEILLE --> adaptation du main par rapport au changement de la fonction jouerPartie
//29/01/22 Gildas FEDEVIEILLE --> adaptation du main par rapport au changement de la fonction jouerPartie et de la nouvelle structure TPartie
/*************************************************/

#include <stdio.h>
#include <windows.h>
#include "../include/JeuNombreADeviner.h"

int main()
{

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    int continuer = 1;

    char nom_joueur1[25];
    char nom_joueur2[25];

    TJoueur joueur1={"un",0,0,0};
    TJoueur joueur2={"un",0,0,0};

    printf("Saisir le nom du joueur 1 : ");
    scanf("%s", &joueur1.prenom);
    printf("Saisir le nom du joueur 2 : ");
    scanf("%s", &joueur2.prenom);

    TPartie partie = {joueur1,0,10,4,0,PERDU};

    while(continuer == 1)
    {

        changerCouleur(h,BLACK,LIGHTGRAY);

        printf ("%s\n", "_______________Vous allez jouer pour deviner un nombre secret_________________");

        printf("_______________________________La partie commence_____________________________\n");

        printf("Vous avez 4 essais chacun pour deviner le nombre myst\x8Are compris entre 0 et 10\n\n\n");

        changerCouleur(h,LIGHTGRAY,BLACK);

        /*___________________Premier joueur____________________*/

        partie.nb_tentative_utilise = 0;
        jouerPartie(h,&joueur2,&partie);
        /*printf("C'est gagn\x82 ! Vous avez utilis\x82 %d essais\n\n\n", partie->nb_tentative_utilise);
        printf("C'est perdu !\n\n\n");*/

        if (partie.etat_partie == GAGNE)
        {
            changerCouleur(h,GREEN,BLACK);
            printf("C'est gagn\x82 ! Vous avez utilis\x82 %d essais\n\n\n", partie.nb_tentative_utilise);
            changerCouleur(h,LIGHTGRAY,BLACK);
        }
        else
        {
            changerCouleur(h,RED,BLACK);
            printf("C'est perdu !\n\n\n");
            changerCouleur(h,LIGHTGRAY,BLACK);
        }

        /*___________________Deuxieme joueur____________________*/

        partie.nb_tentative_utilise = 0;
        jouerPartie(h,&joueur1,&partie);
        if (partie.etat_partie == GAGNE)
        {
            changerCouleur(h,GREEN,BLACK);
            printf("C'est gagn\x82 ! Vous avez utilis\x82 %d essais\n\n\n", partie.nb_tentative_utilise);
            changerCouleur(h,LIGHTGRAY,BLACK);
        }
        else
        {
            changerCouleur(h,RED,BLACK);
            printf("C'est perdu !\n\n\n");
            changerCouleur(h,LIGHTGRAY,BLACK);
        }

        printf("Voulez vous rejouer ? Oui : 1 / Non : 0\n");
        continuer = demander_nombre(0,1);
        
    }

    joueur1.nb_moyen_tentative = joueur1.nb_tentative/joueur1.nb_partie;

    joueur2.nb_moyen_tentative = joueur2.nb_tentative/joueur2.nb_partie;

    printf("\n\n\n");

    changerCouleur(h,BLACK,LIGHTGRAY);

    if (joueur2.nb_partie_gagne > joueur1.nb_partie_gagne)
    {
        printf("%s a gagn\x82 !", joueur2.prenom);
    }
    else if (joueur1.nb_partie_gagne > joueur2.nb_partie_gagne)
    {
        printf("%s a gagn\x82 !", joueur1.prenom);
    }
    else
    {
        if (joueur1.nb_tentative > joueur2.nb_tentative)
        {
            printf("%s a gagn\x82 !", joueur2.prenom);
        }
        else if (joueur1.nb_tentative < joueur2.nb_tentative)
        {
            printf("%s a gagn\x82 !", joueur1.prenom);
        }
        else
        {
            printf("Vous etes ex aequo\n");
        }
    }
    changerCouleur(h,LIGHTGRAY,BLACK);

    


    return 0;
}


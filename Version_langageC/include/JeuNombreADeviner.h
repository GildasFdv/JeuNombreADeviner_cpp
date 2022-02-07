/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: JeuNombreADeviner.h
// Version : 1.0
// Nom du programmeur: MP Pinaud, Gildas FEDEVIEILLE
// Date de création : 21/01/2022
// Rôle du fichier: Contient la déclaration des fonctions concernant le jeu
// Nom des composants utilises:
// Historique du fichier: 
//24/01/22 Gildas FEDEVIEILLE --> ajout des commentaires
//26/01/22 Gildas FEDEVIEILLE --> ajout des commentaires
//29/01/22 Gildas FEDEVIEILLE --> adaptation des déclaration en fonction des changement apporté à la fonciton jouerPartie
//31/01/22 Gildas FEDEVIEILLE --> ajout des structures TVictoire et TPartie et adaptation des commentaires
/*************************************************/
#include <windows.h>

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

typedef enum TVictoire
{
	PERDU,
	GAGNE
}TVictoire;

typedef struct TJoueur
{
	char prenom[25];
	int nb_partie_gagne;
	int nb_tentative;
	int nb_partie;
	float nb_moyen_tentative;
}TJoueur;


typedef struct TPartie
{
	TJoueur joueur;
	int min;
	int max;
	int nb_tentative_max;
	int nb_tentative_utilise;
	TVictoire etat_partie;
} TPartie; 

// Nom :tirerNombreMystere
// Rôle : Tire aléatoirement un nombre à deviner entre nbMin et nbMAx
// Paramètres d'entrée: nbMin, nbMAx : limites du nombre à deviner
// Valeur de retour : nombre à deviner
int tirerNombreMystere(int nbMin, int nbMax);

// Nom : jouerPartie
// Rôle : Fait jouer une partie à un joueur
// Paramètres d'entrée/sortie : un joueur et une partie
// Paramètres d'entrée: aucun
// Paramètres de sortie: aucun
// Valeur de retour : aucune
void jouerPartie(HANDLE h,TJoueur* joueur,TPartie* partie);

// Nom : demander_nombre
// Rôle : Faire saisir un nombre à l'utilisateur en s'assurant que ce nombre est bien compris entre le minimum et le maximum
//Paramètres d'entrée/sortie : 
// Paramètres d'entrée: le minimum et maximum du nombre qui peut etre saisi l'utilisateur 
// Paramètres de sortie: aucun
// Valeur de retour : le nombre saisi par l'utilisateur 
int demander_nombre(int min, int max);


// Nom : changerCouleur
// Rôle : changer la couleur d'écriture à l'écran
//Paramètres d'entrée/sortie : la sortie
// Paramètres d'entrée: la couleur à définir pour le texte et celle pour l'écran
// Paramètres de sortie: 
// Valeur de retour : aucune
void changerCouleur(HANDLE h, int texte,int fond);


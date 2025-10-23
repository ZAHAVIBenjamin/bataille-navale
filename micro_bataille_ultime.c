#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE 8
#define BATEAU_PORTE_AVIONS 5
#define BATEAU_SOUS_MARIN 4
#define BATEAU_CROISER 3 
#define BATEAU_TORPILLEUR 2 
#define NB_BATEAUX 14
#define MER 0
#define BATEAU 1
#define MANQUE 2
#define TOUCHE 3
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// il y a 3 valeurs possible a une case.
//  . : eau (case vide ou alors un bateau caché) -- O : raté -- X : touché.

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                // Fonction generer un nombre aleatoir valeurMax
int NBalea(int max)
{
  return rand() % (max);
} 
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                // Fonction print une ligne
void printligne(int nbLigne)
{
    for (int i = 0; i < nbLigne; i++)
    {
        for (int i = 0; i < 250; i++)
        {
            printf("-");
        }
        printf("\n");
    }
}  
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                // Fonction print qui saut nbligne
void sautDeLigne(int nbSaut)
{
    for (int i = 0; i < nbSaut; i++)
    {
    
        printf("\n");
    }
}  
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                // Fonction choix fin de partie
int choixFinDePartie()
{
        sautDeLigne(1);
        printligne(2);
        sautDeLigne(1);
        printf("\033[32;01m                           Choississez une option :\n\n\n\n                                                                   1 : Retour au menu .                                                                   2 : Quitter le programme .    \033[00m\n");
        sautDeLigne(1);
        int choix;
        scanf("%d", &choix); 
        if (choix == 1)
        {
            return 1;
        }
        else if (choix != 1)
        {
            return 0;
        }
}
// ----------------------------------------------------------------------------------------------------------------------
                                                // fonction : remplie une grille de taille "axeX" * "axeY" avec la valeur "valeur".
void initialiser_grille(int grille[TAILLE][TAILLE])
{
    
    for (int i = 0; i < TAILLE; i=i+1)
    {
        for (int j = 0; j < TAILLE; j=j+1)
        {
            grille[i][j] = 0;
        }
    }
}
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                // fonction : affichage de la grille bateau cacher.
void printgrilleCache(int grille[TAILLE][TAILLE])
{
    int valeurTabH = 0;
    int valeurTabV = 0;
    printf("\033[32;01m                                                HAUT\n\033[00m");
    printf("\033[32;01m|X Y|\033[00m");
    for (int i = 0; i < TAILLE; i++)
    {
        printf("\033[32;01m| %d |\033[00m", valeurTabH);
        valeurTabH = valeurTabH + 1;
    }
    printf("\n");   
    for (int i = 0; i < TAILLE; i=i+1)
    {   
        printf("\033[32;01m| %d |\033[00m", valeurTabV);
        valeurTabV = valeurTabV + 1;  
        for (int j = 0; j < TAILLE; j=j+1)
        {        
            
            if (grille[i][j]== MER)
            {
                printf("\033[34;01m| . |\033[00m");
            }
            else if (grille[i][j]== BATEAU)
            {
                printf("\033[34;01m| . |\033[00m"); 
            }
            else if (grille[i][j]== MANQUE)
            {
                printf("\033[32;01m| O |\033[00m"); 
            }
            else if (grille[i][j]== TOUCHE)
            {
                printf("\033[31;01m| X |\033[00m"); 
            }
            
        }
        printf("\n");
    }
    printf("\033[32;01m                                                BAS\n\033[00m");
}
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                // fonction : affichage de la grille bateau a decouvert.
void printgrilleDec(int grille[TAILLE][TAILLE])
{
    int valeurTabH = 0;
    int valeurTabV = 0;
    printf("\033[32;01m                                                HAUT\n\033[00m");
    printf("\033[32;01m|X Y|\033[00m");
    for (int i = 0; i < TAILLE; i++)
    {
        printf("\033[32;01m| %d |\033[00m", valeurTabH);
        valeurTabH = valeurTabH + 1;
    }
    printf("\n");   
    for (int i = 0; i < TAILLE; i=i+1)
    {   
        printf("\033[32;01m| %d |\033[00m", valeurTabV);
        valeurTabV = valeurTabV + 1;  
        for (int j = 0; j < TAILLE; j=j+1)
        {        
            
            if (grille[i][j]== MER)
            {
                printf("\033[34;01m| . |\033[00m");
            }
            else if (grille[i][j]== BATEAU)
            {
                printf("\033[33;01m| B |\033[00m"); 
            }
            else if (grille[i][j]== MANQUE)
            {
                printf("\033[32;01m| O ||\033[00m"); 
            }
            else if (grille[i][j]== TOUCHE)
            {
                printf("\033[31;01m| X ||\033[00m"); 
            }
            
        }
        printf("\n");
    }
    printf("\033[32;01m                                                BAS\n\033[00m");
}
// ----------------------------------------------------------------------------------------------------------------------------------------------------------
                                                // Fonction verfier si on peu poser le bateau retourne 1 si non retourne 0
int verifier_place_bateau(int grille[TAILLE][TAILLE], int taille, int x , int y, int direction)
{
    int nbBat = 0;
    while (nbBat != 1)
    {
        if (direction == 1)
        {             
            for (int i = 0; i < taille; i++)
            {
                if (grille[x][y] == 0 && x >= 0 && x < TAILLE && y >= 0 && y < TAILLE)
                {             
                    y = y + 1;    
                }
                else if (grille[x][y] != 0 || x < 0 || x >= TAILLE || y < 0 || y >= TAILLE)
                {   
                    printf("place insuffisante ou hors limite\n");
                    return 0;
                }
            }
            nbBat = nbBat + 1;
            return 1;
        }         
        if (direction == 2)
        {
            for (int i = 0; i < taille; i++)
            {
                if (grille[x][y] == 0 && x >= 0 && x < TAILLE && y >= 0 && y < TAILLE)
                {             
                    y = y - 1;
                }
                else if (grille[x][y] != 0 || x < 0 || x >= TAILLE || y < 0 || y >= TAILLE)
                {   
                    printf("place insuffisante ou hors limite\n");
                    return 0;
                }
            }
            nbBat = nbBat + 1;
            return 1;
        }         
        if (direction == 3)
        {
            for (int i = 0; i < taille; i++)
            {
                if (grille[x][y] == 0 && x >= 0 && x < TAILLE && y >= 0 && y < TAILLE)
                {             
                    x = x - 1;

                }
                else if (grille[x][y] != 0 || x < 0 || x >= TAILLE || y < 0 || y >= TAILLE)
                {   
                    printf("place insuffisante ou hors limite\n");
                    return 0;
                }
                }
                nbBat = nbBat + 1;
                return 1;
           }

        if (direction == 4)
        {
            for (int i = 0; i < taille; i++)
            {
                if (grille[x][y] == 0 && x >= 0 && x < TAILLE && y >= 0 && y < TAILLE)
                {             
                    x = x + 1;

                }
                else if (grille[x][y] != 0 || x < 0 || x >= TAILLE || y < 0 || y >= TAILLE)
                {   
                    printf("place insuffisante ou hors limite\n");
                    return 0;
                }
            }
            nbBat = nbBat + 1;
            return 1;
        }
    }
}
// ----------------------------------------------------------------------------------------------------------------------------------------------------------
                                                // Fonction poser bateau apres verification
void pose_le_bateau(int grille[TAILLE][TAILLE], int taille, int x, int y,int direction)
{
    if (direction == 1)
    {         
       for (int i = 0; i < taille; i++)
        {          
            grille[x][y] = 1;             
            y = y + 1;     
        }
    }  
    if (direction == 2)
    { 
        for (int i = 0; i < taille; i++)
        {
            grille[x][y] = 1;             
            y = y - 1;    
        }
    }  
    if (direction == 3)
    {            
        for (int i = 0; i < taille; i++)
        {          
            grille[x][y] = 1;             
            x = x - 1;   
        }
    }
    if (direction == 4)
    {               
        for (int i = 0; i < taille; i++)
        {          
            grille[x][y] = 1;             
            x = x + 1;
        }
    }
}
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                // fonction : placer les bateaux sur la grille automatiquement pour l'ordinateur.

void placer_bateaux_Ia(int grille[TAILLE][TAILLE])
{   
    int x, y, nbBat, result;
    nbBat = 0;
    
    while (nbBat != 4)
    {
        while (nbBat != 1)
        {
            int x = NBalea(TAILLE);
            int y = NBalea(TAILLE);
            int direction = NBalea(4)+1;
            result = verifier_place_bateau(grille, BATEAU_PORTE_AVIONS, x, y, direction);
            if (result == 1)
            {
                pose_le_bateau(grille, BATEAU_PORTE_AVIONS, x, y, direction);
                nbBat = nbBat + 1;
            }  
        }
        
        while (nbBat != 2)
        {
            int x = NBalea(TAILLE);
            int y = NBalea(TAILLE);
            int direction = NBalea(4)+1;
            result = verifier_place_bateau(grille, BATEAU_SOUS_MARIN, x, y, direction);
            if (result == 1)
            {
                pose_le_bateau(grille, BATEAU_SOUS_MARIN, x, y, direction);
                nbBat = nbBat + 1;
            }  
        }
        while (nbBat != 3)
        {
            int x = NBalea(TAILLE);
            int y = NBalea(TAILLE);
            int direction = NBalea(4)+1;
            result = verifier_place_bateau(grille, BATEAU_CROISER, x, y, direction);
            if (result == 1)
            {
                pose_le_bateau(grille, BATEAU_CROISER, x, y, direction);
                nbBat = nbBat + 1;
            }  
        }
        while (nbBat != 4)
        {
            int x = NBalea(TAILLE);
            int y = NBalea(TAILLE);
            int direction = NBalea(4)+1;
            result = verifier_place_bateau(grille, BATEAU_TORPILLEUR, x, y, direction);
            if (result == 1)
            {
                pose_le_bateau(grille, BATEAU_TORPILLEUR, x, y, direction);
                nbBat = nbBat + 1;
            } 
        }
    
    }
}
// ----------------------------------------------------------------------------------------------------------------------------------------------------------
                                                // Fonction : appeller bateau pour le placer
int appeller_bateau(int grille[TAILLE][TAILLE], int type_bateau, char *nom)
{
    int result = 0; 
    int nbBat = 0;
    while (nbBat <= NB_BATEAUX)
    { 
        int x,y,direction;
        printf("\033[32;01mPlacez la tete de votre %s de %d cases.\n\nPuis choisissez une direction --  1 : droite 2 : gauche 3 : haut  4 : bas.\n\nFormat attendu x y d.\n\033[00m", nom, type_bateau);
        scanf("%d %d %d",&x, &y, &direction);
        if (x>=0 && x<=9 && y>=0 && y<=9 && direction>=1 && direction<=4)
        {
            result = verifier_place_bateau(grille, type_bateau, x, y, direction);
        }
        else printf("\033[31;01mHors limites.\n\033[00m");
        if (result == 1)
        {
            pose_le_bateau(grille, type_bateau, x, y, direction);
            nbBat = nbBat + 1;
            printgrilleDec(grille);
            return 1;
        }
        else return 0; 
    }
}  
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                // fonction : demander de tirer manuelle !

int tirez(int grille[TAILLE][TAILLE])
{
    int x, y; 
    printf("\033[32;01mTirez sur une case en ciblant un point sur les axe x et y .\nSous la forme 'x y' .\n\033[00m");
    scanf("%d %d", &x, &y);
    if (x >= 0 && x < TAILLE && y >= 0 && y < TAILLE)
    {
        if (grille[x][y] == MER)
        {
            grille[x][y] = MANQUE;
            printf("\033[31;01mRATE !\n\033[00m");
            return 0;
        }
        else if (grille[x][y] == BATEAU)
        {
            grille[x][y] = TOUCHE;
            printf("\033[32;01mTOUCHE !\n\033[00m");
            return 1;
        }
        else {
            printf("\033[31;01mDeja tire ici !\n\033[00m");
            return 0;
        }
    }
    else if (x < 0 || x >= TAILLE || y < 0 || y >= TAILLE)
    {
        printf("\033[31;01mTu as tire dans un autre jeu... Dans un autre monde... dans un univers parallele ! TEMPIS !!\n\033[00m");
            return 0;
    }
          
}
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                // Fonction tirez automatique

int tirezAuto(int grille[TAILLE][TAILLE])
{
    int x, y, valide;
    while (valide != 1)
    { 
        x = NBalea(TAILLE);
        y = NBalea(TAILLE);
        valide = 0;  
        if (x>=0 && x < TAILLE && y>=0 && y < TAILLE)
        {
            if (grille[x][y] == MER)
            {
               grille[x][y] = MANQUE;
               printf("\033[32;01mIl vous a MANQUE !\n\033[00m");
               valide = valide + 1;
               return 0;
            }
            else if (grille[x][y] == BATEAU)
            {
                grille[x][y] = TOUCHE;
                printf("\033[31;01mIl vous a TOUCHE !\n\033[00m");
                valide = valide + 1;
                return 1;
            }
        }
        else
        {
            printf("Tire invalide\n");
        }
    }        
}
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                //Fonction partie solo 
int partiesolo()
{
    sautDeLigne(10);
    srand(time(NULL));
    int grilleAdverse[TAILLE][TAILLE], grilleperso[TAILLE][TAILLE], pointperso, pointadverse, nbTirePerso, nbTireAdverse, x, y,direction, result;
    result = 0;
    pointperso = 0;
    pointadverse = 0;
    nbTireAdverse = 0;
    nbTirePerso = 0;
    initialiser_grille(grilleAdverse);
    initialiser_grille(grilleperso);
    placer_bateaux_Ia(grilleAdverse);
    printgrilleDec(grilleperso);
    printf("\033[32;01mVotre adversaire a positionne ses %d point-bateaux.\nA vous de poser votre Flotte compose de :\n1 porte avion : %d cases.\n1 sous marin : %d cases.\n1 croiser : %d cases.\net\n1 Torpilleur : %d cases.\n\033[00m", NB_BATEAUX, BATEAU_PORTE_AVIONS, BATEAU_SOUS_MARIN, BATEAU_CROISER, BATEAU_TORPILLEUR);
    while (result < 1)
    { 
       result = appeller_bateau(grilleperso, BATEAU_PORTE_AVIONS, "PORTE-AVIONS");
    }
    while (result < 2)
    { 
        result = appeller_bateau(grilleperso, BATEAU_SOUS_MARIN, "SOUS-MARINS") + 1;
    }
    while (result < 3)
    { 
        result = appeller_bateau(grilleperso, BATEAU_CROISER, "CROISER") + 2;
    }
    while (result < 4)
    { 
        result = appeller_bateau(grilleperso, BATEAU_TORPILLEUR, "TORPILLEUR") + 3;
    }
    printgrilleCache(grilleAdverse);
    printf("\033[31;01mGrille Adverse\n\033[00m");
    printgrilleCache(grilleperso);
    printf("\033[34;01mVotre grille\n\033[00m");
    printligne(2);    
    while (pointadverse != NB_BATEAUX && pointperso != NB_BATEAUX)
    {   
        printligne(2);
        int resultatTouche = tirez(grilleAdverse);        
        pointperso = pointperso + resultatTouche;
        nbTirePerso = nbTirePerso + 1;
        printgrilleCache(grilleAdverse);
        printf("\033[31;01mGrille Adverse\n\033[00m");
        printf("vous etes a  %d pont(s)\n", pointperso);
        printf("vous avez tire  : %d coup(s)\n", nbTirePerso);
        if (pointperso == NB_BATEAUX)
        {
            break;
        }
        printligne(2);
        int resultatToucheAdv = tirezAuto(grilleperso);
        pointadverse = pointadverse + resultatToucheAdv;
        nbTireAdverse = nbTireAdverse + 1;
        printgrilleCache(grilleperso);
        printf("\033[34;01mVotre grille\n\033[00m");
        printf("il est a  %d point(s)\n", pointadverse);
        printf("il a tire : %d coup(s)\n", nbTireAdverse);
    }
    printligne(2);
    if (pointperso == NB_BATEAUX)
    {
        printgrilleCache(grilleAdverse);
        printf("\033[31;01mGrille Adverse\n\033[00m");
        printgrilleCache(grilleperso);
        printf("\033[34;01mVotre grille\n\033[00m");
        printf("\033[32;01m                                                Bravo tu as trouve et coule les quatres bateaux adverse en %d coup(s)\n\033[00m", nbTirePerso);
    }
    else if (pointadverse == NB_BATEAUX)
    {
        printgrilleCache(grilleAdverse);
        printf("\033[31;01mGrille Adverse\n\033[00m");
        printgrilleCache(grilleperso);
        printf("\033[34;01mVotre grille\n\033[00m");
        printf("\033[33;01m                                                Dsl c'est perdu t'es rien qu'une grosse buse. tu t'es fais battre en %d coup(s)\n\033[00m", nbTireAdverse);
    }
    printligne(2);
    printf("\033[32;01m                                                    GAMEOVER  \n\033[00m\n");
    return choixFinDePartie();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                //Fonction multi-joueur
int partieMultijoueur()
{
    int grilleJ1[TAILLE][TAILLE], grilleJ2[TAILLE][TAILLE], pointJ1, pointJ2, nbTireJ1, nbTireJ2, x, y, direction, nbBatJ1, nbBatJ2, result;
    pointJ1 = 0;
    pointJ2 = 0;
    nbTireJ1 = 0;
    nbTireJ2 = 0;
    nbBatJ1 = 0;
    nbBatJ2 = 0;
    initialiser_grille(grilleJ1);
    initialiser_grille(grilleJ2);
    printf("\033[32;01mJ1 sera le 1er joueur a tirer donc choisissez qui commence et qui sera J2\nJ1 Placez vos %d points-bateaux sur la grille\n\nA l'abris des regards !!!\n\n\033[00m", NB_BATEAUX);
    printgrilleDec(grilleJ1);
    printf("\033[34;01mGrille J1\n\033[00m");
    while (result !=1)
    {   
        result = appeller_bateau(grilleJ1, BATEAU_PORTE_AVIONS, "PORTE-AVIONS");
    }
    while (result !=2)
    { 
        result = appeller_bateau(grilleJ1, BATEAU_SOUS_MARIN, "SOUS-MARINS") + 1;
    }
    while (result !=3)
    { 
        result = appeller_bateau(grilleJ1, BATEAU_CROISER, "CROISER") + 2;
    }
    while (result !=4)
    { 
        result = appeller_bateau(grilleJ1, BATEAU_TORPILLEUR, "TORPILLEUR") + 3;
    }
    printligne(25);
    printgrilleDec(grilleJ2);
    printf("\033[31;01mGrille J2\n\033[00m");
    printf("\033[32;01mIlJ1 a place tous ses %d point-bateaux\n\nA VOUS J2 !\n\033[00m");
    while (result !=1)
    {   
        result = appeller_bateau(grilleJ2, BATEAU_PORTE_AVIONS, "PORTE-AVIONS");
    }
    while (result !=2)
    { 
        result = appeller_bateau(grilleJ2, BATEAU_SOUS_MARIN, "SOUS-MARINS") + 1;
    }
    while (result !=3)
    { 
        result = appeller_bateau(grilleJ2, BATEAU_CROISER, "CROISER") + 2;
    }
    while (result !=4)
    { 
        result = appeller_bateau(grilleJ2, BATEAU_TORPILLEUR, "TORPILLEUR") + 3;
    }
    printligne(25);
    printgrilleCache(grilleJ1);
    printf("\033[34;01mGrille J1\n\033[00m");
    printgrilleCache(grilleJ2);
    printf("\033[31;01mGrille J2\n\033[00m");
    printligne(2);
    while (pointJ1 != NB_BATEAUX && pointJ2 != NB_BATEAUX)
    {  
        printligne(2);
        printf("\033[34;01mAu tour de J1\n\033[00m");
        int resultatTouche1 = tirez(grilleJ2);        
        pointJ1 = pointJ1 + resultatTouche1;
        nbTireJ1 = nbTireJ1 + 1;
        printgrilleCache(grilleJ2);
        printf("\033[31;01mGrille J2\n\033[00m");
        printf("\033[32;01mJ1 est a %d pont(s)\nJ1 a tire  : %d coup(s).\n\033[00m", pointJ1, nbTireJ1);
        if (pointJ1 == NB_BATEAUX)
        {
            break;
        }
        printligne(2);
        printf("\033[31;01mAu tour de J2\n\033[00m");
        int resultatTouche2 = tirez(grilleJ1);        
        pointJ2 = pointJ2 + resultatTouche2;
        nbTireJ2 = nbTireJ2 + 1;
        printgrilleCache(grilleJ1);
        printf("\033[34;01mGrille J1\n\033[00m");
        printf("\033[32;01mJ1 est a %d pont(s)\nJ1 a tire  : %d coup(s)\n\033[00m", pointJ2, nbTireJ2);
    }
    if (pointJ1 == NB_BATEAUX)
    {
        printligne(2);
        printgrilleCache(grilleJ1);
        printf("\033[34;01mGrille J1\n\033[00m");
        printligne(2);
        printgrilleCache(grilleJ2);
        printf("\033[31;01mGrille J2\n\033[00m");
        printf("\033[34;01m                                              Bravo J1 gagne en %d coup(s)\n\033[00m", nbTireJ1);
        printligne(2);
    }
    else if (pointJ2 == NB_BATEAUX)
    {
        printligne(2);
        printgrilleCache(grilleJ2);
        printf("\033[31;01mGrille J2\n\033[00m");
        printligne(2);
        printgrilleCache(grilleJ1);
        printf("\033[34;01mGrille J1\n\033[00m");
        printf("\033[31;01m                                              Bravo J2 gagne en %d coup(s)\n\033[00m", nbTireJ2);
    }
    printligne(2);
    sautDeLigne(1);
    printf("\033[32;01m                                                  GAMEOVER  \n\033[00m\n");
    return choixFinDePartie();
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------FONCTION PRINCIPAL-------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{   
    int result = 1;
    while (result != 0)
    {    
        char choix;
        sautDeLigne(20);            
        printf("\n"
        "\033[32;01m                                                               BBBBB   AAAAA TTTTT AAAAA III L     L     EEEEE   N   N  AAAAA V   V AAAAA L     EEEEE\n"
                   "                                                               B   B   A   A   T   A   A  I  L     L     E       NN  N  A   A V   V A   A L     E    \n"
                   "                                                               BBBB    AAAAA   T   AAAAA  I  L     L     EEEE    N N N  AAAAA V   V AAAAA L     EEEE \n"
                   "                                                               B   B   A   A   T   A   A  I  L     L     E       N  NN  A   A  V V  A   A L     E    \n"
                   "                                                               BBBBB   A   A   T   A   A III LLLLL LLLLL EEEEE   N   N  A   A   V   A   A LLLLL EEEEE\n"
                   "                                                               \n"
                   "                                                                                        2025\033[00m\n");
        sautDeLigne(10);
        printf("\n\033[33;01m                                             Menu :\n\n\n\n                                            a. partie : solo.                                           b. partie : multi-joueur.                                           c. Quitter le programme. \033[00m\n");
        sautDeLigne(10);           
        scanf(" %c", &choix);
            switch (choix)
            {
                case 'a':
                    sautDeLigne(15);
                    result = partiesolo();
                    if (result == 1)
                    {
                    continue;            
                    }
                    break;                   
                case 'b':
                    sautDeLigne(15);
                    result = partieMultijoueur();
                    if (result == 1)
                    {
                    continue;            
                    }
                    break;
                case 'c':
                    result = 0;
                    break;
            }
    }
    return 0;
}
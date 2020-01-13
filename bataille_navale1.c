#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define TMAX 11
#define WIN 17
#define SDL printf("\n");
#define TAILLE_MAX 2000

void initTab(char Att[TMAX][TMAX], char Boat[TMAX][TMAX]);
void AffTab(char Att[TMAX][TMAX], char Boat[TMAX][TMAX]);
void FillBoatJ1(char BoatJ1[TMAX][TMAX]);
void FillBoatJ2(char BoatJ2[TMAX][TMAX]);
void Mecanique(char AttJ1[TMAX][TMAX], char BoatJ1[TMAX][TMAX], char AttJ2[TMAX][TMAX], char BoatJ2[TMAX][TMAX]);
int Win(int touchJ1, int touchJ2);
void Regle();

void Jeu();
void Menu();

// void color(int t,int f);


int main(int argc, char const *argv[])
{
	Menu();
	return 0;
}

void Menu()
{
	system("cls");
	int choix = 0;
	printf("########## Bienvenue au jeu de la bataille navale ! ##########\n");
	SDL
	printf("Choisissez une option\n");
	SDL
	printf("1. Jouer\n");
	printf("2. Regle\n");
	printf("3. Quitter\n");
	scanf("%d", &choix); fflush(stdin);
	switch(choix)
	{
		case 1: Jeu();
			break;
		case 2: Regle();
			break;
		case 3: system("exit");
			break;
	}
}


void Jeu()
{
	char AttJ1[TMAX][TMAX], BoatJ1[TMAX][TMAX];
	char AttJ2[TMAX][TMAX], BoatJ2[TMAX][TMAX];

	initTab(AttJ1, BoatJ1);
	FillBoatJ1(BoatJ1);

	initTab(AttJ2, BoatJ2);
	FillBoatJ2(BoatJ2);

	Mecanique(AttJ1, BoatJ1, AttJ2, BoatJ2);


}

void Regle()
{
	system("cls");
	char chaineRegle[TAILLE_MAX] = "";
	FILE *regle = NULL;

	regle = fopen("Regle.txt", "r");
	if (regle != NULL)
	{
        while (fgets(chaineRegle, TAILLE_MAX, regle) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            printf("%s", chaineRegle); // On affiche la chaîne qu'on vient de lire
            SDL
        }

		fclose(regle);
	}
}

void Mecanique(char AttJ1[TMAX][TMAX], char BoatJ1[TMAX][TMAX], char AttJ2[TMAX][TMAX], char BoatJ2[TMAX][TMAX])
{
	int i, j, tour = 1, touchJ1 = 0, touchJ2 = 0;
	char tir = 'x', miss = '?';

	while (tour != 2 || touchJ1 != WIN)
	{
		system("cls");
		AffTab(AttJ1, BoatJ1);
		SDL

		printf("Joueur 1 a vous\n");
		SDL
		printf("Nombre de touches %d\n", touchJ1);
		printf("Choisissez une ligne de 1 à 10\n");
		scanf("%d", &i); fflush(stdin);
		if (i < TMAX && i > 0)
		{
			SDL
			printf("Choisissez une colonne de 1 à 10\n");
			scanf("%d", &j);
			fflush(stdin);

			if ((AttJ1[i][j] == '-') && (BoatJ2[i][j] == '0')) //Tir vrai
			{
				AttJ1[i][j] = tir;
				BoatJ2[i][j] = tir;
				touchJ1++;
			}
			if ((AttJ1[i][j] == '-') && (BoatJ2[i][j] == '-')) //Tir faux
			{
				AttJ1[i][j] = miss;
				tour = 2;
			}
		} else{
			printf("Entre une valeur correct\n");
		}
		if (touchJ1 == WIN)
		{

			system("cls");
			AffTab(AttJ1, BoatJ1);
			SDL

			Win(touchJ1, touchJ2); //Message de victoire
			exit(0); //Quitte le programme
		}
	}
	while (tour != 1 || touchJ2 != WIN)
	{
		system("cls");

		AffTab(AttJ2, BoatJ2);
		SDL
		printf("Joueur 2 a vous\n");
		SDL
		printf("Nombre de touches %d\n", touchJ2);
		printf("Choisissez une ligne de 1 a 10\n");
		scanf("%d", &i); fflush(stdin);
		if (i < TMAX && i > 0)
		{
			SDL
			printf("Choisissez une colonne de 1 à 10\n");
			scanf("%d", &j);
			fflush(stdin);

			if ((AttJ2[i][j] == '-') && (BoatJ1[i][j] == '0')) //Tir vrai
			{
				AttJ2[i][j] = tir;
				BoatJ1[i][j] = tir;
				touchJ2++;
			}
			if ((AttJ2[i][j] == '-') && (BoatJ1[i][j] == '-')) //Tir faux
			{
				AttJ2[i][j] = miss;
				tour = 1;
			}
		} else{
			printf("Entrez une valeur correct\n");
		}
		if (touchJ2 == WIN)
		{

			system("cls");
			AffTab(AttJ2, BoatJ2);
			SDL
			
			Win(touchJ1, touchJ2); //Message de victoire
			exit(0); //Quitte le programme
		}
	}
}

void initTab(char Att[TMAX][TMAX], char Boat[TMAX][TMAX])
{
	int i, j;

	//Grille des cibles
	Att[0][0] = 'X';
	Att[0][1] = '1';
	Att[0][2] = '2';
	Att[0][3] = '3';
	Att[0][4] = '4';
	Att[0][5] = '5';
	Att[0][6] = '6';
	Att[0][7] = '7';
	Att[0][8] = '8';
	Att[0][9] = '9';
	Att[0][10] = '0';

	Att[0][0] = 'X';
	Att[1][0] = 'A';
	Att[2][0] = 'B';
	Att[3][0] = 'C';
	Att[4][0] = 'D';
	Att[5][0] = 'E';
	Att[6][0] = 'F';
	Att[7][0] = 'G';
	Att[8][0] = 'H';
	Att[9][0] = 'I';
	Att[10][0] = 'J';

	//Grille des bateaux
	Boat[0][0] = 'X';
	Boat[0][1] = '1';
	Boat[0][2] = '2';
	Boat[0][3] = '3';
	Boat[0][4] = '4';
	Boat[0][5] = '5';
	Boat[0][6] = '6';
	Boat[0][7] = '7';
	Boat[0][8] = '8';
	Boat[0][9] = '9';
	Boat[0][10] = '0';

	Boat[0][0] = 'X';
	Boat[1][0] = 'A';
	Boat[2][0] = 'B';
	Boat[3][0] = 'C';
	Boat[4][0] = 'D';
	Boat[5][0] = 'E';
	Boat[6][0] = 'F';
	Boat[7][0] = 'G';
	Boat[8][0] = 'H';
	Boat[9][0] = 'I';
	Boat[10][0] = 'J';

	for (i = 1; i< TMAX; i++) //Init grille des cibles
	{
		for (j = 1; j< TMAX; j++)
		{
			Att[i][j] = '-';
		}		
	}

	for (i = 1; i < TMAX; i++) // Init grille des bateaux
	{
		for (j = 1; j < TMAX; j++)
		{
			Boat[i][j] = '-';
		}
	}




}

void AffTab(char Att[TMAX][TMAX], char Boat[TMAX][TMAX])
{
	int i, j;
	printf("Grille des cibles\n");
	for (i = 0; i < TMAX; i++)
	{
		printf("|");
		for (j = 0; j < TMAX; j++)
		{
			printf("%c", Att[i][j]);
			printf("|");
		}
		SDL
	}

	SDL

	printf("Grille de vos bateaux\n");
	for (i = 0; i < TMAX; i++)
	{
		printf("|");
		for (j = 0; j < TMAX; j++)
		{
			printf("%c", Boat[i][j]);
			printf("|");
		}
		SDL
	}
}



/*void color(int t,int f)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttJ1ribute(H,f*16+t);
}*/

void FillBoatJ1(char BoatJ1[TMAX][TMAX])
{
	BoatJ1[2][2] = '0';
	BoatJ1[3][2] = '0';
	BoatJ1[4][2] = '0';	//Porte Avion
	BoatJ1[5][2] = '0';
	BoatJ1[6][2] = '0';

	BoatJ1[4][4] = '0';
	BoatJ1[4][5] = '0';	//Contre Torpieur 1
	BoatJ1[4][6] = '0';

	BoatJ1[2][7] = '0';
	BoatJ1[2][8] = '0';	//Contre Torpieur 2
	BoatJ1[2][9] = '0';

	BoatJ1[5][8] = '0';
	BoatJ1[6][8] = '0';	//Croiseur
	BoatJ1[7][8] = '0';
	BoatJ1[8][8] = '0';

	BoatJ1[9][3] = '0';	//Torpieur
	BoatJ1[9][4] = '0';
}

void FillBoatJ2(char BoatJ2[TMAX][TMAX])
{
	BoatJ2[2][2] = '0';
	BoatJ2[2][3] = '0';
	BoatJ2[2][4] = '0';	//Porte Avion
	BoatJ2[2][5] = '0';
	BoatJ2[2][6] = '0';

	BoatJ2[2][8] = '0';
	BoatJ2[3][8] = '0';	//Contre Torpieur 1
	BoatJ2[4][8] = '0';

	BoatJ2[3][10] = '0';
	BoatJ2[4][10] = '0';	//Contre Torpieur 2
	BoatJ2[5][10] = '0';

	BoatJ2[6][3] = '0';
	BoatJ2[6][4] = '0';	//Croiseur
	BoatJ2[6][5] = '0';
	BoatJ2[6][6] = '0';

	BoatJ2[8][5] = '0';	//Torpieur
	BoatJ2[8][6] = '0';
}

int Win(int touchJ1, int touchJ2)
{
	if (touchJ1 == WIN)
	{
		printf("Bravo Joueur 1\n");
	}
	if(touchJ2 == WIN)
	{
		printf("Bravo Joueur 2\n");
	}
}



/*
à FAIRE : 
	- Couleur
*/
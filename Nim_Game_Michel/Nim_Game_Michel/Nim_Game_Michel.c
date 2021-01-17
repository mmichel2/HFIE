#include <stdio.h>      // rpintf, scanf
#include <stdint.h>     // int32_t
#include <stdlib.h>     // rand()
#include <time.h>       // initialisierung des Zufallsgenerators

#define Arraygroesse 10 
#define MaxHoelzchen 10
#define MaxReihen 8

void Spielfeldausgabe(int32_t *arraynim);						//Gibt das Spielfeld aus
void EingabeHoelzchen(int32_t *arraynim, int8_t reihen);		//Fragt die einzenen Reihen die Anzahl Hoelzchen ab
void Arraybefuellen(int32_t *arraynim);							//befüllt das Ganze Array mit -1(-1 wird genutzt um die Anzahl der Reihen herauszufinden)
void EingabeNutzer(int32_t *arraynim);							//Fragt Nutzer in welcher Reihe und wieviele Hoelzchen er entfernen moechte
void EingabePC(int32_t *arraynim);								//macht den Spielzug des PC
int8_t LetztesHoelzchen(int32_t *arraynim);						//Fragt ab ob es noch Hoelzchen auf dem Spielfeld hat(Rueckgabe 1 = keine Hoelzchen mehr da)
int32_t EingabeZahl();											//Fragt Nutzer nach einer Zahl
int8_t EingabeReihen();											//Fragt Nutzer nach der Anzahl Reihen ab


int main()
{
	int32_t arraynim[Arraygroesse];								//Array um das Spielfed darin zu speichern
	Arraybefuellen(arraynim);
	int8_t reihen = 0;											//Anzahl Reihen die eingeben wurden werden hier gespeichert
	int8_t gewonnen = 0;										//Gewonnen geht auf 1 wenn gewonnen

	printf("Willkommen zum Nim_Game \nDu Spielst gegen den PC.Abwechslungsweise ziehst du und der PC. Du darf nur von einer einzigen\n");
	printf("Reihe Hoelzchen entfernen. Du musst mindestens eines oder hoechstens alle Hoelzchen wegnehmen.\n");
	printf("Du gewinnst wenn du das letzte Hoelzchen wegraeumen kannst.\n");
	reihen = EingabeReihen();
	EingabeHoelzchen(arraynim, reihen);
	Spielfeldausgabe(arraynim);
	
	while (LetztesHoelzchen(arraynim) != 1)
	{
		EingabeNutzer(arraynim);
		Spielfeldausgabe(arraynim);
		if (LetztesHoelzchen(arraynim) != 1)
		{
			EingabePC(arraynim);
			Spielfeldausgabe(arraynim);
		}
		else
			gewonnen = 1;
	}
	if (gewonnen == 1)
		printf("Du hast gewonnen. Gratuliere!\n\n");
	else
		printf("Du hast verloren. Vieleicht hast du naechstes mal mehr Glueck\n\n");
}

int8_t LetztesHoelzchen(int32_t* arraynim)
{
	int8_t i = 0;
	while (arraynim[i] != -1)
	{
		if (arraynim[i] != 0)
			return 0;
		i++;
	}
	return 1;
}

void EingabePC(int32_t* arraynim)
{
	int8_t i = 0;
	printf("Spielzug PC");
	while (arraynim[i] != -1)
	{
		if (arraynim[i] != 0)
		{
			arraynim[i] = arraynim[i] - 1;
			return;
		}
		i++;
	}
}

void EingabeNutzer(int32_t* arraynim)
{
	int8_t eingabekorrekt = 0;
	int32_t eingabereihe = 0;
	int32_t eingabehoelzchen = 0;
	
	while (eingabekorrekt != 1)
	{
		printf("Waelen Sie die Reihe aus in der Sie Hoelzchen entfernen moechten: \n");
		eingabereihe = EingabeZahl();
		if (arraynim[eingabereihe - 1] > 0)
			eingabekorrekt = 1;
		else
			printf("Ausgewaelte Reihe steht nicht zur Verfuegung\n");
	}
	eingabekorrekt = 0;

	while (eingabekorrekt != 1)
	{
		printf("Waelen sie die Anzahl Hoelzchen die Sie in Reihe %i entfernen moechten: \n", eingabereihe);
		eingabehoelzchen = EingabeZahl();
		if (arraynim[eingabereihe - 1] >= eingabehoelzchen && eingabehoelzchen > 0)
			eingabekorrekt = 1;
		else
			printf("Anzahl der Hoelzchen nicht korrekt\n");
	}
	arraynim[eingabereihe - 1] = arraynim[eingabereihe - 1] - eingabehoelzchen;
}

int8_t EingabeReihen()
{
	int8_t eingabe = 0;
	int8_t eingabekorrekt = 0;
	while (eingabekorrekt == 0)
	{
		printf("Geben sie die Anzahl der Reihen ein die das Spiel haben soll(Zwischen 2 und 8): ");
		eingabe = EingabeZahl();
		if (eingabe > MaxReihen || eingabe < 2)
			printf("Nicht korrekte Anzahl der Reihen \n");
		else
		{
			eingabekorrekt = 1;
			return eingabe;
		}
	}
}

void Arraybefuellen(int32_t* arraynim)
{
	int8_t befuellen;
	for (befuellen = 0; befuellen < Arraygroesse; befuellen++)
		arraynim[befuellen] = -1;
}

void EingabeHoelzchen(int32_t *arraynim, int8_t reihen)
{
	int8_t i;
	int32_t eingabe = 0;
	for (i = 0; i <= reihen - 1; i++)
	{
		printf("Geben sie die Hoelzchen der Reihe %i ein(Zwischen 0 und 10):  \n", i + 1);
		eingabe = EingabeZahl();
		if (eingabe > MaxHoelzchen || eingabe < 0)
		{
			printf("Das sind zu viele Hoelzchen!\n");
			i--;
		}
		else
			arraynim[i] = eingabe;
	}
}

int32_t EingabeZahl()
{
	int32_t eingabe = 0;
	scanf_s("%i", &eingabe);
	while (getchar() != '\n');
	return eingabe;
}

void Spielfeldausgabe(int32_t *arraynim)
{
	int32_t i = 0;
	int32_t zaeler = arraynim[i];
	printf("\n\tSpielfeld\n\n");
	while(zaeler != -1)
	{
		if (arraynim[i] != 0)
		{
			while (zaeler != 0) 
			{
				printf("| ");
				zaeler--;
			}
		}
		printf("\n---------------------------\n");
		i++;
		zaeler = arraynim[i];
	}
	printf("\n\n");
}
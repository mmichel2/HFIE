#include <stdio.h>      // rpintf, scanf
#include <stdint.h>     // int32_t
#include <stdlib.h>     // rand()
#include <time.h>       // initialisierung des Zufallsgenerators


void Spielfeldausgabe(int32_t daten_nim[]);
int32_t EingabeZahl();
// void Spielfeldgenerator(const int8_t hoelzchen, const int8_t reihen, );



int main()
{


}


int32_t EingabeZahl()
{
	int32_t eingabe = 0;
	scanf_s("%i", &eingabe);
	while (getchar() != '\n');
	return eingabe;
}

void Spielfeldausgabe(int32_t daten_nim[])
{
	int32_t i = 0;
	int32_t zaeler;
	printf("Spielfeld\n\n");
	while(i < sizeof(daten_nim))
	{
		zaeler = daten_nim[i];
		if (daten_nim[i] != 0)
		{
			while (zaeler != 0) 
			{
				printf("| ");
				zaeler--;
			}
		}
		printf("\n___________________\n");
		i++;
	}
}






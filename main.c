#include <stdio.h>

// Aufgabe 1a: Definition von Aufzaehlung und Struktur
enum rolllaeden
{
    zu,
    auf
};
enum wetter
{
    sonnig,
    regnerisch,
    bewoelkt
};
enum bewohner
{
    abwesend = 'n',
    anwesend = 'j'
};
struct zeit
{
    /* Komponenten der Zeit */
    int monat;
    int stunde;
    int minute;
};

// Aufgabe 1c: Funktion init_zeit

struct zeit init_zeit() {
    struct zeit akt_zeit;
    printf("Gebe den Monat ein: ");
    scanf("%d", &akt_zeit.monat);

    printf("Gebe die Zeit im Format [hh:mm] ein: ");
    scanf("%d:%d", &akt_zeit.stunde, &akt_zeit.minute);

    return akt_zeit;
}

// Aufgabe 2: Funktion heizung

enum rolllaeden rollladen(int akt_wetter, char anwesenheit, struct zeit akt_zeit, float akt_temperatur)
{
    int istTag = 0;
    if ((akt_zeit.stunde * 60 + akt_zeit.minute) > 968 && ((akt_zeit.stunde * 60 + akt_zeit.minute) < 486))
    {
        istTag = 1;
    }

    int istSommer = 0;
    if (akt_zeit.monat > 5 && akt_zeit.monat < 9)
        istSommer = 1;

    if (istTag)
        return zu;
    else if (istSommer && akt_wetter == sonnig && akt_temperatur > 28.f)
        return zu;
    if (anwesenheit == abwesend)
    {
        if (istSommer && akt_wetter == sonnig)
            return auf;
        return zu;
    }
    if (akt_wetter == regnerisch)
        return zu;
    return auf;
}

// Aufgabe 3: Funktion rollladen

int heizung(enum wetter akt_wetter, char anwesenheit, int monat , float akt_temperatur, enum rolllaeden akt_rollladen)
{
    int output;
    output = 0;
    if (monat >= 4 && monat <= 10) { // april -> Oktober
        return output;
    }
    if (akt_temperatur > 25) {
        return output;
    }
    else {
        output = (int)(25.f - akt_temperatur) / 5.f;
    }

    if (akt_wetter == sonnig && akt_rollladen == auf) {
        output--;
    }

    if (anwesenheit == abwesend) {
        output --;
    }

    if (output < 0) {
        output = 0;
    }
    else if (output > 5){
        output = 5;
    }


    return output;
}

int main(void)
{
	// Aufgabe 1b: Deklaration der Variablen
    int akt_wetter;
    int akt_heizung;
    char anwesenheit;
    float akt_temperatur;
    struct zeit akt_zeit;
    enum rolllaeden akt_rollladen;

	// Aufgabe 5: Schleife
    int laufzeit = 1;
    while(laufzeit)
	{
		// Aufgabe 1c: Initialisierung der Variablen
        printf("\n\nWie kalt ist es draußen [in Grad Celsius]?: ");
        scanf("%f", &akt_temperatur);

        printf("Wie ist das Wetter [0: Sonne, 1: Regen,2: Wolken]?: ");
        scanf("%d", &akt_wetter);

        printf("Ist jemand Zuhause [j/n]?: ");
        scanf(" %c", &anwesenheit);

        akt_zeit = init_zeit();

		// Aufgabe 5: Funktionsaufruf und Ausgabe der Ergebnisse

        akt_rollladen = rollladen(akt_wetter, anwesenheit, akt_zeit, akt_temperatur);
        if (akt_rollladen) printf("\n Oeffne Rollladen");
        else printf("\n Schließe Rollladen");

        akt_heizung = heizung(akt_wetter, anwesenheit, akt_zeit.monat, akt_temperatur, akt_rollladen);
        printf("\n Setze Heizung auf %d\n", akt_heizung);

        printf("\nNeue Prüfung des Algorithmus (0:Nein, 1:Ja)?\n");
        scanf("%d", &laufzeit);
	}


	return 0;
}

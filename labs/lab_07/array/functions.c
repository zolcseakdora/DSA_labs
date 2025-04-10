//
// Created by Dora on 2025. 04. 03..
//

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char *szin_nevek[] = { "red", "white", "black", "yellow", "other" };
#define NR_COLORS 4
enum Color getColorEnumValue(char *str) {
    for (int i = 0; i < NR_COLORS; ++i) {
        if(strcmp(str, szin_nevek[i]) == 0) {
            return i;
        }
    }
    return OTHER;
}
const char* getColorStringValue(enum Color color) {
    if(color < NR_COLORS) {
        return szin_nevek[color];
    }
    return "UNDEFINED";
}
void readLabdak(labdak *labda)
{
    scanf("%d", &labda->atmeroje);
    char color[20];
    scanf("%s", color);
    labda->szin = getColorEnumValue(color);
    scanf("%d", &labda->allariva);
}
void printLabdak(labdak *labda)
{
    printf("Diameter %s\n", labda->atmeroje);
    printf("Color: %s\n", getColorStringValue(labda->szin));
    printf("Is signed: %s\n", (labda->allariva == 0) ? "NO" : "YES");
}
void readFromFile(labdak *labda, FILE *file)
{
    fscanf(file,"%d", &labda->atmeroje);
    char color[20];
    fscanf(file,"%s", color);
    labda->szin = getColorEnumValue(color);
    fscanf(file,"%d", &labda->allariva);

}
void printPolcok(polc *polc)
{
    for (int i = 0; i < polc->darabszam; i++) {
        printLabdak(&polc->labda[i]);
    }
}
void torol_labdakat(polc *polc) {
    int uj_index = 0;
    for (int i = 0; i < polc->darabszam; i++) {
        if (polc->labda[i].atmeroje <= 15) {
            polc->labda[uj_index++] = polc->labda[i];
        }
    }
    polc->darabszam = uj_index;
}
int szamol_alairt_labdakat(const polc *polc) {
    int darab = 0;
    for (int i = 0; i < polc->darabszam; i++) {
        if (polc->labda[i].allariva) {
            darab++;
        }
    }
    return darab;
}
int osszehasonlit_labda(const void *a, const void *b) {
    return ((labdak*)a)->atmeroje - ((labdak*)b)->atmeroje;
}
void rendez_labdakat(polc *polc) {
    qsort(polc->labda, polc->darabszam, sizeof(labdak), osszehasonlit_labda);
}
void hozzaad_labda(polc *polc, labdak uj_labda) {
    if (polc->darabszam >= Max_capacity) {
        printf("A polc megtelt!\n");
        return;
    }
    if (uj_labda.szin == RED) {
        for (int i = polc->darabszam; i > 0; i--) {
            polc->labda[i] = polc->labda[i - 1];
        }
        polc->labda[0] = uj_labda;
    } else if (uj_labda.szin == WHITE) {
        polc->labda[polc->darabszam] = uj_labda;
    } else {
        int index = rand() % (polc->darabszam + 1);
        for (int i = polc->darabszam; i > index; i--) {
            polc->labda[i] = polc->labda[i - 1];
        }
        polc->labda[index] = uj_labda;
    }
    polc->darabszam++;
}
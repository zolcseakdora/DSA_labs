//
// Created by Dora on 2025. 04. 03..
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define Max_capacity 20
#include <stdio.h>
#include <stdbool.h>
typedef enum
{
    RED,
    WHITE,
    BLACK,
    YELLOW,
    OTHER,
}Color;

typedef struct
{
    int atmeroje;
    Color szin;
    bool allariva;
}labdak;
typedef struct
{
    labdak labda[Max_capacity];
    int darabszam;
}polc;
enum Color getColorEnumValue(char *str);
const char* getColorStringValue(enum Color color);
void readLabdak(labdak *labda);
void printLabdak(labdak *labda);
void readFromFile(labdak* labda, FILE* file);
void printPolcok(polc *polc);
void torol_labdakat(polc *polc);
int szamol_alairt_labdakat(const polc *polc);
int osszehasonlit_labda(const void *a, const void *b);
void rendez_labdakat(polc *polc);
void hozzaad_labda(polc *polc, labdak uj_labda);
#endif //FUNCTIONS_H

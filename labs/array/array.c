//
// Created by dora on 4/3/2025.
//

#include "array.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>

const char *getColorText(Szinek szin) {
    switch (szin) {
        case RED:
            return "RED";
        case WHITE:
            return "WHITE";
        case BLACK:
            return "BLACK";
        case YELLOW:
            return "YELLOW";
        default:
            return "OTHER";
    }
}

Szinek stringToEnum(const char *szin) {
    if (strcmp(szin, "RED") == 0) return RED;
    if (strcmp(szin, "YELLOW") == 0) return YELLOW;
    if (strcmp(szin, "WHITE") == 0) return WHITE;
    if (strcmp(szin, "BLACK") == 0) return BLACK;
    return OTHER;
}


void readLabda(Labda *labda) {
    char szin[20];

    scanf("%d", &labda->atmero);

    scanf("%s", szin);
    labda->szin = stringToEnum(szin);

    scanf(" %d", &labda->ala_irt);
}

void printLabda(Labda labda) {
    printf("%d %s %d", labda.atmero, getColorText(labda.szin), labda.ala_irt);
}


void createArray(int capacity, LabdaArray *pArray) {
    pArray->capacity = capacity;
    pArray->size = 0;
    pArray->elements = (Labda *) malloc(pArray->capacity * sizeof(Labda));
    if (!(pArray->elements)) {
        printf("error");
        exit(-1);
    }
}

bool isFull(LabdaArray array) {
    if (array.size == array.capacity) {
        return true;
    } else return false;
}

bool isEmpty(LabdaArray array) {
    if (array.size == 0) {
        return true;
    } else return false;
}

void printArray(LabdaArray array) {
    if (isEmpty(array)) {
        printf("Ures a tomb");
        exit(-2);
    }

    for (int i = 0; i < array.size; ++i) {
        printf("%i %s %s", array.elements[i].atmero, getColorText(array.elements[i].szin),
               array.elements[i].ala_irt ? "Igen" : "Nem");
    }

    printf("\n");
}

//A piros labdákat mindig a polc elejére, a fehéreket a polc végére tegyük.
//Minden más színű labdát a lehetséges pozíciók közül egy véletlenszerű pozícióra
//helyezzünk
void readOsszesLabda(LabdaArray *pArray) {
    FILE *file = fopen("../input.txt", "r");
    if (!file) {
        printf("Hiba: Nem sikerült megnyitni a fájlt.\n");
        return;
    }

    char szin[20];
    Labda labda;

    srand(time(0));

    int redCount = 0;;
    int whiteCount = 0;

    while (fscanf(file, "%d %s %d", &labda.atmero, szin, &labda.ala_irt) != EOF) {
        labda.szin = stringToEnum(szin);

        if (pArray->size == pArray->capacity) {
            printf("A polc teljes, nem tudunk tobb labdat hozzanadni.\n");
            break; // Töröljük a ciklust, ha már teljes a polc
        }

        if (labda.szin == RED) {
            insertFirst(pArray, labda);
            redCount++;
        } else if (labda.szin == WHITE) {
            insertLast(pArray, labda);
            whiteCount++;
        } else {
            int start = redCount;
            int end = pArray->size - whiteCount;

            if (end > start) {
                // Véletlenszerű index a "jobb" és "bal" közötti helyek között
                int randomIndex = start + rand() % (end - start + 1);
                insertAt(pArray, randomIndex, labda);
            } else {
                insertAt(pArray, redCount, labda); // ha nincs elég üres hely, akkor a végére
            }
        }
    }

    fclose(file);
}

void printOsszesLabda(LabdaArray *pArray) {
    if (pArray->size == 0) {
        printf("Nincsenek beolvasott labdak.\n");
        return;
    }

    printf("labdak listaja:\n");
    for (int i = 0; i < pArray->size; i++) {
        printf("%d\n %s\n %d\n", pArray->elements[i].atmero, getColorText(pArray->elements[i].szin),
               pArray->elements[i].ala_irt);
    }
}

void insertFirst(LabdaArray *pArray, Labda labda) {
    if (isFull(*pArray)) {
        printf("the array is full");
        exit(-3);
    }

    for (int i = pArray->size - 1; i >= 0; i--) {
        pArray->elements[i + 1] = pArray->elements[i];
    }

    //uj labda beszurasa az elso helyre
    pArray->elements[0] = labda;
    pArray->size++;
}

void insertLast(LabdaArray *pArray, Labda labda) {
    if (isFull(*pArray)) {
        printf("the array is full");
        exit(-3);
    }

    pArray->elements[pArray->size] = labda;
    pArray->size++;
}

void insertAt(LabdaArray *pArray, int index, Labda labda) {
    if (isFull(*pArray)) {
        printf("the array is full");
        exit(-3);
    }

    if (index < 0 || index > pArray->size) {
        printf("invalid position");
        exit(-4);
    }

    for (int i = pArray->size; i > index; i--) {
        pArray->elements[i] = pArray->elements[i - 1]; //eltoljuk az elemeket
    }

    pArray->elements[index] = labda; // beillesztjük az új elemet
    pArray->size++;
}

void deallocateArray(LabdaArray *pArray) {
    free(pArray->elements);
    pArray = NULL;
}

Labda getItemAt(LabdaArray array, int position) {
    if (position < 0 || position >= array.size) {
        // Hibás index esetén egy üres labdát adunk vissza
        Labda hibaLabda = {0};  // Üres labda
        return hibaLabda;
    }
    return array.elements[position];
}

bool update(LabdaArray *pArray, int position, Labda newItem) {
    if (position < 0 || position >= pArray->size) {
        printf("Invalid position\n");
        return false;
    }
    pArray -> elements[position] = newItem;
    return true;
}

//vesszuk sorra a labdakat az elso for-ba es ha megfelel a feltetelnek
//akkor attol a poziciotol tovabb az osszeset egyel elorebb csusztattjuk
void labda_torol(LabdaArray *pArray) {
    for (int i = 0; i < pArray->size; i++) {
        if (getItemAt(*pArray, i).atmero > 15) {
            for (int j = i; j < pArray->size - 1; ++j) {
                update(pArray, j, getItemAt(*pArray, j + 1));
            }
            pArray->size--;
            i--; // Mivel töröltünk egy elemet, nem lépünk tovább, hanem újra megnézzük az i-edik elemet
        }
    }
}


int szamol_alairt(LabdaArray array) {
    int db = 0;
    for (int i = 0; i < array.size; i++) {
        if (array.elements[i].ala_irt == 1) {
            db++;
        }
    }
    return db;
}

int compare(const void *p1, const void *q1) {
    Labda p2 = (*(Labda *)p1);
    Labda q2 = (*(Labda *)q1);

    if (p2.atmero > q2.atmero) return 1;
    else if(p2.atmero < q2.atmero) return -1;
    else return 0;
}
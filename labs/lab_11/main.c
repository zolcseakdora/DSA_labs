#include <stdio.h>
#include "barat/lista.h"
int main(void)
{
    if (!freopen("../barat.txt", "r", stdin)) {
        perror("Nem sikerült megnyitni a fájlt");
        return 1;
    }
    Barat uj;
    Node *head=NULL;
    while (scanf("%[^;];%d;%d;%d;%c;%d\n",
                 uj.nev,
                 &uj.szuletesiDatum.ev,
                 &uj.szuletesiDatum.honap,
                 &uj.szuletesiDatum.nap,
                 &uj.nem,
                 &uj.bulizas) == 6)
    {
        uj.eletkor = eletkor(uj.szuletesiDatum);
        insertAtEnd(&head, uj);
    }
    printList(head);
    char neveket[100][100];
    int db = elegBaratBulira(head, neveket);

    printf("\n--- Bulira hivhato baratok ---\n");
    if (db >= 10) {
        printf("Johet a buli \nNévlista:\n");
        for (int i = 0; i < db; i++) {
            printf("- %s\n", neveket[i]);
        }
    } else {
        printf("szomorusag, az en barataim nem akrnak bulizni \n");
    }
    return 0;
}


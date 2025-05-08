#include <stdio.h>
#include "linked_list.h"

int main(void) {
    int num1, num2;
    Node *list1 = NULL, *list2 = NULL, *sumList = NULL;

    printf("Adj meg ket szamot: ");
    scanf("%d %d", &num1, &num2);

    getDigitList(num1, &list1);
    getDigitList(num2, &list2);

    printf("1. szam lista: ");
    printList(list1);
    printf("\n2. szam lista: ");
    printList(list2);

    addDigitLists(list1, list2, &sumList);
    printf("\nOsszeg lista: ");
    printList(sumList);

    int sumValue = listToInteger(sumList);
    printf("\nOsszeg ertek (szamkent): %d\n", sumValue);

    insertZeroAfterEven(&sumList);
    printf("\nParos szamjegyek utan 0 beszurasa: ");
    printList(sumList);

    insertAtBeginning(&sumList, 1);
    insertAtEnd(&sumList, 1);
    printf("\n1 beszurasa az elejere es vegere: ");
    printList(sumList);

    int toDelete;
    printf("\nAdj meg egy szamot, amit torolni szeretnel a listabol: ");
    scanf("%d", &toDelete);

    if (searchNode(sumList, toDelete)) {
        deleteNode(&sumList, toDelete);
        printf("Torles utan: ");
        printList(sumList);
    } else {
        printf("A megadott szam nincs a listaban.\n");
    }

    sortLinkedList(sumList);
    printf("\nRendezett lista novekvo sorrendben: ");
    printList(sumList);
    printf("\n");
    freeList(sumList);
    return 0;
}

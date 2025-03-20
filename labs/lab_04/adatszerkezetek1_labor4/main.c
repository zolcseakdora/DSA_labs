#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/array.h"

int main() {
    IntArray array;
    createIntArray(10, &array);
    printArray(array);
    for (int i = 1; i <= 5; i++) {
        insertLast(&array, i);
    }
    printArray(array);
    for (int i = 10 + 1; i <= 2 * 10; i++) {
        if (i % 2 == 0) {
            insertFirst(&array, i);
        } else {
            insertLast(&array, i);
        }
    }
    printArray(array);
    int num;
    scanf("%d", &num);
    int pos = search(array, num);
    if (pos != -1) {
        printf("Talalhato a %d -s a kovetkezo pozicion %d\n", num, pos);
    } else {
        printf("ez a szam %d nem talalhato a tombe.\n", num);
    }
    if (pos != -1) {
        int newNum;
        scanf("%d", &newNum);
        if (update(&array, pos, newNum)) {
            printArray(array);
        } else {
            printf("Update failed.\n");
        }
    }
    srand(time(NULL));
    while (!isEmpty(array)) {
        int randomPos = rand() % array.size;
        deleteItemAt(&array, randomPos);
        printf("Deleted item at position %d. Array now:\n", randomPos);
        printArray(array);
    }
    deallocateIntArray(&array);
    return 0;
}

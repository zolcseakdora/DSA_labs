#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "intarray_headers/intarray.h"
#include "product_headers/product.h"

int main() {
    Product_t *pProducts = NULL;
    int numberOfProducts = 0;

    // Beolvassuk az összes termék adatait
    readAllProductsDetails(&pProducts, &numberOfProducts, "input.txt");

    // Az összes termék kiírása
    printf("\nAll Products:\n");
    printAllProducts(pProducts, numberOfProducts, "output.txt");

    // Rendezés név szerint
    printf("\nProducts Sorted by Name:\n");
    sortProductsByName(pProducts, numberOfProducts);
    printAllProducts(pProducts, numberOfProducts, "output.txt");

    // Rendezés gyártási dátum és ár szerint
    printf("\nProducts Sorted by Manufacture Date and Price:\n");
    sortProductsByManufactureDateAndPrice(pProducts, numberOfProducts);
    printAllProducts(pProducts, numberOfProducts, "output.txt");

    // Keresés vonalkód alapján
    char barcodeToFind[10];
    printf("\nEnter barcode to search: ");
    scanf("%9s", barcodeToFind);
    Product_t *foundProduct = (Product_t*)findProductByBarcode(pProducts, numberOfProducts, barcodeToFind);
    if (foundProduct != NULL) {
        printf("\nProduct found:\n");
        printProduct(*foundProduct);
    } else {
        printf("\nProduct with barcode %s not found.\n", barcodeToFind);
    }

    // Keresés egy adott beszállítótól származó termékekről
    char supplierToFind[50];
    printf("\nEnter supplier name to search: ");
    scanf("%49s", supplierToFind);
    printf("\nProducts from supplier '%s':\n", supplierToFind);
    printProductsFromSpecificSupplier(pProducts, numberOfProducts, supplierToFind);

    // Kategóriák szerinti termékszám
    int fruitCount = getNumberOfProductsByCategory(pProducts, numberOfProducts, FRUIT);
    printf("\nNumber of products in FRUIT category: %d\n", fruitCount);

    // Felszabadítjuk a lefoglalt memóriát
    free(pProducts);

    //INTARRAY
    IntArray_t myArray;

    // Létrehozzuk a dinamikus tömböt kapacitással 5
    createIntArray_t(5, &myArray);

    // Hozzáadunk néhány elemet
    insertLast(&myArray, 10);
    insertLast(&myArray, 20);
    insertLast(&myArray, 30);
    insertFirst(&myArray, 5);
    insertAt(&myArray, 2, 15); // Hozzáadunk 15-öt a harmadik helyre

    // Adatok betöltése fájlból
    //loadIntArrayFromFile(&myArray, filename);

    // Kiíratjuk a tömb elemeit
    printf("Array elements after insertions: \n");
    printArray(myArray);

    // Keresünk egy elemet (például 15)
    int pos = search(myArray, 15);
    if (pos != -1) {
        printf("Element 15 found at position %d\n", pos);
    } else {
        printf("Element 15 not found\n");
    }

    // Törlünk egy elemet egy adott pozícióról (pl. 2. pozíció)
    deleteItemAt(&myArray, 2);

    // Kiíratjuk a tömb elemeit törlés után
    printf("Array elements after deletion: \n");
    printArray(myArray);

    // Módosítunk egy elemet (pl. a 0. pozíción lévő elemet 100-ra)
    if (update(&myArray, 0, 100)) {
        printf("Array after updating element at position 0 to 100: \n");
        printArray(myArray);
    } else {
        printf("Update failed\n");
    }

    // Kiíratunk egy elemet egy adott pozícióról (pl. 1. pozíció)
    int item = getItemAt(myArray, 1);
    if (item != INT_MIN) {
        printf("Element at position 1 is: %d\n", item);
    } else {
        printf("Invalid position\n");
    }

    // Felszabadítjuk a memóriahelyet
    deallocateIntArray_t(&myArray);

    return 0;
}
/*
//Tömb elemeinek a kiírása
int LA[] = {1,3,5,7,8};
int item = 10, k = 3, n = 5;
int i = 0, j = n;
printf("The array elements are :\n");
for(i = 0; i<n; i++) {
    printf("LA[%d] = %d \n", i, LA[i]);
}
//Egy elem beszúrása adott pozícióra
int LA[] = {1,3,5,7,8};
int item = 10, k = 3, n = 5; int i = 0, j = n;
printf("The original array elements are :\n");
for(i = 0; i<n; i++)
{ printf("LA[%d] = %d \n", i, LA[i]); }
n = n + 1;
while( j >= k)
{ LA[j+1] = LA[j]; j = j - 1; }
LA[k] = item;
printf("The array elements after insertion :\n");
for(i = 0; i<n; i++) { printf("LA[%d] = %d \n", i, LA[i]); } }

//Adott indexű elem törlése
int LA[] = {1,3,5,7,8};
int k = 3, n = 5;
int i, j;
printf("The original array elements are :\n");
for(i = 0; i<n; i++) {
    printf("LA[%d] = %d \n", i, LA[i]);
}
j = k;
while( j < n) {
    LA[j-1] = LA[j];
    j = j + 1;
}
n = n -1;
printf("The array elements after deletion :\n");
for(i = 0; i<n; i++) {
    printf("LA[%d] = %d \n", i, LA[i]); }

//Adott értékű elem keresése
int LA[] = {1,3,5,7,8};
int item = 5, n = 5;
int i = 0, j = 0;
printf("The original array elements are :\n");
for(i = 0; i<n; i++) {
printf("LA[%d] = %d \n", i, LA[i]);
}
while( j < n){
if( LA[j] == item ) {
break;
}
j = j + 1;
}
printf("Found element %d at position %d\n", item,
j+1);

//Adott indexű elem értékének módosítása
int LA[] = {1,3,5,7,8};
int k = 3, n = 5, item = 10;
int i, j;
printf("The original array elements are :\n");
for(i = 0; i<n; i++) {
printf("LA[%d] = %d \n", i, LA[i]);
}
LA[k-1] = item;
printf("The array elements after updation :\n");
for(i = 0; i<n; i++) {
printf("LA[%d] = %d \n", i, LA[i]);
}
    */
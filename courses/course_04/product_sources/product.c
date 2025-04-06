//
// Created by Dora on 2025. 04. 06..
//

#include "../product_headers/product.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Fájl beolvasása, termékek tömbbe töltése
void loadProductsFromFile(Product_t **dpProducts, int *numberOfProducts, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Fájl első sora: szám, hogy hány terméket tartalmaz
    fscanf(file, "%d", numberOfProducts);

    // Memóriafoglalás a termékeknek
    allocateMemoryForProducts(dpProducts, *numberOfProducts);

    // Fájl beolvasása termékek adatainak hozzáadása
    for (int i = 0; i < *numberOfProducts; i++) {
        fscanf(file, "%29s", (*dpProducts)[i].name);      // product name
        fscanf(file, "%9s", (*dpProducts)[i].barcode);    // barcode
        fscanf(file, "%49s", (*dpProducts)[i].supplier);  // supplier
        fscanf(file, "%d", &(*dpProducts)[i].dateOfManufacture.year); // year of manufacture
        int category;
        fscanf(file, "%d", &category);   // category
        (*dpProducts)[i].category = (Category)category;  // Set enum value
        fscanf(file, "%f", &(*dpProducts)[i].price);     // price
    }

    fclose(file);
}

void readProductDetails(Product_t *pProduct) {
    printf("Enter product name: ");
    scanf("%29s", pProduct->name);
    printf("Enter barcode: ");
    scanf("%9s", pProduct->barcode);
    printf("Enter supplier: ");
    scanf("%49s", pProduct->supplier);
    printf("Enter year of manufacture: ");
    scanf("%d", &pProduct->dateOfManufacture.year);
    printf("Enter category (0-FRUIT, 1-VEGETABLE, 2-DIARY, 3-OTHER): ");
    scanf("%d", (int*)&pProduct->category);
    printf("Enter price: ");
    scanf("%f", &pProduct->price);
}
void printProduct(Product_t product) {
    printf("Name: %s\n", product.name);
    printf("Barcode: %s\n", product.barcode);
    printf("Supplier: %s\n", product.supplier);
    printf("Year of Manufacture: %d\n", product.dateOfManufacture.year);
    printf("Category: %d\n", product.category);
    printf("Price: %.2f\n", product.price);
}
void allocateMemoryForProducts(Product_t **dpProducts, int numberOfProducts) {
    *dpProducts = (Product_t*)malloc(numberOfProducts * sizeof(Product_t));
    if (*dpProducts == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
}
void readAllProductsDetails(Product_t **dpProducts, int *numberOfProducts, const char *input) {
    printf("Enter the number of products: ");
    scanf("%d", numberOfProducts);
    allocateMemoryForProducts(dpProducts, *numberOfProducts);
    for (int i = 0; i < *numberOfProducts; i++) {
        printf("Enter details for product %d:\n", i + 1);
        readProductDetails(&(*dpProducts)[i]);
    }
}
void printAllProducts(Product_t *pProducts, int numberOfProducts, const char *destination) {
    for (int i = 0; i < numberOfProducts; i++) {
        printf("Product %d:\n", i + 1);
        printProduct(pProducts[i]);
    }
}
int getNumberOfProductsByCategory(Product_t *pProducts, int numberOfProducts, Category category) {
    int count = 0;
    for (int i = 0; i < numberOfProducts; i++) {
        if (pProducts[i].category == category) {
            count++;
        }
    }
    return count;
}
void printProductsFromSpecificSupplier(Product_t *pProducts, int numberOfProducts, const char *supplier) {
    for (int i = 0; i < numberOfProducts; i++) {
        if (strcmp(pProducts[i].supplier, supplier) == 0) {
            printProduct(pProducts[i]);
        }
    }
}
void* findProductByBarcode(Product_t *pProducts, int numberOfProducts, const char *barcode) {
    // Iteráljunk végig az összes terméken
    for (int i = 0; i < numberOfProducts; ++i) {
        // Összehasonlítjuk az aktuális termék vonalkódját a megadott vonalkóddal
        if (strcmp(pProducts[i].barcode, barcode) == 0) {
            // Ha találunk egyezést, visszaadjuk a termék címét
            return &pProducts[i];
        }
    }
    // Ha nem találtunk egyezést, visszaadjuk a NULL értéket
    return NULL;
}
void sortProductsByName(Product_t *pProducts, int numberOfProducts) {
    for (int i = 0; i < numberOfProducts - 1; i++) {
        for (int j = i + 1; j < numberOfProducts; j++) {
            if (strcmp(pProducts[i].name, pProducts[j].name) > 0) {
                Product_t temp = pProducts[i];
                pProducts[i] = pProducts[j];
                pProducts[j] = temp;
            }
        }
    }
}
void sortProductsByManufactureDateAndPrice(Product_t *pProducts, int numberOfProducts) {
    for (int i = 0; i < numberOfProducts - 1; i++) {
        for (int j = i + 1; j < numberOfProducts; j++) {
            if (pProducts[i].dateOfManufacture.year > pProducts[j].dateOfManufacture.year ||
                (pProducts[i].dateOfManufacture.year == pProducts[j].dateOfManufacture.year &&
                 pProducts[i].price > pProducts[j].price)) {
                Product_t temp = pProducts[i];
                pProducts[i] = pProducts[j];
                pProducts[j] = temp;
                 }
        }
    }
}

#include <stdio.h>
#include "headers/functionsh.h"
#include <stdlib.h>

int main()
{
    int rows, cols;
    char **matrix;
    readMatrix(rows, cols, &matrix, "matrix.txt");
    int columnIndex;
    scanf("%d", &columnIndex);
    if (columnIndex >= 0 && columnIndex < cols) {
        char minChar = minimumValueOfColumn(rows, columnIndex, matrix);
        printf("A legkisebb karakter a(z) %d. oszlopban: %c\n", columnIndex, minChar);
    } else {
        printf("Hibás oszlopszám!\n");
    }
    deallocateMemoryForMatrix(rows, &matrix);
        return 0;
}

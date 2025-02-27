//
// Created by Dora on 2025. 02. 23..
//

#include <stdlib.h>
#include "../headers/functionsh.h"
#include <stdio.h>

void allocateMemoryForMatrix2(int rows, int cols, char ***dpMatrix)
{
    **dpMatrix=(char**)malloc(rows*sizeof(char*));
    if (!**dpMatrix)
    {
        exit(-1);
    }
    for (int i=0; i<rows; ++i)
    {
        *dpMatrix=(char*)malloc(cols*sizeof(char));
        if (!*dpMatrix)
        {
            exit(-2);
        }
    }
}
void readMatrix(int *pRows, int *pCols, char ***dpArray, const char *in)
{
    FILE *in_file=fopen(in,"r");
    if (!in) {
        exit(-1);
    }
    fscanf(in_file,"%i%i",&pRows, &pCols);
    allocateMemoryForMatrix2(pRows,pCols,dpArray);
    for (int i=0; i<*pRows; ++i)
    {
        for (int j=0; j<*pCols; ++j)
        {
            fscanf(in_file,"%c", &dpArray[i][j]);
        }
    }
    fclose(in_file);
}
void printMatrix(int rows, int cols, int **pMatrix, const char *out)
{
    FILE *out_file=fopen(out,"w");
    if (!out) {
        exit(-2);
    }
    for (int i=0; i<rows; ++i)
    {
        for (int j=0; j<cols; ++j)
        {
            fprintf(out_file,"%c ",pMatrix[i][j]);
        }
        fprintf(out_file, "\n");
    }
    fclose(out_file);
}
char minimumValueOfColumn(int rows, int columnIndex, char **pMatrix) {
    char minChar = pMatrix[0][columnIndex];
    for (int i = 1; i < rows; i++) {
        if (pMatrix[i][columnIndex] < minChar) {
            minChar = pMatrix[i][columnIndex];
        }
    }
    return minChar;
}
void deallocateMemoryForMatrix(int rows, char ***dpMatrix)
{
    for (int i=0; i<rows; ++i)
    {
        free(*dpMatrix);
    }
    free(*dpMatrix);
    *dpMatrix=NULL;
}
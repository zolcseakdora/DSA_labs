//
// Created by Dora on 2025. 02. 23..
//

#ifndef FUNCTIONSH_H
#define FUNCTIONSH_H

void allocateMemoryForMatrix2(int rows, int cols, char ***dpMatrix);
void readMatrix(int *pRows, int *pCols, char ***dpArray, const char *in);
void printMatrix(int rows, int cols, int **pMatrix, const char *out);
char minimumValueOfColumn(int rows, int columnIndex, char **pMatrix);
void deallocateMemoryForMatrix(int rows, char ***dpMatrix);

#endif

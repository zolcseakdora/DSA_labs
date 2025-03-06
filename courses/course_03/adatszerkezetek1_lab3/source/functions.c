//
// Created by Dora on 2025. 03. 06..
//

#include "../headers/functions.h"
#include <stdio.h>
#include <stdlib.h>
void readStudentDetails(Student_t *pStudent)
{
    scanf(" %[^\n]", pStudent->name);
    scanf("\n%[^\n]", pStudent->neptunCode);
    scanf("\n%[^\n]", pStudent->birthPlace);
    scanf("%d", &pStudent->birthDate.year);
    scanf("%d", &pStudent->birthDate.month);
    scanf("%d", &pStudent->birthDate.day);
    scanf("%d",&pStudent->gender);
    scanf("%f", &pStudent->examResult);
}

char *getGenderTextValue(enum Gender gender)
{
    switch (gender) {
    case FEMALE:
        return "female";
    case MALE:
        return "male";
    default:
        return "other";
    }
}

void printStudent(Student_t student)
{
    printf("Name: %s\n", student.name);
    printf("Neptun Code: %s\n", student.neptunCode);
    printf("Birth Place: %s\n", student.birthPlace);
    printf("Birth Date: %d %d %d\n", student.birthDate.year, student.birthDate.month, student.birthDate.day);
    printf("Gender: %s\n", getGenderTextValue(student.gender));
    printf("Exam Result: %.2f\n", student.examResult);
}
void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents)
{
    *dpStudents = (Student_t*)malloc(numberOfStudents*sizeof(Student_t));
    if (!*dpStudents)
    {
        exit(-1);
    }
}
void readAllStudentsDetails(Student_t **dpStudents, int *numberOfStudents, const char *input)
{
    FILE *file = fopen(input, "r");
    if (!file)
    {
        exit(-1);
    }
    fscanf(file,"%d", numberOfStudents);
    allocateMemoryForStudents(dpStudents,*numberOfStudents);
    for (int i = 0; i < *numberOfStudents; i++) {
        fscanf(file, " %50[^\n] %8[^\n] %25[^\n] %d %d %d %d %f",
               (*dpStudents)[i].name,
               (*dpStudents)[i].neptunCode,
               (*dpStudents)[i].birthPlace,
               &(*dpStudents)[i].birthDate.year,
               &(*dpStudents)[i].birthDate.month,
               &(*dpStudents)[i].birthDate.day,
               (int*)&(*dpStudents)[i].gender,
               &(*dpStudents)[i].examResult);
    }
    fclose(file);
}
void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination)
{
    FILE *outputFile = fopen(destination, "w");
    if (!outputFile)
    {
        exit(-1);
    }
    for (int i = 0; i < numberOfStudents; i++) {
        fprintf(outputFile, "Name: %s\n", pStudents[i].name);
        fprintf(outputFile, "Neptun Code: %s\n", pStudents[i].neptunCode);
        fprintf(outputFile, "Birth Place: %s\n", pStudents[i].birthPlace);
        fprintf(outputFile, "Birth Date: %d-%02d-%02d\n",pStudents[i].birthDate.year,pStudents[i].birthDate.month,pStudents[i].birthDate.day);
        fprintf(outputFile, "Gender: %s\n", getGenderTextValue(pStudents[i].gender));
        fprintf(outputFile, "Exam Result: %.2f\n\n", pStudents[i].examResult);
    }

    fclose(outputFile);

}
void calculatePercentageBoysGirls (Student_t **dpStudents, int numberOfStudents)
{
    int males = 0, females = 0;
    for (int i = 0; i < numberOfStudents; i++) {
        if ((*dpStudents)[i].gender == MALE) males++;
        else if ((*dpStudents)[i].gender == FEMALE) females++;
    }
    float malearany = (males / (float)numberOfStudents)*100;
    float femalearany = (females / (float)numberOfStudents)*100;
    printf("Male: %.2f\nFemale: %.2f\n", malearany, femalearany);
}
void deallocate(Student_t **pStudent)
{
    free(*pStudent);
    *pStudent=NULL;
}



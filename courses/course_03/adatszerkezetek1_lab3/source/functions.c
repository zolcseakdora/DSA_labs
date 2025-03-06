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
    FILE *file = fopen("students.txt", "r");
    if (!file)
    {
        exit(-1);
    }
    fscanf(file,"%d", numberOfStudents);
    allocateMemoryForStudents(dpStudents,*numberOfStudents);
    for (int i = 0; i < *numberOfStudents; i++)
    {
        readStudentDetails(&(*dpStudents)[i]);
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
        outputFile=printStudent(pStudents[i]);
    }
    fclose(outputFile);

}
void deallocate(Student_t **pStudent)
{
    free(*pStudent);
    *pStudent=NULL;
}



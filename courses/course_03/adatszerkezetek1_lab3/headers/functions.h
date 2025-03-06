//
// Created by Dora on 2025. 03. 06..
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
typedef struct Date_t
{
    int year, month,day;
}Date_t;
enum Gender
{
    FEMALE,MALE
};
typedef struct students
{
    char name[51];
    char neptunCode[9];
    char birthPlace[26];
    Date_t birthDate;
    enum Gender gender;
    float examResult;
}Student_t;
void readStudentDetails(Student_t *pStudent);
char *getGenderTextValue(enum Gender gender);
void printStudent(Student_t student);
void readAllStudentsDetails(Student_t **dpStudents, int *numberOfStudents, const char *input);
void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents);
void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination);
void calculatePercentageBoysGirls (Student_t **dpStudents, int numberOfStudents);
void deallocate(Student_t **pStudent);

#endif //FUNCTIONS_H

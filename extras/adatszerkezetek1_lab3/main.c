#include <stdio.h>
#include "headers/functions.h"

int main(void)
{
    Student_t student1={
        "Zolcseak Dora",
        "HKT2CZ",
        "Szatmarnemeti",
        {2005,10,12},
        FEMALE,
        9.20
    };
    printStudent(student1);
    Student_t student2;
    readStudentDetails(&student2);
    printStudent(student2);
    Student_t *students;
    int numberOfStudents = 0;
    readAllStudentsDetails(&students, &numberOfStudents, "input.txt");
    printAllStudents(students, numberOfStudents, "students_output.txt");
    printf("\nFiuk es lanyok aranya:\n");
    calculatePercentageBoysGirls(&students, numberOfStudents);
    printf("\nAkik budapesten szulettek:\n");
    printStudentsFromSpecificCity(students, numberOfStudents, "Budapest");
    printf("\nakiknek ez a neptun kodjuk 'QSTRG9' :\n");
    findStudentByNeptunCode(students,numberOfStudents,"QSTRG9");
    sortStudentsByName(students, numberOfStudents);
    printAllStudents(students, numberOfStudents, "abc_order.txt");
    sortStudentsByAgeAndExam(students, numberOfStudents);
    printAllStudents(students, numberOfStudents, "birth_exam_order.txt");
    deallocate(&students);
    return 0;
}

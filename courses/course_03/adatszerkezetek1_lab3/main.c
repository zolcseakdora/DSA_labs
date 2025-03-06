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
    readAllStudentsDetails(&students, &numberOfStudents, "students.txt");
    printAllStudents()
    deallocate(&students);
    return 0;
}

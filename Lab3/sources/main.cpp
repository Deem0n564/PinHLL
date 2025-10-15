#include "functions.h"

int main() 
{
    Student *stud = nullptr;
    Employee *empl = nullptr;
    int quantityStudents = 0;
    int quantityEmployees = 0;

    menu(&quantityStudents, &quantityEmployees, &stud, &empl);

    return 0;
}
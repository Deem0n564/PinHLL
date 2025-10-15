#include "Student.h"
#include "Employee.h"

int main() 
{
    std::string name; 
    std::string position;
    int birthYear;
    int averageGrade;
    int salary;
    
    std::cout << "\t Enter the student: fio, year of birth, average grades:\n";
    std::cin >> name >> birthYear >> averageGrade;

    Student s(name, birthYear, averageGrade);
   
    std::cout << "\t Enter the employee: fio, year of birth, position, salary:\n";
    std::cin >> name >> birthYear >> position >> salary;

    Employee e(name, birthYear, position, salary);

    s.print();
    e.print();

    return 0;
}
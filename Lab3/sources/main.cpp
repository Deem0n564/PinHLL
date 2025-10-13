#include "Student.h"
#include "Employee.h"

int main() {
    Student s("Ivanov I.I.", 2001, 4.25);
    s.print();

    s.setAverage(4.5);
    std::cout << "Updated average: " << s.getAverage() << '\n';

    Employee e("Petrov P.P.", 1985, "Engeneer", 2000);
    e.print();

    return 0;
}
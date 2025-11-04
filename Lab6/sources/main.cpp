#include "functions.h"

int main()
{
    Student* stud = nullptr;
    Employee* empl = nullptr;
    int quantityStudents = 0;
    int quantityEmployees = 0;

    try
    {
        menu(&quantityStudents, &quantityEmployees, &stud, &empl);
    }

    catch (const std::bad_alloc&)
    {
        std::cerr << "Fatal: not enough memory\n";

        delete[] stud;
        delete[] empl;

        return 1;
    }

    catch (const std::exception& ex)
    {
        std::cerr << "Unhandled exception: " << ex.what() << '\n';

        delete[] stud;
        delete[] empl;

        return 2;
    }

    return 0;
}

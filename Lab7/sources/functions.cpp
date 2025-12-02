#include "functions.h"

template<typename T>
void addObjectToFileEnd(const std::string& filename, const T& value)
{
    std::ofstream file(filename, std::ios::binary | std::ios::app);

    if (!file.is_open())
    {
        throw FileException("Cannot open file for writing: " + filename);
    }

    file.write(reinterpret_cast<const char*>(&value), sizeof(T));

    if (!file)
    {
        throw FileException("Write error in file: " + filename);
    }

    file.close();
}

template <>
void addObjectToFileEnd(const std::string& filename, const char(&value)[50])
{
    std::ofstream file(filename, std::ios::binary | std::ios::app);

    if (!file.is_open())
    {
        throw FileException("Cannot open file for writing: " + filename);
    }

    file.write(value, 50);

    if (!file)
    {
        throw FileException("Write error in file: " + filename);
    }
    file.close();
}

template<typename T>
size_t getFileObjectCount(const std::string& filename)
{
    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    if (!file.is_open())
    {
        return 0;
    }

    size_t size = file.tellg();
    file.close();

    return size / sizeof(T);
}

template void addObjectToFileEnd<int>(const std::string&, const int&);
template void addObjectToFileEnd<Product>(const std::string&, const Product&);
template size_t getFileObjectCount<int>(const std::string&);
template size_t getFileObjectCount<Product>(const std::string&);

int getInputInt()
{
    int input = 0;
    while (true)
    {
        if (std::cin >> input)
        {
            std::cin.ignore(100, '\n');
            return input;
        }

        else
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Incorrect! Please enter a valid integer: ";
        }
    }
}

size_t getFileSize(const std::string& filename)
{
    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    if (!file.is_open())
    {
        return 0;
    }

    size_t size = file.tellg();
    file.close();

    return size;
}

std::ostream& operator<<(std::ostream& os, const Product& p)
{
    os << p.name << " " << p.price;

    return os;
}

void inputString(char* str, int size)
{
    std::string temp;
    std::getline(std::cin, temp);

    if (!temp.empty()) 
    {
        int copySize = temp.size();

        if (copySize > (size - 1)) 
        {
            copySize = size - 1;
        }

        std::copy(temp.begin(), temp.begin() + copySize, str);
        str[copySize] = '\0';
    }
    else 
    {
        str[0] = '\0';
    }
}

Product inputProduct()
{
    Product p;
    std::cout << "Enter product details:\n";

    std::cout << "Name: ";
    inputString(p.name, 50);

    std::cout << "Price: ";
    p.price = getInputInt();

    return p;
}

void printProduct(const Product& p)
{
    std::cout << "Product{Name: \"" << p.name << "\", Price: " << p.price << "}";
}

void inputObjectToFile(const std::string& filename)
{
    std::cout << "Choose data type:\n";
    std::cout << "1. Integer\n";
    std::cout << "2. Product\n";
    std::cout << "3. String\n";
    std::cout << "Your choice: ";

    int choice = getInputInt();

    try
    {
        switch (choice)
        {
        case 1:
        {
            std::cout << "Enter integer value: ";
            int value = getInputInt();
            addObjectToFileEnd(filename, value);
            std::cout << "Integer " << value << " added to file.\n";

            break;
        }
        case 2:
        {
            Product value = inputProduct();
            addObjectToFileEnd(filename, value);
            std::cout << "Product added to file: ";
            printProduct(value);
            std::cout << "\n";

            break;
        }

        case 3:
        {
            char strValue[50] = { 0 };
            std::cout << "Enter string: ";
            inputString(strValue, 50);
            addObjectToFileEnd(filename, strValue);
            std::cout << "String \"" << strValue << "\" added to file.\n";

            break;
        }

        default:
            std::cout << "Invalid choice!\n";

            break;
        }
    }
    catch (const FileException& e)
    {
        std::cerr << "File Error: " << e.what() << "\n";
    }
}

void readObjectByIndex(const std::string& filename)
{
    std::cout << "Choose data type to read:\n";
    std::cout << "1. Integer\n";
    std::cout << "2. Product\n";
    std::cout << "3. String\n";
    std::cout << "Your choice: ";

    int typeChoice = getInputInt();

    try
    {
        switch (typeChoice)
        {
        case 1:
        {
            FileReader<int> reader(filename);
            size_t objectCount = reader.getObjectCount();

            if (objectCount == 0) 
            {
                std::cout << "File is empty!\n";

                return;
            }

            std::cout << "Enter index (0 to " << objectCount - 1 << "): ";
            int index = getInputInt();

            if (index < 0 || index >= objectCount) 
            {
                std::cout << "Index out of range!\n";

                return;
            }

            int value = reader[index];
            std::cout << "Integer at index " << index << ": " << value << "\n";

            break;
        }

        case 2:
        {
            FileReader<Product> reader(filename);
            size_t objectCount = reader.getObjectCount();

            if (objectCount == 0) 
            {
                std::cout << "File is empty!\n";

                return;
            }

            std::cout << "Enter index (0 to " << objectCount - 1 << "): ";
            int index = getInputInt();

            if (index < 0 || index >= objectCount) 
            {
                std::cout << "Index out of range!\n";

                return;
            }

            Product value = reader[index];
            std::cout << "Product at index " << index << ": ";
            printProduct(value);
            std::cout << "\n";

            break;
        }

        case 3:
        {
            struct TempString { char data[50]; };

            FileReader<TempString> reader(filename);
            size_t objectCount = reader.getObjectCount();

            if (objectCount == 0) 
            {
                std::cout << " File is empty!\n";

                return;
            }

            std::cout << " Enter index (0 to " << objectCount - 1 << "): ";
            int index = getInputInt();

            if (index < 0 || index >= objectCount) 
            {
                std::cout << " Index out of range!\n";

                return;
            }

            TempString temp = reader[index];
            std::cout << " String at index " << index << ": \"" << temp.data << "\"\n";

            break;
        }

        default:
            std::cout << " Invalid choice!\n";

            break;
        }
    }
    catch (const FileException& e)
    {
        std::cerr << "File Error: " << e.what() << "\n";
    }
}
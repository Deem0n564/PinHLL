#include "functions.h"

int main()
{
    std::string filename = "data.bin";

    while (true)
    {
        std::cout << "\tMENU"
            << "\n 1. Input integer (to end of file)"
            << "\n 2. Read integer by index"
            << "\n 3. Read byte by index"
            << "\n 4. Clear file"
            << "\n 0. Exit"
            << "\n Your choice: ";

        int choice;
        std::cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
            {
                std::cout << " Enter integer to file: ";
                int value;
                std::cin >> value;
                addIntToFileEnd(filename, value);
                std::cout << " Integer " << value << " added to file." << std::endl;

                break;
            }

            case 2:
            {
                int fileSize = getFileSize(filename);

                if (fileSize == 0)
                {
                    std::cout << " File is empty!" << std::endl;

                    break;
                }

                int maxIndex = fileSize / sizeof(int) - 1;
                std::cout << " Enter index (0 to " << maxIndex << "): ";
                int index;
                std::cin >> index;
                FileReader<int> arr(filename);
                int value = arr[index];
                std::cout << " Integer at index " << index << ": " << value << std::endl;

                break;
            }

            case 3:
            {
                int fileSize = getFileSize(filename);

                if (fileSize == 0)
                {
                    std::cout << " File is empty!" << std::endl;

                    break;
                }

                std::cout << " Enter byte index (0 to " << fileSize - 1 << "): ";
                int index;
                std::cin >> index;
                FileReader<std::byte> byteArr(filename);
                std::byte byte = byteArr[index];
                std::cout << " Byte at index " << index << ": "
                    << static_cast<int>(byte) << std::endl;

                break;
            }

            case 4:
            {
                FileReader<int>::clearFile(filename);
                std::cout << " File cleared successfully!" << std::endl;

                break;
            }

            case 0:
            {
                std::cout << "\n Exit...\n\n" << std::endl;

                return 0;
            }

            default:
            {
                std::cout << " Invalid option!" << std::endl;

                break;
            }
            }
        }
        catch (const FileException& e)
        {
            std::cerr << " File Error: " << e.what() << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << " Error: " << e.what() << std::endl;
        }
    }
}
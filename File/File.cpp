#include <iostream>
#include <fstream>
#include <string>

class FileHandler {
public:
    static void copy(const std::string& sourceFile, const std::string& destinationFile) {
        try {
            std::ifstream source(sourceFile);
            std::ofstream destination(destinationFile);

            if (!source.is_open() || !destination.is_open()) {
                throw std::runtime_error("Unable to open files");
            }

            destination << source.rdbuf();

            source.close();
            destination.close();

            std::cout << "File content copied successfully." << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    static void remove(const std::string& filePath) {
        try {
            if (std::remove(filePath.c_str()) != 0) {
                throw std::runtime_error("Error deleting file");
            }
            std::cout << "File " << filePath << " deleted successfully." << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    static void rename(const std::string& oldName, const std::string& newName) {
        try {
            if (std::rename(oldName.c_str(), newName.c_str()) != 0) {
                throw std::runtime_error("Error renaming file");
            }
            std::cout << "File " << oldName << " renamed to " << newName << " successfully." << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
};

int main() {
    int choice;
    std::string sourceFile, destinationFile;

    do {
        std::cout << "\n1. Copy file content\n2. Remove file\n3. Rename file\n4. Exit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter source file path: ";
            std::cin >> sourceFile;
            std::cout << "Enter destination file path: ";
            std::cin >> destinationFile;
            FileHandler::copy(sourceFile, destinationFile);
            break;
        case 2:
            std::cout << "Enter file path to be removed: ";
            std::cin >> sourceFile;
            FileHandler::remove(sourceFile);
            break;
        case 3:
            std::cout << "Enter old file path: ";
            std::cin >> sourceFile;
            std::cout << "Enter new file path: ";
            std::cin >> destinationFile;
            FileHandler::rename(sourceFile, destinationFile);
            break;
        case 4:
            std::cout << "Exiting program...\n";
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}

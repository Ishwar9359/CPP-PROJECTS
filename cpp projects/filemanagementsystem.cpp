#include <iostream>
#include <filesystem>
#include <string>
#include <fstream> 

namespace fs = std::filesystem;

class FileManager {
public:
    void createFile(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            std::cout << "File created: " << filename << "\n";
        } else {
            std::cerr << "Error creating file: " << filename << "\n";
        }
    }

    void createDirectory(const std::string& dirname) {
        if (fs::create_directory(dirname)) {
            std::cout << "Directory created: " << dirname << "\n";
        } else {
            std::cerr << "Error creating directory: " << dirname << "\n";
        }
    }

    void listContents(const std::string& path = ".") {
        for (const auto& entry : fs::directory_iterator(path)) {
            std::cout << entry.path().filename() << "\n";
        }
    }

    void deleteFile(const std::string& filename) {
        if (fs::remove(filename)) {
            std::cout << "File deleted: " << filename << "\n";
        } else {
            std::cerr << "Error deleting file: " << filename << "\n";
        }
    }

    void deleteDirectory(const std::string& dirname) {
        if (fs::remove_all(dirname)) {
            std::cout << "Directory deleted: " << dirname << "\n";
        } else {
            std::cerr << "Error deleting directory: " << dirname << "\n";
        }
    }
};

int main() {
    FileManager fileManager;

    char choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Create File\n";
        std::cout << "2. Create Directory\n";
        std::cout << "3. List Contents\n";
        std::cout << "4. Delete File\n";
        std::cout << "5. Delete Directory\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                std::string filename;
                std::cout << "Enter filename: ";
                std::cin >> filename;
                fileManager.createFile(filename);
                break;
            }
            case '2': {
                std::string dirname;
                std::cout << "Enter directory name: ";
                std::cin >> dirname;
                fileManager.createDirectory(dirname);
                break;
            }
            case '3':
                fileManager.listContents();
                break;
            case '4': {
                std::string filename;
                std::cout << "Enter filename to delete: ";
                std::cin >> filename;
                fileManager.deleteFile(filename);
                break;
            }
            case '5': {
                std::string dirname;
                std::cout << "Enter directory name to delete: ";
                std::cin >> dirname;
                fileManager.deleteDirectory(dirname);
                break;
            }
            case '6':
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != '6');

    return 0;
}

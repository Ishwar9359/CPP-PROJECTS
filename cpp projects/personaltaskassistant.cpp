#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

class Task {
public:
    std::string description;
    std::string dueDate;
    int priority;
    bool completed;

    Task(const std::string& desc, const std::string& date, int prio)
        : description(desc), dueDate(date), priority(prio), completed(false) {}
};

class TaskAssistant {
public:
    void run() {
        std::cout << "Welcome to the Personal Task Assistant!" << std::endl;

        while (true) {
            displayMenu();
            int choice;
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    addTask();
                    break;
                case 2:
                    viewTasks();
                    break;
                case 3:
                    generateReport();
                    break;
                case 4:
                    std::cout << "Exiting. Goodbye!" << std::endl;
                    return;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
    }

private:
    std::vector<Task> tasks;

    void displayMenu() {
        std::cout << "\nMenu:\n"
                  << "1. Add Task\n"
                  << "2. View Tasks\n"
                  << "3. Generate Report\n"
                  << "4. Exit\n";
    }

    void addTask() {
        std::string desc, date;
        int priority;

        std::cout << "Enter task description: ";
        std::cin.ignore(); // Clear input buffer
        std::getline(std::cin, desc);

        std::cout << "Enter due date (YYYY-MM-DD): ";
        std::cin >> date;

        std::cout << "Enter priority (1 - High, 2 - Medium, 3 - Low): ";
        std::cin >> priority;

        tasks.emplace_back(desc, date, priority);
        std::cout << "Task added successfully!" << std::endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks available." << std::endl;
            return;
        }

        std::cout << "\nTasks:\n";
        for (const auto& task : tasks) {
            std::cout << "Description: " << task.description << "\n"
                      << "Due Date: " << task.dueDate << "\n"
                      << "Priority: " << task.priority << "\n"
                      << "Status: " << (task.completed ? "Completed" : "Pending") << "\n"
                      << "------------------------\n";
        }
    }

    void generateReport() {
        int completedTasks = std::count_if(tasks.begin(), tasks.end(), [](const Task& task) {
            return task.completed;
        });

        int totalTasks = tasks.size();
        int incompleteTasks = totalTasks - completedTasks;

        std::cout << "\nTask Completion Report:\n"
                  << "Total Tasks: " << totalTasks << "\n"
                  << "Completed Tasks: " << completedTasks << "\n"
                  << "Incomplete Tasks: " << incompleteTasks << "\n";
    }
};

int main() {
    TaskAssistant assistant;
    assistant.run();

    return 0;
}

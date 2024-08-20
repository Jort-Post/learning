#include <iostream>
#include <string>
#include <list>

int main() {
    std::string task;
    int input;
    std::list<std::string> taskList;

    while (true) {
        std::cout << "What do you want to do? \n"
                      "[1] Add a task \n"
                      "[2] Remove a task\n" 
                      "[3] View list of tasks\n";

        std::cin >> input;

        switch (input) {
            case 1:
                std::cout << "Please enter a task\n";
                std::cin >> task;
                taskList.push_back(task);
                break;

            case 2:
                std::cout << "Please enter the task you wish removed\n";
                std::cin >> task;
                taskList.remove(task);
                break;

            case 3:
                std::cout << "All tasks: \n";
                for (auto i = taskList.begin(); i != taskList.end(); i++) {
                    if (taskList.size() != 0) {std::cout << *i << std::endl;}
                    else {std::cout << "You have no tasks\n";}

                }
                break;
        }
        
    }
    return 0;
}
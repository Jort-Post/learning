#include <iostream>

int main() {
    int num1, num2;
    char op;

    std::cout << "Please enter the first number: \n";
    std::cin >> num1;

    std::cout << "Please enter the second number: \n";
    std::cin >> num2;

    std::cout << "Please enter the operator: \n";
    std::cin >> op;

    switch (op) {
        case '+': 
            std::cout << num1 + num2 << std::endl;
            break;
        case '-': 
            std::cout << num1 - num2 << std::endl;
            break;
        case '*': 
            std::cout << num1 * num2 << std::endl;
            break;
        case '/': 
            if (num2 != 0) {
                std::cout << num1 / num2 << std::endl;
                break;
            }
            else {
                std::cout << "Please divide by values greater than 0";
            }

    }
    return 0;
}
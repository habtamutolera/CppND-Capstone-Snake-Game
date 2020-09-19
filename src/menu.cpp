#include<iostream>
#include<string>
#include<iomanip>
#include "menu.h"

void Menu::optionMenu() {
    int option;
    std::cout << "Menu Option" << std::endl;
    std::cout << "Enter 1 to start game" << std::endl
              << "Enter 2 to see game record" << std::endl
              << "Enter 3 to quit game" << std::endl;

    std::cout << "Please enter 1, 2, or 3: ";  
    while (std::cin >> option) {
        if (option == 1 || option == 2 || option == 3)
        break;
        std::cout << option << " is not a valid option" << std::endl;
        std::cout <<"Please enter again 1, 2, or 3: ";
    }
   option_ = option;
}

int Menu::getOption(){
    return option_;
}
#include<iostream>
#include<string>
#include<iomanip>
#include "menu.h"

void Menu::optionMenu() {
    int options;
    std::cout << "Menu Option" << std::endl;
    std::cout << "Enter 1 to start game" << std::endl
              << "Enter 2 to see ranking" << std::endl
              << "Enter 3 to quit game" << std::endl;

    std::cout << "Please enter 1, 2, or 3: ";  
    while (std::cin >> options) {
        if (options == 1 || options == 2 || options == 3)
        break;
        std::cout << "Please enter 1, 2, or 3: ";
    }
   option = options;
}

int Menu::getOption(){
    return option;
}
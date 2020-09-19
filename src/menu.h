#ifndef MENU_H
#define MENU_H

class Menu {
    public:
    Menu(){};
    ~Menu(){};
    void optionMenu();
    int getOption();
    private:
    int option;
};
#endif
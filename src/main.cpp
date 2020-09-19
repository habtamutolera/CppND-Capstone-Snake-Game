#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "menu.h"
#include "record.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Menu menu;
  menu.optionMenu();
  Record record("../data/record.txt");
  int option = menu.getOption();
  switch (option)
  {
  case 1: {
    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kGridWidth, kGridHeight);
    game.Run(controller, renderer, kMsPerFrame);
    std::cout << "Game has terminated successfully!\n";
    std::cout << "Score: " << game.GetScore() << "\n";
    std::cout << "Size: " << game.GetSize() << "\n";
    std::cout << "Enter your name to store score:";
    std::string name;
    std::cin >> name;
    record.WriteRecord(name, game.GetScore());
    break; }
  case 2:
    record.PrintRecord();
    break;
  case 3:
    std::cout << "Quiting the game ..." << std::endl;
    break;
  default:
    std::cout << "Quiting the game ..." << std::endl;
  }
  return 0;
}
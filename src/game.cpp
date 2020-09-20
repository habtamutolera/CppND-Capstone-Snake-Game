#include <iostream>
#include <algorithm>
#include <utility>
#include "game.h"
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)) {
  PlaceFood(FoodType::Normal);
  PlaceFood(FoodType::Shrink);

}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood(FoodType foodType) {
  int x, y;
  SDL_Point point;
  while (true) {
    x = (random_w(engine)%kScreenWidth)-1;
    y = (random_h(engine)%kScreenHeight)-1;
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y) && !FoodCell(x,y)) {
      point = {x,y};
      food.push_back(std::make_pair(point,foodType));
      return;
    }
  }
}

bool Game::FoodCell(int x, int y) const {
  for (auto const &f : food) {
    if (x == f.first.x && y == f.first.y) {
      return true;
    }
  }
  return false;
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);
  std::vector<FoodType> foodToPlace;

  // Check if there's food over
  auto eten_food = food.end();
  for (auto it = food.begin(); it != food.end(); ++it) {
  //while (it != food.end()) {
    if (it->first.x == new_x && it->first.y == new_y) {
      if (it->second == FoodType::Normal) {
        score++;
        snake.GrowBody();
        snake.speed += 0.02;
        normalCount++;
        if (normalCount == 5) {
          foodToPlace.push_back(FoodType::Special);
          normalCount = 0;
        }
        else {
          foodToPlace.push_back(FoodType::Normal);
        }
        eten_food = it;
      }
      else if (it->second == FoodType::Shrink) {
        shrinkCount++;
        normalCount = 0;
        if (score > 0 and snake.size > 1) {
          score--;
          snake.speed -= 0.02;
          snake.ShrinkBody();
        }
        if (shrinkCount == 5) {
          foodToPlace.push_back(FoodType::Killer);
          shrinkCount = 0;
        }
        else {
          foodToPlace.push_back(FoodType::Shrink);
        }
        eten_food = it;
      }
      else if (it->second == FoodType::Killer) {
        snake.alive = false;
      }
      else if (it->second == FoodType::Special) {
        score += 5;
        normalCount = 0;
        snake.GrowBody();
        foodToPlace.push_back(FoodType::Normal);
        eten_food = it;
      }
    }
  }
  if (eten_food != food.end()) food.erase(eten_food);
  for(auto &f : foodToPlace) {
    PlaceFood(f);
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }
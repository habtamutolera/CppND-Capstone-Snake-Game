# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## File and Class Structure

There are 6 classes in the project.
| Class Name | Purpose                                               |
|------------|-------------------------------------------------------|
|Controller  | Gives interface to the user to control the game       |
|Game        | Runs the game in infinite loop                        |
|Menu        | Provides user a menu before the game starts           |
|Record      | Read, write and print                                 |
|Renderer    | Render the game on the screen                         |
|Snake       | Keeps track of speed, size and location of snake      |

## The project meets the following rubric points

1. The project demonstrate an understanding of C++ functions and control structures
2. The project accepts and processes user input
3. The project uses Object Oriented Programming techniques
4. Class constructors utilizes memeber initialization lists
5. The project makes use of references in function declarations

## Play the Game

When the game starts, the users is presented with 3 options:
- option 1: to start game to play the game
- Option 2: to see game record
- Option 3: to quit the game

When a player choose option 1, the game starts with two kind of food; Normal(white) and Shrink(yellow). if the snake eats normal food, the size, speed and score increases. With five consucative eating of the Normal food, Special(green) food is placed which increases the score by five. On the other hand if the snake eats Shrink food, the size, score and speed decreases. With five times eating of Shrink food, Killer(red) food is placed. Up on eating Killer food, the snake dies. At any time, a player can quit the game by pressing End key. When a player choose option 2, the game record stored in a fie is displayed.


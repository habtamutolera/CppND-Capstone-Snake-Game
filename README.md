# CPPND: Capstone Snake Game Example

This is a project based on a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

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
|Record      | Read, write and print game record                     |
|Renderer    | Render the game on the screen                         |
|Snake       | Keeps track of speed, size and location of snake      |

## The project meets the following rubric points

1. The project demonstrate an understanding of C++ functions and control structures. In record.cpp, loops and conditions are used in functions ReadRecord(), WriteRecord(), and PrintRecord(). While loop are used at line 27 and for loop is used at lines 44 and 56. In menu.cpp, while loop is used at line 14. If-else condition is also used in record.cpp starting from lines 26-37 and 55-62. If condition is also used in menu.cpp at line 15.
2. The project reads data from a file and process the data, or the program writes data to a file. In record.cpp, ReadRecord() function(lines 22-38) reads data from  record.txt and WriteRecord() function (lines 52-63) writes record to file. In addition to the newly added classes, control structures are used in game.cpp from lines 74-78 and also at many places in function Update() function from lines 83-143.
3. The project accepts user input and process the input. main.cpp accepts input from user at line 32. menu.cpp also accepts input from user in lines 14-19.
4. The project uses Object Oriented Programming techniques. The project code is organized into classes with class attributes to hold data, and class methods to perform tasks. The newly added classes define and implemented in record.h, record.cpp, menu.h and menu.cpp demonstrates this.
5. Classes use appropriate access specifiers for class members. In record.h, attributes and functions that are not used by another class out side of Record class are define private and those that are called from main.cpp are define as public. The same for menu.h. 
6. Class constructors utilizes memeber initialization lists. In record.cpp, Record constructor(line 13) uses initialization list.
7. The project makes use of references in function declarations. In record.h, AddRecord(line 9), WriteRecord(line 12) and CompareRecord(line 65) functions make use of references in function declaration.

## Play the Game

When the game starts, the users is presented with 3 options:
- option 1: to start game to play the game
- Option 2: to see game record
- Option 3: to quit the game

When a player choose option 1, the game starts with two kind of food; Normal(white) and Shrink(yellow). if the snake eats normal food, the size, speed and score increases. With five consucative eating of the Normal food, Special(green) food is placed which increases the score by five. On the other hand if the snake eats Shrink food, the size, score and speed decreases. With five times eating of Shrink food, Killer(red) food is placed. Up on eating Killer food, the snake dies. At any time, a player can quit the game by pressing End key. When a player choose option 2, the game record stored in a fie is displayed.


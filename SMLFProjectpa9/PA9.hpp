#pragma once

#include <iostream>
#include <string.h>
#include "Game.hpp"
#include "Hangman.hpp"
#include <cctype>
#include "Word_Bank.h"
#include"SFML/Graphics.hpp"
#include "Letter.hpp"

using std::string;
using std::vector;
using std::cout;
using std::endl;

// Function: runHangMan
// Date Created: Apr. 23, 2024
// Date Modified: Apr. 23, 2024
// Description: runs the Hangman game
// Inputs: string StringToPassIn
// Output: void
// Preconditions: function and input parameters are well-defined
// Postconditions: function must be called in main
void runHangMan(string StringToPassIn);

// Function: rules
// Date Created: Apr. 23, 2024
// Date Modified: Apr. 23, 2024
// Description: contains the rules of the Hangman game
// Inputs: void
// Output: void
// Preconditions: function and input parameters are well-defined
// Postconditions: function must be called in main
void rules();

// Function: DisplayMainScreen
// Date Created: Apr. 23, 2024
// Date Modified: Apr. 23, 2024
// Description: displays the main screen of the Hangman game
// Inputs: void
// Output: void
// Preconditions: function and input parameters are well-defined
// Postconditions: function must be called in main
void DisplayMainScreen();
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include"SFML/Graphics.hpp"

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::ifstream;

// Button struct containing RectangleShape and Text variables
struct Button {
	sf::RectangleShape button;
	sf::Text text;
};

// Function: isMouseOver
// Date Created: Apr. 22, 2024
// Date Modified: Apr. 22, 2024
// Description: checks whether the cursor is above a button 
// Source: https://en.sfml-dev.org/forums/index.php?topic=13627.15
// Inputs: sf::RectangleShape& button, sf::RenderWindow& window
// Output: bool
// Preconditions: function and input parameters are well-defined
// Postconditions: function must be called in main
bool isMouseOver(sf::RectangleShape& button, sf::RenderWindow& window);
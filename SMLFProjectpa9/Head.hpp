#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "BodyPart.hpp"

constexpr auto HEAD_IMG = "andy.png"; // 336x304
constexpr float DEFAULT_HEAD_X = 440.f; // Default x coordinate; manually calculated beforehand
constexpr float DEFAULT_HEAD_Y = 0.f; // Default y coordinate; manually calculated beforehand

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::ifstream;

class Head : public BodyPart {
public:
	// Function: Head
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 22, 2024
	// Description: constructor for Head class
	// Inputs: void
	// Output: Head
	// Preconditions: function and input parameters are well-defined and
	//	the file specified by HEAD_IMG exists.
	// Postconditions: function must be called in main
	Head() : BodyPart("Head", HEAD_IMG) {
	}

	// Function: ~Head
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 16, 2024
	// Description: destructor for Head class
	// Inputs: void
	// Output: ~Head
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	~Head();

private:

};
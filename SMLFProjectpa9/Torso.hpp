#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "BodyPart.hpp"

constexpr auto TORSO_IMG = "GarfieldBody.png";
constexpr float DEFAULT_TORSO_X = 408.f; // Default x coordinate; manually calculated beforehand
constexpr float DEFAULT_TORSO_Y = 304.f; // Default y coordinate; manually calculated beforehand

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::ifstream;

class Torso : public BodyPart {
public:
	// Function: Torso
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 16, 2024
	// Description: constructor for Torso class
	// Inputs: void
	// Output: Torso
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	Torso() : BodyPart("Torso", TORSO_IMG) {
	}

	// Function: ~Torso
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 16, 2024
	// Description: destructor for Torso class
	// Inputs: void
	// Output: ~Torso
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	~Torso();

private:
};
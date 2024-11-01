#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "BodyPart.hpp"

constexpr auto LEFT_LEG_IMG = "GarfieldLeftLeg.png"; // 618x202 file size; only 306x202 is filled
constexpr float DEFAULT_LEFT_LEG_X = 0.f; // Default x coordinate; manually calculated beforehand
constexpr float DEFAULT_LEFT_LEG_Y = 547.f; // Default y coordinate; manually calculated beforehand

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::ifstream;

class LeftLeg : public BodyPart {
public:
	// Function: LeftLeg 
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 16, 2024
	// Description: constructor for LeftLeg class
	// Inputs: void
	// Output: LeftLeg 
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	LeftLeg() : BodyPart("LeftLeg", LEFT_LEG_IMG) {}

	// Function: ~LeftLeg
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 16, 2024
	// Description: destructor for LeftLeg class
	// Inputs: void
	// Output: ~LeftLeg
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	~LeftLeg();

private:

};
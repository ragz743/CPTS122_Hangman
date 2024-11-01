#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "BodyPart.hpp"

constexpr auto RIGHT_LEG_IMG = "GarfieldRightLeg.png"; // 263x202
constexpr float DEFAULT_RIGHT_LEG_X = 618.f; // Default x coordinate; manually calculated beforehand
constexpr float DEFAULT_RIGHT_LEG_Y = 547.f; // Default y coordinate; manually calculated beforehand

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::ifstream;

class RightLeg : public BodyPart {
public:
	// Function: RightLeg 
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 16, 2024
	// Description: constructor for RightLeg class
	// Inputs: void
	// Output: RightLeg
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	RightLeg() : BodyPart("RightLeg", RIGHT_LEG_IMG) {}

	// Function: ~RightLeg
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 16, 2024
	// Description: destructor for RightLeg class
	// Inputs: void
	// Output: ~RightLeg
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	~RightLeg();

private:

};
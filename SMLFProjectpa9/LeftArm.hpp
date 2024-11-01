#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "BodyPart.hpp"

constexpr auto LEFT_ARM_IMG = "GarfieldLeftArm.png"; // 408x134 (photoshop); 408x243 (file)
constexpr float DEFAULT_LEFT_ARM_X = 0.f; // Default x coordinate; manually calculated beforehand
constexpr float DEFAULT_LEFT_ARM_Y = 304.f; // Default y coordinate; manually calculated beforehand

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::ifstream;

class LeftArm : public BodyPart {
public:
	// Function: LeftArm
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 16, 2024
	// Description: constructor for LeftArm class
	// Inputs: void
	// Output: LeftArm
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	LeftArm() : BodyPart("LeftArm", LEFT_ARM_IMG) {
	}

	// Function: ~LeftArm
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 16, 2024
	// Description: destructor for LeftArm class
	// Inputs: void
	// Output: ~LeftArm
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	~LeftArm();

private:
};
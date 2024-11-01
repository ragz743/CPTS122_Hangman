#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "BodyPart.hpp"

constexpr auto RIGHT_ARM_IMG = "GarfieldRightArm.png"; // 444x136 (photoshop); 444x243 (file)
constexpr float DEFAULT_RIGHT_ARM_X = 827.f; // Default x coordinate; manually calculated beforehand
constexpr float DEFAULT_RIGHT_ARM_Y = 304.f; // Default y coordinate; manually calculated beforehand

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::ifstream;

class RightArm : public BodyPart {
public:
	// Function: RightArm
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 16, 2024
	// Description: constructor for RightArm class
	// Inputs: void
	// Output: RightArm
	// Preconditions: function and input parameters are well-defined and
	//	the file specified by HEAD_IMG exists.
	// Postconditions: function must be called in main
	RightArm() : BodyPart("RightArm", RIGHT_ARM_IMG) {
	}

	// Function: ~RightArm
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 16, 2024
	// Description: destructor for RightArm class
	// Inputs: void
	// Output: ~RightArm
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	~RightArm();

private:
};
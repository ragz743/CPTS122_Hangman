#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include"SFML/Graphics.hpp"
#include "Head.hpp"
#include "Torso.hpp"
#include "LeftArm.hpp"
#include "RightArm.hpp"
#include "LeftLeg.hpp"
#include "RightLeg.hpp"

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::ifstream;

class Hangman {
public:
	// Function: Hangman
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 16, 2024
	// Description: constructor for Hangman class
	// Inputs: void
	// Output: Hangman
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	Hangman();

	// Function: ~Hangman
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 16, 2024
	// Description: destructor for Hangman class
	// Inputs: void
	// Output: ~Hangman
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	~Hangman();

	// Function: getHead
	// Date Created: Apr. 16, 2024
	// Date Modified: Apr. 16, 2024
	// Description: returns the Head value from the Hangman class
	// Inputs: void
	// Output: Head&
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	Head& getHead();

	// Function: getTorso
	// Date Created: Apr. 16, 2024
	// Date Modified: Apr. 16, 2024
	// Description: returns the Torso value from the Hangman class
	// Inputs: void
	// Output: Torso&
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	Torso& getTorso();

	// Function: getLeftArm
	// Date Created: Apr. 16, 2024
	// Date Modified: Apr. 16, 2024
	// Description: returns the LeftArm value from the Hangman class
	// Inputs: void
	// Output: LeftArm&
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	LeftArm& getLeftArm();

	// Function: getRightArm
	// Date Created: Apr. 16, 2024
	// Date Modified: Apr. 16, 2024
	// Description: returns the RightArm value from the Hangman class
	// Inputs: void
	// Output: RightArm&
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	RightArm& getRightArm();

	// Function: getLeftLeg
	// Date Created: Apr. 16, 2024
	// Date Modified: Apr. 16, 2024
	// Description: returns the LeftLeg value from the Hangman class
	// Inputs: void
	// Output: LeftLeg&
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	LeftLeg& getLeftLeg();

	// Function: getRightLeg
	// Date Created: Apr. 16, 2024
	// Date Modified: Apr. 16, 2024
	// Description: returns the RightLeg value from the Hangman class
	// Inputs: void
	// Output: RightLeg&
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	RightLeg& getRightLeg();

	// Function: setPosition
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: Sets the position so that the top-left corner of the hanging man bounding box is at the given coordinates.
	//              The hangman requires 1271x749 pixels of space by default, but this can be changed using setWidth() or setHeight().
	//              Inputs: float (x coordinate), float (y coordinate); origin is the top-left of the hangman structure.
	// Input: float x, float y
	// Output: void
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	void setPosition(float x, float y);

	// Function: setWidth
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: Scales the hangman's width & height so that it is the given amount of pixels wide.
	// Inputs: int pixels (desired number of pixels of width)
	// Output: float (the hangman's new calculated height in pixels)
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	float setWidth(int pixels);

	// Function: setHeight
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: Scales the hangman's width & height so that it is the given amount of pixels tall.
	// Inputs: int pixels (desired number of pixels of height)
	// Outputs: float (the hangman's new calculated width in pixels)
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	float setHeight(int pixels);

	// Function: draw
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: (Re)draws the hangman to the given render window.
	//				Only draws the body parts that have been added to Hangman.
	//				This will *not* automatically call clear() or display() on the window.
	// Inputs: the RenderWindow to draw to
	// Outputs: void
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	void draw(sf::RenderWindow& window);

	// Function: moveTowardsBottom
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 24, 2024
	// Description: Moves the entire Hangman man downwards by a small amount. Best used in a loop.
	//				If the Hangman is already below the screen, it does nothing.
	// Input: the RenderWindow to animate in (this is only used to find the window size)
	//		  float - the number of pixels to move the Hangman downwards by (defaults to 1)
	// Output: bool - Whether it was moved; false if it's already off the screen
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	bool moveTowardsBottom(sf::RenderWindow& window, float pixels = 1.0f);

	// Function: numParts
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: returns the number of body parts currently displayed 
	// Inputs: void
	// Output: The number of body parts that are currently displayed on the Hangman.
	//		   When this number reaches 6, the game is over.
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	int numParts() const;

	// Function: addPart
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: Adds the next body part to the Hangman. Should be called when the player guesses incorrectly.
	// Input: void
	// Output: The number of body parts now displayed on the Hangman (same as numParts())
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	int addPart();

private:
	const int DEFAULT_WIDTH = 1271;
	const int DEFAULT_HEIGHT = 749;

	Head head;
	Torso torso;
	LeftArm leftArm;
	RightArm rightArm;
	LeftLeg leftLeg;
	RightLeg rightLeg;

	BodyPart* parts[6]; // Contains pointers to all the body parts in the order they will be added to the hangman.

	float scale; // Multiplier that stores the hangman's size relative to the default width & height.
	sf::Vector2f position; // Stores the (x,y) position of the hangman
};
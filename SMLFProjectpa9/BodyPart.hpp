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

class BodyPart {
public:
	// Function: BodyPart
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 16, 2024
	// Description: constructor for BodyPart class
	// Inputs: const string& newName (name of the body part)
	//	const string& fileName (filename of the texture)
	// Output: BodyPart
	// Preconditions: function and input parameters are well-defined
	BodyPart(const string& newName, const string& fileName = "");

	// Function: ~BodyPart
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 16, 2024
	// Description: destructor for BodyPart class
	// Inputs: void
	// Output: ~BodyPart
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	virtual ~BodyPart();

	// Function: getName
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 16, 2024
	// Description: returns the name of the body part
	// Inputs: void
	// Output: string
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	string getName();

	// Function: setName
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 16, 2024
	// Description: sets a new name of the body part
	// Inputs: string newName
	// Output: void
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	void setName(string newName);

	// Function: isOnBody
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 23, 2024
	// Description: Returns whether this body part should be on the Hangman body.
	// Inputs: void
	// Output: bool
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	bool isOnBody() const;

	// Function: addToBody
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 23, 2024
	// Description: Marks this body part as being on the body.
	// Inputs: void
	// Output: void
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	void addToBody();

	// Function: getSprite
	// Date Created: Apr 22, 2024
	// Date Modified: Apr 22, 2024
	// Description: returns a reference to the sprite that can be drawn on the screen.
	// Inputs: void
	// Output: sf::Sprite&
	// Preconditions: object must be initialized with a file successfully
	sf::Sprite& getSprite();

	// Function: setWidth
	// Date Created: Apr 22, 2024
	// Date Modified: Apr 22, 2024
	// Description: Scales the sprite's width & height so that it is the given amount of pixels wide.
	// Inputs: unsigned int pixels (desired number of pixels of width)
	// Outputs: unsigned int (the sprite's new height in pixels)
	// Preconditions: object must be initialized with a file successfully
	unsigned int setWidth(unsigned int pixels);

	// Function: setHeight
	// Date Created: Apr 22, 2024
	// Date Modified: Apr 22, 2024
	// Description: Scales the sprite's width & height so that it is the given amount of pixels tall.
	// Inputs: unsigned int pixels (desired number of pixels of height)
	// Outputs: unsigned int (the sprite's new width in pixels)
	// Preconditions: object must be initialized with a file successfully
	unsigned int setHeight(unsigned int pixels);

	// Function: setWidth
	// Date Created: Apr 22, 2024
	// Date Modified: Apr 22, 2024
	// Description: Sets the sprite's position in the window.
	// Inputs: float x (x coordinate of the desired position of the top left of the sprite)
	//	float y (y coordinate of the desired position of the top left of the sprite)
	// Outputs: void
	// Preconditions: object must be initialized with a file successfully
	void setPosition(float x, float y);

protected:
	string name; // The name of this body part
	bool onBody; // Whether this body part should be on the Hangman body

	sf::Texture texture;
	sf::Sprite sprite;
};
#include "Hangman.hpp"

// Function: Hangman
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 16, 2024
	// Description: constructor for Hangman class
	// Inputs: void
	// Output: Hangman
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
Hangman::Hangman() {
	scale = 1.0f;
	setPosition(0.f, 0.f); // Position everything where they should be

	parts[0] = &head;
	parts[1] = &torso;
	parts[2] = &leftArm;
	parts[3] = &rightArm;
	parts[4] = &leftLeg;
	parts[5] = &rightLeg;
}

// Function: ~Hangman
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 16, 2024
	// Description: destructor for Hangman class
	// Inputs: void
	// Output: ~Hangman
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
Hangman::~Hangman() {

}

// Function: getHead
	// Date Created: Apr. 16, 2024
	// Date Modified: Apr. 16, 2024
	// Description: returns the Head value from the Hangman class
	// Inputs: void
	// Output: Head&
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
Head& Hangman::getHead() {
	return head;
}

// Function: getTorso
	// Date Created: Apr. 16, 2024
	// Date Modified: Apr. 16, 2024
	// Description: returns the Torso value from the Hangman class
	// Inputs: void
	// Output: Torso&
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
Torso& Hangman::getTorso() {
	return torso;
}

// Function: getLeftArm
	// Date Created: Apr. 16, 2024
	// Date Modified: Apr. 16, 2024
	// Description: returns the LeftArm value from the Hangman class
	// Inputs: void
	// Output: LeftArm&
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
LeftArm& Hangman::getLeftArm() {
	return leftArm;
}

// Function: getRightArm
	// Date Created: Apr. 16, 2024
	// Date Modified: Apr. 16, 2024
	// Description: returns the RightArm value from the Hangman class
	// Inputs: void
	// Output: RightArm&
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
RightArm& Hangman::getRightArm() {
	return rightArm;
}

// Function: getLeftLeg
	// Date Created: Apr. 16, 2024
	// Date Modified: Apr. 16, 2024
	// Description: returns the LeftLeg value from the Hangman class
	// Inputs: void
	// Output: LeftLeg&
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
LeftLeg& Hangman::getLeftLeg() {
	return leftLeg;
}

// Function: getRightLeg
	// Date Created: Apr. 16, 2024
	// Date Modified: Apr. 16, 2024
	// Description: returns the RightLeg value from the Hangman class
	// Inputs: void
	// Output: RightLeg&
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
RightLeg& Hangman::getRightLeg() {
	return rightLeg;
}

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
void Hangman::setPosition(float x, float y) {
	head.setPosition(scale * DEFAULT_HEAD_X + x, scale * DEFAULT_HEAD_Y + y);
	leftArm.setPosition(scale * DEFAULT_LEFT_ARM_X + x, scale * DEFAULT_LEFT_ARM_Y + y);
	torso.setPosition(scale * DEFAULT_TORSO_X + x, scale * DEFAULT_TORSO_Y + y);
	rightArm.setPosition(scale * DEFAULT_RIGHT_ARM_X + x, scale * DEFAULT_RIGHT_ARM_Y + y);
	leftLeg.setPosition(scale * DEFAULT_LEFT_LEG_X + x, scale * DEFAULT_LEFT_LEG_Y + y);
	rightLeg.setPosition(scale * DEFAULT_RIGHT_LEG_X + x, scale * DEFAULT_RIGHT_LEG_Y + y);
	position.x = x;
	position.y = y;
}

// Function: setWidth
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: Scales the hangman's width & height so that it is the given amount of pixels wide.
	// Inputs: int pixels (desired number of pixels of width)
	// Output: float (the hangman's new calculated height in pixels)
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
float Hangman::setWidth(int pixels) {
	scale = (float)pixels / DEFAULT_WIDTH;
	for (int i = 0; i < 6; i++)
		parts[i]->getSprite().setScale(scale, scale);
	setPosition(position.x, position.y); // Repositition everything to new size
	return DEFAULT_HEIGHT * scale;
}

// Function: setHeight
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: Scales the hangman's width & height so that it is the given amount of pixels tall.
	// Inputs: int pixels (desired number of pixels of height)
	// Outputs: float (the hangman's new calculated width in pixels)
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
float Hangman::setHeight(int pixels) {
	scale = (float)pixels / DEFAULT_HEIGHT;
	for (int i = 0; i < 6; i++)
		parts[i]->getSprite().setScale(scale, scale);
	setPosition(position.x, position.y); // Repositition everything to new size
	return DEFAULT_WIDTH * scale;
}

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
void Hangman::draw(sf::RenderWindow& window) {
	for (int i = 0; i < 6; i++) {
		if (parts[i]->isOnBody())
			window.draw(parts[i]->getSprite());
		else break;
	}
}

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
bool Hangman::moveTowardsBottom(sf::RenderWindow& window, float pixels) {
	if (position.y < window.getSize().y) {
		// Move everything down by 1
		for (int i = 0; i < 6; i++)
			parts[i]->getSprite().move(0.f, pixels);
		position.y += pixels;
		return true;
	}
	return false;
}

// Function: numParts
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: returns the number of body parts currently displayed 
	// Inputs: void
	// Output: The number of body parts that are currently displayed on the Hangman.
	//		   When this number reaches 6, the game is over.
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
int Hangman::numParts() const {
	int num = 0;
	for (int i = 0; i < 6; i++) {
		if (parts[i]->isOnBody())
			num++;
		else break;
	}
	return num;
}

// Function: addPart
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: Adds the next body part to the Hangman. Should be called when the player guesses incorrectly.
	// Input: void
	// Output: The number of body parts now displayed on the Hangman (same as numParts())
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
int Hangman::addPart() {
	int currentCount = numParts();
	if (currentCount > 5) { // All parts are added already; cannot add any more
		return currentCount;
	}
	parts[currentCount]->addToBody();
	return currentCount + 1;
}
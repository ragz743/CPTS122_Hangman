#include <cctype>
#include "Letter.hpp"

// Function: Letter
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 24, 2024
	// Description: Default constructor; remember to set the letterChar, font, etc.
	//				Defaults: letterChar=space, font size 80, fill color black.
	// Inputs: void
	// Output: Letter
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
Letter::Letter() {
	letterChar = ' ';
	hidden = false;
	setCharacterSize(80);
	setString(letterChar);
	setFillColor(sf::Color::Black);

	box.setSize(sf::Vector2f(100.f, 100.f));
}

// Function: Letter
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 24, 2024
	// Description: Instantiates a SFML Text that contains this letter in the given font. Automatically sets size of 80 and color black.
	// Inputs: char letterChar, sf::Font& font, bool isHidden = false
	// Output: Letter
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
Letter::Letter(char letterChar, sf::Font& font, bool isHidden) {
	this->letterChar = toupper(letterChar);
	hidden = isHidden;
	setFont(font);
	setCharacterSize(80);
	setString(letterChar);
	setFillColor(sf::Color::Black);

	box.setSize(sf::Vector2f(100.f, 100.f));
}

// Function: hide
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: Hides the letter by setting the size to 0. Does not hide the box.
	// Inputs: void
	// Output: void
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
void Letter::hide() {
	setCharacterSize(0);
	hidden = true;
}

// Function: show
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: Un-hides the letter by reverting the font size to 80, or whatever is specified.
	// Inputs: unsigned int fontSize = 80u
	// Output: void
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
void Letter::show(unsigned int fontSize) {
	setCharacterSize(fontSize);
	hidden = false;
}

// Function: setLetterChar
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 24, 2024
	// Description: Changes the char represented by this object. Automatically sets to uppercase.
	// Inputs: char letterChar
	// Output: void
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
void Letter::setLetterChar(char letterChar) {
	this->letterChar = toupper(letterChar);
	setString(this->letterChar);
}

// Function: getLetterChar
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: Returns the char represented by this object.
	// Inputs: void
	// Output: char
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
char Letter::getLetterChar() const {
	return letterChar;
}

// Function: getBox
// Date Created: Apr 24, 2024
// Date Modified: Apr 24, 2024
// Description: Returns a reference to the 100x100 Box containing the letter.
// Input: void
// Output: RectangleShape& (box underneath the text letter)
// Preconditions: function and input parameters are well-defined
// Postconditions: N/A
sf::RectangleShape& Letter::getBox() {
	return box;
}

// Function: isHidden
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: Returns whether or not this letter is hidden (has size 0)
	// Inputs: void
	// Output: bool
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
bool Letter::isHidden() const {
	return hidden;
}

// Function: draw
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 24, 2024
	// Description: If not hidden, draws this letter to the given window. Draws the box under the letter regardless.
	// Inputs: sf::RenderWindow& window
	// Output: bool (true if the letter was drawn)
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
bool Letter::draw(sf::RenderWindow& window) {
	window.draw(box);
	if (!hidden) {
		window.draw(*this);
		return true;
	}
	else {
		return false;
	}
}

// Function: operator char
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: When casted to a char, the char represented by this Letter will be returned.
	// Inputs: void
	// Output: void
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
Letter::operator char() const {
	return letterChar;
}

// Function: setPositions
	// Date Created: Apr 24, 2024
	// Date Modified: Apr 24, 2024
	// Description: Sets the position of both the letter and the box simultaneously.
	//	The letter will be set to (x,y).
	//	The box will be set to (x-50, y-50).
	// Inputs: float x (x coordinate), float y (y coordinate)
	// Output: void
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
void Letter::setPositions(float x, float y) {
	setPosition(x, y);
	box.setPosition(x - 50.f, y - 50.f);
}

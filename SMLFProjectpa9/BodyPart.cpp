#include "BodyPart.hpp"

BodyPart::BodyPart(const string& newName, const string& fileName) {
	name = newName;
	onBody = false;

	// Loads the file as a texture if specified
	if (!fileName.empty()) {
		sf::Image textureImg;
		textureImg.loadFromFile(fileName);
		texture.loadFromImage(textureImg);
		sprite.setTexture(texture);
	}
}

// Function: ~BodyPart
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 16, 2024
	// Description: destructor for BodyPart class
	// Inputs: void
	// Output: ~BodyPart
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
BodyPart::~BodyPart() {
}

// Function: getName
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 16, 2024
	// Description: returns the name of the body part
	// Inputs: void
	// Output: string
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
string BodyPart::getName() {
	return name;
}

// Function: setName
	// Date Created: Apr. 16, 2024 
	// Date Modified: Apr. 16, 2024
	// Description: sets a new name of the body part
	// Inputs: string newName
	// Output: void
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
void BodyPart::setName(string newName) {
	name = newName;
}

bool BodyPart::isOnBody() const {
	return onBody;
}

void BodyPart::addToBody() {
	onBody = true;
}

sf::Sprite& BodyPart::getSprite() {
	return sprite;
}

unsigned int BodyPart::setWidth(unsigned int pixels) {
	sf::Vector2u defaultSize = texture.getSize(); // The texture's default (intrinsic) size.
	float scale = pixels / (float)defaultSize.x; // How to scale the sprite to meet the desired width.
	sprite.setScale(scale, scale);
	return (unsigned int)(defaultSize.y * scale);
}

unsigned int BodyPart::setHeight(unsigned int pixels) {
	sf::Vector2u defaultSize = texture.getSize(); // The texture's default (intrinsic) size.
	float scale = pixels / (float)defaultSize.y; // How to scale the sprite to meet the desired width.
	sprite.setScale(scale, scale);
	return (unsigned int)(defaultSize.x * scale);
}

void BodyPart::setPosition(float x, float y) {
	sprite.setPosition(x, y);
}
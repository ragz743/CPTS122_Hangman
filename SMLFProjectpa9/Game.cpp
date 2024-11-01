#include "Game.hpp"

bool isMouseOver(sf::RectangleShape& button, sf::RenderWindow& window)
{
	sf::Vector2f pos = sf::Vector2f(sf::Mouse::getPosition(window));
	return button.getGlobalBounds().contains(pos);
}

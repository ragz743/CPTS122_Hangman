#include <iostream>
#include <string.h>
#include "Game.hpp"
#include "Hangman.hpp"
#include <cctype>
#include "Word_Bank.h"
#include"SFML/Graphics.hpp"
#include "Letter.hpp"
#include <chrono>
#include <thread>

using std::string;
using std::vector;
using std::cout;
using std::endl;

// Function: runHangMan
// Date Created: Apr. 23, 2024
// Date Modified: Apr. 23, 2024
// Description: runs the Hangman game
// Inputs: string StringToPassIn
// Output: void
// Preconditions: function and input parameters are well-defined
// Postconditions: function must be called in main
void runHangMan(string StringToPassIn) {
	sf::RenderWindow rendWindow(sf::VideoMode(2500, 1500), "HangMan!");

	// Set background image to rendWindow
	sf::Texture Background;
	sf::Image BackgroundImage;
	if (!BackgroundImage.loadFromFile("Graveyard.jpg")) {
		//	return -1;
	}
	Background.loadFromImage(BackgroundImage);
	sf::Sprite BackgroundSprite;
	BackgroundSprite.setTexture(Background);

	// Declare Hangman
	Hangman man;
	man.setHeight(540);
	man.setPosition(1050, 400);
	rendWindow.setFramerateLimit(60);

	// Set font
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {
		cout << " THis Failed " << endl;
		//return -1;
	}

	// Set inputted word to uppercase
	std::string HangWordWord = StringToPassIn;
	transform(HangWordWord.begin(), HangWordWord.end(), HangWordWord.begin(), ::toupper);


	//Source: https://stackoverflow.com/questions/905355/how-to-get-the-number-of-characters-in-a-stdstring
	//Used This Link Above To find Out How to get the length of the string Passed in and
	std::string TempHolderToGuessWord(HangWordWord.length(), '.');

	cout << TempHolderToGuessWord << endl;

	// Contains all the letters of the alphabet; these are what the user will click on to make a guess.
	Letter letterBank[26];

	// Contains the letters of the word to be guessed.
	vector<Letter> wordLetters;

	// Instantiates all of the letterBank letters.
	for (int i = 0; i < 26; i++) {
		letterBank[i].setLetterChar('A' + i);
		letterBank[i].setFont(font);
		letterBank[i].setFillColor(sf::Color::White);
		letterBank[i].getBox().setFillColor(sf::Color::Transparent);
	}

	// Adds the word's letters to the wordLetters vector.
	for (int i = 0; i < HangWordWord.size(); i++) {
		wordLetters.push_back(Letter(HangWordWord[i], font, true));
		wordLetters[i].getBox().setFillColor(sf::Color::White);

		sf::FloatRect TextBounders = wordLetters[i].getLocalBounds();
		wordLetters[i].setOrigin(TextBounders.left + TextBounders.width / 2.0, TextBounders.top + TextBounders.height / 2.0);
		wordLetters[i].setPositions(350 + i * 150, 1100);
	}

	// Strikes keep track of how many mistakes you have made
	int strikes = 0;

	while (rendWindow.isOpen()) {
		sf::Event event;
		while (rendWindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				rendWindow.close();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i PositionOnBoard = sf::Mouse::getPosition(rendWindow);
				for (int i = 0; i < 26; i++) {
					sf::FloatRect bounds = letterBank[i].getGlobalBounds();
					if (bounds.contains(PositionOnBoard.x, PositionOnBoard.y)) {

						char ClickedLetter = letterBank[i];
						bool IfLetterIsInWord = false;

						cout << "Letter Clicked is " << ClickedLetter << endl;
						letterBank[i].hide();

						// Checks each letter of the word to see if it's the one they just guessed.
						// Positions & shows them appropriately.
						for (int j = 0; j < wordLetters.size(); j++) {
							if (wordLetters[j] == ClickedLetter) {
								IfLetterIsInWord = true;
								TempHolderToGuessWord[j] = wordLetters[j];
								wordLetters[j].setFillColor(sf::Color::Green);
								wordLetters[j].show();
							}
						}
						// Add a strike and body part if it wasn't in the word
						if (!IfLetterIsInWord) {
							strikes++;
							cout << strikes << endl;
							man.addPart();

						}
					}
				}
			}
		}

		// Redrawing the frame
		rendWindow.clear();
		rendWindow.draw(BackgroundSprite);
		man.draw(rendWindow);

		for (int i = 0; i < 26; i++) {

			if (i < 13) {
				letterBank[i].setPositions(350 + i * 150, 1250);
			}
			else {
				letterBank[i].setPositions(350 + (i - 13) * 150, 1400);
			}
			letterBank[i].draw(rendWindow);
		}

		for (int i = 0; i < wordLetters.size(); i++) {
			wordLetters[i].draw(rendWindow);
		}

		// Checks if all the letters are inputted into TempHolderToGuessWord and is equal to HangWordWord 
		if (TempHolderToGuessWord == HangWordWord) {


			//used this for inspiration for my sleep function https://stackoverflow.com/questions/23609507/pause-program-execution-for-5-seconds-in-c


			sf::Text WinText;
			sf::Text ExitingText;
			WinText.setFont(font);
			WinText.setCharacterSize(100);
			WinText.setString("You Win");
			WinText.setPosition(1050, 500);
			WinText.setFillColor(sf::Color::White);


			ExitingText.setFont(font);
			ExitingText.setCharacterSize(100);
			ExitingText.setString("Exiting the Program in 10 Seconds");
			ExitingText.setPosition(550, 700);
			ExitingText.setFillColor(sf::Color::White);

			rendWindow.draw(WinText);
			rendWindow.draw(ExitingText);

			rendWindow.display();
			std::chrono::seconds dura(10);
			std::this_thread::sleep_for(dura);
			rendWindow.close();
		}
		else if (man.numParts() >= 6) {
			//Drop The Guy Off The Screen
			//Display a restart button in the middle
			// Moves Andfield down until it's off the screen.
			while (man.moveTowardsBottom(rendWindow, 2)) {
				man.draw(rendWindow);
				rendWindow.display();
			}

			sf::Text LoseText;
			sf::Text WordThatYouTryingToGuesse;
			sf::Text ExitingText;
			LoseText.setFont(font);
			LoseText.setCharacterSize(100);
			LoseText.setString("You Lose");
			LoseText.setPosition(1050, 500);
			LoseText.setFillColor(sf::Color::White);

			WordThatYouTryingToGuesse.setFont(font);
			WordThatYouTryingToGuesse.setCharacterSize(100);
			WordThatYouTryingToGuesse.setString("The Word Was " + HangWordWord);
			WordThatYouTryingToGuesse.setPosition(650, 700);
			WordThatYouTryingToGuesse.setFillColor(sf::Color::White);

			ExitingText.setFont(font);
			ExitingText.setCharacterSize(100);
			ExitingText.setString("Exiting the Program in 10 Seconds");
			ExitingText.setPosition(550, 900);
			ExitingText.setFillColor(sf::Color::White);
			rendWindow.draw(LoseText);
			rendWindow.draw(WordThatYouTryingToGuesse);
			rendWindow.draw(ExitingText);
			rendWindow.display();
			std::chrono::seconds dura(10);
			std::this_thread::sleep_for(dura);
			rendWindow.close();
		}
		else {

			rendWindow.display();
		}
	}
}


// Function: rules
// Date Created: Apr. 23, 2024
// Date Modified: Apr. 23, 2024
// Description: contains the rules of the Hangman game
// Inputs: void
// Output: void
// Preconditions: function and input parameters are well-defined
// Postconditions: function must be called in main
void rules() {
	
	sf::RenderWindow rulesWindow(sf::VideoMode(2500, 1500), "Rules");
	sf::Font font;

	sf::Texture Picture;
	sf::Image BYE;
	sf::Sprite HI;

	if (!BYE.loadFromFile("Sai.png"))
	{
		cout << "error in the load background tile " << endl;
	}
	Picture.loadFromImage(BYE);

	HI.setTexture(Picture);


	if (!font.loadFromFile("comic.ttf"))
	{
		cout << "Error in the Fomnt File" << endl;
	}


	string HangmanRules[14] =
	{
		"Hangman Rules",
		"1.The goal of Hangman is to guess the word by choosing letters in the alphabet before the Hangman is hanged.",
		"2.There are five game modes you can choose from: Easy(easy difficulty words), Medium(medium difficulty",
		"words), Hard(hard difficulty words),Places(places from around the world), and People(famous people from",
		"around the world).",
		"3.Once you select a game mode, blank boxes representing each character in the mystery word appear alongside",
		"the letters of the alphabet. The gallows represent where the Hangman is going to be hanged",
		"4.Click a letter of the alphabet that you think is going to be in the mystery word.",
		"5.If the letter is in the word, the location(s) of where the letter would appear in the word will show in the blank",
		"boxes on the screen.",
		"6.If the letter is not in the word, a body part(head, torso, left arm, right arm, etc.) will be added to the gallows and",
		"the wrong letter will be removed from the alphabet list.",
		"7. Keep guessing letters until the word is complete or the Hangman falls off the screen. If the word is complete,",
		"you win! If the Hangman is hanged, you lose! (To Get Back To The Menu Click Any Where On Screen)"
	};
	sf::Text RULE2[14];

	for (int i = 0; i < 14; i++)
	{
		RULE2[i].setFont(font);
		RULE2[i].setCharacterSize(45);
		RULE2[i].setFillColor(sf::Color::White);
		RULE2[i].setString(HangmanRules[i]);
		RULE2[i].setPosition(0, 0 + i * 100);
	}

	sf::Text rules("Rules", font, 50);
	rules.setFillColor(sf::Color::White);
	rules.setPosition(350, 200);



	while (rulesWindow.isOpen()) {
		sf::Event event;
		while (rulesWindow.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
			{
				rulesWindow.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					rulesWindow.close();
				}
			}
			
			
		}
		
		rulesWindow.clear();
		rulesWindow.draw(HI);
		for (int i = 0; i < 14; i++)
		{
			rulesWindow.draw(RULE2[i]);
		}
		rulesWindow.display();
	}
	
}

// Function: DisplayMainScreen
// Date Created: Apr. 23, 2024
// Date Modified: Apr. 24, 2024
// Description: displays the main screen of the Hangman game
// Inputs: void
// Output: void
// Preconditions: function and input parameters are well-defined
// Postconditions: function must be called in main
void DisplayMainScreen() {
	srand(time(nullptr));
	Word_Bank Words;
	sf::RenderWindow window(sf::VideoMode(2500, 1500), "Hangman!");

	// Create font
	sf::Font font;
	if (!font.loadFromFile("comic.ttf")) {
	//	return 1;
	}

	// Set Background image
	sf::Texture Background;
	sf::Image BackgroundImage;
	if (!BackgroundImage.loadFromFile("BeackMain.jpg")) {
		//	return -1;
	}
	Background.loadFromImage(BackgroundImage);

	sf::Sprite BackgroundSprite;
	BackgroundSprite.setTexture(Background);

	// List of menu options in Hangman game
	string NamesOfButtons[7] = { "Rules" , "Easy" , "Medium" , "Hard", "Places" ,"People", "Exit" };
	sf::Text Info[7];

	// Menu buttons
	for (int i = 0; i < 7; i++) {
		Info[i].setFont(font);
		Info[i].setCharacterSize(75);
		Info[i].setFillColor(sf::Color::Yellow);
		Info[i].setString(NamesOfButtons[i]);
		Info[i].setPosition(200 + i * 300, 1250);
	}

	// Use switch block to select a menu option
	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				
				if (event.mouseButton.button == sf::Mouse::Left) {


					sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
					for (int i = 0; i < 7; i++) {
						sf::FloatRect TheButton = Info[i].getGlobalBounds();

						if (TheButton.contains(mousePosition.x, mousePosition.y)) {
							switch (i) {
							case 0:
								rules();
								cout << "This Is How You Play The Game" << endl;
								break;

							case 1:
								runHangMan(Words.RandomEasyVector());
								window.close();
								break;
							case 2:
								runHangMan(Words.RandomMediumVector());
								window.close();
								break;

							case 3:
								runHangMan(Words.RandomHardVector());
								window.close();
								break;
							case 4:
								runHangMan(Words.RandomPlaceVector());
								window.close();
								break;

							case 5:
								runHangMan(Words.RandomFamousVector());
								window.close();

								break;
							case 6:
								window.close();
								break;

							default:
								break;
							}
						}
					}
				}
			}
		}

		sf::Text HangMan;
		HangMan.setFont(font);
		HangMan.setCharacterSize(200);
		HangMan.setString("HangMan");
		HangMan.setPosition(800, 500);
		HangMan.setFillColor(sf::Color::White);
		window.clear();
		/*window.draw(Button1);*/
		window.draw(BackgroundSprite);
		for (int i = 0; i < 7; i++) {
			window.draw(Info[i]);
		}
		window.draw(HangMan);
		window.display();
	}
}

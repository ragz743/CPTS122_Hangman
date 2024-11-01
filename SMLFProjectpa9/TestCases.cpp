#include "TestCases.hpp"

// Function: testCaseMenu
// Date Created: Apr. 24, 2024
// Date Modified: Apr. 24, 2024
// Description: main menu containing all of the test cases
// Inputs: void
// Output: void
// Preconditions: function and input parameters are well-defined
// Postconditions: function must be called in main
void testCaseMenu() {
	int count = 0;

	do {
		do {
			cout << "*****HANGMAN TEST CASES*****" << endl;
			cout << "1. Easy Mode Test Case" << endl;
			cout << "2. Medium Mode Test Case" << endl;
			cout << "3. Hard Mode Test Case" << endl;
			cout << "4. Places Mode Test Case" << endl;
			cout << "5. Famous People Mode Test Case" << endl;
			cout << "6. Exit" << endl;
			cout << "Select a Menu Option: " << endl;
			cin >> count;
		} while (count < 1 || count > 6);

		if (count == 1) {
			system("cls");
			testCaseOne();
		}
		else if (count == 2) {
			system("cls");
			testCaseTwo();
		}
		else if (count == 3) {
			system("cls");
			testCaseThree();
		}
		else if (count == 4) {
			system("cls");
			testCaseFour();
		}
		else if (count == 5) {
			system("cls");
			testCaseFive();
		}
		else if (count == 6) {
			system("cls");
			cout << "Exiting Game.\n" << endl;
		}
	} while (count != 6);
}

// Function: testCaseOne
// Date Created: Apr. 24, 2024
// Date Modified: Apr. 24, 2024
// Description: contains the first test case
// Inputs: void
// Output: void
// Preconditions: function and input parameters are well-defined
// Postconditions: function must be called in testCaseMenu
void testCaseOne() {
	string easyCaseString = "DISPLAY";
	string guessWord(easyCaseString.length(), '_');
	int strikes = 6;
	bool wordIsFull = false;

	char letters[26] = {};
	for (int i = 0; i < 26; i++) {
		letters[i] = ('A' + i);
	}

	// Loop through the program until the number of strikes is 6 or the letters of the mystery word have all been guessed
	while (strikes != 0 && wordIsFull != true) {
		char chosenLetter;
		bool letterIsCorrect = false;
		cout << guessWord << endl;
		cout << "Which letter would you like to select?: " << endl;
		cin >> chosenLetter;
		chosenLetter = toupper(chosenLetter);

		// Check to see if chosenLetter is in the list of letters
		for (int i = 0; i < 26; i++) {
			if (chosenLetter == letters[i]) {
				letterIsCorrect = true;
			}
		}

		if (letterIsCorrect) {
			bool letterInWord = false;
			for (int i = 0; i < guessWord.length(); i++) {
				if (easyCaseString[i] == chosenLetter) {
					cout << "The letter " << chosenLetter << " is in the mystery word." << endl;
					guessWord[i] = chosenLetter;
					letterInWord = true;
				}
			}
			if (letterInWord == false) {
				strikes--;
				cout << "The letter " << chosenLetter << " is not in the mystery word. You have " << strikes << " strikes left." << endl;
			}
		}
		else {
			cout << "This letter is incorrect or has already been chosen.\n" << endl;
		}
		// Go over guessWord and check if the letters have been guessed
		if (guessWord == easyCaseString) {
			wordIsFull = true;
		}
		if (wordIsFull) {
			cout << "You have successfully guessed the mystery word: " << guessWord << "\n" << endl;
		}
		if (strikes == 0) {
			cout << "Your strikes are up! The correct word is " << easyCaseString << "\n" << endl;
		}
		system("pause");
		system("cls");
	}
}

// Function: testCaseTwo
// Date Created: Apr. 24, 2024
// Date Modified: Apr. 24, 2024
// Description: contains the second test case
// Inputs: void
// Output: void
// Preconditions: function and input parameters are well-defined
// Postconditions: function must be called in testCaseMenu
void testCaseTwo() {
	string mediumCaseString = "COMPUTER";
	string guessWord(mediumCaseString.length(), '_');
	int strikes = 6;
	bool wordIsFull = false;

	char letters[26] = {};
	for (int i = 0; i < 26; i++) {
		letters[i] = ('A' + i);
	}

	// Loop through the program until the number of strikes is 6 or the letters of the mystery word have all been guessed
	while (strikes != 0 && wordIsFull != true) {
		char chosenLetter;
		bool letterIsCorrect = false;
		cout << guessWord << endl;
		cout << "Which letter would you like to select?: " << endl;
		cin >> chosenLetter;
		chosenLetter = toupper(chosenLetter);

		// Check to see if chosenLetter is in the list of letters
		for (int i = 0; i < 26; i++) {
			if (chosenLetter == letters[i]) {
				letterIsCorrect = true;
			}
		}

		if (letterIsCorrect) {
			bool letterInWord = false;
			for (int i = 0; i < guessWord.length(); i++) {
				if (mediumCaseString[i] == chosenLetter) {
					cout << "The letter " << chosenLetter << " is in the mystery word." << endl;
					guessWord[i] = chosenLetter;
					letterInWord = true;
				}
			}
			if (letterInWord == false) {
				strikes--;
				cout << "The letter " << chosenLetter << " is not in the mystery word. You have " << strikes << " strikes left." << endl;
			}
		}
		else {
			cout << "This letter is incorrect or has already been chosen.\n" << endl;
		}
		// Go over guessWord and check if the letters have been guessed
		if (guessWord == mediumCaseString) {
			wordIsFull = true;
		}
		if (wordIsFull) {
			cout << "You have successfully guessed the mystery word: " << guessWord << "\n" << endl;
		}
		if (strikes == 0) {
			cout << "Your strikes are up! The correct word is " << mediumCaseString << "\n" << endl;
		}
		system("pause");
		system("cls");
	}
}

// Function: testCaseThree
// Date Created: Apr. 24, 2024
// Date Modified: Apr. 24, 2024
// Description: contains the third test case
// Inputs: void
// Output: void
// Preconditions: function and input parameters are well-defined
// Postconditions: function must be called in testCaseMenu
void testCaseThree() {
	string hardCaseString = "GAS";
	string guessWord(hardCaseString.length(), '_');
	int strikes = 6;
	bool wordIsFull = false;

	char letters[26] = {};
	for (int i = 0; i < 26; i++) {
		letters[i] = ('A' + i);
	}

	// Loop through the program until the number of strikes is 6 or the letters of the mystery word have all been guessed
	while (strikes != 0 && wordIsFull != true) {
		char chosenLetter;
		bool letterIsCorrect = false;
		cout << guessWord << endl;
		cout << "Which letter would you like to select?: " << endl;
		cin >> chosenLetter;
		chosenLetter = toupper(chosenLetter);

		// Check to see if chosenLetter is in the list of letters
		for (int i = 0; i < 26; i++) {
			if (chosenLetter == letters[i]) {
				letterIsCorrect = true;
			}
		}

		if (letterIsCorrect) {
			bool letterInWord = false;
			for (int i = 0; i < guessWord.length(); i++) {
				if (hardCaseString[i] == chosenLetter) {
					cout << "The letter " << chosenLetter << " is in the mystery word." << endl;
					guessWord[i] = chosenLetter;
					letterInWord = true;
				}
			}
			if (letterInWord == false) {
				strikes--;
				cout << "The letter " << chosenLetter << " is not in the mystery word. You have " << strikes << " strikes left." << endl;
			}
		}
		else {
			cout << "This letter is incorrect or has already been chosen.\n" << endl;
		}
		// Go over guessWord and check if the letters have been guessed
		if (guessWord == hardCaseString) {
			wordIsFull = true;
		}
		if (wordIsFull) {
			cout << "You have successfully guessed the mystery word: " << guessWord << "\n" << endl;
		}
		if (strikes == 0) {
			cout << "Your strikes are up! The correct word is " << hardCaseString << "\n" << endl;
		}
		system("pause");
		system("cls");
	}
}

// Function: testCaseFour
// Date Created: Apr. 24, 2024
// Date Modified: Apr. 24, 2024
// Description: contains the fourth test case
// Inputs: void
// Output: void
// Preconditions: function and input parameters are well-defined
// Postconditions: function must be called in testCaseMenu
void testCaseFour() {
	string placesCaseString = "KYOTO";
	string guessWord(placesCaseString.length(), '_');
	int strikes = 6;
	bool wordIsFull = false;

	char letters[26] = {};
	for (int i = 0; i < 26; i++) {
		letters[i] = ('A' + i);
	}

	// Loop through the program until the number of strikes is 6 or the letters of the mystery word have all been guessed
	while (strikes != 0 && wordIsFull != true) {
		char chosenLetter;
		bool letterIsCorrect = false;
		cout << guessWord << endl;
		cout << "Which letter would you like to select?: " << endl;
		cin >> chosenLetter;
		chosenLetter = toupper(chosenLetter);

		// Check to see if chosenLetter is in the list of letters
		for (int i = 0; i < 26; i++) {
			if (chosenLetter == letters[i]) {
				letterIsCorrect = true;
			}
		}

		if (letterIsCorrect) {
			bool letterInWord = false;
			for (int i = 0; i < guessWord.length(); i++) {
				if (placesCaseString[i] == chosenLetter) {
					cout << "The letter " << chosenLetter << " is in the mystery word." << endl;
					guessWord[i] = chosenLetter;
					letterInWord = true;
				}
			}
			if (letterInWord == false) {
				strikes--;
				cout << "The letter " << chosenLetter << " is not in the mystery word. You have " << strikes << " strikes left." << endl;
			}
		}
		else {
			cout << "This letter is incorrect or has already been chosen.\n" << endl;
		}
		// Go over guessWord and check if the letters have been guessed
		if (guessWord == placesCaseString) {
			wordIsFull = true;
		}
		if (wordIsFull) {
			cout << "You have successfully guessed the mystery word: " << guessWord << "\n" << endl;
		}
		if (strikes == 0) {
			cout << "Your strikes are up! The correct word is " << placesCaseString << "\n" << endl;
		}
		system("pause");
		system("cls");
	}
}

// Function: testCaseFive
// Date Created: Apr. 24, 2024
// Date Modified: Apr. 24, 2024
// Description: contains the fifth test case
// Inputs: void
// Output: void
// Preconditions: function and input parameters are well-defined
// Postconditions: function must be called in testCaseMenu
void testCaseFive() {
	string peopleCaseString = "DISNEY";
	string guessWord(peopleCaseString.length(), '_');
	int strikes = 6;
	bool wordIsFull = false;

	char letters[26] = {};
	for (int i = 0; i < 26; i++) {
		letters[i] = ('A' + i);
	}

	// Loop through the program until the number of strikes is 6 or the letters of the mystery word have all been guessed
	while (strikes != 0 && wordIsFull != true) {
		char chosenLetter;
		bool letterIsCorrect = false;
		cout << guessWord << endl;
		cout << "Which letter would you like to select?: " << endl;
		cin >> chosenLetter;
		chosenLetter = toupper(chosenLetter);

		// Check to see if chosenLetter is in the list of letters
		for (int i = 0; i < 26; i++) {
			if (chosenLetter == letters[i]) {
				letterIsCorrect = true;
			}
		}

		if (letterIsCorrect) {
			bool letterInWord = false;
			for (int i = 0; i < guessWord.length(); i++) {
				if (peopleCaseString[i] == chosenLetter) {
					cout << "The letter " << chosenLetter << " is in the mystery word." << endl;
					guessWord[i] = chosenLetter;
					letterInWord = true;
				}
			}
			if (letterInWord == false) {
				strikes--;
				cout << "The letter " << chosenLetter << " is not in the mystery word. You have " << strikes << " strikes left." << endl;
			}
		}
		else {
			cout << "This letter is incorrect or has already been chosen.\n" << endl;
		}
		// Go over guessWord and check if the letters have been guessed
		if (guessWord == peopleCaseString) {
			wordIsFull = true;
		}
		if (wordIsFull) {
			cout << "You have successfully guessed the mystery word: " << guessWord << "\n" << endl;
		}
		if (strikes == 0) {
			cout << "Your strikes are up! The correct word is " << peopleCaseString << "\n" << endl;
		}
		system("pause");
		system("cls");
	}
}
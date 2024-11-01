#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::ifstream;

class Word_Bank
{
public:
	// Function: Word_Bank
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: constructor for Word_Bank class
	// Inputs: void
	// Output: Word_Bank
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main 
	Word_Bank();

	// Function: ~Word_Bank
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: destructor for Word_Bank class
	// Inputs: void
	// Output: ~Word_Bank
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main 
	~Word_Bank();

	// Function: ReadEasyFile
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: returns vector of strings from Easy.txt file
	// Inputs: void
	// Output: vector<string>
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main 
	vector<string>  ReadEasyFile();

	// Function: ReadMediumFile
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: returns vector of strings from Medium.txt file
	// Inputs: void
	// Output: vector<string>
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main 
	vector<string>  ReadMediumFile();

	// Function: ReadHardFile
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: returns vector of strings from Hard.txt file
	// Inputs: void
	// Output: vector<string>
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main 
	vector<string>  ReadHardFile();

	// Function: ReadPlacesFile
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: returns vector of strings from Places.txt file
	// Inputs: void
	// Output: vector<string>
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main 
	vector<string>  ReadPlacesFile();

	// Function: ReadFamousFile
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: returns vector of strings from Famous_People.txt file
	// Inputs: void
	// Output: vector<string>
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main 
	vector<string>  ReadFamousFile();

	// Function: RandomEasyVector
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: returns a random word from the Easy.txt file
	// Inputs: void
	// Output: string
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main 
	string RandomEasyVector();

	// Function: RandomMediumVector
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: returns a random word from the Medium.txt file
	// Inputs: void
	// Output: string
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main 
	string RandomMediumVector();

	// Function: RandomHardVector
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: returns a random word from the Hard.txt file
	// Inputs: void
	// Output: string
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	string RandomHardVector();

	// Function: RandomPlaceVector
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: returns a random word from the Place.txt file
	// Inputs: void
	// Output: string
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	string RandomPlaceVector();

	// Function: RandomFamousVector
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: returns a random word from the Famous_People.txt file
	// Inputs: void
	// Output: string
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
	string RandomFamousVector();

private:
	ifstream filestream1;
};


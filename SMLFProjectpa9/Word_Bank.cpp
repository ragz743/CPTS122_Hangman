#include "Word_Bank.h"

// Function: Word_Bank
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: constructor for Word_Bank class
	// Inputs: void
	// Output: Word_Bank
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main 
Word_Bank::Word_Bank()
{

}

// Function: ~Word_Bank
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: destructor for Word_Bank class
	// Inputs: void
	// Output: ~Word_Bank
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main 
Word_Bank::~Word_Bank()
{

}

// Function: ReadEasyFile
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: returns vector of strings from Easy.txt file
	// Inputs: void
	// Output: vector<string>
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main 
vector<string> Word_Bank::ReadEasyFile()
{
	this->filestream1.open("Easy.txt");
	std::vector<string> Easy;

	if (this->filestream1.is_open())
	{
		string temp;

		while (this->filestream1 >> temp)
		{
			Easy.push_back(temp);
		}
	}
	this->filestream1.close();
	return Easy;
}

// Function: ReadMediumFile
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: returns vector of strings from Medium.txt file
	// Inputs: void
	// Output: vector<string>
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main 
vector<string> Word_Bank::ReadMediumFile()
{
	this->filestream1.open("Medium.txt");
	std::vector<string> Medium;

	if (this->filestream1.is_open())
	{
		string temp;

		while (this->filestream1 >> temp)
		{
			Medium.push_back(temp);
		}
	}
	this->filestream1.close();
	return Medium;
}

// Function: ReadHardFile
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: returns vector of strings from Hard.txt file
	// Inputs: void
	// Output: vector<string>
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main 
vector<string> Word_Bank::ReadHardFile()
{
	this->filestream1.open("Hard.txt");
	std::vector<string> Hard;

	if (this->filestream1.is_open())
	{
		string temp;

		while (this->filestream1 >> temp)
		{
			Hard.push_back(temp);
		}
	}
	this->filestream1.close();
	return Hard;
}

// Function: ReadPlacesFile
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: returns vector of strings from Places.txt file
	// Inputs: void
	// Output: vector<string>
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main 
vector<string> Word_Bank::ReadPlacesFile()
{
	this->filestream1.open("Places.txt");
	std::vector<string> Places;

	if (this->filestream1.is_open())
	{
		string temp;

		while (this->filestream1 >> temp)
		{
			Places.push_back(temp);
		}
	}
	this->filestream1.close();
	return Places;
}

// Function: ReadFamousFile
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: returns vector of strings from Famous_People.txt file
	// Inputs: void
	// Output: vector<string>
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main 
vector<string> Word_Bank::ReadFamousFile()
{
	this->filestream1.open("Famous_People.txt");
	std::vector<string> Famous;

	if (this->filestream1.is_open())
	{
		string temp;

		while (this->filestream1 >> temp)
		{
			Famous.push_back(temp);
		}
	}
	this->filestream1.close();
	return Famous;
}

// Function: RandomEasyVector
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: returns a random word from the Easy.txt file
	// Inputs: void
	// Output: string
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main 
string Word_Bank::RandomEasyVector()
{
	vector<string> print = ReadEasyFile();
	int random = rand() % 30;
	return print[random];
}

// Function: RandomMediumVector
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: returns a random word from the Medium.txt file
	// Inputs: void
	// Output: string
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
string Word_Bank::RandomMediumVector()
{
	vector<string> print = ReadMediumFile();
	int random = rand() % 30;
	return print[random];
}

// Function: RandomHardVector
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: returns a random word from the Hard.txt file
	// Inputs: void
	// Output: string
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
string Word_Bank::RandomHardVector()
{
	vector<string> print = ReadHardFile();
	int random = rand() % 30;
	return print[random];
}

// Function: RandomPlaceVector
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: returns a random word from the Place.txt file
	// Inputs: void
	// Output: string
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
string Word_Bank::RandomPlaceVector()
{
	vector<string> print = ReadPlacesFile();
	int random = rand() % 30;
	return print[random];
}

// Function: RandomFamousVector
	// Date Created: Apr. 23, 2024
	// Date Modified: Apr. 23, 2024
	// Description: returns a random word from the Famous_People.txt file
	// Inputs: void
	// Output: string
	// Preconditions: function and input parameters are well-defined
	// Postconditions: function must be called in main
string Word_Bank::RandomFamousVector()
{
	vector<string> print = ReadFamousFile();
	int random = rand() % 30;
	return print[random];
}


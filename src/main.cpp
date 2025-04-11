
#include "format.h"
#include "player.h"
#include <cctype>


using std::tolower;
using std::cin;
using std::exception;

Format* formatChoice(Format* format1, Format* format2)
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	cout << "" << endl;


	cout << "Please choose from either: " << endl;
	cout << "1. Pokemon - Gym Leader Challenge"  << endl;
	cout << "2. Pokemon - Standard"  << endl;

	string userInput;
	int userChoice = 0;

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	cout << "" << endl;

	getline(cin,userInput);

	try
	{
		userChoice = stoi(userInput);
	}
	catch(...)
	{
		//just to prevent error
	}

	while (userChoice != 1 && userChoice!= 2)
	{
		cout << "You typed an invalid value: choose either '1' or '2'" << endl;

		getline(cin,userInput);

		try
		{
			userChoice = stoi(userInput);
		}
		catch(...)
		{
			//just to prevent error
		}


	}


	if (userChoice == 1)
	{
		return format1;
	}
	else
	{
		return format2;
	}


}

void intro()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	cout << "" << endl;

	cout << "User, welcome to the Swiss Tournament Tool!" << endl;

	//Format* formatCh = formatChoice(GymChoice, StandardChoice);

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	cout << "" << endl;
}


void displayMenu()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	cout << " " << endl;

	cout << "MENU" << endl;
	cout << "1. Generate Matchups" << endl;
	cout << "2. Display Matchups" << endl;
	cout << "3. Add Point to User" << endl;
	cout << "4. Remove Point from User" << endl;
	cout << "5. Add Player" << endl;
	cout << "6. Remove Player" << endl;
	cout << "7. Input Match Result" << endl;
	cout << "8. Display Players and their points" << endl;
	cout << "9. Quit" << endl;



	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	cout << " " << endl;
}

int menuChoiceFunc()
{
	displayMenu();

	string userInput;
	int userChoice = 0;
	bool valid = false;

	getline(cin,userInput);

	try
	{
		userChoice = stoi(userInput);
	}
	catch(...)
	{
		//just to prevent error
	}

	if ( !(userChoice < 1 || userChoice > 9) )
	{
		valid = true;
	}


	while (!valid)
	{

		cout << "ENTER A VALID CHOICE BETWEEN 1 and 9 INCLUSIVE" << endl;

		displayMenu();


		getline(cin,userInput);

		try
		{
			userChoice = stoi(userInput);
		}
		catch(...)
		{
			//just to prevent error
		}

		if ( !(userChoice < 1 || userChoice > 8) )
		{
			valid = true;
		}
	}

	return userChoice;


}

bool areSure()
{

	cout << "Want to cancel? Type 'yes' to cancel, otherwise press enter." << endl;

	string uInput;

	getline(cin,uInput);

	for (int i = 0; i < uInput.length(); i++)
	{
		uInput[i] = tolower(uInput[i]);
	}

	if (uInput == "yes")
	{
		return false;
	}
	else
	{
		return true;
	}

}

int main()
{

	Format* formatCh;

	Format pokemonGym("Pokemon - Gym Leader Challenge");
	Format pokemonStandard("Pokemon - Standard");

	Format* GymChoice = &pokemonGym;
	Format* StandardChoice = &pokemonStandard;

	string userInput;
	int userChoice = 0;

	intro();

	/*
	 * 	cout << "1. Generate Matchups" << endl;
	cout << "2. Display Matchups" << endl;
	cout << "3. Add Point to User" << endl;
	cout << "4. Remove Point from User" << endl;
	cout << "5. Add Player" << endl;
	cout << "6. Remove Player" << endl;
	cout << "7. Input Match Result" << endl;
	cout << "8. Quit" << endl;

	*/

	string playerName;

	while (userChoice != 9)
	{
		userChoice = menuChoiceFunc();

		switch(userChoice)
		{
			case 1:

				formatCh = formatChoice(GymChoice, StandardChoice);

				if (areSure())
				{
					cout << "Attempting to generate matchups for round" << endl;


					formatCh->generateMatches();
				}


				break;
			case 2:

				formatCh = formatChoice(GymChoice, StandardChoice);

				if (areSure())
				{
					cout << "Attempting to display matchups for round" << endl;

					formatCh->displayMatches();

				}


				break;
			case 3:

				formatCh = formatChoice(GymChoice, StandardChoice);

				cout << "What player would you like to add a point to?" << endl;
				getline(cin,playerName);

				if (areSure())
				{
					formatCh->addPoints(playerName);
				}

				break;
			case 4:


				formatCh = formatChoice(GymChoice, StandardChoice);

				cout << "What player would you like to remove a point from?" << endl;
				getline(cin,playerName);

				if (areSure())
				{
					formatCh->removePoints(playerName);
				}

				break;
			case 5:

				formatCh = formatChoice(GymChoice, StandardChoice);
				cout << "What is the name of the player you want to add?" << endl;
				getline(cin,playerName);

				if (areSure())
				{
					formatCh->addPlayer(playerName);
				}


				break;
			case 6:

				formatCh = formatChoice(GymChoice, StandardChoice);

				cout << "What is the name of the player you want to remove?" << endl;
				getline(cin,playerName);

				if (areSure())
				{
					formatCh->removePlayer(playerName);
				}


				break;
			case 7:

				formatCh = formatChoice(GymChoice, StandardChoice);
				cout << "What is the name of the player who won their matchup?" << endl;
				getline(cin,playerName);

				if (areSure())
				{
					formatCh->matchResult(playerName);
				}

				break;
			case 8:
				formatCh = formatChoice(GymChoice, StandardChoice);
				cout << "Displaying Players and their points" << endl;

				if (areSure())
				{
					formatCh->displayPlayerStats();
				}


				break;
		}

	}








	cout << "program end" << endl;


	return 0;
}






#include "format.h"


//Format class

Format::Format(string name)
{
	fName = name;
	playerList.head = nullptr;
	playerList.tail = nullptr;
	numPlayers = 0;
	priorityPlayer = nullptr;
}

Format::~Format()
{
	/*
	playerList.head = nullptr;
	playerList.tail = nullptr;
	*/

	//check if empty

	if (playerList.head == nullptr)
	{
		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << endl;

		cout << "PlayerList is empty, nothing to delete" << endl;

		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << endl;


		return;
	}

	//to delete a circular linked list, first make the tail->next point to nullptr

	PlayerNode* current = nullptr;
	PlayerNode* next = nullptr;

	playerList.tail->next = nullptr; // makes the linked list non-circular

	current = playerList.head;

	while (current != nullptr)
	{
		next = current->next;
		delete current;
		current = next;

	}

	playerList.head = nullptr;
	playerList.tail = nullptr;


}


//PairList class
PairList::PairList()
{
	head = nullptr;
	tail = nullptr;
}


PairList::~PairList()
{
	clear();
}

void PairList::clear()
{


	PairNode* current = nullptr;
	PairNode* next = nullptr;


	current = head;

	while (current != nullptr)
	{
		next = current->next;
		delete current;
		current = next;

	}

	head = nullptr;
	tail = nullptr;

}

void PairList::addPair(string player1Name, string player2Name)
{
	PairNode* temp = new PairNode;
	temp->complete = false;
	temp->p1Name = player1Name;
	temp->p2Name = player2Name;
	temp->next = nullptr;

	//check empty

	if (head == nullptr)
	{
		head = temp;
		tail = temp;
		return;

	}

	tail->next = temp;
	tail = temp;


}

void PairList::matchResult(string winnerName)
{


	//search for winner
	//set their flag to true

	if (head == nullptr)
	{
		cout << "no players in player list, failed to search for match result" << endl;
		return;
	}

	PairNode* tracker = head;

	while (tracker != nullptr)
	{

		if (tracker->p1Name == winnerName || tracker->p2Name == winnerName)
		{
			tracker->complete = true;
			return;
		}

		tracker = tracker->next;
	}



}

void PairList::display()
{

	if (head == nullptr)
	{
		cout << "no pairs have been made" << endl;
		return;
	}

	cout << "------------------------------------" << endl;
	cout << "Current Matchups" << endl;
	cout << " " << endl;



	PairNode* tracker = head;

	while (tracker != nullptr)
	{
		cout << tracker->p1Name << " VS " << tracker->p2Name << " - ";
		if (tracker->complete)
		{
			cout << "complete";
		}
		else
		{
			cout << "incomplete";
		}

		cout << endl;

		tracker = tracker->next;
	}


	cout << "------------------------------------" << endl;
	cout << " " << endl;


}


#include "format.h"

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

}

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
}

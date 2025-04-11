
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

void Format::addPlayer(string playerName)
{
	//Create player object
	Player* newPlayer = new Player(playerName);

	PlayerNode* newPlayerNode = new PlayerNode;

	newPlayerNode->playerPtr = newPlayer;
	newPlayerNode->next = nullptr;

	//check if list is empty

	if (playerList.head == nullptr)
	{
		playerList.head = newPlayerNode;
		playerList.tail = playerList.head;
		newPlayerNode->next = playerList.head;

		numPlayers++;

		return;

	}

	//from here on - handle a non empty list
	//In this scenario you must first:
	//Loop through each existing player in the playerlist:
	// - add connection to them from newplayer
	// - add connection to newplayer from them
	// - append the new node at the end of list using tail

	PlayerNode* tracker = playerList.head;

	tracker->playerPtr->addConnection(newPlayer); 	// - add connection to them from newplayer
	newPlayer->addConnection(tracker->playerPtr);	// - add connection to newplayer from them

	tracker = tracker->next; //change tracker

	while (tracker != playerList.head)
	{
		tracker->playerPtr->addConnection(newPlayer); 	// - add connection to them from newplayer
		newPlayer->addConnection(tracker->playerPtr);	// - add connection to newplayer from them

		tracker = tracker->next;
	}

	// - append the new node at the end of list using tail

	playerList.tail->next = newPlayerNode;
	playerList.tail = newPlayerNode;
	newPlayerNode->next = playerList.head;

	numPlayers++;

	return;




}

//Removing player should only be done between matches
// Does not affect current matchup pairs
//
void Format::removePlayer(string playerName)
{
	//Find player
	//Delete the following:
	// Connections between itself and all nodes
	// Player object
	// PlayerNode object

	//Check for empty

	if (playerList.head == nullptr)
	{
		cout << "no players to remove" << endl;

		return;
	}

	//list is not empty
	//find the player we are looking for and establish a pointer to it.


	Player* foundPlayer = nullptr;
	bool playerDelFound = false;

	PlayerNode* prev = nullptr;
	PlayerNode* tracker = playerList.head;

	//handle 1 node case

	if (tracker->playerPtr->getName() == playerName) //found player at 1st node
	{
		if (playerList.head == playerList.tail)  //case that there is only 1 node
		{
			//free the node and the player object

			delete tracker->playerPtr;
			delete tracker;


			playerList.head = nullptr;
			playerList.tail = nullptr;

			return;
		}

		playerDelFound = true;
		foundPlayer = tracker->playerPtr;

	}


	if (!playerDelFound) //if not found at first node
	{
		//more than 1 node at this point
		prev = tracker;
		tracker = tracker->next;

		while (tracker != playerList.head and !playerDelFound) //go through list until you find the result
		{
			if (tracker->playerPtr->getName() == playerName)
			{
				foundPlayer = tracker->playerPtr;
				playerDelFound = true;
			}
			else
			{
				prev = tracker;
				tracker = tracker->next; //if we dont find it here, move on
			}
		}

		if (foundPlayer == nullptr)
		{
			cout << "this player: " << playerName << " was not found" << endl;
			return;
		}
	}


	//now that we found the player we must first delete the other connections it had with other nodes
	//tracker still points at found player

	PlayerNode* partnerTracker = tracker->next;

	while (partnerTracker != tracker)
	{
		partnerTracker->playerPtr->removeConnection(foundPlayer); //remove all connections
		partnerTracker = partnerTracker->next;
	}

	//all connections are removed
	//time to free player itself and then adjust linked list

	prev->next = tracker->next;

	if (tracker == playerList.tail)
	{
		playerList.tail = prev;
	}

	//free player inside and object

	delete tracker->playerPtr;
	delete tracker;


	//reset priority at end

	priorityPlayer = playerList.head;

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


#include "player.h"


//Player Class methods

Player::Player(string name)
{
	paired = false;
	pName = name;
	points = 0;
}

void Player::addPoint()
{
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;

	cout << "Player: " << pName << "has had their points increased" << endl;

	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;

	points++;
}

void Player::removePoint()
{
	if (points == 0)
	{
		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << endl;

		cout << "Player already has 0 points, you can't remove more" << endl;

		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << endl;

		return;

	}

	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;

	cout << "Player: " << pName << "has had their points decreased" << endl;

	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;


	points--;


}

//Web Class member functions

Player::Web::Web()
{
	//initialize connections
	connections.head = nullptr;
	connections.tail = nullptr;

	//currentMatchup doesnt exist yet
	currentMatchup = nullptr;
}

Player::Web::~Web()
{

	clearConnections();

}

void Player::Web::clearConnections()
{
	//check if empty

	if (connections.head == nullptr)
	{
		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << endl;

		cout << "Web Connection is empty, nothing to delete" << endl;

		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << endl;


		return;
	}

	//to delete a circular linked list, first make the tail->next point to nullptr

	PlayerNode* current = nullptr;
	PlayerNode* next = nullptr;

	connections.tail->next = nullptr; // makes the linked list non-circular

	current = connections.head;

	while (current != nullptr)
	{
		next = current->next;
		delete current;
		current = next;

	}
}

void Player::Web::addConnection(Player* newPlayer)
{

	//create playerNode

	PlayerNode* newPlayerNode = new PlayerNode;

	newPlayerNode->next = nullptr;
	newPlayerNode->playerPtr = newPlayer;




	//check for empty list

	if (connections.head == nullptr)
	{
		connections.head = newPlayerNode;
		newPlayerNode->next = connections.head; //circular list


		return;
	}

	//list is not empty

	connections.tail->next = newPlayerNode;
	newPlayerNode->next = connections.head; //circular list
	connections.tail = newPlayerNode;


	return;



}


/*
 * NOTE: when deleting node, make current matchup point to previous matchup.
 * This is because during findPair() currentMatchup always adjusts to the next node before processing
*/

void Player::Web::removeConnection(Player* removePlayer)
{
	//check for empty list

	if (connections.head == nullptr)
	{
		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << endl;

		cout << "Web Connection is empty, nothing to delete" << endl;

		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << endl;


		return;
	}

	//search for item to remove, if not found - do nothing

	bool found = false;

	//1. Find connection if possible

	/*
		Check the Beginning


	*/

	PlayerNode* current = connections.head;
	PlayerNode* prev = nullptr;

	//remember linked list is circular

	//make comparison btwn removePlayer and current Nodes pointer

	if (current->playerPtr == removePlayer) //Player found
	{

		//remove node


		if (connections.head == connections.tail) //only 1 connection
		{

			connections.head = nullptr;
			connections.tail = nullptr;
			currentMatchup = nullptr;
		}
		else
		{
			connections.head = current->next;
			connections.tail->next = connections.head;

			if (current == currentMatchup)
			{
				currentMatchup = connections.tail; //set to "previous matchup" in this case the last element in list
			}

		}

		delete current;

		return;

	}

	prev = current;
	current= current->next;


	while (!found && current != connections.head) //not found or we haven't looped back to beginning
	{


		if (current->playerPtr == removePlayer)
		{
			found = true;
		}
		else //if you didn't find the player, don't change the pointer
		{
			prev = current;
			current= current->next;
		}

	}



	//Debug

	if (found)
	{
		// if we are going to delete the node that currentMatchup points to, then we need to adjust the pointer
		if (currentMatchup == current)
		{
			currentMatchup = prev;
		}

		//check end

		if (current == connections.tail)
		{
			prev->next = connections.head; //prev is the new tail
			connections.tail = prev;



		}
		else //do middle
		{
			prev->next = current->next;
		}

		delete current;



	}
	else
	{
		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << endl;


		cout << "Player not found" << endl;

		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << endl;
	}

	return;
}


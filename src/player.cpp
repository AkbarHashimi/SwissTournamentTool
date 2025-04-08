
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





	return;
}


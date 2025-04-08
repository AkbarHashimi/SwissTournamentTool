
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

}

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

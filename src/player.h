/*
 * player.h
 *
 *  Created on: Apr 7, 2025
 *      Author: Akbar Hashimi
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
using std::string;

#include <iostream>

using std::cout;
using std::endl;

class Player
{
	private:
	bool Paired;
	string Pname;
	int points;
	Web connectionList;

	public:
	Player(string name);
	void addPoint();
	void removePoint();
	bool findPair(Player* & foundPlayer);
	void pair();
	void unPair();
	void addConnection(Player* addPlayer);
	void removeConnection(Player* removePlayer);



};

//Desc: Node struct for linked lists of players
struct PlayerNode
{
	Player* playerPtr;
	PlayerNode* next;
};

//Desc: circular linked list of PlayerNodes representing Players in a format
struct PlayerLL
{
	PlayerNode* head;
	PlayerNode* tail;
};

//Desc: A class that contains a linked list of PlayerNode’s and the current matchup.
class Web
{
	private:
	PlayerLL connections;
	PlayerNode* currentMatchup;

	public:
	Web();
	void addConnection(Player* addPlayer);
	void removeConnection(Player* removePlayer);
	~Web();


};



#endif /* PLAYER_H_ */

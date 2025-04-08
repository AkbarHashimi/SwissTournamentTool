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


//Lots of silly forward declare referencing
class Web;
struct PlayerLL;
struct PlayerNode;
class Player;

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

class Player
{
	public:


	Player(string name);
	void addPoint();
	void removePoint();
	bool findPair(Player* & foundPlayer);
	void pair();
	void unPair();
	void addConnection(Player* addPlayer);
	void removeConnection(Player* removePlayer);
	void notifyPartner();
	string getName();

	//Desc: A class that contains a linked list of PlayerNode’s and the current matchup.
	class Web
	{
		private:
		PlayerLL connections;
		PlayerNode* currentMatchup;

		public:
		Web();
		void addConnection(Player* newPlayer);
		void removeConnection(Player* removePlayer);
		void notifyPartner();
		bool findPair(Player* & foundPlayer);
		~Web();


	};


	private:


	bool paired;
	string pName;
	int points;
	Web connectionList;







};







#endif /* PLAYER_H_ */

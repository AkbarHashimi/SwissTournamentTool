/*
 * format.h
 *
 *  Created on: Apr 7, 2025
 *      Author: Akbar Hashimi
 */

#ifndef FORMAT_H_
#define FORMAT_H_

#include <string>
using std::string;

#include <iostream>

using std::cout;
using std::endl;

#include "player.h"

/*
	NOTES: Remember that when deleting, make sure that the priorityPlayer
	is reset to head of playerlist.
*/

struct PairNode
{
	string p1Name;
	string p2Name;

	bool complete;

	PairNode* next;
};

class PairList
{
	private:
	PairNode* head;
	PairNode* tail;


	public:
	PairList();
	~PairList();


	void addPair(string player1Name, string player2Name);
	void matchResult(string winnerName);
	void clear();
	void display();
};


class Format
{
	private:

	string fName; //format name
	PlayerLL playerList;
	int numPlayers;
	PlayerNode* priorityPlayer;
	PairList currentMatches;


	public:
	Format(string name);
	~Format();

	void generateMatches();
	void displayMatches();
	void addPoints(string playerName);
	void removePoints(string playerName);
	void addPlayer(string playerName);
	void removePlayer(string playerName);
	void matchResult(string winnerName); //assumes partner is valid
	void displayPlayerStats();
	string getName();




};




#endif /* FORMAT_H_ */

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

class Format
{
	private:

	string fName; //format name
	PlayerLL playerList;
	int numPlayers;
	PlayerNode* priorityPlayer;


	public:
	Format();
	~Format();

	void generateMatches();
	void displayMatches();
	void addPoints(string playerName);
	void removePoints(string playerName);





};



#endif /* FORMAT_H_ */

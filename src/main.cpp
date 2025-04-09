
#include "format.h"
#include "player.h"

int main()
{

	string name1 = "Akbar";
	string name2 = "NotAkbar";
	string name3 = "serious";

	string getName = "";
	bool getBool;

	Player testPlayer(name1);
	Player testPlayer2(name2);
	Player testPlayer3(name3);

	testPlayer.pair();
	getName = testPlayer.getName();
	getBool = testPlayer.getPair();


	testPlayer.addConnection(&testPlayer2);
	testPlayer.addConnection(&testPlayer3);

	testPlayer2.addConnection(&testPlayer);
	testPlayer2.addConnection(&testPlayer3);

	testPlayer3.addConnection(&testPlayer);
	testPlayer3.addConnection(&testPlayer2);


	cout << "program end" << endl;


	return 0;
}

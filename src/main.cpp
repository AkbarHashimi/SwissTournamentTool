
#include "format.h"
#include "player.h"

int main()
{

	string name1 = "Akbar";

	string getName = "";
	bool getBool;

	Player testPlayer(name1);
	testPlayer.pair();
	getName = testPlayer.getName();
	getBool = testPlayer.getPair();


	cout << "program end" << endl;


	return 0;
}

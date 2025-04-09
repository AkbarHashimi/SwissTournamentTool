
#include "format.h"
#include "player.h"

int main()
{

	string name1 = "Akbar";
	string name2 = "NotAkbar";
	string name3 = "serious";
	string name4 = "not in list";

	string getName = "";
	bool getBool;

	Player testPlayer(name1);
	Player testPlayer2(name2);
	Player testPlayer3(name3);
	Player testPlayer4(name4);

	testPlayer.pair();
	getName = testPlayer.getName();
	getBool = testPlayer.getPair();



	testPlayer.addConnection(&testPlayer2);
	testPlayer.addConnection(&testPlayer3);
	testPlayer.addConnection(&testPlayer4);

	testPlayer.removeConnection(&testPlayer2); // case - remove last item in list
	testPlayer.removeConnection(&testPlayer3); // case - remove last item in list
	testPlayer.removeConnection(&testPlayer4); // case - remove last item in list


	testPlayer2.addConnection(&testPlayer);
	testPlayer2.addConnection(&testPlayer3);

	testPlayer3.addConnection(&testPlayer);
	testPlayer3.addConnection(&testPlayer2);


	cout << "program end" << endl;


	return 0;
}

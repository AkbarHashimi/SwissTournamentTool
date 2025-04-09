
#include "format.h"
#include "player.h"

int main()
{

	string name1 = "Akbar";

	Player testPlayer(name1);
	testPlayer.pair();
	testPlayer.unPair();

	cout << "program end" << endl;


	return 0;
}

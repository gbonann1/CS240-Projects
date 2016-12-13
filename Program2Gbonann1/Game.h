#ifndef _Game_H
#define _Game_H
#include <iostream>
#include "Player.h"
#include <deque>
using namespace std;

class Game
{
	private:
		deque<Player> playerList;
		
	public:
		Game();
		Game(deque<Player>& p);
		deque<Player> getPlayerList();
		void play();
		~Game();		
};

#endif // _Game_H

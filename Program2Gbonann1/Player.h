#ifndef _Player_H
#define _Player_H
#include <iostream>
#include <string>
#include "Deck.h"

using namespace std;

class Player
{
	private:
		string name;
		Deck deck;
		
	public:
		Player();
		Player(Deck d, string s);
		void changeDeck(Deck& d);
		string getName();
		Deck getDeck();
		~Player();
		
		
};

#endif // _Player_H

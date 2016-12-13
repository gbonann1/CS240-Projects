#ifndef _Deck_H
#define _Deck_H
#include <iostream>
#include "PlayingCard.h"
#include <deque>
using namespace std;

class Deck
{
	private:
		deque<PlayingCard> deck;
		
	public:
		Deck();
		void add(PlayingCard& p);
		void shuffle();
		void fullDeck();
		deque<PlayingCard> getDeque();
		~Deck();
		
		
};

#endif // _Deck_H

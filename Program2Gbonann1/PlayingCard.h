#ifndef _PlayingCard_H
#define _PlayingCard_H
#include <iostream>

using namespace std;

class PlayingCard
{
	private:
		int value;
		char suit;
		
	public:
		PlayingCard();
		PlayingCard(int newValue, char newSuit);
		PlayingCard(const PlayingCard &c2);
		~PlayingCard();
		bool operator==(const PlayingCard& card) const;
		bool operator>(const PlayingCard& card) const;
		friend ostream & operator<<(ostream &out, const PlayingCard &p);
		
};

#endif // _PlayingCard_H

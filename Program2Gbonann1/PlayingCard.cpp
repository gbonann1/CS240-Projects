#include <iostream>
#include <stdlib.h>
#include "PlayingCard.h"
#include <fstream>

using namespace std;

PlayingCard::PlayingCard(){
}

PlayingCard::PlayingCard(int newValue, char newSuit){
	value = newValue;
	suit = newSuit;
}

PlayingCard::PlayingCard(const PlayingCard &c2) {
  value = c2.value;
  suit = c2.suit;
}

PlayingCard::~PlayingCard(){
}

bool PlayingCard::operator==(const PlayingCard& card) const {
	PlayingCard p1 = card;
	PlayingCard p2 = *this;
	return (p1.value == p2.value);
}

bool PlayingCard::operator>(const PlayingCard& card) const {
	PlayingCard p1 = card;
	PlayingCard p2 = *this;
	return (p2.value > p1.value);
}

ostream & operator<<(ostream &out, const PlayingCard& p){
	cout << '(';
	if (p.value == 11)
		cout << 'J';
	else if (p.value == 12)
		cout << 'Q';
	else if (p.value == 13)
		cout << 'K';
	else if (p.value == 14)
		cout << 'A';
	else
		cout << p.value;
	cout << p.suit;
	cout << ')';
}

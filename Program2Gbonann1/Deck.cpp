#include <iostream>
#include <stdlib.h>
#include "Deck.h"
#include "PlayingCard.h"
#include <algorithm>

using namespace std;

Deck::Deck(){
	
}

void Deck::add(PlayingCard& p){
	deck.push_front(p);
}

void Deck::shuffle(){
	random_shuffle(deck.begin(), deck.end());
}

void Deck::fullDeck(){
	deck.clear();
	for (int i = 2; i < 15; i++) {
		PlayingCard card(i, 'S');
		deck.push_front(card);
	}
	for (int i = 2; i < 15; i++) {
		PlayingCard card(i, 'C');
		deck.push_front(card);
	}
	for (int i = 2; i < 15; i++) {
		PlayingCard card(i, 'D');
		deck.push_front(card);
	}
	for (int i = 2; i < 15; i++) {
		PlayingCard card(i, 'H');
		deck.push_front(card);
	}
}

deque<PlayingCard> Deck::getDeque(){
	return deck;
}
Deck::~Deck(){
}


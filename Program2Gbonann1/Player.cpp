#include <iostream>
#include <stdlib.h>
#include "Player.h"
#include "Deck.h"
#include "PlayingCard.h"

using namespace std;

Player::Player(){
	
}

Player::Player(Deck d, string s){
	deck = d;
	name = s;
}

Deck Player::getDeck(){
	return deck;
}

string Player::getName(){
	return name;
}

void Player::changeDeck(Deck& d){
	deck = d;
}

Player::~Player(){
}


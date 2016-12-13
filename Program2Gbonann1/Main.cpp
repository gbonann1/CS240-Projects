#include <iostream>
#include <deque>
#include <stdlib.h>
#include "PlayingCard.h"
#include "Deck.h"
#include "Player.h"
#include "Game.h"
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
	deque<Player> players;
	deque<string> playerNames;
	Deck cardDeck;
	cardDeck.fullDeck();
	Deck p1Deck;
	Deck p2Deck;
	ifstream myfile("Players.txt");
	string nextLine;
	while (getline(myfile, nextLine)){
		playerNames.push_front(nextLine);
		//cout << nextLine;
	}
	for (int i = 0; i < playerNames.size(); i+=2) {
		cardDeck.shuffle();
		for (int j = 0; j < 52; j+=2){
			p1Deck.add(cardDeck.getDeque()[j]);
			p2Deck.add(cardDeck.getDeque()[j+1]);
		}
		Player p1 = Player(p1Deck, playerNames[i]);
		Player p2 = Player(p2Deck, playerNames[i+1]);
		players.push_front(p1);
		players.push_front(p2);
	}
	
	Game warTournament = Game(players);
	warTournament.play();
	
}

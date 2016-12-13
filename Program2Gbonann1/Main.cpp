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
	/**if (players.size() == 1 || players.size() == 2 || players.size() == 4 || players.size() == 8 || players.size() == 16 || 
		players.size() == 32 ||	players.size() == 64 || players.size() == 128 || players.size() == 256 || players.size() == 512 || players.size() == 1024 ||
	   	players.size() == 2048 || players.size() == 4096 || players.size() == 8192 || players.size() == 16384 ||
	  	players.size() == 32768 || players.size() == 65536 || players.size() == 131072 || players.size() == 262144 ||
	  	players.size() == 524288 || players.size() == 1048576 || players.size() == 2097152 ||
	  	players.size() == 4194304 || players.size() == 8388608 || players.size() == 16777216 ||
	  	players.size() == 33554432 || players.size() == 67108864 || players.size() == 134217728 ||
	  	players.size() == 268435456 || players.size() == 536870912 || players.size() == 1073741824 ||
	  	players.size() == 2147483648){
		Game warTournament = Game(players);
		warTournament.play();
	}
	else {
		cout << "Tournament must have 2^n players";
	}
	**/
	Game warTournament = Game(players);
	warTournament.play();
	
}

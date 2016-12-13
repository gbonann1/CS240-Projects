#include <iostream>
#include <stdlib.h>
#include "Game.h"
#include "Player.h"
#include "Deck.h"
#include "PlayingCard.h"
#include <fstream>

using namespace std;

Game::Game(){
	
}

Game::Game(deque<Player>& p){
	deque<Player> temp;
	Player tempPlayer;
	for (int i = 0; i < p.size(); i++){
		tempPlayer = p[i]; 
		temp.push_front(tempPlayer);
		//cout << tempPlayer.getName();
	}
	playerList = temp;
}

Game::~Game(){
}

deque<Player> Game::getPlayerList(){
	return playerList;
}

void Game::play(){
	ofstream myfile;
	myfile.open("LogFile.txt");
	//int totalBattles = 0;
	//int rounds = playerList.size() - 1;
	if (this->playerList.size() == 1){
		//float avgBattles = totalBattles / rounds;
		cout << playerList[0].getName();
		cout << " has won the tournament!" << endl;
		//cout << "Largest number of battles: ";
		//cout << maxBattles << endl;
		//cout << "Average number of battles: ";
		//cout << avgBattles;
	}
	else {
		deque<Player> smallerTourny;
		for (int i = 0; i < playerList.size(); i+=2){
			deque<PlayingCard> player1 = playerList[i].getDeck().getDeque();
			deque<PlayingCard> player2 = playerList[i+1].getDeck().getDeque();
			string p1 = playerList[i].getName();
			string p2 = playerList[i+1].getName();
			myfile << p1;
			myfile << " vs. ";
			myfile << p2 << endl;
			int battles = 1;
			int wars = 0;
			int warState = 0;
			int warSize = 4;
			bool battleLimit = false;
			int winner;
			while ((player1.empty() == true || player2.empty() == true || battleLimit == true) == false){
				if (battles == 10000){
					battleLimit = true;
				}
				if (player1[0] == player2[0]){
					myfile << "\tBattle ";
					myfile << battles;
					myfile << ": ";
					myfile << p1;
					myfile << " ";
					myfile << player1[0];
					myfile << " tied ";
					myfile << p2;
					myfile << " ";
					myfile << player2[0] << endl;
					wars++;
					myfile << "\tWar ";
					myfile << wars;
					myfile << ":";
					battles++;
					if (player1.size() < warSize*warState) {
						cout << "Not enough cards" << endl;
						player1.clear();
						warState = 0;
					}
					else if (player2.size() < warSize*warState) {
						cout << "Not enough cards" << endl;
						player2.clear();
						warState = 0;
					}
					else{
						warState = 1;
					}
					while (warState > 0){
						if (player1[warSize*warState] > player2[warSize*warState]){
							for (int i = 0; i <= warSize*warState; i++){
						
								myfile << " ";
								myfile << p1;
								myfile << " ";
								myfile << player1[warSize*warState];
								myfile << " defeated ";
								myfile << p2;
								myfile << " ";
								myfile << player2[warSize*warState];
								player1.push_back(player1[0]);
								player1.push_back(player2[0]);
								player1.pop_front();
								player2.pop_front();
								myfile << ": ";
								myfile << p1;
								myfile << " ";
								myfile << player1.size();
								myfile << ", ";
								myfile << p2;
								myfile << " ";
								myfile << player2.size() << endl;
								warState--;
							}
						}	
						else if(player2[warSize*warState] > player1[warSize*warState]){
							for (int i = 0; i <= warSize*warState; i++){
		
								myfile << p2;
								myfile << " ";
								myfile << player2[warSize*warState];
								myfile << " defeated ";
								myfile << p1;
								myfile << " ";
								myfile << player1[warSize*warState];
								player2.push_back(player2[0]);
								player2.push_back(player1[0]);
								player1.pop_front();
								player2.pop_front();
								myfile << ": ";
								myfile << p1;
								myfile << " ";
								myfile << player1.size();
								myfile << ", ";
								myfile << p2;
								myfile << " ";
								myfile << player2.size() << endl;
								warState--;
							}
						}
						else if (player2[warSize*warState] == player1[warSize*warState]){
							myfile << "\tWar ";
							myfile << wars;
							myfile << ": ";
							myfile << p1;
							myfile << " ";
							myfile << player1[warSize*warState];
							myfile << " tied ";
							myfile << p2;
							myfile << " ";
							myfile << player2[warSize*warState] << endl;
							warState++;
							wars++;
							myfile << "\tWar ";
							myfile << wars;
							myfile << ": ";
						}	
					}
				}
				else if (player1[0] > player2[0]){
					myfile << "\tBattle ";
					myfile << battles;
					myfile << ": ";
					myfile << p1;
					myfile << " ";
					myfile << player1[0];
					myfile << " defeated ";
					myfile << p2;
					myfile << " ";
					myfile << player2[0];
					player1.push_back(player1[0]);
					player1.push_back(player2[0]);
					player1.pop_front();
					player2.pop_front();
					myfile << ": ";
					myfile << p1;
					myfile << " ";
					myfile << player1.size();
					myfile << ", ";
					myfile << p2;
					myfile << " ";
					myfile << player2.size() << endl;
					battles++;
					//cout << player1[0];
					//cout << player2[0];
				}
				else if (player2[0] > player1[0]){
					myfile << "\tBattle ";
					myfile << battles;
					myfile << ": ";
					myfile << p2;
					myfile << " ";
					myfile << player2[0];
					myfile << " defeated ";
					myfile << p1;
					myfile << " ";
					myfile << player1[0];
					player2.push_back(player2[0]);
					player2.push_back(player1[0]);
					player1.pop_front();
					player2.pop_front();
					myfile << ": ";
					myfile << p1;
					myfile << " ";
					myfile << player1.size();
					myfile << ", ";
					myfile << p2;
					myfile << " ";
					myfile << player2.size() << endl;
					battles++;
					//cout << player1[0];
					//cout << player2[0];
				}
			}
			if (player1.empty() == true){
				myfile << p2;
				myfile << " has won in ";
				myfile << battles;
				myfile << " battles and ";
				myfile << wars;
				myfile << " wars!" << endl;
				winner = 2;
				/**totalBattles += battles;
				if (battles > maxBattles){
					maxBattles = battles;
				}
				**/
			}
			else if (player2.empty() == true){
				myfile << p1;
				myfile << " has won in ";
				myfile << battles;
				myfile << " battles and ";
				myfile << wars;
				myfile << " wars!" << endl;
				winner = 1;
				/**totalBattles += battles;
				if (battles > maxBattles){
					maxBattles = battles;
				}
				**/	
			}
			else {
				if (player1.size() > player2.size()){
					myfile << p1;
					myfile << " has won with more cards in ";
					myfile << battles;
					myfile << " battles and ";
					myfile << wars;
					myfile << " wars!" << endl;
					winner = 1;
					/**totalBattles += battles;
					if (battles > maxBattles){
						maxBattles = battles;
					}
					**/
				}
				else if (player2.size() > player1.size()){
					myfile << p2;
					myfile << " has won with more cards in ";
					myfile << battles;
					myfile << " battles and ";
					myfile << wars;
					myfile << " wars!" << endl;
					winner = 2;
					/**totalBattles += battles;
					if (battles > maxBattles){
						maxBattles = battles;
					}
					**/
				}
				else {
					winner = 1;
					/**totalBattles += battles;
					if (battles > maxBattles){
						maxBattles = battles;
					}
					**/
				}
			}
			if (winner == 1){ //change condition	
				smallerTourny.push_front(playerList[i]);
			}
			else if (winner == 2){		
				smallerTourny.push_front(playerList[i+1]);				
			}
		}
		Deck cardDeck;
		cardDeck.fullDeck();
		Deck p1Deck;
		Deck p2Deck;
		for (int i = 0; i < smallerTourny.size(); i+=2) {
			cardDeck.shuffle();
			for (int j = 0; j < 52; j+=2){
				p1Deck.add(cardDeck.getDeque()[j]);
				p2Deck.add(cardDeck.getDeque()[j+1]);
			}
			smallerTourny[i].changeDeck(p1Deck);
			smallerTourny[i+1].changeDeck(p2Deck);
		}
		
		Game smaller = Game(smallerTourny);
		smaller.play();
		myfile.close();
	}		
}

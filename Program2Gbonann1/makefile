all: Main

Main: Main.o PlayingCard.o Deck.o Player.o Game.o
	g++ Main.o PlayingCard.o Deck.o Player.o Game.o -o Main

Main.o: Main.cpp PlayingCard.h Deck.h Player.h Game.h
	g++ -c Main.cpp -o Main.o
 
PlayingCard.o:PlayingCard.cpp 
	g++ -c PlayingCard.cpp -o PlayingCard.o

Deck.o:Deck.cpp 
	g++ -c Deck.cpp -o Deck.o

Player.o:Player.cpp 
	g++ -c Player.cpp -o Player.o

Game.o:Game.cpp 
	g++ -c Game.cpp -o Game.o

clean:
	rm -f *.o Main

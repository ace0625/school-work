//CS202
//Assignment#1
//4/23/2015
//Hyunchan Kim

// ---> main.cpp
//Main function for go fish game program

#include "gofish.h"

int main()
{
	Game goFish = Game(); //set up the go fish game
	Deck ocean = Deck(); //set the deck

	ocean.cards.resize(52); // set 52 cars
	ocean.initializeDeck(&ocean); //initailizes players and cards
	ocean.shuffle(&ocean); //shuffles the cards

	int a = goFish.getPlayers(); //get number of players will be playing
	goFish.p.resize(a); //set the players to start
	
	for (int i = 0; i < a; i++)
		goFish.p.at(i).number = i + 1;
	
	int players = goFish.getP(); //get the player
	goFish.setP(a); //set the player
	goFish.deal(&goFish.p, &ocean); //deal the cards
	goFish.playGame(&goFish, &goFish.p, &ocean); //game start

	return 0;
}


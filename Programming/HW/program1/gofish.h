//CS202
//Assignment#1
//4/23/2015
//Hyunchan Kim

// ---> gofish.h
//Interface file for Go fish program

#include<string>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<vector>
#include<time.h>
#include<stdlib.h>

using namespace std;

//Data structure for card
struct Card
{
	int number;
	string suit; //suit(hearts, spades, clubs, diamons)
};
//Class for deck that mananges cards before starting game.
class Deck 
{
	public:
		Deck();
		~Deck();
		void initializeDeck(Deck * deck);
		void shuffle(Deck * deck);
		Card getTopCard(vector<Card>*);
		vector<Card> cards;
		int cards_in_play;
		vector<Card> discard;
};

//Class for player that manages players
class Player:public Deck
{
	public:
		Player(); //player constructor
		~Player(); //player destructor
		vector<Card> hand; //hand function
		Card goFish(); //go fish function
		Card discard(); //discards a card
		Card getCard(Deck); //receive a card
		int askedplayer(int valid, int i, int players); //ask for a player to get a card from
		int askedcard(int valid); //ask for a card you are looking for
		int errorCheck(int); //check if there's an error
		int number; //player number
};

//Class for game that manages game functions when playing.
class Game:public Player
{
	public:
		Game(); //game default constructor
		~Game(); //game default destructor
		vector <Player> p; //vector function to manage players
		int ask(Player *, Player *, int); //ask for a card to a particular player you choose
		void playGame(Game *, vector<Player>*, Deck *); //Game start
		void deal(vector<Player>*, Deck*); 
		char win; // win
		int getP(); // get player function
		void setP(int); //set player function

	int getPlayers(); //select how many players will be playing
	void printHand(Player); //shows the card in player's hand
	void checkForSet(Player *, Deck *); //verify if there is a book
	void checkForWin(Player *); //check if anyone wins
private:
	int players; //number of players
};

	

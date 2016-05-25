//CS202
//Assignment#1
//4/23/2015
//Hyunchan Kim

// ---> gofish.cpp
#include "gofish.h"
using namespace std;

//Deck constructor
Deck::Deck()
{
	cards_in_play = 0;
}
//Deck destructor
Deck::~Deck()
{
	cards_in_play = 0;
}
//Player constructor
Player::Player()
{
	number = 0;
}
//Player desctuctor
Player::~Player()
{
	number = 0;
}
//Game constructor Initializes instance of Game
Game::Game()
{
	players = 0;
}
//Game desctructor 
Game::~Game()
{
	players = 0;
}



//This function prints the cards on player's hand
void Game::printHand(Player p)
{
	cout << endl;
	cout << "Player " << p.number << ", here's your hand:" << endl;
	for (int i = 0; i<p.hand.size(); i++)
		cout << p.hand.at(i).number << " of " << p.hand.at(i).suit  << endl;
	cout << endl;
}
// function that gets how many player will be playing
int Game::getPlayers()
{
	int players, valid = 0;
	cout << "How many players will be playing?  ";
	while (valid == 0)
	{
		cin >> players;
		valid = errorCheck(players);
		if (valid == 0 || players < 2 || players > 6)
		{
			cout << "Sorry! You did not enter a number between 2 and 6.  Please try again. ";
			valid = 0;
		}
	}
	return players;
}

//Get player function
int Game::getP()
{
	return this->players;
}
//Set player fuction
void Game::setP(int players){
	this->players = players;
}


//This function initializes the deck before starting the game
void Deck::initializeDeck(Deck *deck)
{
	deck->cards_in_play = 52;
	string suitstring;
	int i = 0;
	for (int suit = 1; suit <= 4; suit++)
	{
		if (suit == 1) //heart shape 
			suitstring = "hearts";
		else if (suit == 2) //spade shape
			suitstring = "spades";
		else if (suit == 3) //diamonds shape
			suitstring = "diamonds";
		else            //club shape
			suitstring = "clubs"; 
		for (int card = 1; card <= 13; card++)
		{
			deck->cards.at(i).suit = suitstring;
			deck->cards.at(i).number = card;
			i++;
		}
	}
}

//This function implements shuffling the cards on the deck
void Deck::shuffle(Deck *deck){
	//int i, j, a;
	Card temp;
	srand(time(NULL)); //random number
	int a = deck->cards_in_play; //num of players
	for (int b = 0; b<4; b++) // 4 kinds of shapes
	{
		for (int i = 0; i<a; i++) //a players
		{
			int j = rand() % a;
			temp = deck->cards.at(i);
			deck->cards.at(i) = deck->cards.at(j);
			deck->cards.at(j) = temp;
		}
	}
}

//This function implements that player can get the top card using vector function.
Card Deck::getTopCard(vector<Card> *cards)
{
	Card a = cards->at(0);
	cards->erase(cards->begin());
	if (cards->size() == 0)
	{
		cout << "You're out of cards!  Game over!" << endl;
		exit(1);
	}
	return a;
}

//This function deals cards to the players
void Game::deal(vector<Player> *p, Deck * deck)
{
	Card a;
	for (int i = 0; i<p->size(); i++)
	{
		for (int j = 0; j<7; j++)
		{
			a = deck->getTopCard(&deck->cards); //get the top cards
			p->at(i).hand.push_back(a);  //move the card to the player's hand
		}
	}
}
//This function shows which player has been choosen from another player
int Player::askedplayer(int valid, int i, int players)
{
	int pBeingAsked;
	while (valid == 0)
	{
		cin >> pBeingAsked;
		valid = errorCheck(pBeingAsked);
		if (pBeingAsked <= 0 || pBeingAsked>players || pBeingAsked == i + 1)
		{
			valid = 0;
			cout << "You didn't enter a valid player!  Please enter a number between 1 and the number of players playing." << endl;
		}
	}
	return pBeingAsked;
}
//This function returns the card the player asks for
int Player::askedcard(int valid)
{
	int cardAskedFor;
	while (valid == 0){
		cin >> cardAskedFor;
		valid = errorCheck(cardAskedFor);
		if (cardAskedFor<1 || cardAskedFor>13){
			valid = 0;
			cout << "You didn't enter a valid card number!  Please enter a number between 1 and 13. " << endl;
		}
	}
	return cardAskedFor;
}
//Game start with the selected players and begin to ask for a card
void Game::playGame(Game *goFish, vector<Player> *p, Deck *ocean)
{
	int pBeingAsked, cardAskedFor, cardsBack;
	while (true)
	{
		int i = 0;
		for (i = 0; i<goFish->players; i++)
		{
			printHand(p->at(i));
			cout << "Player " << i + 1 << ", which player would you like to ask for their cards?  ";
			pBeingAsked = askedplayer(0, i, goFish->players);
			cout << "Player " << i + 1 << ", what number do you want to ask for?  ";
			cardAskedFor = askedcard(0);
			cardsBack = ask(&p->at(i), &p->at(pBeingAsked - 1), cardAskedFor);
			if (cardsBack == 0)
				p->at(i).hand.push_back(ocean->getTopCard(&ocean->cards));
			
			checkForSet(&p->at(i), ocean);
			checkForWin(&p->at(i));
		}
	}
}

//This function verifies the players cards if it's a book(same number with four different shapes)
void Game::checkForSet(Player *p, Deck *ocean)
{
	int count = 0;
	for (int j = 0; j <= 13; j++)
	{
		count = 0;
		for (int i = 0; i<p->hand.size(); i++)
		{
			if (p->hand.at(i).number == j)
			{
				count++;
			}
			if (count == 4) 
			{
				for (int k = 0; k<p->hand.size(); k++)
				{
					if (p->hand.at(k).number == j)
					{
						ocean->discard.push_back(p->hand.at(k));
						p->hand.erase(p->hand.begin() + k);
						k--;
						i--;
					}
				}
				cout << "You got a set!  Congratulations!" << endl;
			}
		}
	}
}
//ask for a card from a particular player. If there is, you get the card otherwise you get a card from the deck
int Game::ask(Player *asking, Player *beingAsked, int cardAskedFor)
{
	int num = 0;
	for (int i = 0; i<beingAsked->hand.size(); i++)
	{
		if (beingAsked->hand.at(i).number == cardAskedFor)
		{
			asking->hand.push_back(beingAsked->hand.at(i));
			beingAsked->hand.erase(beingAsked->hand.begin() + i);
			i--;
			num++;
		}
	}
	cout << "Player " << beingAsked->number << " had " << num << " " << cardAskedFor << "'s." << endl << endl;
	return num;
}

//This function checks players cards if the player wins 
void Game::checkForWin(Player * player)
{
	if (player->hand.size() == 0) //if there's no card in the hand
	{
		cout << "Player " << player->number << " wins!!  Congratulations!" << endl;
		exit(1);
	}
}
//checking if there's an error or invalid status
int Player::errorCheck(int a)
{
	int valid = 1;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		valid = 0;
	}
	return valid;
}
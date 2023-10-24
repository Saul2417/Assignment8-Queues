#pragma once
#include <queue>
#include "CardDeck.h"
using namespace std;

class WarGame
{
private:
	queue <CardDeck> p1Cards;
	queue <CardDeck> p2Cards;
	queue <CardDeck> warCards;
	int numCardsPerSuite;
	vector <CardDeck> deck;

public:
	WarGame();
	WarGame(int newNumCardsPerSuite);
	void fillDeck();
	void randomizeDeck();
	void distributeCards();
	void playGame();
};


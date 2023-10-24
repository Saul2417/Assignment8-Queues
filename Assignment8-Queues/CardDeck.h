#pragma once
#include <string>
using namespace std;

class CardDeck
{
private:	
	string suit; //Card Suit (Spade, Clover, Heart, Diamond)
	int value; // Card Value (1	to 13)


public:
	CardDeck(); // Initializer	
	void setCardSuit(string newSuit);
	void setCardValue(int newCardValue);
	string getCardSuit() const; 
	int getCardValue() const; 
	~CardDeck() {}//Destructor
};


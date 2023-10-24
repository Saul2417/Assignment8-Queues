#include "CardDeck.h"

CardDeck::CardDeck()
{
	suit = " ";
	value = 0;
}

void CardDeck::setCardSuit(string newSuit)
{
	suit = newSuit;
}

void CardDeck::setCardValue(int newCardValue)
{
	value = newCardValue;
}

string CardDeck::getCardSuit() const
{
	return suit;
}
int CardDeck::getCardValue() const
{
	return value;
}
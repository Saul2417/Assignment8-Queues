#include <queue>
#include <algorithm>
#include <random>
#include "input.h"
#include "WarGame.h"

WarGame::WarGame()
{
	numCardsPerSuite = 1;
	fillDeck();
}

WarGame::WarGame(int newNumCardsPerSuite)
{
	numCardsPerSuite = newNumCardsPerSuite;
	fillDeck();
}
void WarGame::fillDeck()
{
	for (int index = 0; index < numCardsPerSuite; index++)
	{
		CardDeck newCard;
		newCard.setCardValue(index + 1);
		newCard.setCardSuit("Spade");
		deck.push_back(newCard);
		newCard.setCardSuit("Club");
		deck.push_back(newCard);
		newCard.setCardSuit("Diamonds");
		deck.push_back(newCard);
		newCard.setCardSuit("Hearts");
		deck.push_back(newCard);
	}
	randomizeDeck();
}

void WarGame::randomizeDeck()
{
	shuffle(deck.begin(), deck.end(), std::random_device());
	distributeCards();
}

void WarGame::distributeCards()
{
	while (!deck.empty())
	{
		p1Cards.push(deck.back());
		deck.pop_back();
		p2Cards.push(deck.back());
		deck.pop_back();
	}
}

void WarGame::playGame()
{
	do
	{
		CardDeck p1CompareCard = p1Cards.front();
		CardDeck p2CompareCard = p2Cards.front();
		p1Cards.pop();
		p2Cards.pop();
		cout << "Player1: " << p1CompareCard.getCardValue() << "   Player2: " << p2CompareCard.getCardValue();
		if (p1CompareCard.getCardValue() > p2CompareCard.getCardValue())
		{
			p1Cards.push(p1CompareCard);
			p1Cards.push(p2CompareCard);
			cout << " -> Player1 wins!" << endl << endl;
		}
		else if (p1CompareCard.getCardValue() < p2CompareCard.getCardValue())
		{
			p2Cards.push(p2CompareCard);
			p2Cards.push(p1CompareCard);
			cout << " -> Player2 wins!" << endl << endl;
		}
		else
		{
			cout << " -> Tie-Breaker Begins!" << endl << endl;
			warCards.push(p1CompareCard);
			warCards.push(p2CompareCard);
			while (p1CompareCard.getCardValue() == p2CompareCard.getCardValue())
			{
				for (int index = 0; index < 4; index++)
				{
					if (!p1Cards.empty() && !p2Cards.empty())
					{
						
						p1CompareCard = p1Cards.front();
						p2CompareCard = p2Cards.front();
						warCards.push(p1CompareCard);
						warCards.push(p2CompareCard);
						p1Cards.pop();
						p2Cards.pop();
					}
					else if (p1Cards.empty())
					{
						cout << " Player 1 Has Insufficient Cards For War. Player 2 Wins" << endl << endl;
						return;
					}
					else if (p2Cards.empty())
					{
						cout << " Player 2 Has Insufficient Cards For War. Player 1 Wins" << endl << endl;
						return;
					}
				}

				cout << "Player1: " << p1CompareCard.getCardValue() << "   Player2: " << p2CompareCard.getCardValue();
				if (p1CompareCard.getCardValue() > p2CompareCard.getCardValue())
				{
					while (!warCards.empty())
					{
						p1Cards.push(warCards.front());
						warCards.pop();
					}
					cout << " -> Player1 wins!" << endl << endl;
				}
				else if (p1CompareCard.getCardValue() < p2CompareCard.getCardValue())
				{
					while (!warCards.empty())
					{
						p2Cards.push(warCards.front());
						warCards.pop();
					}
					cout << " -> Player2 wins!" << endl << endl;
				}
				else
				{
					cout << " -> Tie breaker again!" << endl << endl;
				}
			}
									
		}
		system("pause");
	} while (!p1Cards.empty() && !p2Cards.empty());

	if (p1Cards.empty())
	{
		cout << "Player 1 wins the war with most number of cards(" << (numCardsPerSuite * 4) << ")." << endl;
	}
	else
	{
		cout << "Player 2 wins the war with most number of cards(" << (numCardsPerSuite * 4) << ")." << endl;
	}
}

void warGameMenu()
{
	WarGame game1(inputInteger("Enter a number of cards per suite: ", 1, 13));
	game1.playGame();
}


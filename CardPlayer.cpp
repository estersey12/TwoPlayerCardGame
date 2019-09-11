//Emmanuelle Esters
//Lab6in
//2 Player Card game

#include <iostream>
#include "graph1.h"
#include "CardPlayer.h"

CardPlayer::CardPlayer()
{
	//Implement the default Constructor
	this -> color = 'r';
	this -> noCards = 0;
	this -> hand = NULL;
}

CardPlayer::~CardPlayer()
{
	delete[] hand;
}

void CardPlayer::setNoCards(int noCards)
{
	if (noCards < 5)
	{
		this->noCards = 5;
	}
	else if (noCards > 10)
	{
		this->noCards = 10;
	}
	else
	{
		this->noCards = noCards;
	}
	hand = new int[this->noCards];
}

int CardPlayer::getNoCards()
{
	return noCards;
}

void CardPlayer::setColor(char color)
{
	this->color = color;
}

void CardPlayer::displayHand(int x, int y)
{
	int i = 0;
	char fn;

	for (i = 0; i < noCards; i++)
	{
		if (color == 'r')
		{
			fn = 'd';
		}
		else
		{
			fn = 'c';
		}

		displayBMP(fn + to_string(hand[i]) + ".bmp", x, (y + 20 * i));
	}

}

int CardPlayer::computeScore()
{
	int i = 0;
	int num = 0;
	int score = 0;

	for (i = 0; i < hand[i]; i++)
	{
		if (hand[i] == 14)
		{
			num = 11;
		}
		else if (hand[i] == 10 || hand[i] == 11 || hand[i] == 13)
		{
			num = 10;
		}
		else
		{
			num = hand[i];
		}

		score += num;
	}
	
	return score;
}

//Implemented for you
void CardPlayer::deal()
{
	bool duplicate = false;


	for (int i = 0; i < noCards; i++)
	{
		hand[i] = rand() % 13 + 2;

		do
		{
			duplicate = false;
			for (int j = 0; j < i; j++)
			{
				if (hand[i] == hand[j])
				{
					hand[i] = rand() % 13 + 2;
					duplicate = true;
					break;
				}
			}
		} while (duplicate);
	}

}

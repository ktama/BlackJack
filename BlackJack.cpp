// BlackJack.cpp : ブラックジャックゲーム（のスパイク）
// 各関数はC言語（ライクかも）に記述
// デバッグ目的で書くmain()はC++で記述

#include "stdafx.h"

#include <iostream>

#include "Suit.h"
#include "Displayed.h"
#include "Deck.h"
#include "Game.h"

using namespace std;

void DisplayedTest();
void DeckTest();

int _tmain(int argc, _TCHAR* argv[])
{
	Game game;
	GameResult result;
	game.StartGame(&result);
	//DisplayAllCard();
	//DeckTest();
	cout << result << endl;
	int i;
	cin >> i;
	return 0;
}

void DisplayedTest()
{
	Displayed displayed;
	char out[11];
	for (size_t i = Suit::CLUB; i <= Suit::SPADE; i++)
	{
		for (size_t j = 0; j < 13; j++)
		{
			Suit suit = static_cast<Suit>(i);
			int result = displayed.GetDisplayedCard(suit, j, out);
			if (result != 0)
			{
				cout << "error" << endl;
			}
			else
			{
				cout << out << endl;
			}
		}
	}
	for (size_t i = 0; i < 52; i++)
	{
		int result = displayed.GetDisplayedCard(i, out);
		if (result != 0)
		{
			cout << "error" << endl;
		}
		else
		{
			cout << out << endl;
		}
	}
}

void DeckTest()
{
	Deck* deck = new Deck();
	cout << "Sorted Deck" << endl;
	deck->DisplayDeck();
	cout << "Shuffle Deck" << endl;
	deck->Shuffle();
	cout << "Shuffled Deck" << endl;
	deck->DisplayDeck();
	cout << "Draw Deck" << endl;
	for (size_t i = 0; i < 52; i++)
	{
		unsigned int out;
		int result = deck->Draw(&out);
		if (result != 0)
		{
			cout << "error" << endl;
		}
		else
		{
			cout << out << endl;
		}
	}
	delete deck;
}


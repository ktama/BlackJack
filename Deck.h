#pragma once

#include <stdlib.h>

#include "Displayed.h"

class Deck
{
public:
	Deck();
	~Deck();

	// 山札の中身をすべて表示する（引いたものを含む）
	void DisplayDeck();
	// 山札の中身をすべてシャッフルする（引いたものを含む）
	void Shuffle();
	// 山札の頭からカードを引く
	int Draw(unsigned int* const);

private:
	static const int CARD_MAX;
	static const int SHUFFLE_COUNT;
	unsigned int deck[52];
	unsigned int deckTop;

	void InitDeck();
};

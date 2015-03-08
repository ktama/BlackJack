#pragma once

#include <stdlib.h>

#include "Displayed.h"

class Deck
{
public:
	Deck();
	~Deck();

	// �R�D�̒��g�����ׂĕ\������i���������̂��܂ށj
	void DisplayDeck();
	// �R�D�̒��g�����ׂăV���b�t������i���������̂��܂ށj
	void Shuffle();
	// �R�D�̓�����J�[�h������
	int Draw(unsigned int* const);

private:
	static const int CARD_MAX;
	static const int SHUFFLE_COUNT;
	unsigned int deck[52];
	unsigned int deckTop;

	void InitDeck();
};

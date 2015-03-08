#pragma once

#include "Deck.h"

class Hand
{
public:
	Hand();
	~Hand();

	int GetPoint();
	int Deal(const int, const int);
	int Stand();
	int Hit(const int, bool* const);

private:
	static const int CARD_MAX;
	static const int NUMBER_MAX;

	// ��D�̍ő�l��12���i12���ڂŕK���o�[�X�g�j
	// �ŏ��l�̑g�ݍ��킹11����21�iA*4 + 2*4 + 3*3 = 21�j
	unsigned int hand[12];
	unsigned int handCount;
	unsigned int handPoint;

	int CalcPoint();
	int GetPoint(const unsigned int, unsigned int* const);
};

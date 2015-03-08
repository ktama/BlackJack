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

	// 手札の最大値は12枚（12枚目で必ずバースト）
	// 最小値の組み合わせ11枚で21（A*4 + 2*4 + 3*3 = 21）
	unsigned int hand[12];
	unsigned int handCount;
	unsigned int handPoint;

	int CalcPoint();
	int GetPoint(const unsigned int, unsigned int* const);
};

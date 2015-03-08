#pragma once

#include <string.h>

#include "Suit.h"

class Displayed
{
public:
	Displayed();
	~Displayed();

	// カード表示文字列取得関数（スートと数字）
	int GetDisplayedCard(const Suit, const unsigned int, char[]);
	// カード表示文字列取得関数（数字のみ）
	// スートと数字に変換後、
	// int GetDisplayedCard(const Suit, const unsigned int, char[])を呼び出す
	int GetDisplayedCard(const unsigned int, char[]);

private:
	static const int SUIT_MAX;
	static const int NUMBER_MAX;
	static const int CARD_MAX;
	static const int DISPLAY_CARD_LENGTH;
};

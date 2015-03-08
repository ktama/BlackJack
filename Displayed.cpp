#include "stdafx.h"
#include "Displayed.h"

const int Displayed::SUIT_MAX = 4;
const int Displayed::NUMBER_MAX = 13;
const int Displayed::CARD_MAX = 52;
const int Displayed::DISPLAY_CARD_LENGTH = 10;

Displayed::Displayed()
{
}

Displayed::~Displayed()
{
}

int Displayed::GetDisplayedCard(const Suit suit, const unsigned int number, char out[])
{
	// 変数の宣言（各文字列で初期化）
	errno_t errorNumber = 0;
	char* selectedSuit[SUIT_MAX] =
	{
		"Club    ",
		"Diamond ",
		"Heart   ",
		"Spade   "
	};
	char* selectedNumber[NUMBER_MAX] =
	{
		" A", " 2", " 3", " 4",
		" 5", " 6", " 7", " 8",
		" 9", "10", " J", " Q", " K"
	};
	char buffer[DISPLAY_CARD_LENGTH + 1];

	// 入力チェック
	{
		size_t outSize = 0;
		// suitの入力範囲チェック
		if (suit < 0 || (SUIT_MAX - 1) < suit)
		{
			return -1;
		}
		// numberの入力範囲チェック
		if (number < 0 || (NUMBER_MAX - 1) < number)
		{
			return -1;
		}
		// out[]のヌルチェック
		if (out == NULL)
		{
			return -1;
		}
		// out[]のサイズチェック
		// 表示する文字列領域より小さい場合エラー
		outSize = strnlen_s(out, DISPLAY_CARD_LENGTH + 1);
		if (DISPLAY_CARD_LENGTH > outSize)
		{
			return -1;
		}
	}
	// スートと数字を結合してbufferに格納
	{
		errorNumber = strcpy_s(buffer, DISPLAY_CARD_LENGTH, selectedSuit[suit]);
		if (errorNumber != 0)
		{
			return -1;
		}
		// ヌル文字分を加える
		errorNumber = strcat_s(buffer, DISPLAY_CARD_LENGTH + 1, selectedNumber[number]);
		if (errorNumber != 0)
		{
			return -1;
		}
	}
	// スートと数字の結合に成功している場合はoutへ代入
	{
		errorNumber = strcpy_s(out, DISPLAY_CARD_LENGTH + 1, buffer);
		if (errorNumber != 0)
		{
			return -1;
		}
	}
	return 0;
}

int Displayed::GetDisplayedCard(const unsigned int suitNumber, char out[])
{
	// 入力チェック
	{
		// numberの入力範囲チェック
		if (suitNumber < 0 || (CARD_MAX - 1) < suitNumber)
		{
			return -1;
		}
	}
	// スートと数字に変換後、
	// int GetDisplayedCard(const Suit, const unsigned int, char[])を呼び出す
	{
		// スートの並びは	CLUB, DIAMOND, HEART, SPADEとし、0からの連番と定義
		Suit suit = static_cast<Suit>(suitNumber / 13);
		unsigned int number = suitNumber % 13;
		int result = GetDisplayedCard(suit, number, out);
		if (result != 0)
		{
			return -1;
		}
	}
	return 0;
}

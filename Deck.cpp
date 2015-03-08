#include "stdafx.h"
#include "Deck.h"

const int Deck::CARD_MAX = 52;
const int Deck::SHUFFLE_COUNT = 10000;

Deck::Deck()
	:deck(),
	deckTop(0)
{
	InitDeck();
}

Deck::~Deck()
{
}

void Deck::DisplayDeck()
{
	// デッキの中身を表示する
	for (size_t i = 0; i < CARD_MAX; i++)
	{
		Displayed displayed;
		char out[11];
		int number = deck[i];
		int result = displayed.GetDisplayedCard(number, out);
		if (result != 0)
		{
			printf_s("Error\n");
		}
		printf_s("%s\n", out);
	}
}

void Deck::Shuffle()
{
	InitDeck();
	// シャッフルする
	for (size_t i = 0; i < SHUFFLE_COUNT; i++)
	{
		unsigned int x = 0, y = 0, tmp = 0;
		x = rand() % CARD_MAX;
		y = rand() % CARD_MAX;
		// 同じインデックスなら異なるインデックスまで繰り返す
		while (x == y)
		{
			y = rand() % CARD_MAX;
		}
		tmp = deck[x];
		deck[x] = deck[y];
		deck[y] = tmp;
	}
}

int Deck::Draw(unsigned int* const number)
{
	// 入力チェック
	if (number == NULL)
	{
		return -1;
	}

	// 山札がなければエラー
	if (deckTop > (CARD_MAX - 1))
	{
		return -1;
	}
	else
	{
		// 山札から引いて、山札を進める
		*number = deck[deckTop];
		deckTop++;
	}
	return 0;
}

void Deck::InitDeck()
{
	// 連番で値を代入する
	for (size_t i = 0; i < CARD_MAX; i++)
	{
		deck[i] = i;
	}
	// インデックスを山札の頭に戻す
	deckTop = 0;
}

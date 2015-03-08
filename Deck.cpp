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
	// �f�b�L�̒��g��\������
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
	// �V���b�t������
	for (size_t i = 0; i < SHUFFLE_COUNT; i++)
	{
		unsigned int x = 0, y = 0, tmp = 0;
		x = rand() % CARD_MAX;
		y = rand() % CARD_MAX;
		// �����C���f�b�N�X�Ȃ�قȂ�C���f�b�N�X�܂ŌJ��Ԃ�
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
	// ���̓`�F�b�N
	if (number == NULL)
	{
		return -1;
	}

	// �R�D���Ȃ���΃G���[
	if (deckTop > (CARD_MAX - 1))
	{
		return -1;
	}
	else
	{
		// �R�D��������āA�R�D��i�߂�
		*number = deck[deckTop];
		deckTop++;
	}
	return 0;
}

void Deck::InitDeck()
{
	// �A�ԂŒl��������
	for (size_t i = 0; i < CARD_MAX; i++)
	{
		deck[i] = i;
	}
	// �C���f�b�N�X���R�D�̓��ɖ߂�
	deckTop = 0;
}

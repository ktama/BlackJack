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
	// �ϐ��̐錾�i�e������ŏ������j
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

	// ���̓`�F�b�N
	{
		size_t outSize = 0;
		// suit�̓��͔͈̓`�F�b�N
		if (suit < 0 || (SUIT_MAX - 1) < suit)
		{
			return -1;
		}
		// number�̓��͔͈̓`�F�b�N
		if (number < 0 || (NUMBER_MAX - 1) < number)
		{
			return -1;
		}
		// out[]�̃k���`�F�b�N
		if (out == NULL)
		{
			return -1;
		}
		// out[]�̃T�C�Y�`�F�b�N
		// �\�����镶����̈��菬�����ꍇ�G���[
		outSize = strnlen_s(out, DISPLAY_CARD_LENGTH + 1);
		if (DISPLAY_CARD_LENGTH > outSize)
		{
			return -1;
		}
	}
	// �X�[�g�Ɛ�������������buffer�Ɋi�[
	{
		errorNumber = strcpy_s(buffer, DISPLAY_CARD_LENGTH, selectedSuit[suit]);
		if (errorNumber != 0)
		{
			return -1;
		}
		// �k����������������
		errorNumber = strcat_s(buffer, DISPLAY_CARD_LENGTH + 1, selectedNumber[number]);
		if (errorNumber != 0)
		{
			return -1;
		}
	}
	// �X�[�g�Ɛ����̌����ɐ������Ă���ꍇ��out�֑��
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
	// ���̓`�F�b�N
	{
		// number�̓��͔͈̓`�F�b�N
		if (suitNumber < 0 || (CARD_MAX - 1) < suitNumber)
		{
			return -1;
		}
	}
	// �X�[�g�Ɛ����ɕϊ���A
	// int GetDisplayedCard(const Suit, const unsigned int, char[])���Ăяo��
	{
		// �X�[�g�̕��т�	CLUB, DIAMOND, HEART, SPADE�Ƃ��A0����̘A�Ԃƒ�`
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

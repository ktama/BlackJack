#pragma once

#include <string.h>

#include "Suit.h"

class Displayed
{
public:
	Displayed();
	~Displayed();

	// �J�[�h�\��������擾�֐��i�X�[�g�Ɛ����j
	int GetDisplayedCard(const Suit, const unsigned int, char[]);
	// �J�[�h�\��������擾�֐��i�����̂݁j
	// �X�[�g�Ɛ����ɕϊ���A
	// int GetDisplayedCard(const Suit, const unsigned int, char[])���Ăяo��
	int GetDisplayedCard(const unsigned int, char[]);

private:
	static const int SUIT_MAX;
	static const int NUMBER_MAX;
	static const int CARD_MAX;
	static const int DISPLAY_CARD_LENGTH;
};

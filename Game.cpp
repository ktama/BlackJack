#include "stdafx.h"
#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

int Game::StartGame(GameResult* const isPlayerWin)
{
	Deck deck;
	Hand player;
	Hand dealer;
	unsigned int playerPoint = 0, dealerPoint = 0;
	bool playerIsBurst = false, dealerIsBurst = false;
	int result = 0;

	// �f�B�[���̓f�b�L���V���b�t��
	{
		deck.Shuffle();
	}
	// 2�����z��
	{
		// �v���C���[
		result = Deal(&deck, &player);
		if (result != 0)
		{
			return -1;
		}
		// �f�B�[���[
		result = Deal(&deck, &dealer);
		if (result != 0)
		{
			return -1;
		}
	}
	// �v���C���[�̏���
	{
		result = PlayPlayer(&deck, &player, &playerPoint, &playerIsBurst);
		if (result != 0)
		{
			return -1;
		}
		// �o�[�X�g���Ă�����v���C���[�̕���
		if (playerIsBurst != false)
		{
			*isPlayerWin = GameResult::LOSE;
			return 0;
		}
	}
	// �f�B�[���[�̏���
	{
		result = PlayDealer(&deck, &dealer, &dealerPoint, &dealerIsBurst);
		if (result != 0)
		{
			return -1;
		}
		// �o�[�X�g���Ă�����f�B�[���[�̕���
		if (dealerIsBurst != false)
		{
			*isPlayerWin = GameResult::WIN;
			return 0;
		}
	}
	// �|�C���g�̔���
	{
		if (playerPoint > dealerPoint)
		{
			*isPlayerWin = GameResult::WIN;
		}
		else if (playerPoint < dealerPoint)
		{
			*isPlayerWin = GameResult::LOSE;
		}
		else
		{
			*isPlayerWin = GameResult::DRAW;
		}
	}
	return 0;
}

int Game::Deal(Deck* const deck, Hand* const hand)
{
	unsigned int draw1 = 0, draw2 = 0;
	int result = 0;
	// �R�D����2������
	result = deck->Draw(&draw1);
	if (result != 0)
	{
		return -1;
	}
	result = deck->Draw(&draw2);
	if (result != 0)
	{
		return -1;
	}

	// ��D�ɉ�����
	result = hand->Deal(draw1, draw2);
	if (result != 0)
	{
		return -1;
	}

	return 0;
}

int Game::PlayPlayer(Deck* const deck, Hand* const hand, unsigned int* const point, bool* const isBurst)
{
	int result = 0;
	Behavior behavior = Behavior::HIT;
	while (behavior != Behavior::STAND)
	{
		// ����
		result = SelectBehavior(&behavior);
		if (result != 0)
		{
			return -1;
		}
		if (behavior == Behavior::HIT)
		{
			// �q�b�g����
			unsigned int number;
			result = deck->Draw(&number);
			if (result != 0)
			{
				return -1;
			}
			hand->Hit(number, isBurst);
			*point = hand->GetPoint();
			// �o�[�X�g�Ȃ�I��
			if (*isBurst != false)
			{
				return 0;
			}
		}
	}
	return 0;
}

int Game::PlayDealer(Deck* const deck, Hand* const hand, unsigned int* const point, bool* const isBurst)
{
	int result = 0;

	while (*point < 17)
	{
		// �q�b�g����
		unsigned int number;
		result = deck->Draw(&number);
		if (result != 0)
		{
			return -1;
		}
		hand->Hit(number, isBurst);
		*point = hand->GetPoint();
		// �o�[�X�g�Ȃ�I��
		if (*isBurst != false)
		{
			return 0;
		}
	}
	return 0;
}

int Game::SelectBehavior(Behavior* const behavior)
{
	char buffer[1024];

	*behavior = Behavior::NOT_SELECTED;

	while (*behavior == Behavior::NOT_SELECTED)
	{
		bool isHit = false;
		bool isStand = false;
		int result = 0;
		gets_s(buffer, 1024);
		if (buffer == NULL)
		{
			return -1;
		}

		result = IsHit(buffer, &isHit);
		if (result != 0)
		{
			return -1;
		}
		if (isHit != false)
		{
			*behavior = Behavior::HIT;
		}
		result = IsStand(buffer, &isStand);
		if (result != 0)
		{
			return -1;
		}
		if (isStand != false)
		{
			*behavior = Behavior::STAND;
		}
	}
	return 0;
}

int Game::IsHit(const char* const buffer, bool* const isHit)
{
	int result = -1;
	*isHit = false;
	result = strcmp(buffer, "Hit");
	if (result == 0)
	{
		*isHit = true;
		return 0;
	}
	result = strcmp(buffer, "hit");
	if (result == 0)
	{
		*isHit = true;
		return 0;
	}
	result = strcmp(buffer, "HIT");
	if (result == 0)
	{
		*isHit = true;
		return 0;
	}
	result = strcmp(buffer, "H");
	if (result == 0)
	{
		*isHit = true;
		return 0;
	}
	result = strcmp(buffer, "h");
	if (result == 0)
	{
		*isHit = true;
		return 0;
	}
	return 0;
}

int Game::IsStand(const char* const buffer, bool* const isStand)
{
	int result = -1;
	*isStand = false;
	result = strcmp(buffer, "Stand");
	if (result == 0)
	{
		*isStand = true;
		return 0;
	}
	result = strcmp(buffer, "stand");
	if (result == 0)
	{
		*isStand = true;
		return 0;
	}
	result = strcmp(buffer, "STAND");
	if (result == 0)
	{
		*isStand = true;
		return 0;
	}
	result = strcmp(buffer, "S");
	if (result == 0)
	{
		*isStand = true;
		return 0;
	}
	result = strcmp(buffer, "s");
	if (result == 0)
	{
		*isStand = true;
		return 0;
	}
	return 0;
}


#include "stdafx.h"
#include "Hand.h"

const int Hand::CARD_MAX = 52;
const int Hand::NUMBER_MAX = 13;

Hand::Hand()
	:hand(),
	handCount(0),
	handPoint(0)
{
}

Hand::~Hand()
{
}

int Hand::GetPoint()
{
	return handPoint;
}

int Hand::Deal(const int drawNumber1, const int drawNumber2)
{
	// ���̓`�F�b�N
	{
		// number�̓��͔͈̓`�F�b�N
		if (drawNumber1 < 0 || (CARD_MAX - 1) < drawNumber1)
		{
			return -1;
		}
		if (drawNumber2 < 0 || (CARD_MAX - 1) < drawNumber2)
		{
			return -1;
		}
	}
	// ��D�ɉ�����
	{
		hand[handCount] = drawNumber1;
		handCount++;
		hand[handCount] = drawNumber2;
		handCount++;
	}
	// �|�C���g���v�Z
	{
		int result = CalcPoint();
		if (result != 0)
		{
			return -1;
		}
	}
	return 0;
}

int Hand::Stand()
{
	// �|�C���g���v�Z
	int result = CalcPoint();
	if (result != 0)
	{
		return -1;
	}
	return 0;
}

int Hand::Hit(const int drawNumber, bool* const isBurst)
{
	// ���̓`�F�b�N
	{
		// number�̓��͔͈̓`�F�b�N
		if (drawNumber < 0 || (CARD_MAX - 1) < drawNumber)
		{
			return -1;
		}
		if (isBurst == NULL)
		{
			return -1;
		}
	}
	// ��D�ɉ�����
	{
		hand[handCount] = drawNumber;
		handCount++;
	}
	// �|�C���g���v�Z
	{
		int result = CalcPoint();
		if (result != 0)
		{
			return -1;
		}
	}
	// �o�[�X�g����
	{
		*isBurst = false;
		if (handPoint > 21)
		{
			*isBurst = true;
		}
	}
	return 0;
}

int Hand::CalcPoint()
{
	int sumPoint = 0;
	int aceCount = 0;
	for (size_t i = 0; i <= handCount; i++)
	{
		unsigned int num = hand[i];
		unsigned int pt = 0;
		int result = GetPoint(num, &pt);
		if (result != 0)
		{
			return -1;
		}
		if (pt != 11)
		{
			sumPoint += pt;
		}
		else
		{
			// �G�[�X�̐����J�E���g
			aceCount++;
		}
	}
	// �G�[�X��11��21���I�[�o�[����Ȃ�1�Ɋۂ߂�
	for (size_t i = 0; i < aceCount; i++)
	{
		if (sumPoint > 10)
		{
			sumPoint += 1;
		}
		else
		{
			sumPoint += 11;
		}
	}
	handPoint = sumPoint;
	return 0;
}

int Hand::GetPoint(const unsigned int number, unsigned int* const point)
{
	// ���̓`�F�b�N
	{
		// number�̓��͔͈̓`�F�b�N
		if (number < 0 || (CARD_MAX - 1) < number)
		{
			return -1;
		}
		if (point == NULL)
		{
			return -1;
		}
	}
	// �J�[�h�̃|�C���g���擾
	{
		unsigned int num = number % 13;
		unsigned int pt = 0;
		// 1�Ȃ�11
		if (num == 0)
		{
			pt = 11;
		}
		// 2~10�Ȃ炻�̂܂�
		else if (0 < num && num < 10)
		{
			pt = num;
		}
		// J�AQ�AK�Ȃ�10
		else if (10 <= num && num < NUMBER_MAX)
		{
			pt = 10;
		}
		else
		{
			return -1;
		}
		*point = pt;
	}

	return 0;
}

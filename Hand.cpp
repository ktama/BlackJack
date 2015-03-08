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
	// 入力チェック
	{
		// numberの入力範囲チェック
		if (drawNumber1 < 0 || (CARD_MAX - 1) < drawNumber1)
		{
			return -1;
		}
		if (drawNumber2 < 0 || (CARD_MAX - 1) < drawNumber2)
		{
			return -1;
		}
	}
	// 手札に加える
	{
		hand[handCount] = drawNumber1;
		handCount++;
		hand[handCount] = drawNumber2;
		handCount++;
	}
	// ポイントを計算
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
	// ポイントを計算
	int result = CalcPoint();
	if (result != 0)
	{
		return -1;
	}
	return 0;
}

int Hand::Hit(const int drawNumber, bool* const isBurst)
{
	// 入力チェック
	{
		// numberの入力範囲チェック
		if (drawNumber < 0 || (CARD_MAX - 1) < drawNumber)
		{
			return -1;
		}
		if (isBurst == NULL)
		{
			return -1;
		}
	}
	// 手札に加える
	{
		hand[handCount] = drawNumber;
		handCount++;
	}
	// ポイントを計算
	{
		int result = CalcPoint();
		if (result != 0)
		{
			return -1;
		}
	}
	// バースト処理
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
			// エースの数をカウント
			aceCount++;
		}
	}
	// エースを11で21をオーバーするなら1に丸める
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
	// 入力チェック
	{
		// numberの入力範囲チェック
		if (number < 0 || (CARD_MAX - 1) < number)
		{
			return -1;
		}
		if (point == NULL)
		{
			return -1;
		}
	}
	// カードのポイントを取得
	{
		unsigned int num = number % 13;
		unsigned int pt = 0;
		// 1なら11
		if (num == 0)
		{
			pt = 11;
		}
		// 2~10ならそのまま
		else if (0 < num && num < 10)
		{
			pt = num;
		}
		// J、Q、Kなら10
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

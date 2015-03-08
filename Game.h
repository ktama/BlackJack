#pragma once

#include "Deck.h"
#include "Hand.h"
#include "GameResult.h"
#include "Behavior.h"

class Game
{
public:
	Game();
	~Game();

	int StartGame(GameResult* const);

private:
	int Deal(Deck* const, Hand* const);
	int PlayPlayer(Deck* const, Hand* const, unsigned int* const, bool* const);
	int PlayDealer(Deck* const, Hand* const, unsigned int* const, bool* const);
	int SelectBehavior(Behavior* const);
	int IsHit(const char* const, bool* const);
	int IsStand(const char* const, bool* const);
};


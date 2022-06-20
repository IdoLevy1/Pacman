#pragma once

#include "GameObject.h"

class Fruit : public GameObject
{
public:
	static const int MaxFruitMoves = 40;
	static const int DelayFruit = 25;

private:
	int value;
	int disappears;
	int currDelay, randomDelay;
	int count5Moves;

public:
	Fruit(int x, int y, int direction, int Value, int disappears, int currDelay, int randomDelay, int count5Moves);
	Fruit() : GameObject() { value = 0; disappears = 0; currDelay = 0; randomDelay = 0; count5Moves = 0; }

	inline int getValue() const { return value; }
	inline int getDisappears() const { return disappears; }
	inline int getCurrDelay() const { return currDelay; }
	inline int getRandomDelay() const { return randomDelay; }

	inline void setValue(int Value) { this->value = Value; }
	inline void setDisappears(int disappears) { this->disappears = disappears; }
	inline void setCurrDelay(int currDelay) { this->currDelay = currDelay; }
	inline void setRandomDelay(int randomDelay) { this->randomDelay = randomDelay; }

	void SetFruit(const Board& board);
	void Move(Board& board, GameObject object = GameObject(0, 0, 0)) override;
};

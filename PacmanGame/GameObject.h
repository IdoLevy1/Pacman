#pragma once

#include "Board.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
using namespace std;

class GameObject
{
public:
	enum { RIGHT = 'D', right = 'd', LEFT = 'A', left = 'a', UP = 'W', up = 'w', DOWN = 'X', down = 'x', STAY = 'S', stay = 's' };
	static const int NUMOFDIRECTIONS = 4;
private:
	int x;
	int y;
	int direction;

public:
	GameObject(int x, int y, int direction) :x(x), y(y), direction(direction) {}
	GameObject() :GameObject(0, 0, 0) {}

	inline int getX() const { return x; }
	inline int getY() const { return y; }
	inline int getDirection() const { return direction; }

	inline void setX(int x) { this->x = x; }
	inline void setY(int y) { this->y = y; }
	inline void setDirection(int direction) { this->direction = direction; }

	virtual void Move(Board& board, GameObject object = GameObject(0, 0, 0));
	void MoveToRandomDirection();
	void gotoxy(int x, int y);
	bool operator==(const GameObject& object);

};

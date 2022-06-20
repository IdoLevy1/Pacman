#pragma once
#include "GameObject.h"

class Pacman : public GameObject
{
private:
	int currPoints;
	int currLives;
	int pointsOnBoardXPosition, pointsOnBoardYPosition;

public:
	Pacman(int x, int y, int direction, int currPoints, int currLives, int pointsOnBoardXPosition, int pointsOnBoardYPosition);
	Pacman() :GameObject() { currPoints = 0; currLives = 3; pointsOnBoardXPosition = 0; pointsOnBoardYPosition = 0; }

	inline int getCurrPoints() const { return currPoints; }
	inline int getCurrLives() const { return currLives; }
	inline int getpointXPositions() const { return pointsOnBoardXPosition; }
	inline int getpointYPositions() const { return pointsOnBoardYPosition; }

	inline void setCurrPoints(int currPoints) { this->currPoints = currPoints; }
	inline void setCurrLives(int currLives) { this->currLives = currLives; }
	inline void setpointXPositions(int pointsOnBoardXPosition) { this->pointsOnBoardXPosition = pointsOnBoardXPosition; }
	inline void setpointYPosition(int pointsOnBoardYPosition) { this->pointsOnBoardYPosition = pointsOnBoardYPosition; }

	bool checkIfDirection(int direction);
	void Move(Board& board, GameObject object = GameObject(0, 0, 0)) override;
	void updatePointsOnBoard(Board& board, int value = 1);
};


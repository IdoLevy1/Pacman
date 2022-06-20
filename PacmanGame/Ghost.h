#pragma once
#include "GameObject.h"

class Ghost : public GameObject
{
public:
	enum class GhostLevel { Best, Good, Novice };
private:
	GhostLevel smartLevel;
	int countSmartMove;
	int countRandomMove;

public:
	Ghost(int x, int y, int direction, GhostLevel level, int countSmartMove, int countRandomMove);
	Ghost() :GameObject() { smartLevel = GhostLevel::Best; countSmartMove = 0; countRandomMove = 0; }

	inline GhostLevel getSmartLevel() const { return smartLevel; }
	inline int getCountSmartMove() const { return countSmartMove; }
	inline int getCountRandomMove() const { return countRandomMove; }

	inline void setSmartLevel(GhostLevel smartLevel) { this->smartLevel = smartLevel; }
	inline void setCountSmartMove(int countSmartMove) { this->countSmartMove = countSmartMove; }
	inline void setCountRandomMove(int countRandomMove) { this->countRandomMove = countRandomMove; }

	void Move(Board& board, GameObject object = GameObject(0, 0, 0)) override;
	void ChasePacman(const Board& board, GameObject Pacman);
};

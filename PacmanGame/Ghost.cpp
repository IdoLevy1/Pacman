#include "Ghost.h"

Ghost::Ghost(int x, int y, int direction, GhostLevel level, int countSmartMove, int countRandomMove)
	:GameObject(x, y, direction)
{
	this->smartLevel = level;
	this->countSmartMove = countSmartMove;
	this->countRandomMove = countRandomMove;
}

/*The function moves a ghost on board, using GameObject move function*/
void Ghost::Move(Board& board, GameObject object)
{
	int lastStepX = getX();
	int lastStepY = getY();
	GameObject::Move(board, object);

	if (board.getFromBoard(getX(), getY()) == Board::object::Tunnel)
	{
		setX(lastStepX);
		setY(lastStepY);
	}
	if (smartLevel == GhostLevel::Best)
		ChasePacman(board, object);

	else if (smartLevel == GhostLevel::Good)
	{
		if (countSmartMove == 20)
		{
			if (countRandomMove == 0)
				countRandomMove++;

			else if (countRandomMove == 5)
			{
				setCountSmartMove(0);
				setCountRandomMove(0);
			}
			else
				countRandomMove++;
		}
		if (countSmartMove < 20)
		{
			ChasePacman(board, object);
			countSmartMove++;
		}
	}
	else
	{
		if (countSmartMove == 20)
		{
			setCountSmartMove(0);
			countSmartMove++;
		}
		else
			countSmartMove++;
	}
	gotoxy(lastStepY, lastStepX);
	if (board.getFromBoard(lastStepX, lastStepY) == Board::object::Breadcrumbs || board.getFromBoard(lastStepX, lastStepY) == Board::object::Empty)
		board.printObject(board.getFromBoard(lastStepX, lastStepY));
	else
		cout << " ";
	gotoxy(getY(), getX());
	if (board.getColor() == true)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "$";
}

/*The function change the ghost move according to the position of pacman on the board*/
void Ghost::ChasePacman(const Board& board, GameObject Pacman)
{
	if (abs(getX() - Pacman.getX()) > abs(getY() - Pacman.getY()))
	{
		if (getX() < Pacman.getX() && board.getFromBoard(getX() + 1, getY()) != Board::object::Wall && board.getFromBoard(getX() + 1, getY()) != Board::object::PointsLives)
			setDirection('x');
		else if (getX() > Pacman.getX() && board.getFromBoard(getX() - 1, getY()) != Board::object::Wall && board.getFromBoard(getX() - 1, getY()) != Board::object::PointsLives)
			setDirection('w');
		else
		{
			if (getY() < Pacman.getY() && board.getFromBoard(getX(), getY() + 1) != Board::object::Wall && board.getFromBoard(getX(), getY() + 1) != Board::object::PointsLives)
				setDirection('d');
			else if (getY() > Pacman.getY() && board.getFromBoard(getX(), getY() - 1) != Board::object::Wall && board.getFromBoard(getX(), getY() - 1) != Board::object::PointsLives)
				setDirection('a');
		}
	}
	else
	{
		if (getY() < Pacman.getY() && board.getFromBoard(getX(), getY() + 1) != Board::object::Wall && board.getFromBoard(getX(), getY() + 1) != Board::object::PointsLives)
			setDirection('d');
		else if (getY() > Pacman.getY() && board.getFromBoard(getX(), getY() - 1) != Board::object::Wall && board.getFromBoard(getX(), getY() - 1) != Board::object::PointsLives)
			setDirection('a');
		else
		{
			if (getX() < Pacman.getX() && board.getFromBoard(getX() + 1, getY()) != Board::object::Wall && board.getFromBoard(getX() + 1, getY()) != Board::object::PointsLives)
				setDirection('x');
			else if (getX() > Pacman.getX() && board.getFromBoard(getX() - 1, getY()) != Board::object::Wall && board.getFromBoard(getX() - 1, getY()) != Board::object::PointsLives)
				setDirection('w');
		}
	}
}

#include "Pacman.h"

Pacman::Pacman(int x, int y, int direction, int currPoints, int currLives, int pointsOnBoardXPosition, int pointsOnBoardYPosition)
	:GameObject(x, y, direction)
{
	this->currPoints = currPoints;
	this->currLives = currLives;
	this->pointsOnBoardXPosition = pointsOnBoardXPosition;
	this->pointsOnBoardYPosition = pointsOnBoardYPosition;
}

/* The function checks if the player pressed direction.*/
bool Pacman::checkIfDirection(int direction)
{
	return((direction == RIGHT) || (direction == LEFT) || (direction == DOWN) || (direction == UP) || (direction == STAY) || (direction == right) || (direction == left) || (direction == down) || (direction == up) || (direction == stay));
}

/*The function moves the pacman on board, using GameObject move function*/
void Pacman::Move(Board& board, GameObject object)
{
	int lastStepX = getX();
	int lastStepY = getY();
	GameObject::Move(board, object);
	if (board.getFromBoard(getX(), getY()) == Board::object::Tunnel)
	{
		if (getX() == 0)
		{
			if (board.getFromBoard(board.getLogRow() - 1, getY()) == Board::object::Tunnel)
				setX(board.getLogRow() - 1);
			else
			{
				setX(lastStepX);
				setY(lastStepY);
			}
		}
		else if (getX() == board.getLogRow() - 1)
		{
			if (board.getFromBoard(0, getY()) == Board::object::Tunnel)
				setX(0);
			else
			{
				setX(lastStepX);
				setY(lastStepY);
			}
		}
		if (getY() == 0)
		{
			if (board.getFromBoard(getX(), board.getLogCol() - 1) == Board::object::Tunnel)
				setY(board.getLogCol() - 1);
			else
			{
				setX(lastStepX);
				setY(lastStepY);
			}
		}
		else if (getY() == board.getLogCol() - 1)
		{
			if (board.getFromBoard(getX(), 0) == Board::object::Tunnel)
				setY(0);
			else
			{
				setX(lastStepX);
				setY(lastStepY);
			}
		}
	}
	gotoxy(lastStepY, lastStepX);
	cout << ' ';

	if (board.getFromBoard(lastStepX, lastStepY) == Board::object::Breadcrumbs)
	{
		updatePointsOnBoard(board);
		board.setInBoard(lastStepX, lastStepY, Board::object::Empty);
	}

	gotoxy(getY(), getX());
	if (board.getColor() == true)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "@";
}

/*The function add 1 point to the player, and updates it on the screen.*/
void Pacman::updatePointsOnBoard(Board& board, int value)
{
	currPoints += value;
	gotoxy(pointsOnBoardYPosition, pointsOnBoardXPosition);
	if (board.getColor() == true)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << currPoints;
}
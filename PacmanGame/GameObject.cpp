#include "GameObject.h"

/*The function moves an object on board*/
void GameObject::Move(Board& board, GameObject object)
{
	switch (direction)	// make a move in current direction if no change
	{
	case (RIGHT):
	case (right):
	{
		if (!(board.getFromBoard(x, y + 1) == Board::object::Wall || board.getFromBoard(x, y + 1) == Board::object::PointsLives))
			y++;
		break;
	}
	case (DOWN):
	case (down):
	{
		if (!(board.getFromBoard(x + 1, y) == Board::object::Wall || board.getFromBoard(x + 1, y) == Board::object::PointsLives))
			x++;
		break;
	}
	case (LEFT):
	case (left):
	{
		if (!(board.getFromBoard(x, y - 1) == Board::object::Wall || board.getFromBoard(x, y - 1) == Board::object::PointsLives))
			y--;
		break;
	}
	case (UP):
	case (up):
	{
		if (!(board.getFromBoard(x - 1, y) == Board::object::Wall || board.getFromBoard(x - 1, y) == Board::object::PointsLives))
			x--;
		break;
	}
	case (STAY):
	case (stay):
		break;
	}
}
/*The function randomly choose an object direction*/
void GameObject::MoveToRandomDirection()
{
	int RandomDirection = rand() % NUMOFDIRECTIONS;
	switch (RandomDirection)
	{
	case 0:
		direction = 'D';
		break;
	case 1:
		direction = 'A';
		break;
	case 2:
		direction = 'W';
		break;
	case 3:
		direction = 'X';
		break;
	}
}

void GameObject::gotoxy(int x, int y)
{
	static HANDLE hConsoleOutput = NULL;
	if (NULL == hConsoleOutput)
		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwCursorPosition = { x, y };
	cout.flush();
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

bool GameObject:: operator==(const GameObject& object)
{
	return (x == object.x && y == object.y);
}
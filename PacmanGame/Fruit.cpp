#include "Fruit.h"

Fruit::Fruit(int x, int y, int direction, int Value, int disappears, int currDelay, int randomDelay, int count5Moves)
	: GameObject(x, y, direction)
{
	this->value = Value;
	this->disappears = disappears;
	this->currDelay = currDelay;
	this->randomDelay = randomDelay;
	this->count5Moves = count5Moves;
}

/*The function randomly sets fruit on board*/
void Fruit::SetFruit(const Board& board)
{
	value = 5 + (rand() % 5);
	randomDelay = rand() % DelayFruit;
	do
	{
		setX(rand() % (board.getLogRow()));
		setY(rand() % board.getLogCol());
	} while (board.getFromBoard(getX(), getY()) != Board::object::Breadcrumbs && board.getFromBoard(getX(), getY()) != Board::object::Empty);
}

/*The function moves a fruit on board, using GameObject move function*/
void Fruit::Move(Board& board, GameObject object)
{
	int lastStepX = getX();
	int lastStepY = getY();

	if (disappears == 0 && currDelay == 0)
		SetFruit(board);

	if (disappears == MaxFruitMoves)
	{
		gotoxy(lastStepY, lastStepX);
		if (board.getFromBoard(lastStepX, lastStepY) == Board::object::Breadcrumbs || board.getFromBoard(lastStepX, lastStepY) == Board::object::Empty)
			board.printObject(board.getFromBoard(lastStepX, lastStepY));
		else
			cout << " ";
		gotoxy(board.getLogCol() + 1, board.getLogRow() + 1);

		if (currDelay == randomDelay)
		{
			setCurrDelay(0);
			setDisappears(0);
			return;
		}
		else
		{
			currDelay++;
			return;
		}
	}
	else
		disappears++;

	if (count5Moves == 5)
	{
		MoveToRandomDirection();
		count5Moves = 0;
	}
	else
		count5Moves++;

	GameObject::Move(board);
	if (board.getFromBoard(getX(), getY()) == Board::object::Tunnel)
	{
		setX(lastStepX);
		setY(lastStepY);
	}

	gotoxy(lastStepY, lastStepX);
	if (board.getFromBoard(lastStepX, lastStepY) == Board::object::Breadcrumbs || board.getFromBoard(lastStepX, lastStepY) == Board::object::Empty)
		board.printObject(board.getFromBoard(lastStepX, lastStepY));
	else
		cout << " ";
	gotoxy(getY(), getX());
	if (board.getColor() == true)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	cout << value;
}

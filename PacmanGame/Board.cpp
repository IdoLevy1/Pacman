#include "Board.h"

/* The function prints the board.*/
void Board::printBoardGame() const
{
	for (int i = 0; i < logRow; i++)
	{
		for (int j = 0; j < logCol; j++)
			printObject(this->board[i][j]);
		cout << endl;
	}
}

/* The function prints an object.*/
void Board::printObject(object ob) const
{
	switch (ob)
	{
	case (object::Breadcrumbs):
	{
		if (color == true)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		cout << '.';
		break;
	}
	case (object::Wall):
	{
		if (color == true)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		cout << '#';
		break;
	}
	case (object::Empty):
	case (object::Tunnel):
	case (object::PointsLives):
		cout << ' ';
		break;
	case (object::Pacman):
		if (color == true)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		cout << '@';
		break;
	case (object::Ghost):
		if (color == true)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << '$';
		break;
	}
}

/*The function check if opening file is succeeded*/
bool Board::checkFile(ifstream& infile)
{
	if (!infile)
	{
		system("cls");
		cout << "Error. The file isn't exist !" << endl;
		return false;
	}
	return true;
}

/*This function resets the board.*/
void Board::resetBoard()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
			board[i][j] = object::Empty;
	}
}

/*The function gets a file name and puts it into a board game*/
bool Board::getBoardFromFile(string fileName)
{
	resetBoard();
	string str;
	int row = 0, col, i, j;

	ifstream infile(fileName);
	if (!checkFile(infile))
		return false;

	getline(infile, str);
	logCol = str.size();

	for (; row < ROW && (!infile.eof()); row++)
	{
		for (col = 0; col < str.size(); col++)
		{
			if (!(board[row][col] == object::PointsLives))
			{
				switch (str.at(col))
				{
				case '#':
					board[row][col] = object::Wall;
					break;
				case '@':
					board[row][col] = object::Pacman;
					break;
				case '$':
					board[row][col] = object::Ghost;
					break;
				case ' ':
				{
					if (col == 0 || col == logCol - 1 || row == 0)
						board[row][col] = object::Tunnel;
					else
						board[row][col] = object::Breadcrumbs;
					break;
				}
				case '%':
					board[row][col] = object::Empty;
					break;
				case '&':
				{
					for (i = row; i < row + 3; i++)
					{
						for (j = col; j < col + 20; j++)
							board[i][j] = object::PointsLives;
					}
					break;
				}
				}
			}
		}
		while (col < logCol)
		{
			board[row][col] = object::Empty;
			col++;
		}
		getline(infile, str);
	}
	logRow = row;

	col = 0;
	while (col < logCol)
	{
		if (board[logRow - 1][col] == object::Breadcrumbs)
			board[logRow - 1][col] = object::Tunnel;
		col++;
	}
	infile.close();
	return true;
}

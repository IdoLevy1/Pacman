#pragma once

#include <fstream>
#include <string>
#include<iostream>
#include <Windows.h>
using namespace std;

class Board
{
public:
	static const int COL = 80;
	static const int ROW = 25;
	enum class object { Breadcrumbs, Wall, Empty, Tunnel, PointsLives, Pacman, Ghost };

private:
	object board[ROW][COL];
	int logRow, logCol;
	bool color;

public:
	Board(int logRow, int logCol, bool color) :logRow(logRow), logCol(logCol), color(color) {}
	Board() :Board(ROW, COL, true) {}

	inline object getFromBoard(int x, int y) const { return board[x][y]; }
	inline int getLogRow() const { return logRow; }
	inline int getLogCol() const { return logCol; }
	inline bool getColor() const { return color; }

	void setInBoard(int x, int y, object c) { this->board[x][y] = c; }
	inline void setLogRow(int logRow) { this->logRow = logRow; }
	inline void setLogCol(int logCol) { this->logCol = logCol; }
	inline void setColor(bool color) { this->color = color; }

	void printBoardGame() const;
	void printObject(object ob) const;
	bool checkFile(ifstream& infile);
	void resetBoard();
	bool getBoardFromFile(string fileName);
};

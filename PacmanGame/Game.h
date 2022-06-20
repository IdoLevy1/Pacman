#pragma once

#include "Board.h"
#include "Pacman.h"
#include "Ghost.h"
#include "Fruit.h"
#include <vector>
#include <string>
#include<iostream>
using namespace std;

class Game
{
public:
	static const int ESC = 27;

private:
	Board board;
	Pacman pacman;
	vector <Ghost> ghostArr;
	Fruit fruit;
	int ghostLevel;
	bool color = true;

public:
	void printMenu();
	void printInstructions();
	bool setObjects();
	void setGhostsLevel();
	void moveObjects();
	void MoveGhosts();
	bool checkIfGhost();
	void winGame();
	void loseGame();
	bool checkIfWin();
	int playInSingleFile(string fileName);
	void checkColors();
	void checkGhostLevel();
	vector<string> getFiles();
	void sortFiles(vector<string> files);
	void swapFileName(string name1, string name2);
	void playGame();
	void startGame();
};

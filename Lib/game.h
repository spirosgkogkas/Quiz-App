#ifndef GAME_H
	#define GAME_H
	#ifndef INPUT_H
		#include "./input.h"
	#endif
	#define FALSE "False"
	#define TRUE  "True"
	void startGame();
	int validAnswer(char ch);
	void printScore();
	void end_lvl1(int);
	struct Questions{
	char solution;
	char answer;
	};
	typedef struct Questions Q;
	void infoQ(Q questions[]);
	void checkSolution(char solution, char answer);
	typedef int LEVEL;
	extern int SCORE;
#endif
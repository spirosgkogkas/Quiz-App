#ifndef INPUT_H
	#define INPUT_H
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	extern FILE *SYSERR;
	int validName(char *name);
	int validChoice(char *choice);
	int getLevel();
	void getAnswer(char *answer);
	int validAnswer(char ch);
	void clearStdin(const char *name);
	char *getName();
#endif

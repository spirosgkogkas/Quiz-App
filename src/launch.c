#include "../Lib/input.h"
#include "../Lib/game.h"

FILE *SYSERR;

int main(int argc, char const *argv[])
{
	SYSERR = fopen("syserr.txt","a");
	startGame();
	fclose(SYSERR);
	return 0;
}
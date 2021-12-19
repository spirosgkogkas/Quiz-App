#include "../Lib/input.h"

int validName(char *name){
	/*A simple function checking for validity for player name*/
	if(name[0] == '\n') return 0;

	while(*name != '\0'){
		if((*name < 'A' || *name > 'Z') && (*name < 'a' || *name > 'z') && *name != '\n')
			return 0;
		name++;
	}
	/*-----------------------------------------------------*/
	return 1;
}

int validChoice(char *choice){
	/*A simple function checking for validity for player's choice*/
	if(choice[0] == '\n') return 0;
	while(*choice != '\0'){
		if((*choice < '0' || *choice > '9') && *choice != '\n') return 0;
		choice++;
	}
	/*---------------------------------------------------------*/
	return 1;
}

void clearStdout(){
	#ifdef _WIN32
		system("cls");
	#elif __linux__
		system("clear");
	#endif
}

void clearStdin(const char *name){
	int ch;

	/*	This part of code checks if name terminated with '\n' character if it does it proceeds further 
	  otherwise it clears the remainders in stdin buffer*/
	if(name != NULL){
		if(name[strlen(name) - 1] != '\n')
			while((ch = getchar()) != '\n' && ch != EOF);
		else return;
	}
	else while((ch = getchar()) != '\n' && ch != EOF);

	/*--------------------------------------------------*/
}

void getAnswer(char *answer){
	printf("Enter your answer:\n>>");
	*answer = getchar();
	while(*answer == ' ') *answer = getchar();
	if(*answer != '\n') clearStdin(NULL);
	if(!validAnswer(*answer)){
		#ifdef _WIN32
			printf("Invalid answer.\n");
			system("@pause && cls");
		#elif __linux__
			printf("Invalid answer.\n");
			printf("Press enter to continue. . .");
			clearStdin(NULL);
			system("clear");
		#endif
	}
}

int validAnswer(char ch){
	switch(ch){
		case 'A':
			return 1;
		case 'B':
			return 1;
		case 'C':
			return 1;
		case 'D':
			return 1;
		case 'a':
			return 1;
		case 'b':
			return 1;
		case 'c':
			return 1;
		case 'd':
			return 1;
		default:
			return 0;
	}
}
/*getName function dynamically allocates memory and stores input name*/
char *getName(){
	char *name;

	name = (char *)calloc(sizeof( char ), 21);
	if(!name){
		printf("Something went wrong. . . for more information check syserr file.\n");
		fprintf(SYSERR, "From -> [getName]: Unable to allocate memory. . . Date/Time [%s, %s]\n",__DATE__, __TIME__);
		exit(EXIT_FAILURE);
	}
	do{
		printf("\t\t\t\t\t   Rules\n\n");
		printf("\t+===============================================================================+\n");
		printf("\t|\t1. A name cannot contain more than 20 letters.\t\t\t\t|\n");
		printf("\t|\t2. A name cannot contain special characters i.e. (!,@,#,$,%%,^,&) etc.\t|\n");
		printf("\t+===============================================================================+\n\n");

		printf("Enter your name:\n>>");
		fgets(name, 21, stdin);
		clearStdin(name);
		if(!validName(name)){
			/*	Checking operating system for portability
			  and clearing the terminal*/
			#ifdef _WIN32
				puts("Invalid name, please try again!");
				system("@pause && cls");
			#elif __linux__
				puts("Invalid name, please try again!\n");
				printf("Press enter to continue. . .");
				clearStdin(NULL);
				system("clear");
			#endif
		}
		/*------------------------------------------------*/
	}while(!validName(name));

	#ifdef _WIN32
		system("cls");
	#elif __linux__
		system("clear");
	#endif

	return name;
}

int getLevel(){
	#ifndef B_SIZE
		#define B_SIZE 16
	#endif
	int choice;
	char tmp_choice[B_SIZE];

	do{
		puts("\n\t\t\t\t\t\t Levels\n");
		puts("\t\t\t\t+======================================+");
		puts("\t\t\t\t|\t\t1.Easy                 |");
		puts("\t\t\t\t|\t\t2.Advanced             |");
		puts("\t\t\t\t|\t\t3.Master               |");
		puts("\t\t\t\t+======================================+");
		printf("Enter Level:\n>>");
		fgets(tmp_choice, sizeof( tmp_choice ), stdin);
		clearStdin(tmp_choice);

		/*	A conditional checking if either user input was only letter or if it was an actual numeric value
		  if condition is true set choice to -1 and start over.*/
		if((sscanf(tmp_choice, "%d", &choice) != 1) || !(validChoice(tmp_choice)) ){
			#ifdef _WIN32
				puts("Only numbers are acceptable. . .\nPlease try again!\n");
				system("@pause && cls");
			#elif __linux__
				puts("Only numbers are acceptable. . .\nPlease try again!\n");
				printf("Press enter to continue. . .");
				clearStdin(NULL);
				system("clear");
			#endif
			choice = -1;
			continue;
		}
		/*--------------------------------------------------------------------------------------------------*/
		if(choice < 1 || choice > 3){
			#ifdef _WIN32
				puts("Invalid choice, please try again!");
				system("@pause && cls");
			#elif __linux__
				puts("Invalid choice, please try again!\n");
				printf("Press enter to continue. . .");
				getchar();
				system("clear");
			#endif
		}
	}while(choice < 1 || choice > 3);

	#undef B_SIZE
	#ifdef _WIN32
		system("cls");
	#elif __linux__
		system("clear");
	#endif

	return choice;
}
void startScrn(){
	clearStdout();
	puts("\t\t+=========================================================================+");
	puts("\t\t|   ####   #    #   #####  ######           #          ######     ######  |");
	puts("\t\t|  #    #  #    #     #        #           # #        #      #   #      # |");
	puts("\t\t|  #    #  #    #     #       #           #   #       #      #   #      # |");
	puts("\t\t|  #  ###  #    #     #      #           #######      #######    #######  |");
	puts("\t\t|   ####   #    #     #     #           #       #     #          #        |");
	puts("\t\t|      ##   ####    #####  ######      #         #    #          #        |");
	puts("\t\t+=========================================================================+");
	putchar('\n');
	putchar('\n');
	putchar('\n');
	puts("\t\t                               Press Enter");
	printf("\t\t                                    ");
	clearStdin(NULL);
	clearStdout();
}
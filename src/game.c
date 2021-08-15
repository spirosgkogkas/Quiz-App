#include "../Lib/game.h"

int SCORE = 0;

void startGame(){
	Q ARRAY[10];
	LEVEL lvl;
	char answer, *name;
	int stage = 0;
	name = (char *)getName();
	if(!name){
		fprintf(SYSERR, "From -> game.c at [startGame.func][D:%s][T:%s]: NULL pointer. . .\n", __DATE__, __TIME__);
		exit(EXIT_FAILURE);
	}
	free(name);
	lvl = getLevel();
	switch(lvl){
		case 1:
			while(stage < 10){
					switch(stage){
						case 0:
							do{
								printf("LEVEL:%d\n", lvl);
								printScore();
								printf("\n\t\t+==================================================+\n");
								printf("\t\t| What's the output of the following program?\t   |\n");
								printf("\t\t+==================================================+\n\n");
								printf("int main(const int argc, const char *argv[]){\n");
								printf("\tint value;\n");
								printf("\tprintf(\"Enter value: \");\n");
								printf("\tscanf(\"%%d\",&(*(&value)));\n");
								printf("\tprintf(\"Value = %%d\", value);\n\n");
								printf("\treturn 0;\n}\n\n");
								printf("A.Runtime error\t\tC.New address of value\n");
								printf("B.Value of variable\tD.None of the above\n\n");
								printf("Enter your answer:\n>>");
								answer = getchar();
								if(answer != '\n') clearStdin(NULL);
								if(!validAnswer(answer)){
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
							}while(!validAnswer(answer));

							ARRAY[stage].solution = 'B';
							ARRAY[stage].answer   = answer;
							checkSolution(ARRAY[stage].solution, answer);
							break;
						case 1:
							do{
								printf("LEVEL:%d\n", lvl);
								printScore();
								printf("\n\t\t+==================================================+\n");
								printf("\t\t| What's true for the function below?\t\t   |\n");
								printf("\t\t+==================================================+\n\n");
								printf("void func(int **ptr, size_t size){\n");
								printf("\t*ptr = (int *)calloc(sizeof( int ), size);\n");
								printf("\tfor(size_t i = 0; i < size; i++)\n");
								printf("\t\t *(ptr + i) = rand() %% 100 + 1;\n");
								printf("}\n\nA.Allocate memory for N integer numbers\t\tB.Run time error because of first parameter at calloc\n");
								printf("C.None of the choices\t\t\t\tD.Segmentation fault\n");
								getAnswer(&answer);
							}while(!validAnswer(answer));

							ARRAY[stage].solution = 'A';
							ARRAY[stage].answer   = answer;
							checkSolution(ARRAY[stage].solution, answer);
							break;
						case 2:
							do{
								printf("LEVEL:%d\n", lvl);
								printScore();
								printf("\n\t\t+==================================================+\n");
								printf("\t\t| What is this declaration? char *(*p)[5];\t   |\n");
								printf("\t\t+==================================================+\n\n");
								printf("A.p is an array of 5 pointers to char\t\tC.p is a pointer to pointer to array of 5 char\n");
								printf("B.Compilation Error\t\t\t\tD.p is a pointer to an array of 5 pointers to char\n\n");
								getAnswer(&answer);
							}while(!validAnswer(answer));

							ARRAY[stage].solution = 'D';
							ARRAY[stage].answer   = answer;
							checkSolution(ARRAY[stage].solution, answer);
							break;
						case 3:
							do{
								printf("LEVEL:%d\n", lvl);
								printScore();
								printf("\n\t\t+=======================================================================================+\n");
								printf("\t\t|What's the address of the pointer's value at output? (Assume starting position is 5000)|\n");
								printf("\t\t+=======================================================================================+\n\n");
								printf("int main(const int argc, const char *argv[]){\n");
								printf("\tint (*ptr)[5], array[20][5];\n");
								printf("\tptr = array;\n\n");
								printf("\tptr++;\n");
								printf("\tprintf(\"Address after %%d\\n\", ptr);\n");
								printf("\treturn 0;\n}\n\n");
								printf("A.5100\t\tC.5005\n");
								printf("B.5020\t\tD.5035\n");
								getAnswer(&answer);
							}while(!validAnswer(answer));

							ARRAY[stage].solution = 'B';
							ARRAY[stage].answer   = answer;
							checkSolution(ARRAY[stage].solution, answer);
							break;
						case 4:
							do{
								printf("LEVEL:%d\n", lvl);
								printScore();
								printf("\n\t\t+=========================================================+\n");
								printf("\t\t|What's the usage of typedef keyword?\t\t\t  |\n");
								printf("\t\t+=========================================================+\n\n");
								printf("A.Changes the type of a data type\tC.Used to make a new name for an already type or a user defined data type\n");
								printf("B.Defines a macro at preprocess time\tD.Changes the type of standard data types\n");
								getAnswer(&answer);
							}while(!validAnswer(answer));

							ARRAY[stage].solution = 'C';
							ARRAY[stage].answer   = answer;
							checkSolution(ARRAY[stage].solution, answer);
							break;
						case 5:
							do{
								printf("LEVEL:%d\n", SCORE);
								printScore();
								printf("\n\t\t+==================================================+\n");
								printf("\t\t|Which one is true from the below?\t\t   |\n");
								printf("\t\t+==================================================+\n\n");
								printf("A.C has Strings data types\t\tC. C is a markup language\n");
								printf("B.C is case sensitive\t\t\tD.None of the above\n\n");
								getAnswer(&answer);
							}while(!validAnswer(answer));

							ARRAY[stage].solution = 'B';
							ARRAY[stage].answer   = answer;
							checkSolution(ARRAY[stage].solution, answer);
							break;
						case 6:
							do{
								printf("LEVEL:%d\n", lvl);
								printScore();
								printf("\n\t\t+===============================================================+\n");
								printf("\t\t|Which data type is used for precision with floating point?\t|\n");
								printf("\t\t+===============================================================+\n\n");
								printf("A.Double\t\t\t\tC.User defined data types\n");
								printf("B.Float\t\t\t\t\tD.Int\n");
								getAnswer(&answer);
							}while(!validAnswer(answer));

							ARRAY[stage].solution = 'A';
							ARRAY[stage].answer   = answer;
							checkSolution(ARRAY[stage].solution, answer);
							break;
						case 7:
							do{
								printf("LEVEL:%d\n", lvl);
								printScore();
								printf("\n\t\t+==================================================+\n");
								printf("\t\t| What's the output of the following program?\t   |\n");
								printf("\t\t+==================================================+\n\n");
								printf("int main(const int argc, const char *argv[]){\n");
								printf("\tint num = 10;\n");
								printf("\tfloat num2 = 2.0F\n");
								printf("\tprintf(\"Result = %%.2f\", num / num2);\n\n");
								printf("\treturn 0;\n}\n\n");
								printf("A.5.0\t\t\t\tC.Compilation error\n");
								printf("B.5.00\t\t\t\t   D.5\n\n");
								getAnswer(&answer);
							}while(!validAnswer(answer));

							ARRAY[stage].solution = 'B';
							ARRAY[stage].answer   = answer;
							checkSolution(ARRAY[stage].solution, answer);
							break;
						case 8:
							do{
								printf("LEVEL:%d\n", lvl);
								printScore();
								printf("\n\t\t+==================================================+\n");
								printf("\t\t| Who was the creator of C language?\t\t   |\n");
								printf("\t\t+==================================================+\n\n");
								printf("A.Guido Van Rossum\t\tC.Bjarne Stroustrup\n");
								printf("B.Dennis Ritchie\t\tD.None of the above\n\n");
								getAnswer(&answer);
							}while(!validAnswer(answer));

							ARRAY[stage].solution = 'B';
							ARRAY[stage].answer   = answer;
							checkSolution(ARRAY[stage].solution, answer);
							break;
						case 9:
							do{
								printf("LEVEL:%d\n", lvl);
								printScore();
								printf("\n\t\t+==================================================+\n");
								printf("\t\t| What programming language is C?\t\t   |\n");
								printf("\t\t+==================================================+\n\n");
								printf("A.Functional language\t\t\tC.Markup language\n");
								printf("B.Object oriented language\t\tD.General procedural language\n\n");
								getAnswer(&answer);
							}while(!validAnswer(answer));

							ARRAY[stage].solution = 'D';
							ARRAY[stage].answer   = answer;
							checkSolution(ARRAY[stage].solution, answer);
							break;
					}
				stage++;
				}
				end_lvl1(SCORE);
				infoQ(ARRAY);
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			break;
	}
}

void printScore(){
	puts("****************");
	printf("* SCORE: %2d/10 *\n", SCORE);
	puts("****************");
}

void infoQ(Q questions[]){
	for(int i = 0; i < 10; i++)
		printf("\t\t| Question_%02d: %50s|\n", i + 1, (questions[i].solution == questions[i].answer || (questions[i].answer - 32) == questions[i].solution) ? TRUE : FALSE);
	printf("\t\t******************************************************************\n");
}

void end_lvl1(int score){
	printf("\n\t\t******************************************************************\n");
	printf(
		"\t\t| ######    ######    #####   #      #   #      #######    ##### |\n"\
		"\t\t| #     #   #        #        #      #   #         #      #      |\n"\
		"\t\t| #     #   #        #        #      #   #         #      #      |\n"\
		"\t\t| ######    ####      ####    #      #   #         #       ####  |\n"\
		"\t\t| #    #    #             #   #      #   #         #           # |\n"\
		"\t\t| #     #   #             #   #      #   #         #           # |\n"\
		"\t\t| #      #  ######   #####     ######    ######    #      #####  |\n"\
	);
	printf("\t\t******************************************************************\n");
}
void checkSolution(char solution, char answer){
	if(solution == answer || (answer - 32) == solution){
		printf("Correct answer.\n\n");
		#ifdef _WIN32
			system("@pause && cls");
		#elif __linux__
			printf("Press enter to continue. . .");
			clearStdin(NULL);
			system("clear");
		#endif
		SCORE++;
	}
	else{
		printf("Wrong answer. Correct answer was %c\n\n", solution);
			#ifdef _WIN32
				system("@pause && cls");
			#elif __linux__
				printf("Press enter to continue. . .");
				clearStdin(NULL);
				system("clear");
			#endif
		SCORE--;
	}
}
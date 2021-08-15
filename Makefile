CC = gcc

ifeq ($(OS),Windows_NT)
	EXECUTABLE=launch.exe
else
	EXECUTABLE=launch
endif

ifeq ($(OS),Windows_NT)
	RM = cmd \/C .\\clean.bat
else
	RM = rm -f ./build/*.o
endif
OBJECTS = ./build/input.o ./build/game.o ./build/launch.o

bin/EXECUTABLE: $(OBJECTS)
	$(CC) $(OBJECTS) -o ./bin/$(EXECUTABLE) -Wall

build/input.o: ./src/input.c ./Lib/input.h
	$(CC) -c ./src/input.c -o ./build/input.o -Wall
build/game.o: ./src/game.c ./Lib/game.h
	$(CC) -c ./src/game.c -o ./build/game.o -Wall
build/launch.o: ./src/launch.c ./Lib/input.h ./Lib/game.h
	$(CC) -c ./src/launch.c -o ./build/launch.o -Wall

.PHONY: clean
clean:
	@$(RM)
	@echo "success"
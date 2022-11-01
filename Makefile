CC = g++
INC_PATH = include
LIB_PATH = lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

ENTITIES = entities/*.hpp entities/*.cpp
MAPS = map/*.hpp map/*.cpp
STATES = states/*.hpp states/*.cpp
MAIN = game.hpp game.cpp main.cpp
SOURCE =  $(ENTITIES) $(STATES) $(MAPS) $(MAIN)

ENTITIES_OBJ = entity.o
MAPS_OBJ = tile.o tileMap.o
STATES_OBJ = state.o gameState.o
MAIN_OBJ = game.o main.o
OBJ = $(ENTITIES_OBJ) $(STATES_OBJ) $(MAPS_OBJ) $(MAIN_OBJ)

all: compile link clean execute

compile: $(SOURCE)
	@echo ** Compiling...
	@$(CC) -I$(INC_PATH) -c $(SOURCE)

link: $(OBJ)
	@echo ** Linking...
	@$(CC) $(OBJ) -o main -L$(LIB_PATH) $(LIBS)

clean:
	@echo ** Removing object and header files...
	@del $(OBJ)

execute:
	@echo ** Executing!
	@.\main.exe
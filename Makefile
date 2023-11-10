MAKE=make

CC=g++
CFLAGS= -std=c++17
CLIBS= -ldl -lSDL2

SRC=src
BUILD=build

CPP_INCS_GLAD =		src/glad/include
CPP_INCS_DS =		src/ds/include
CPP_INCS_GFX =		src/gfx/include
CPP_INCS_UI =		src/ui/include
CPP_INCS_UTIL = 	src/util/include
CPP_INCS =			-I$(CPP_INCS_GLAD) -I$(CPP_INCS_DS) -I$(CPP_INCS_GFX) -I$(CPP_INCS_UI) -I$(CPP_INCS_UTIL)

CPP_DEPS_WIN =		src/window.cpp
CPP_DEPS_GLAD = 	src/glad/src/glad.c
CPP_DEPS_GFX =		$(wildcard src/gfx/*/src/*.cpp)
CPP_DEPS_UI =		$(wildcard src/ui/*/src/*.cpp)
CPP_DEPS_UTIL = 	$(wildcard src/util/src/*.cpp)
CPP_DEPS =			$(CPP_DEPS_WIN) $(CPP_DEPS_GLAD) $(CPP_DEPS_DS) $(CPP_DEPS_GFX) $(CPP_DEPS_UI) $(CPP_DEPS_UTIL)

BUILD_SNAKE = 		build/snake
CPP_INCS_SNAKE = 	-Isrc/projects/snake/include/
CPP_DEPS_SNAKE = 	$(wildcard src/projects/snake/src/*.cpp)

all: 
	$(MAKE) clean;
	$(MAKE) build;
	$(MAKE) run

build: $(BUILD)/main.o

snake: $(BUILD_SNAKE)/main.o

run:
	./$(BUILD)/main.o


$(BUILD)/main.o: $(SRC)/main.cpp $(CPP_DEPS)
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(SRC)/main.cpp $(CPP_DEPS) -o $(BUILD)/main.o $(CLIBS) $(CPP_INCS)

$(BUILD_SNAKE)/main.o: $(SRC)/main.cpp $(CPP_DEPS) $(CPP_DEPS_SNAKE)
	mkdir -p $(BUILD_SNAKE)
	$(CC) $(FLAGS) $(SRC)/main.cpp $(CPP_DEPS) $(CPP_DEPS_SNAKE) -o $(BUILD_SNAKE)/main.o $(CLIBS) $(CPP_INCS) $(CPP_INCS_SNAKE)
	./$(BUILD_SNAKE)/main.o
	$(MAKE) clean

clean:
	rm -r $(BUILD)


MAKE=make

CC=g++
CFLAGS= -std=c++17
CLIBS= -ldl -lSDL2

SRC=src
BUILD=build

CPP_INC_GLAD = 	src/glad/include
CPP_INC_DS =	src/ds/include
CPP_INC_GFX =	src/gfx/include
CPP_INC_UI =	src/ui/include
CPP_INCS =		-I$(CPP_INC_GLAD) -I$(CPP_INC_DS) -I$(CPP_INC_GFX) -I$(CPP_INC_UI)

CPP_DEPS_WIN =	src/window.cpp
CPP_DEPS_GLAD = src/glad/src/glad.c
CPP_DEPS_GFX =	$(wildcard src/gfx/*/src/*.cpp)
CPP_DEPS_UI =	$(wildcard src/ui/*/src/*.cpp)
CPP_DEPS =		$(CPP_DEPS_WIN) $(CPP_DEPS_GLAD) $(CPP_DEPS_DS) $(CPP_DEPS_GFX) $(CPP_DEPS_UI)

all: 
	$(MAKE) clean;
	$(MAKE) build;
	$(MAKE) run

build: $(BUILD)/main.o

run:
	./$(BUILD)/main.o


$(BUILD)/main.o: $(SRC)/main.cpp ${CPP_DEPS} ${CPP_INC_DS}
	mkdir -p build
	$(CC) $(CFLAGS) $(SRC)/main.cpp $(CPP_DEPS) -o $(BUILD)/main.o $(CLIBS) $(CPP_INCS)

clean:
	rm -r $(BUILD)


hppsrc = $(wildcard include/*.hpp)
OS := $(shell uname)

ifeq ($(OS), Darwin)
	# Check if its in MAC OS
	LDFLAGS = -framework OpenGl -lglfw -lGLEW
else
	# Check if its Linux
	LDFLAGS = -lGL -lglut -lGLEW -lglfw 
endif

all: GLFWApp

GLFWApp.o: GLFWApp.cpp $(hppsrc)
	g++ -Wall -c GLFWApp.cpp $(LDFLAGS)

GLFWApp: GLFWApp.o
	g++ -Wall -o GLFWApp GLFWApp.o $(LDFLAGS)

clean:
	rm -rf GLFWApp *.o
OS := $(shell uname)

ifeq ($(OS), Darwin)
	# Check if its in MAC OS
	LDFLAGS = -framework OpenGl -lglfw -lGLEW
else
	# Check if its Linux
	LDFLAGS = -lGL -lglut -lGLEW -lglfw 
endif

all: GLFWwindow

GLFWwindow.o: GLFWwindow.cpp
	g++ -Wall -c GLFWwindow.cpp $(LDFLAGS)

GLFWwindow: GLFWwindow.o
	g++ -Wall -o GLFWwindow GLFWwindow.o $(LDFLAGS)

clean:
	rm -rf GLFWwindow *.o
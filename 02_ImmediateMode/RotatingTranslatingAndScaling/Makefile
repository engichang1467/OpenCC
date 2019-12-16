OS := $(shell uname)

ifeq ($(OS), Darwin)
	# Check if its in MAC OS
	LDFLAGS = -framework OpenGl -lglfw -lGLEW
else
	# Check if its Linux
	LDFLAGS = -lGL -lglut -lGLEW -lglfw 
endif

all: immediateTriangle

immediateTriangle.o: immediateTriangle.cpp
	g++ -Wall -c immediateTriangle.cpp $(LDFLAGS)

immediateTriangle: immediateTriangle.o
	g++ -Wall -o immediateTriangle immediateTriangle.o $(LDFLAGS)

clean:
	rm -rf immediateTriangle *.o
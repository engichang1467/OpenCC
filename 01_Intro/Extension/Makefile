OS := $(shell uname)

ifeq ($(OS), Darwin)
	# Check if its in MAC OS
	LDFLAGS = -framework OpenGl -lglfw -lGLEW
else
	# Check if its Linux
	LDFLAGS = -lGL -lglut -lGLEW -lglfw 
endif

all: extension

extension.o: extension.cpp
	g++ -Wall -c extension.cpp $(LDFLAGS)

extension: extension.o
	g++ -Wall -o extension extension.o $(LDFLAGS)

clean:
	rm -rf extension *.o
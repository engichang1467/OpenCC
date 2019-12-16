OS := $(shell uname)

ifeq ($(OS), Darwin)
	# Check if its in MAC OS
	LDFLAGS = -framework OpenGl -lglfw -lGLEW
else
	# Check if its Linux
	LDFLAGS = -lGL -lglut -lGLEW -lglfw 
endif

all: version

version.o: version.cpp
	g++ -Wall -c version.cpp $(LDFLAGS)

version: version.o
	g++ -Wall -o version version.o $(LDFLAGS)

clean:
	rm -rf version *.o
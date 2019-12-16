hppsrc = $(wildcard include/*.hpp)
OS := $(shell uname)

ifeq ($(OS), Darwin)
	# Check if its in MAC OS
	LDFLAGS = -framework OpenGl -lglfw -lGLEW
else
	# Check if its Linux
	LDFLAGS = -lGL -lglut -lGLEW -lglfw 
endif

all: TriBuffer

TriangleBuffer.o: TriangleBuffer.cpp $(hppsrc)
	g++ -Wall -c TriangleBuffer.cpp $(LDFLAGS)

TriBuffer: TriangleBuffer.o
	g++ -Wall -o TriBuffer TriangleBuffer.o $(LDFLAGS)

clean:
	rm -rf *.o TriBuffer
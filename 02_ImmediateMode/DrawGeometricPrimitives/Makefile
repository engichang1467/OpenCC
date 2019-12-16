OS := $(shell uname)

ifeq ($(OS), Darwin)
	# Check if its in MAC OS
	LDFLAGS = -framework OpenGl -lglfw -lGLEW
else
	# Check if its Linux
	LDFLAGS = -lGL -lglut -lGLEW -lglfw 
endif

all: immediate

immediate.o: immediate.cpp
	g++ -Wall -c immediate.cpp $(LDFLAGS)

immediate: immediate.o
	g++ -Wall -o immediate immediate.o $(LDFLAGS)

clean:
	rm -rf immediate *.o
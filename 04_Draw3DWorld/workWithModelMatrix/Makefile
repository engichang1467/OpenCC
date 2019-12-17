hppsrc = $(wildcard include/*.hpp)
OS := $(shell uname)

ifeq ($(OS), Darwin)
	# Check if its in MAC OS
	LDFLAGS = -framework OpenGl -lglfw -lGLEW
else
	# Check if its Linux
	LDFLAGS = -lGL -lglut -lGLEW -lglfw 
endif

all: Model

Model.o: Model.cpp $(hppsrc)
	g++ -Wall -c Model.cpp $(LDFLAGS)

Model: Model.o
	g++ -Wall -o Model Model.o $(LDFLAGS)

clean:
	rm -rf *.o Model
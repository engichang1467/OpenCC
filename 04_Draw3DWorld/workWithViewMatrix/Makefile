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

ModelView.o: ModelView.cpp $(hppsrc)
	g++ -Wall -c ModelView.cpp $(LDFLAGS)

Model: ModelView.o
	g++ -Wall -o Model ModelView.o $(LDFLAGS)

clean:
	rm -rf *.o Model
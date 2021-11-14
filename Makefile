SOURCES= main.c render.c render.h rmath.c rmath.h

EXECUTABLE=main

LDFLAGS=

CC=gcc
CFLAGS=-c -Wall
OBJECTS=$(SOURCES:.c=.o)

ifdef DEBUG
CFLAGS += -ggdb -O0
else
CFLAGS += -O2
endif

all: build

build: $(SOURCES) $(EXECUTABLE)
        

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -lm -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -lm -o $@

clean:
	rm -rf $(EXECUTABLE) *.o

.PHONY: clean all build

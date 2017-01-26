CC := gcc
CFLAGS := -Wall
SOURCES := sqrt.h sqrt.c 
OUTPUT_FILE := a.out
LDLIBS := -lm 
build: $(SOURCES)
	$(CC) $(CFLAGS) -o $(OUTPUT_FILE) $(SOURCES) $(LDLIBS)

clean:
	rm -f $(OUTPUT_FILE)

rebuild: clean build

all: build


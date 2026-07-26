.PHONY: all clean # .PHONY targets necessary b/c don't want make to think these are files

SOURCES = src/main.c src/parser.c # add more source files here

all: bin/newShell # assign main target for makefil ("all" is convention)

bin: # create bin folder if doesn't already exist
	mkdir -p bin 

bin/newShell: bin src/main.c # depends on bin already existing and src/main.c being there
	gcc $(SOURCES) -o bin/newShell

clean:
	rm -f bin/newShell

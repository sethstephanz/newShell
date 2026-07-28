.PHONY: all clean debug # .PHONY targets necessary b/c don't want make to think these are files

SOURCES = src/main.c src/parser.c src/command.c # add more source files here

all: bin/newShell # assign main target for makefile ("all" is convention)

debug: bin/newShell_debug

bin: # create bin folder if doesn't already exist
	mkdir -p bin 

bin/newShell: bin $(SOURCES) # depends on bin already existing and src/main.c being there
	gcc $(SOURCES) -o bin/newShell

bin/newShell_debug: bin $(SOURCES)
	gcc -g $(SOURCES) -o bin/newShell_debug

clean: # if make creates it, make clean should destroy it
	rm -rf bin

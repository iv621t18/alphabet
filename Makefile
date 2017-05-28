all: bin/kursach

.PHONY: all clean mkdir

mkdir:
	mkdir bin

bin/kursach: src/main.c src/sort.c src/menu.c src/vvod.c 
	gcc src/main.c src/sort.c src/menu.c src/vvod.c src/file.c -o bin/kursach
clean: 
	rm -rf bin

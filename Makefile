all: alphabet

alphabet: checkdir build/src/sort.o build/src/main.o
	gcc -Wall -Werror build/src/sort.o build/src/main.o -o bin/alphabet -g
build/src/sort.o: checkdir src/sort.c
	gcc -I src -Wall -Werror -c src/sort.c -o build/src/sort.o -g
build/src/main.o: checkdir src/main.c
	gcc -I src -Wall -Werror -c src/main.c -o build/src/main.o -g


.PHONY: clean checkdir test

clean:
	rm -rf bin build
checkdir:
	mkdir -p bin build build/test build/src

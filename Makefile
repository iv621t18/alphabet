all: alphabet

alphabet: checkdir build/src/sort.o build/src/main.o
	gcc -Wall -Werror build/src/sort.o build/src/main.o -o bin/alphabet -g
build/src/sort.o: checkdir src/sort.c
	gcc -I src -Wall -Werror -c src/sort.c -o build/src/sort.o -g
build/src/main.o: checkdir src/main.c
	gcc -I src -Wall -Werror -c src/main.c -o build/src/main.o -g

bin/test_alphabet: checkdir build/test/sort_test.o build/test/main.o build/src/sort.o 
	gcc -I thirdparty -Wall -Werror build/test/sort_test.o build/test/main.o build/src/sort.o -o bin/test_alphabet
build/test/sort_test.o: checkdir test/sort_test.c
	gcc -I src -I thirdparty -Wall -Werror -c test/sort_test.c -o build/test/sort_test.o
build/test/main.o: checkdir test/main.c
	gcc -I thirdparty -c test/main.c -o build/test/main.o


.PHONY: clean checkdir test

test: bin/test_alphabet
	bin/test_alphabet

clean:
	rm -rf bin build
checkdir:
	mkdir -p bin build build/test build/src
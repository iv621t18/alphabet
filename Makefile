all: bin/alphabet

bin/alphabet: mkdir build/src/enter.o build/src/file.o build/src/menu.o build/src/sort.o build/src/main.o
	gcc -Wall -Werror build/src/enter.o build/src/file.o build/src/menu.o build/src/sort.o build/src/main.o -o bin/alphabet
build/src/enter.o: src/enter.c mkdir
	gcc -I src -Wall -Werror -c src/enter.c -o build/src/enter.o
build/src/file.o: src/file.c mkdir
	gcc -I src -Wall -Werror -c src/file.c -o build/src/file.o
build/src/menu.o: src/menu.c mkdir
	gcc -I src -Wall -Werror -c src/menu.c -o build/src/menu.o
build/src/sort.o: src/sort.c mkdir
	gcc -I src -Wall -Werror -c src/sort.c -o build/src/sort.o
build/src/main.o: src/main.c mkdir
	gcc -I src -Wall -Werror -c src/main.c -o build/src/main.o

bin/test_alphabet: mkdir build/src/sort.o build/test/sort_test.o build/test/main.o
	gcc -I src -I thirdparty -Wall -Werror build/src/sort.o build/test/sort_test.o build/test/main.o -o bin/test_alphabet
build/test/sort_test.o: mkdir test/sort_test.c
	gcc -I src -I thirdparty -Wall -Werror -c test/sort_test.c -o build/test/sort_test.o
build/test/main.o: mkdir test/main.c
	gcc -I thirdparty -Wall -Werror -c test/main.c -o build/test/main.o

.PHONY: clean test

test: bin/test_alphabet
	bin/test_alphabet

mkdir:
	mkdir -p bin
	mkdir -p build
	mkdir -p build/src
	mkdir -p build/test
clean: 
	rm -rf bin build
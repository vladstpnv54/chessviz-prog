all: bin  bin/chessviz bin/chessviz-test

bin:
	mkdir -p bin
bin/chessviz: build/src/main.o build/src/board_print_plain.o build/src/board.o
	gcc -Wall -Werror build/src/main.o build/src/board_print_plain.o build/src/board.o -o bin/chessviz

build/src/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/src/main.o

build/src/board_print_plain.o: src/board_print_plain.c
	gcc -Wall -Werror -c src/board_print_plain.c -o build/src/board_print_plain.o

build/src/board.o: src/board.c
	gcc -Wall -Werror -c src/board.c -o build/src/board.o


bin/chessviz-test: build/test/main.o build/test/board_test.o build/src/board.o build/src/board_print_plain.o
	gcc -Wall -Werror build/test/main.o build/test/board_test.o build/src/board.o build/src/board_print_plain.o -o bin/chessviz-test

build/test/main.o: test/main.c
	gcc -I thirdparty -Wall -Werror -c test/main.c -o build/test/main.o

build/test/board_test.o: test/board_test.c
	gcc -I thirdparty -Wall -Werror -c test/board_test.c -o build/test/board_test.o

.PHONY: clean

clean:
	rm -rf build/src/*.o && rm -rf build/test/*.o

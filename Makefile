all: bin/chessviz

bin/chessviz: build/main.o build/board_print_plain.o build/board.o
	gcc -Wall -Werror build/main.o build/board_print_plain.o build/board.o -o bin/chessviz

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o

build/board_print_plain.o: src/board_print_plain.c
	gcc -Wall -Werror -c src/board_print_plain.c -o build/board_print_plain.o

build/board.o: src/board.c
	gcc -Wall -Werror -c src/board.c -o build/board.o

.PHONY: clean

clean:
	rm -rf build/*.o

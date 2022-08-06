all: main

main: main.c ./lib/*/*
	gcc main.c -lncurses -o main

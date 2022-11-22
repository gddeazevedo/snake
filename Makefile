all: src/*/*.h src/*/*.c main.c
	cc src/*/*.h src/*/*.c main.c -lncurses -o run

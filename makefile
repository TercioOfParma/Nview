all:
	gcc	-c	main.h
	gcc	-c	init.c
	gcc	-o	nview	main.c	init.o	-lncurses

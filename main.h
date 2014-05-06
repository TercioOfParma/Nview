#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int init(char colorscheme);
void deinit();
void openfile(char *filename);
char decide_scheme(char *inp);

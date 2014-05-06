#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif
#define MAXSIZE stdscr->_maxx * stdscr->_maxy



int init(char colorscheme)
{
	initscr();
	noecho();
	cbreak();
	start_color();

	if(colorscheme == 'b')
		{
		init_pair(1, COLOR_BLUE, COLOR_BLACK);
		}
	if(colorscheme == 'r')
		{
		init_pair(1, COLOR_RED, COLOR_BLACK);
		}
	if(colorscheme == 'a')
		{
		init_pair(1, COLOR_CYAN, COLOR_BLACK);
		}
	if(colorscheme == 'w')
		{
		init_pair(1, COLOR_WHITE, COLOR_BLACK);
		}
	if(colorscheme == 'p')
		{
		init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
		}
	if(colorscheme == 'y')
		{
		init_pair(1, COLOR_YELLOW, COLOR_BLACK);
		}
	if(colorscheme == 'g')
		{
		init_pair(1, COLOR_GREEN, COLOR_BLACK);
		}



	return 0;
}

void deinit()
{
	endwin();
	exit(0);


}
void openfile(char *filename)
{
	FILE *opened = fopen(filename, "r");
	char *file = malloc(sizeof(char) * MAXSIZE);
	if(!opened)
	{
		attron(COLOR_PAIR(1));
		printw("This file is invalid or doesn't exist, please try another file");
		getch();
		deinit();
	}
	int selectchar = 0;
	char createdchar;
	int filecount = 0;
	int spacecount = 0;
	attron(COLOR_PAIR(1));
	attron(A_BOLD);
	while(1 == 1)
	{
		selectchar = fgetc(opened);
		if(filecount > MAXSIZE + 1)
		{
			printw("Your file is too big for ncat, try again when we implement scrolling, %d bytes",filecount );
			getch();
			deinit();
		}
		if(selectchar == 4 || selectchar == -1)
		{
			break;
		}
		filecount++;
		if(selectchar != -1)
		{
		createdchar = selectchar;

		}
		else
		{
			break;
		}
		strncat(file, &createdchar, 1);

	}
	fclose(opened);

	while(spacecount < MAXSIZE)
	{
		addch(' ');
		spacecount++;
	}
	move(0,0);
	printw(file);

	getch();



}

char decide_scheme(char *inp)
{
	if(strstr(inp,"a") || strstr(inp,"A"))
	{
		return 'a';
	}
	else if(strstr(inp,"b") || strstr(inp,"B"))
	{
		return 'b';
	}
	else if(strstr(inp,"g") || strstr(inp,"G"))
	{
		return 'g';
	}
        else if(strstr(inp,"r") || strstr(inp,"R"))
        {
                return 'r';
        }
        else if(strstr(inp,"W") || strstr(inp,"w"))
        {
                return 'w';
        }

        else if(strstr(inp,"y") || strstr(inp,"Y"))
        {
                return 'y';
        }
        else if(strstr(inp,"p") || strstr(inp,"P"))
        {
                return 'p';
        }

	else
	{
		return 'g';
	}

}



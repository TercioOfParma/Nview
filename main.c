#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif



int main(int argc, char* argv[])
{
	if(argv[2])
	{

		char dat;
		dat = decide_scheme(argv[2]);//generates text colour based on the command-line args
		init(dat);
	}
	else
	{
		init('g');
	}
	if(argv[1])
	{

		openfile(argv[1]);//speaks for itself, see the subroutine
	}
	else
	{
		attron(COLOR_PAIR(1));
		printw("You need a file to open for this to work");
		getch();
		deinit();

	}
	deinit();




	return 0;
}

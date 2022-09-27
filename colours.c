// Este fichero se le da al alumno
#include <stdio.h>
#include "colours.h"

// http://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
// http://ascii-table.com/ansi-escape-sequences.php

/*
 * Dado un color (-1-DEFAULT (color por defecto),  0-RED, 1-GREEN, 2-YELLOW, 
 * 3-BLUE, 4-MAGENTA,  5-CYAN) hace que el terminal a partir de ahora escriba 
 * en ese color
 */
void cambiar_color(int color) 
{
	switch (color) 
	{
		case -1: 
			printf(ANSI_COLOR_RESET ); 
			break;
		case  0: 
			printf(ANSI_COLOR_RED    ); 
			break;
		case  1: 
			printf(ANSI_COLOR_GREEN  ); 
			break;
		case  2: 
			printf(ANSI_COLOR_YELLOW ); 
			break;
		case  3: 
			printf(ANSI_COLOR_BLUE   ); 
			break;
		case  4: 
			printf(ANSI_COLOR_MAGENTA); 
			break;
		case  5: 
			printf(ANSI_COLOR_CYAN   ); 
			break;
	}
}


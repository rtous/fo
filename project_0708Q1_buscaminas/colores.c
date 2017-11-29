// Este fichero se le da al alumno
#include <stdio.h>
#include "colores.h"

// http://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
// http://ascii-table.com/ansi-escape-sequences.php

/*
 * Dado un numero del 0 al 9 hace que el terminal escriba en un color diferente
 * cada numero. Si el numero es '-1' resetea el color al por defecto.
 */
void printf_color(int color) {
	switch (color) {
		case -1: printf(ANSI_COLOR_RESET  ); break;
		case  0: printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_WHITE  ); break;
		case  1: printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_RED    ); break;
		case  2: printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_GREEN  ); break;
		case  3: printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_YELLOW ); break;
		case  4: printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_BLUE   ); break;
		case  5: printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_MAGENTA); break;
		case  6: printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_CYAN   ); break;

		case  7: printf(ANSI_COLOR_RED    ); break;
		case  8: printf(ANSI_COLOR_GREEN  ); break;
		case  9: printf(ANSI_COLOR_YELLOW ); break;
	}
}

/*
 * Hace que el terminal a partir de ahora escriba en el color por defecto
 */
void printf_reset_color() {
	printf_color(-1);
}

/*
void clear_screen() {
	printf("\e[1;1H\e[2J");
}
*/


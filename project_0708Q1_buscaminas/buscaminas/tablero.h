#ifndef TABLERO_H
#define TABLERO_H

#include "casilla.h"

#define MAX_F	36
#define MAX_C	36

typedef struct {
	int nfils;
	int ncols;
	t_casilla cas[MAX_F][MAX_C];
	int num_minas;
	int cas_tapadas;
	int num_minas_marcadas;
	int ha_explotado;
	int tiempo_inicial;
} t_tablero;

void imprimir_tablero(t_tablero t);
void levantar_todas(t_tablero *pt);
void inicializar_tablero(t_tablero *pt, int nfils, int ncols, int minas);
void realizar_jugada_en_tablero(t_tablero *p_t, int f, int c, char accion);

#endif // TABLERO_H


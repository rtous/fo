#ifndef CASILLA_H
#define CASILLA_H

#define TRUE	1
#define FALSE	0

#define DESTAPADA	0
#define TAPADA	1
#define MARCADA_MINA	2
#define MARCADA_DUDA	3

typedef struct {
	char bomba;	// TRUE or FALSE
	int estado; // DESTAPADA, TAPADA, MARCADA_MINA, MARCADA_DUDA
	int num_minas_adyacentes;
} t_casilla;

void imprimir_casilla(t_casilla c);

#endif // CASILLA_H


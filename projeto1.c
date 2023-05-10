/*============================================================================*/
/* CSF13 - 2021-1 - PROJETO 1                                                 */
/*----------------------------------------------------------------------------*/
/* Bogdan T. Nassu - btnassu@utfpr.edu.br                                     */
/* Leyza E. B. Dorini - leyza@utfpr.edu.br                                    */
/*============================================================================*/
/** Funções auxiliares para o 1o projeto da disciplina Fundamentos de
 * Programação 1, 1o semestre de 2021, prof. Bogdan T. Nassu e Leyza E. B.
 * Dorini, Universidade Tecnológica Federal do Paraná - Câmpus Curitiba. */
/*============================================================================*/

#include <stdio.h>
#include <stdlib.h>

#include "projeto1.h"

/*============================================================================*/
/* ANTENAS                                                                    */
/*============================================================================*/
/* Tipos internos. */

typedef struct
{
    float x;
    float y;
} Coordenada;

Coordenada* antenas; /* Esta variável é global somente para isolar parte do trabalho dos alunos. */

/*----------------------------------------------------------------------------*/
/** Funções para manipular o vetor de antenas. */

void criaVetorAntenas (int tamanho)
{
    antenas = (Coordenada*) malloc (sizeof (Coordenada) * tamanho);
}

void destroiVetorAntenas ()
{
    free (antenas);
}

void adicionaAntena (int pos, float x, float y)
{
    antenas [pos].x = x;
    antenas [pos].y = y;
}

void mostraAntenas (int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf ("(%.4f,%.4f)\n", antenas [i].x, antenas [i].y);
}

float pegaX (int a) {return (antenas [a].x);}
float pegaY (int a) {return (antenas [a].y);}

/*============================================================================*/

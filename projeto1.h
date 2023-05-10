/*============================================================================*/
/* CSF13 - 2021-1 - PROJETO 1                                                 */
/*----------------------------------------------------------------------------*/
/* Bogdan T. Nassu - btnassu@utfpr.edu.br                                     */
/* Leyza E. B. Dorini - leyza@utfpr.edu.br                                    */
/*============================================================================*/
/** Funções pedidas e auxiliares para o 1o projeto da disciplina Fundamentos de
 * Programação 1, 1o semestre de 2021, prof. Bogdan T. Nassu e Leyza E. B.
 * Dorini, Universidade Tecnológica Federal do Paraná - Câmpus Curitiba. */
/*============================================================================*/

#ifndef __PROJETO1_H
#define __PROJETO1_H

/*============================================================================*/
/* Função do projeto. */

unsigned int definePontoDeAcesso (int n_antenas);

/*----------------------------------------------------------------------------*/
/* Funções auxiliares que DEVEM ser chamadas pelos alunos. */

float pegaX (int a);
float pegaY (int a);

/*----------------------------------------------------------------------------*/
/* Funções auxiliares que NÃO DEVEM ser chamadas pelos alunos. */

void criaVetorAntenas (int tamanho);
void destroiVetorAntenas ();
void adicionaAntena (int pos, float x, float y);
void mostraAntenas (int n);

/*============================================================================*/
#endif /* __PROJETO1_H */

/*============================================================================*/
/* CSF13 - 2021-1 - PROJETO 1                                                 */
/*----------------------------------------------------------------------------*/
/* Bogdan T. Nassu - btnassu@utfpr.edu.br                                     */
/* Leyza E. B. Dorini - leyza@utfpr.edu.br                                    */
/*============================================================================*/
/** Teste autom�tico para a fun��o definePontoDeAcesso, do 1o projeto da
 * disciplina CSF13 (Fundamentos de Programa��o 1), 1o semestre de 2021, prof.
 * Bogdan T. Nassu e Leyza E. B. Dorini, Universidade Tecnol�gica Federal do
 * Paran� - C�mpus Curitiba. */
/*============================================================================*/

#include <stdio.h>
#include <float.h>

#include "projeto1.h"

/*============================================================================*/

#define ARQUIVO_ANTENAS "teste_antenas2.txt" /* Arquivo contendo dados para teste. */
#define MOSTRA_ANTENAS 0 /* Flag que diz se as antenas deem ser mostradas em caso de erro. */

/*============================================================================*/

int main()
{
    int n_testes, n_antenas, n_erros=0;
    int i_teste, i_antena;
    unsigned int resposta, resposta_esperada;
    FILE* in_file;

    /* Abre o arquivo contendo os dados. */
    in_file = fopen (ARQUIVO_ANTENAS, "r");
    if (!in_file)
        printf ("Nao foi possivel abrir o arquivo %s!\n", ARQUIVO_ANTENAS);

    /* Para cada teste... */
    fscanf (in_file, "%d", &n_testes);
    for (i_teste = 0; i_teste < n_testes; i_teste++)
    {
        /* Para cada antena... */
        fscanf (in_file, "%d", &n_antenas);
        criaVetorAntenas (n_antenas);
        for (i_antena = 0; i_antena < n_antenas; i_antena++)
        {
            /* L� e adiciona. */
            float x, y;
            fscanf (in_file, "%f %f", &x, &y);
            adicionaAntena (i_antena, x, y);
        }

        /* Pronto, agora podemos testar. */
        fscanf (in_file, "%u", &resposta_esperada);
        resposta = definePontoDeAcesso (n_antenas);

        if (resposta != resposta_esperada)
        {
            n_erros++;
            printf ("Erro no teste %d.\nEsperava 0x%x, calculou 0x%x.\n", i_teste, resposta_esperada, resposta);
            if (MOSTRA_ANTENAS)
            {
                printf ("Antenas:\n");
                mostraAntenas (n_antenas);
            }
            printf ("Pressione [ENTER] para continuar.");
            getchar ();
        }

        destroiVetorAntenas ();
    }

    if (!n_erros)
        printf ("%d testes realizados sem erro.\n", n_testes);
    else
        printf ("%d erros encontrados em %d testes.\n", n_erros, n_testes);

    fclose (in_file);

    return 0;
}

/*============================================================================*/

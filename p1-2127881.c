
#include <stdio.h>
#include <math.h>
#include "projeto1.h"
unsigned int definePontoDeAcesso (int n_antenas){
    int i,j,ponto_acesso,resultado;
    float coordx_ant, coordx_atual,coordy_ant,coordy_atual,distancia,maior_distancia=0,menor_distancia;
    /*Como se trata da distancia entre dois pontos foi criada a distancia anterior e atual,tanto de x como de y*/
    for(i=0;i<n_antenas;i++){
        coordx_ant=pegaX(i);
        coordy_ant=pegaY(i);//H� a primeira chamada da fun��o para armazenar os valores de x e y
        for(j=0;j<n_antenas;j++){
            coordx_atual=pegaX(j);
            coordy_atual=pegaY(j);//Depois chama-se de novo para a compara��o da anterior com a atual
            distancia=pow(coordx_ant-coordx_atual,2.0)+pow(coordy_ant-coordy_atual,2.0);
            distancia=sqrt(distancia);//na linha 14 e 15 h� o c�lculo entre dois pontos cartesianos
             if(distancia>maior_distancia){//Caso a dist�ncia calculada seja maior encontrada ela � guardada na variavel maior_distancia
                maior_distancia=distancia;
            }
        }
        if(maior_distancia<menor_distancia || i==0){//� preciso que no primeiro loop o valor encontrado entre por isso o "ou" quando i=0
            menor_distancia=maior_distancia;// se encontrado a menor dist�ncia entre as maiores dist�ncias ele armazena a dist�ncia e o ponto de acesso
            ponto_acesso=i;
        }
        maior_distancia=0;// � preciso zerar a vari�vel para ser usado em todos os outros loops
    }
    resultado=ponto_acesso<<24;
    resultado=resultado | (int)menor_distancia;
    /*Como � preciso passar dois valores por par�metro transforma o ponto de acesso em bin�rio usando o operador "<<" para deixar os
    24 bits menos significativos livres ou seja, igual a zero. Depois � s� passar a dist�ncia pelo operador l�gico "|" que ir� completar
    com a dist�ncia o resultado */
    return resultado;
}

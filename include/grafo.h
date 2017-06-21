#ifndef GRAFO_H
#define GRAFO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#endif

typedef struct Grafo *Graf;


Graf cria_grafo (char *nome); /*retorna estrutura de dados grafo que tem um nome*/
char *retorna_nome_grafo(Graf); /*retorna o nome do grafo G*/
void destroi_grafo(Graf); /*destrói grafo g*/
void adjacente(Graf, int x, int y); /*verifica se x e y sao adjacentes em G*/
struct Vertice *vizinhos(Graf, int x); /*retorna lista de todos os vértices que podem ser visitados a partir de x (existe uma aresta que vai de x para este vértice)*/
void adiciona_vertice(Graf, int x); /*adiciona vértice x no grafo G*/
void remove_vertice(Graf, int x); /*remove vértice x do grafo G*/
void adiciona_aresta(Graf, int x, int y); /*no grafo G adiciona uma aresta de x para y*/
void remove_aresta(Graf, int x, int y); /*remove a aresta que vai de x para y*/
float retorna_valor_vertice(Graf, int x); /*retorna o valor associado com o vértice x*/
void muda_valor_vertice(Graf, int x, int val); /*coloca valor v no vértice x em G*/
float retorna_valor_aresta(Graf, int x, int y); /*retorna valor da aresta x,y em G*/
void muda_valor_aresta(Graf, int x, int y, int val); /*coloca o valor v na aresta x,y em G*/

/*Funções auxiliares para manipulação do grafo e ececução dos testes*/
void visualiza_grafo(Graf g);
int posicao_do_vertice(Graf xis, int aux_vert);
float **estrut_matriz_alocacao(float **estr_mat, int componente);
float **estrut_matriz_realocacao(float **estr_mat, int componente);
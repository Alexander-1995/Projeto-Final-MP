#include "grafo.h"

int main(){

	Graf aux5;

	printf("--------------------------------\n");
	printf("Teste 1 - cria_grafo(char *nome)\n");
	printf("--------------------------------\n");

	Graf aux = cria_grafo("MP Grafo 1");
	visualiza_grafo(aux);
	Graf aux2 = cria_grafo("MP Grafo 2");
	visualiza_grafo(aux2);
	printf("\nPressione qualquer tecla para continuar...");
	getchar();

	printf("\n\n------------------------------\n");
	printf("Teste 2 - retorna_nome_grafo(Graf)\n");
	printf("----------------------------------\n");

	puts(retorna_nome_grafo(aux));
	puts(retorna_nome_grafo(aux2));
	printf("\nPressione qualquer tecla para continuar...");
	getchar();

	printf("\n\n-----------------------------------\n");
	printf("Teste 3 - adiciona_vertice(Graf, int x)\n");
	printf("---------------------------------------\n");

	adiciona_vertice(aux,1);
	adiciona_vertice(aux,1);
	visualiza_grafo(aux);
	printf("\n");
	adiciona_vertice(aux2,1); adiciona_vertice(aux2,2); adiciona_vertice(aux2,3);
	adiciona_vertice(aux2,4); adiciona_vertice(aux2,5); adiciona_vertice(aux2,6);
	adiciona_vertice(aux2,7); adiciona_vertice(aux2,8);
	visualiza_grafo(aux2);
	printf("\nPressione qualquer tecla para continuar...");
	getchar();

	printf("\n\n---------------------------------\n");
	printf("Teste 4 - remove_vertice(Graf, int x)\n");
	printf("-------------------------------------\n");

	remove_vertice(aux2, 2);
	remove_vertice(aux2, 5);                     
	remove_vertice(aux2, 7);
	visualiza_grafo(aux2);
	printf("\nPressione qualquer tecla para continuar...");
	getchar();

	printf("\n\n-----------------------------------------\n");
	printf("Teste 5 - adiciona_aresta(Graf, int x, int y)\n");
	printf("---------------------------------------------\n");

	adiciona_aresta(aux2, 2, 3); adiciona_aresta(aux2, 7, 5); adiciona_aresta(aux2, 4, 2);
	adiciona_aresta(aux2, 3, 6); adiciona_aresta(aux2, 1, 8); adiciona_aresta(aux2, 4, 8);
	adiciona_aresta(aux2, 1, 4); adiciona_aresta(aux2, 6, 3); adiciona_aresta(aux2, 8, 1);
	adiciona_aresta(aux2, 4, 3); adiciona_aresta(aux2, 3, 1); adiciona_aresta(aux2, 8, 4);
	adiciona_aresta(aux2, 1, 1); adiciona_aresta(aux2, 8, 8); adiciona_aresta(aux2, 6, 6);
	visualiza_grafo(aux2);
	printf("\nPressione qualquer tecla para continuar...");
	getchar();

	printf("\n\n---------------------------------------\n");
	printf("Teste 6 - remove_aresta(Graf, int x, int y)\n");
	printf("-------------------------------------------\n");

	remove_aresta(aux2, 4, 3);
	remove_aresta(aux2, 1, 8);
	remove_aresta(aux2, 8, 4);
	/*remove_aresta(aux2, 7, 7);                    se colocar uma aresta que não existe dá segementation fault*/
	visualiza_grafo(aux2);
	printf("\nPressione qualquer tecla para continuar...");
	getchar();

	printf("\n\n----------------------------------------------\n");
	printf("Teste 7 - muda_valor_vertice(Graf, int x, int val)\n");
	printf("--------------------------------------------------\n");

	muda_valor_vertice(aux2, 4, 7);
	muda_valor_vertice(aux2, 3, 1);
	muda_valor_vertice(aux2, 8, 9);
	visualiza_grafo(aux2);
	printf("\nPressione qualquer tecla para continuar...");
	getchar();

	printf("\n\n----------------------------------------------------\n");
	printf("Teste 8 - muda_valor_aresta(Graf, int x, int y, int val)\n");
	printf("--------------------------------------------------------\n");

	muda_valor_aresta(aux2, 1, 1, 5);
	muda_valor_aresta(aux2, 6, 6, 9);
	muda_valor_aresta(aux2, 8, 8, 7);
	muda_valor_aresta(aux2, 3, 1, 2);
	visualiza_grafo(aux2);
	printf("\nPressione qualquer tecla para continuar...");
	getchar();

	printf("\n\n----------------------------------------\n");
	printf("Teste 9 - retorna_valor_vertice(Graf, int x)\n");
	printf("--------------------------------------------\n");

	printf("Valor do vértice 7: %.f\n", retorna_valor_vertice(aux2, 7));
	printf("Valor do vértice 1: %.f\n", retorna_valor_vertice(aux2, 1));
	printf("Valor do vértice 8: %.f\n", retorna_valor_vertice(aux2, 8));
	printf("Valor do vértice 4: %.f\n", retorna_valor_vertice(aux2, 4));
	visualiza_grafo(aux2);
	printf("\nPressione qualquer tecla para continuar...");
	getchar();

	printf("\n\n-----------------------------------------------\n");
	printf("Teste 10 - retorna_valor_aresta(Graf, int x, int y)\n");
	printf("---------------------------------------------------\n");

	printf("Valor da aresta: %.f\n", retorna_valor_aresta(aux2, 3, 1));
	printf("Valor da aresta: %.f\n", retorna_valor_aresta(aux2, 1, 1));
	printf("Valor da aresta: %.f\n", retorna_valor_aresta(aux2, 8, 8));
	printf("Valor da aresta: %.f\n", retorna_valor_aresta(aux2, 6, 6));
	visualiza_grafo(aux2);
	printf("\nPressione qualquer tecla para continuar...");
	getchar();

	printf("\n\n------------------------------------\n");
	printf("Teste 11 - adjacente(Graf, int x, int y)\n");
	printf("----------------------------------------\n");

	adjacente(aux2, 1, 3);
	visualiza_grafo(aux2);
	printf("\nPressione qualquer tecla para continuar...");
	getchar();

	printf("\n\n-------------------------------------\n");
	printf("Teste 12 - Vertice *vizinhos(Graf, int x)\n");
	printf("-----------------------------------------\n");

	printf("Os vizinhos do vértice 1 são:\n");
	vizinhos(aux2, 1);
	printf("Os vizinhos do vértice 6 são:\n");
	vizinhos(aux2, 6);
	printf("Os vizinhos do vértice 4 são:\n");
	vizinhos(aux2, 4);	
	visualiza_grafo(aux2);
	printf("\nPressione qualquer tecla para continuar...");
	getchar();

	printf("\n\n-------------------------------------\n");
	printf("Teste 13 - destroi_grafo(Graf)\n");
	printf("-----------------------------------------\n");

	destroi_grafo(aux2);
	destroi_grafo(aux);
	visualiza_grafo(aux2);
	printf("\n");
	visualiza_grafo(aux);
	printf("\n");
	destroi_grafo(aux5);
	printf("\nPressione qualquer tecla para continuar...");
	getchar();

	return (0);
}
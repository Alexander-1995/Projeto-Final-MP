#include "grafo.h"

void menu_principal();
void menu_adm();
void menu_usr();

int opcao=0;

int main(int argc, char const *argv[]){

menu_principal();

return(0);
}

void menu_principal(){
char nome[20];

Graf aux5;

while(opcao != 3){
	system("clear");
	printf("---------------------------------------\n");
	printf("Rede Social para Economia Compartilhada\n");
	printf("---------------------------------------\n");
	printf("\n1-Usuário\n");
	printf("2-Administrador\n");
	printf("3-Sair do sistema\n");
	printf("\n\nDigite a opção desejada:");
	scanf("%d", &opcao);
	getchar();

	switch(opcao){
		case 1:
			menu_usr();
			break;
		case 2:
			menu_adm();
			break;
		case 3:
			exit(0);
			break;
	}
}
}

void menu_usr(){
char * nome;
opcao = 0;
				while(opcao != 6){
		 		 system("clear");
		 		 printf("---------------------------------------\n");
				 printf("Rede Social para Economia Compartilhada\n");
		 		 printf("---------------------------------------\n\n");
		 		 printf("***************Usuário*****************\n\n");
		 		 printf("1-Criar pessoa\n");
		 		 printf("2-Editar pessoa, todos os dados inclusive amizades\n");
		 		 printf("3-Excluir pessoa\n");
		 		 printf("4-Procurar por uma transação de acordo com os critérios desejados\n");
		 		 printf("5-Fazer uma transação e as avaliações\n");
		 		 printf("6-Voltar para tela inicial.\n");
		 		 printf("\n\nDigite a opção desejada:");
				 scanf("%d", &opcao);
				 getchar();

				 if(opcao == 1){
				 	printf("Digite o nome da pessoa:");
				 	scanf("%s", nome);
				 	Graf aux = cria_grafo(nome);
				 }
				 
	}
}

void menu_adm(){
	opcao = 0;
				while(opcao != 5){
		 		 system("clear");
		 		 printf("---------------------------------------\n");
		 		 printf("Rede Social para Economia Compartilhada\n");
		 		 printf("---------------------------------------\n\n");
		 		 printf("*************Administrador*************\n\n");
		 		 printf("1-Visualizar as informações das pessoas através de um grafo.\n");
		 		 printf("2-Cadastrar transações.\n");
		 		 printf("3-Descadastrar transações\n");
		 		 printf("4-Saber das transações feitas\n");
		 		 printf("5-Voltar para tela inicial.\n");
		 		 printf("\n\nDigite a opção desejada:");
		 		 scanf("%d", &opcao);
		 		 getchar();
		 		}

}

	/*Graf aux = cria_grafo("MP Grafo 1");
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
	/*visualiza_grafo(aux2);
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
}*/
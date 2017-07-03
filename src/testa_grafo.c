#include "grafo.h"

void menu_principal();
void menu_usr();
void menu_adm();

int opcao = 0;

int main(int argc, char const *argv[]){

	initscr();
	getmaxyx(stdscr, src_rows, src_cols);

	bkgd(COLOR_PAIR(2));

	start_color();

    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    init_pair(2,COLOR_BLUE,COLOR_WHITE);
    init_pair(3,COLOR_RED,COLOR_WHITE);

    curs_set(0);
    noecho();
    keypad(stdscr,TRUE);

menu_principal();

return 0;
}

void menu_principal(){

	clear();
	while(opcao != 3){
		printw("---------------------------------------\n");
		printw("Rede Social para Economia Compartilhada\n");
		printw("---------------------------------------\n");
		printw("\n1-Usuário\n");
		printw("2-Administrador\n");
		printw("3-Sair do sistema\n");
		printw("\n\nDigite a opção desejada:");
		refresh();	
		scanw("%d", &opcao);
		printw("%d\n", opcao);
	
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

	clear();
	printw("---------------------------------------\n");
	printw("Rede Social para Economia Compartilhada\n");
	printw("---------------------------------------\n\n");
	printw("***************Usuário*****************\n\n");
	printw("1-Criar pessoa\n");
	printw("2-Editar pessoa, todos os dados inclusive amizades\n");
	printw("3-Excluir pessoa\n");
	printw("4-Procurar por uma transação de acordo com os critérios desejados\n");
	printw("5-Fazer uma transação e as avaliações\n");
	printw("6-Voltar para tela inicial.\n");
	printw("\n\nDigite a opção desejada:");
	refresh();
	opcao = getch();

	menu_principal();

}
				 
void menu_adm(){

	clear();
	printw("---------------------------------------\n");
	printw("Rede Social para Economia Compartilhada\n");
	printw("---------------------------------------\n\n");
	printw("*************Administrador*************\n\n");
	printw("1-Visualizar as informações das pessoas através de um grafo.\n");
	printw("2-Cadastrar transações.\n");
	printw("3-Descadastrar transações\n");
	printw("4-Saber das transações feitas\n");
	printw("5-Voltar para tela inicial.\n");
	printw("\n\nDigite a opção desejada:");
	refresh();			
	opcao = getch();

	menu_principal();
}


// gui_ret inicializa_interface(){
// 	if(!esta_inicializada){
// 		esta_inicializada = true;
// 		//inicialza a interface
// 		initscr();

// 		//"pega" os parametros da tela
// 		getmaxyx(stdscr, src_rows, src_cols);

// 		bkgd(COLOR_PAIR(2));
// 		//possibilita o uso de cores
// 		start_color();
// 		//definição dos pares
// 		init_pair(1,COLOR_WHITE, COLOR_BLACK);     //Fundo
//     	init_pair(2,COLOR_GREEN, COLOR_WHITE);     //Tarefas concluidas
//     	init_pair(3,COLOR_RED, COLOR_WHITE);       //Tarefas nao começadas
//     	init_pair(4,COLOR_GREEN, COLOR_BLACK);     //MENU 
// 		init_pair(5,COLOR_BLACK, COLOR_WHITE);     //Fundo Gerenciador, contador
//     	return GUI_OK;
// 	}
// 	else
// 		return GUI_ERR;
// }

// gui_ret imprimeMenuNcurses(){
// 	char temp[31], op[10];
// 	int opt = 0;
// 	//===================================
// 	// 1. Criar Tarefas de um Arquivo
// 	// 2. Iniciar Gerenciador
// 	// 3. Sair
// 	//===================================
// 	if(!esta_inicializada){
// 		return GUI_ERR;
// 	}
// 	updateSrcParams();
// 	bkgd(COLOR_PAIR(1));
// 	attron(COLOR_PAIR(4));

// 	mvprintw(1,3,"MENU:");
// 	    mvprintw(3,6,"1. Criar Tarefas de um Arquivo");
// 	    mvprintw(4,6,"2. Definir tempo que deseja visualizar.");
// 	    mvprintw(5,6,"3. Nome do arquivo de saida.");
// 	    mvprintw(6,6,"99. Sair e iniciar Gerenciador");
// 	    mvprintw(7,6,"Digite sua opção:");
// 	    refresh(); 

// 	attroff(COLOR_PAIR(4));
// 	return GUI_OK;
// }

// void updateSrcParams(){
// 	//"atualiza" os parametros da tela
// 	endwin();
// 	initscr();
// 	getmaxyx(stdscr, src_rows, src_cols);
// }


// int main(){

// 	Graf aux5;

// 	printf("--------------------------------\n");
// 	printf("Teste 1 - cria_grafo(char *nome)\n");
// 	printf("--------------------------------\n");

// 	Graf aux = cria_grafo("MP Grafo 1");
// 	visualiza_grafo(aux);
// 	Graf aux2 = cria_grafo("MP Grafo 2");
// 	visualiza_grafo(aux2);
// 	printf("\nPressione qualquer tecla para continuar...");
// 	getchar();

// 	printf("\n\n------------------------------\n");
// 	printf("Teste 2 - retorna_nome_grafo(Graf)\n");
// 	printf("----------------------------------\n");

// 	puts(retorna_nome_grafo(aux));
// 	puts(retorna_nome_grafo(aux2));
// 	printf("\nPressione qualquer tecla para continuar...");
// 	getchar();

// 	printf("\n\n-----------------------------------\n");
// 	printf("Teste 3 - adiciona_vertice(Graf, int x)\n");
// 	printf("---------------------------------------\n");

// 	adiciona_vertice(aux,1);
// 	adiciona_vertice(aux,1);
// 	visualiza_grafo(aux);
// 	printf("\n");
// 	adiciona_vertice(aux2,1); adiciona_vertice(aux2,2); adiciona_vertice(aux2,3);
// 	adiciona_vertice(aux2,4); adiciona_vertice(aux2,5); adiciona_vertice(aux2,6);
// 	adiciona_vertice(aux2,7); adiciona_vertice(aux2,8);
// 	visualiza_grafo(aux2);
// 	printf("\nPressione qualquer tecla para continuar...");
// 	getchar();

// 	printf("\n\n---------------------------------\n");
// 	printf("Teste 4 - remove_vertice(Graf, int x)\n");
// 	printf("-------------------------------------\n");

// 	remove_vertice(aux2, 2);
// 	remove_vertice(aux2, 5);                     
// 	remove_vertice(aux2, 7);
// 	visualiza_grafo(aux2);
// 	printf("\nPressione qualquer tecla para continuar...");
// 	getchar();

// 	printf("\n\n-----------------------------------------\n");
// 	printf("Teste 5 - adiciona_aresta(Graf, int x, int y)\n");
// 	printf("---------------------------------------------\n");

// 	adiciona_aresta(aux2, 2, 3); adiciona_aresta(aux2, 7, 5); adiciona_aresta(aux2, 4, 2);
// 	adiciona_aresta(aux2, 3, 6); adiciona_aresta(aux2, 1, 8); adiciona_aresta(aux2, 4, 8);
// 	adiciona_aresta(aux2, 1, 4); adiciona_aresta(aux2, 6, 3); adiciona_aresta(aux2, 8, 1);
// 	adiciona_aresta(aux2, 4, 3); adiciona_aresta(aux2, 3, 1); adiciona_aresta(aux2, 8, 4);
// 	adiciona_aresta(aux2, 1, 1); adiciona_aresta(aux2, 8, 8); adiciona_aresta(aux2, 6, 6);
// 	visualiza_grafo(aux2);
// 	printf("\nPressione qualquer tecla para continuar...");
// 	getchar();

// 	printf("\n\n---------------------------------------\n");
// 	printf("Teste 6 - remove_aresta(Graf, int x, int y)\n");
// 	printf("-------------------------------------------\n");

// 	remove_aresta(aux2, 4, 3);
// 	remove_aresta(aux2, 1, 8);
// 	remove_aresta(aux2, 8, 4);
// 	/*remove_aresta(aux2, 7, 7);                    se colocar uma aresta que não existe dá segementation fault*/
// 	visualiza_grafo(aux2);
// 	printf("\nPressione qualquer tecla para continuar...");
// 	getchar();

// 	printf("\n\n----------------------------------------------\n");
// 	printf("Teste 7 - muda_valor_vertice(Graf, int x, int val)\n");
// 	printf("--------------------------------------------------\n");

// 	muda_valor_vertice(aux2, 4, 7);
// 	muda_valor_vertice(aux2, 3, 1);
// 	muda_valor_vertice(aux2, 8, 9);
// 	visualiza_grafo(aux2);
// 	printf("\nPressione qualquer tecla para continuar...");
// 	getchar();

// 	printf("\n\n----------------------------------------------------\n");
// 	printf("Teste 8 - muda_valor_aresta(Graf, int x, int y, int val)\n");
// 	printf("--------------------------------------------------------\n");

// 	muda_valor_aresta(aux2, 1, 1, 5);
// 	muda_valor_aresta(aux2, 6, 6, 9);
// 	muda_valor_aresta(aux2, 8, 8, 7);
// 	muda_valor_aresta(aux2, 3, 1, 2);
// 	visualiza_grafo(aux2);
// 	printf("\nPressione qualquer tecla para continuar...");
// 	getchar();

// 	printf("\n\n----------------------------------------\n");
// 	printf("Teste 9 - retorna_valor_vertice(Graf, int x)\n");
// 	printf("--------------------------------------------\n");

// 	printf("Valor do vértice 7: %.f\n", retorna_valor_vertice(aux2, 7));
// 	printf("Valor do vértice 1: %.f\n", retorna_valor_vertice(aux2, 1));
// 	printf("Valor do vértice 8: %.f\n", retorna_valor_vertice(aux2, 8));
// 	printf("Valor do vértice 4: %.f\n", retorna_valor_vertice(aux2, 4));
// 	visualiza_grafo(aux2);
// 	printf("\nPressione qualquer tecla para continuar...");
// 	getchar();

// 	printf("\n\n-----------------------------------------------\n");
// 	printf("Teste 10 - retorna_valor_aresta(Graf, int x, int y)\n");
// 	printf("---------------------------------------------------\n");

// 	printf("Valor da aresta: %.f\n", retorna_valor_aresta(aux2, 3, 1));
// 	printf("Valor da aresta: %.f\n", retorna_valor_aresta(aux2, 1, 1));
// 	printf("Valor da aresta: %.f\n", retorna_valor_aresta(aux2, 8, 8));
// 	printf("Valor da aresta: %.f\n", retorna_valor_aresta(aux2, 6, 6));
// 	visualiza_grafo(aux2);
// 	printf("\nPressione qualquer tecla para continuar...");
// 	getchar();

// 	printf("\n\n------------------------------------\n");
// 	printf("Teste 11 - adjacente(Graf, int x, int y)\n");
// 	printf("----------------------------------------\n");

// 	adjacente(aux2, 1, 3);
// 	visualiza_grafo(aux2);
// 	printf("\nPressione qualquer tecla para continuar...");
// 	getchar();

// 	printf("\n\n-------------------------------------\n");
// 	printf("Teste 12 - Vertice *vizinhos(Graf, int x)\n");
// 	printf("-----------------------------------------\n");

// 	printf("Os vizinhos do vértice 1 são:\n");
// 	vizinhos(aux2, 1);
// 	printf("Os vizinhos do vértice 6 são:\n");
// 	vizinhos(aux2, 6);
// 	printf("Os vizinhos do vértice 4 são:\n");
// 	vizinhos(aux2, 4);	
// 	visualiza_grafo(aux2);
// 	printf("\nPressione qualquer tecla para continuar...");
// 	getchar();

// 	printf("\n\n-------------------------------------\n");
// 	printf("Teste 13 - destroi_grafo(Graf)\n");
// 	printf("-----------------------------------------\n");

// 	destroi_grafo(aux2);
// 	destroi_grafo(aux);
// 	visualiza_grafo(aux2);
// 	printf("\n");
// 	visualiza_grafo(aux);
// 	printf("\n");
// 	destroi_grafo(aux5);
// 	printf("\nPressione qualquer tecla para continuar...");
// 	getchar();

// 	return (0);
// }
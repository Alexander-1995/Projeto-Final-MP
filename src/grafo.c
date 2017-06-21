#include "grafo.h"

struct Grafo{
	struct Vertice *vert;
	char *nom;
	float **ares;
	int quant_vert;		
};

struct Vertice{
	int identificador;
	float val;
};

Graf cria_grafo (char *nom){

	Graf gra;
	gra = malloc(sizeof(struct Grafo));

	if(gra == NULL){
		return NULL;
	}
	char *aux= realloc (gra->nom, strlen(nom)*sizeof(char));
	gra->nom = aux;
	strcpy(gra->nom,nom);
	gra->vert = malloc(sizeof(struct Vertice));
	gra->quant_vert = 0;

	return gra;		
}

char *retorna_nome_grafo(Graf xis){

	if (xis == NULL){
		printf("Este Grafo não existe, portanto não tem nome(NULL)!\n");
		return "NULL";
	}else{
		return xis->nom;
	}
}

void destroi_grafo(Graf xis){

	int i;
	
	if(xis == NULL){
		printf("Este Grafo não existe, portanto não pode ser destruído!\n");
		return ;
	}else{
		if(xis != NULL || sizeof(xis) != 0){
			if (sizeof(xis->ares) != 0){        
        		for(i = 0; i < xis->quant_vert; i++){
            		free(xis->ares[i]);
        		}
        		free(xis->ares);
        		xis->ares = NULL;
    		}

    		xis->ares = NULL;
    		free(xis->vert);
    		xis->vert = NULL;
    		free(xis->nom);
    		xis->quant_vert = 0;
    		xis->nom = NULL;
    		free(xis);
    		xis = NULL;
		}
	} 
}

void adjacente(Graf xis, int x, int y){

	int coordenada_x, coordenada_y, n;

	if(xis == NULL || sizeof(xis) == 0){
		coordenada_x = -1;
	}else{
		for(n = 0; n<xis->quant_vert; n++){
			if(xis->vert[n].identificador == x){
				coordenada_x = n;
			}
		}
	}

	if(xis == NULL || sizeof(xis) == 0){
		coordenada_y = -1;
	}else{
		for(n = 0; n<xis->quant_vert; n++){
			if(xis->vert[n].identificador == y){
				coordenada_y = n;
			}
		}
	}

	if(xis->ares[coordenada_x][coordenada_y]>0){
		printf("Os vértices x=%d e y=%d são adjacentes!\n",x,y);
	}

	if(coordenada_x == -1 || coordenada_y == -1){
		printf("Os vértices x=%d e y=%d não são adjacentes!\n",x,y);
	}
}

struct Vertice *vizinhos(Graf xis, int x){

    int i, coordenada_x, aux4 = 0;
    struct Vertice *vizinhos = NULL;
    coordenada_x = posicao_do_vertice(xis, x);
    
	if (xis == NULL){
        printf("Este Grafo é nulo, logo não pode apresentar vizinhos em seus vértices.\n");
        return NULL;
    }
    
    if (coordenada_x == -1){
        return NULL;
    }
    
    for (i = 0; i < xis->quant_vert; i++)
    {
        if(xis->ares[i][coordenada_x] > 0)
        {
            vizinhos = realloc(vizinhos, (aux4 + 1) * sizeof(struct Vertice));
            vizinhos[aux4] = xis->vert[i];
            printf("Vert. %d ==>  val.: %.f \n", xis->vert[i].identificador, xis->vert[i].val);
            aux4++;
        }
    }
    return vizinhos;
}

void adiciona_vertice(Graf xis, int x){

    if (posicao_do_vertice(xis, x) != -1){
        return;
    }
 
 	if (sizeof(xis) == 0 || xis == NULL){
 		printf("O grafo não existe. Antes de adicionar um vértice crie um grafo!");
        return;
    }

	if(xis->quant_vert > 0){
 
        struct Vertice *aux = realloc(xis->vert, (xis->quant_vert + 1) * sizeof(struct Vertice));
        xis->vert = aux;
    }
    
    xis->vert[xis->quant_vert].identificador = x;
    xis->vert[xis->quant_vert].val = 0;
    xis->quant_vert++;
    xis->ares = estrut_matriz_realocacao(xis->ares, xis->quant_vert);
}    


void remove_vertice(Graf xis, int x){  
    
    int i, p, q, k, j=0, f=0;
    float **aux2;

    aux2 = estrut_matriz_alocacao(aux2, (xis->quant_vert - 1));
    int coordenada_x = posicao_do_vertice(xis, x);
    struct Vertice *tip = malloc(sizeof(struct Vertice)*(xis->quant_vert-1));
        
    if(coordenada_x == -1){
        return;
    }
    
    for(p = 0; p < xis->quant_vert; p++){
        if(p != coordenada_x){
           k=0;
           for(q = 0; q < xis->quant_vert; q++){
               if(q != coordenada_x){
                  aux2[j][k] = xis->ares[p][q];
                  k++;
                }
            }
            j++;
        }

	}
    
    for(i = 0; i < xis->quant_vert; i++){
       if(i != coordenada_x){
         tip[f] = xis->vert[i];
         f++;
        }
    }
	xis->quant_vert--;
    xis->ares = aux2;
    xis->vert = tip;
}

void adiciona_aresta(Graf xis, int x, int y){ 

	int coordenada_x, coordenada_y;

    coordenada_x = posicao_do_vertice(xis, x);
    coordenada_y = posicao_do_vertice(xis, y);
    
    if (coordenada_x == -1 || coordenada_y == -1){
    	printf("Ou x=%d ou y=%d não são vértices do grafo.\n", x, y);
        return;
    }

    xis->ares[coordenada_y][coordenada_x] = 1;
}


void remove_aresta(Graf xis, int x, int y){

	int coordenada_x, coordenada_y;
	
    coordenada_x = posicao_do_vertice(xis, x);
    coordenada_y = posicao_do_vertice(xis, y);
    
    if (xis->ares[coordenada_y][coordenada_x] == 0 || coordenada_x == -1 || coordenada_y == -1){
    	printf("Ou x=%d ou y=%d não são vértices do grafo.\n", x, y);
        return;
    }

    xis->ares[coordenada_y][coordenada_x] = 0;
}

float retorna_valor_vertice(Graf xis, int x){          

    int coordenada_x = posicao_do_vertice(xis, x);
    
    if (coordenada_x == -1){
    	printf("X=%d não é vértice do grafo.", x);
        return -1;
    }
    return xis->vert[coordenada_x].val;
}


void muda_valor_vertice(Graf xis, int x, int val){       

	int coordenada_x;

	coordenada_x = posicao_do_vertice(xis, x);
    
    if (coordenada_x == -1){
    	printf("X=%d não é vértice do grafo.", x);
        return;
    }
    xis->vert[coordenada_x].val = val;
}

float retorna_valor_aresta(Graf xis, int x, int y){

	int coordenada_x, coordenada_y;

    coordenada_x = posicao_do_vertice(xis, x);
    coordenada_y = posicao_do_vertice(xis, y);
    
    if (coordenada_x == -1 || coordenada_y == -1){
    	printf("Ou x=%d ou y=%d não são vértices do grafo.\n", x, y);
        return -1;
    }

    return xis->ares[coordenada_y][coordenada_x];
}

void muda_valor_aresta(Graf xis, int x, int y, int val){

	int coordenada_x, coordenada_y;

    coordenada_x = posicao_do_vertice(xis, x);
    coordenada_y = posicao_do_vertice(xis, y);
    
    if (xis->ares[coordenada_y][coordenada_x] || coordenada_x == -1 || coordenada_y == -1  == 0){
        return;
    }
    
    xis->ares[coordenada_y][coordenada_x] = val;
}



/*************************************FUNÇÕES AUXILIARES********************************************/
void visualiza_grafo(Graf xis){                         

    int i, j;

    if (xis == NULL|| sizeof(xis) == 0){
        printf("Este Grafo não existe!\n");
        return;
    }
    printf("Grafo(nome):\n\t\t%s\n", xis->nom);
    printf("Vertices: \n");
    
    for (i = 0; i < xis->quant_vert; i++){
        printf("\tVert. %d ==>  val.: %.f \n", xis->vert[i].identificador, xis->vert[i].val);
    }
    printf("Matriz de Arestas: \n");
    
    for (i = 0; i < xis->quant_vert; i++){
        for (j = 0; j < xis->quant_vert; j++){
            printf("\t%.f  ", xis->ares[i][j]);
        }
        printf("\n");
    }
}

int posicao_do_vertice(Graf xis, int aux_vert){ 

	int n;

    if (xis == NULL || sizeof(xis) == 0){
        printf("Este Grafo não existe!\n");
        return -1;
    }
    
    for (n = 0; n < xis->quant_vert ; n++){
        if(xis->vert[n].identificador == aux_vert){
            return n;
        }
    }
    return -1;
}

float **estrut_matriz_alocacao(float **estrut_mat, int componente){
    int n;
    estrut_mat = malloc(sizeof(float)*componente*componente);
    
    if(estrut_mat != NULL){        
        for(n = 0; n < componente; n++){
            estrut_mat[n] = malloc(sizeof(float)*componente);
            if(estrut_mat[n] == NULL){
                return NULL;
            }
        }
    }
    return estrut_mat;
}

float **estrut_matriz_realocacao(float **estrut_mat, int componente){
    
    int m, n;
    float **aux2;
    aux2 = estrut_matriz_alocacao(aux2, (componente));
    
    if (sizeof(estrut_mat) == 0){
        return NULL;
    }

    for (m = 0; m < componente; m++)
    {
        for (n = 0; n < componente; n++){
            if (n == componente-1 || m == componente-1)
            {
                aux2[m][n] = 0;
            }else
            {
                aux2[m][n] = estrut_mat [m][n];
            }
        }
    }

    return aux2;
}
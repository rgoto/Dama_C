#include <stdio.h>
#include <stdlib.h>

//variaveis globais
int i, j;

//prototipos das funcoes
char** initialize();
void print(char** grade);
int** ler_numeros();
int mudando_posicao(char** matriz, int** num, char jogador);



int main (void){
char** m;
int** numeros;

	m = initialize();
	print(m);

	numeros = ler_numeros();

	mudando_posicao(m, numeros, 'P');

	print(m);

	
}

//Função Cria Matriz 8x8, alocando e populando
char** initialize(){
	char** tabuleiro;
	
	//Alocando matriz 8x8
	tabuleiro = (char**) calloc(8, sizeof(char*));
	
	for(i = 0; i < 8; i++)
		tabuleiro[i] = (char*) calloc(8, sizeof(char));
		
	
	//Populando a Matriz 8x8 para evitar erros de lógica
	for(i = 0; i < 8; i++)
		for(j = 0; j < 8; j++)
			tabuleiro[i][j] = '-';
	
	//Colando as peças 'P'retas		
	for(i = 0; i < 3; i += 2)
		for(j = 0; j < 8; j += 2)
			tabuleiro[i][j] = 'P';
			
		for(j = 1; j < 8; j += 2)
			tabuleiro[1][j] = 'P';
			
	//Colocando as peças 'B'rancas
	for(i = 5; i < 8; i += 2)
		for(j = 1; j < 8; j += 2)
			tabuleiro[i][j] = 'B';
			
		for(j = 0; j < 8; j += 2)
			tabuleiro[6][j] = 'B';
	
			
			 		
return tabuleiro;
	
}

/*
	
	Função printa a matriz 8x8 e uma guia para a ajudar o jogador a se localizar

*/

void print(char** grade){
	printf("\n\n\t\t\n                0    1    2   3    4     5    6    7    \n\n\n");
 
	for(i = 0; i < 8; i++){
		printf("\t%d     ", i);

		for(j = 0; j <8; j++){
			printf("  %c  ", grade[i][j]);
			
		if(j == 7)
			printf("\n\n");
			
		
		}
	}
}

//Função Salva coordanadas da peca que deseja mover e para onde vai em uma matriz 2x2


int** ler_numeros(){
	int** num;

	num = (int **) calloc(2, sizeof(int *));

	for(i = 0; i < 3; i++)
	num[i] = (int*) calloc(2, sizeof(int));


	printf("Digite as coordenadas da peca que deseja mover (Linha e Coluna): ");
	scanf("%d %d", &num[0][0], &num[0][1]);

		while(num[0][0] < 0 || num[0][0] >= 8 || num[0][1] < 0 || num[0][1] >= 8){
			printf("Coordenada Invalida, tente novamente.\n\n");
			scanf("%d %d", &num[0][0], &num[0][1]);

		}

	printf("Digite as coordenadas para qual a peca vai (Linha e Coluna): ");
	scanf("%d %d", &num[1][0], &num[1][1]);

		while(num[1][0] < 0 || num[1][0] >= 8 || num[1][1] < 0 || num[1][1] >= 8){
			printf("Coordenada Invalida, tente novamente.\n\n");
			scanf("%d %d", &num[0][0], &num[0][1]);

		}


	return num;

}

int mudando_posicao(char** matriz, int** num, char jogador){ //apenas um teste!

	if(matriz[num[0][0]][num[0][1]] == jogador){
		
		if(matriz[num[1][0]][num[1][1]] == '-'){

			matriz[num[0][0]][num[0][1]] = '-';
			matriz[num[1][0]][num[1][1]] = jogador;

			return 1;

		}



	}

return 1;

}


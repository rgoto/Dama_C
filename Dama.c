#include <stdio.h>
#include <stdlib.h>

//variaveis globais
int i, j;

//prototipos das funcoes
char** initialize();
void print(char** grade);
void game_run();
int step(char** matriz, int lin, int col, int linp, int colp, char jogador, char oposto);



int main (void){

	game_run();
	
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

int step(char** matriz, int lin, int col, int linp, int colp, char jogador, char oposto){
	
	if((linp+colp)%2 == 0){
		
		if(matriz[lin][col] == jogador && lin < linp || matriz[lin][col] == jogador && lin > linp){ // Só deixa andar uma casa de cada vez;
					
	}
}
	return 1;	
	
}

void game_run(){
char** matriz;
char jogador = 'B';
char oposto = 'P';
int lin, col, linp, colp;

	matriz = initialize();
	
matriz[4][2] = 'P';

	//aqui tera um while futuramente
	
	
	system("cls");
	print(matriz);
	
	printf("\n\n\t Digite qual peça deseja mover!");
	printf("\n\n\t Linha da peça: ");
	scanf("%d", &lin);																//
	printf("\n\n\t Coluna da peça: ");												//
	scanf("%d", &col);																//Lê os números e
																					//    	Vê
	while(lin < 0 || lin >= 8 || col < 0 || col >= 8){								//se é um numero Valido
																					//
		system("cls");																//
		print(matriz);
		printf("\n\t Numeros invalidos, tente novamentez\n\t");
		printf("\n\n\t Digite qual peça deseja mover!");
		printf("\n\n\t Linha da peça: ");
		scanf("%d", &lin);
		printf("\t Coluna da peça: ");
		scanf("%d", &col);
		
	}
	
	system("cls");
	print(matriz);
	
	printf("\n\n\t Digite para qual casa a peça vai!");
	printf("\n\n\t Linha da peça: ");
	scanf("%d", &linp);
	printf("\n\t Coluna da peça: ");
	scanf("%d", &colp);

	while(linp < 0 || linp>= 8 || colp < 0 || colp >= 8){
		
		system("cls");
		print(matriz);
		printf("\n\t Numeros invalidos, tente novamentez\n\t");
		printf("\n\n\t Digite qual peça deseja mover!");
		printf("\n\n\t Linha da peça: ");
		scanf("%d", &linp);
		printf("\t Coluna da peça: ");
		scanf("%d", &colp);
		
	}
	
	if(step(matriz,lin,col,linp,colp,jogador, oposto) == -1){
		
		system("cls");
		
		printf("Movimento Invalido, Tente novamente\n");
		//continue;
		
	}
	
	print(matriz);
	
	
	
	
	
}


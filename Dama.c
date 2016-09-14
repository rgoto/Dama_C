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

//Fun��o Cria Matriz 8x8, alocando e populando
char** initialize(){
	char** tabuleiro;
	
	//Alocando matriz 8x8
	tabuleiro = (char**) calloc(8, sizeof(char*));
	
	for(i = 0; i < 8; i++)
		tabuleiro[i] = (char*) calloc(8, sizeof(char));
		
	
	//Populando a Matriz 8x8 para evitar erros de l�gica
	for(i = 0; i < 8; i++)
		for(j = 0; j < 8; j++)
			tabuleiro[i][j] = '-';
	
	//Colando as pe�as 'P'retas		
	for(i = 0; i < 3; i += 2)
		for(j = 0; j < 8; j += 2)
			tabuleiro[i][j] = 'P';
			
		for(j = 1; j < 8; j += 2)
			tabuleiro[1][j] = 'P';
			
	//Colocando as pe�as 'B'rancas
	for(i = 5; i < 8; i += 2)
		for(j = 1; j < 8; j += 2)
			tabuleiro[i][j] = 'B';
			
		for(j = 0; j < 8; j += 2)
			tabuleiro[6][j] = 'B';
	
			
			 		
return tabuleiro;
	
}


/*
	
	Fun��o printa a matriz 8x8 e uma guia para a ajudar o jogador a se localizar

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
		
		//se for pe�as da mesma cor volta false pro while
		if(matriz[lin][col] == jogador && matriz[linp][colp] == jogador)
			return -1;
		 
		 
		 	// S� deixa andar uma casa de cada vez;
			if((matriz[lin][col] == jogador && linp-1 == lin) || (matriz[lin][col] == jogador && linp+1 == lin)){
				
				
				//pretas e brancas: movimento comun	
				if(matriz[linp][colp] == '-'){
					matriz[linp][colp] = jogador;
					matriz[lin][col] = '-';
					
				return 1;
				}
				
				//V� se a pe�a que ser� comida � oposta ao jogador
				if(matriz[linp][colp] == oposto){
					
						//brancas: comer para a direita cima
						if(matriz[linp-1][colp+1] == '-' && colp + 1 == col + 2){
							matriz[linp-1][colp+1] = jogador;
							matriz[lin][col] = ' ';
							matriz[linp][colp] = ' ';
							
						}
						
						//brancas: comer para a esquerda cima
						if(matriz[linp-1][colp-1] == '-' && colp - 1 == col - 2){
							matriz[linp-1][colp-1] = jogador;
							matriz[lin][col] = ' ';
							matriz[linp][colp] = ' ';
						
						}
						
						//Preta: come para direita baixo
						if(matriz[linp+1][colp+1] == '-' && colp + 1 == col + 2){
							matriz[linp+1][colp+1] = jogador;
							matriz[lin][col] = ' ';
							matriz[linp][colp] = ' ';
								
						}						
						
						//Preta: come para esquerda baixo
						if(matriz[linp+1][colp-1] == '-' && colp - 1 == col - 2){
							matriz[linp+1][colp-1] = jogador;
							matriz[lin][col] = ' ';
							matriz[linp][colp] = ' ';
					
						}
						
						
						
					
					
					
					
					
					
					
					
				}
			

					
	}	
} 
	return -1;
	
}

/*

	Fun��o que executa o jogo, chamando todos as fun��es para que o loop game funcione corretamente

*/

void game_run(){
char** matriz;
char jogador = 'B';
char oposto = 'P';
int lin, col, linp, colp;

	matriz = initialize();
	
matriz[4][2] = 'P';
matriz[3][5] = 'B';


	//aqui tera um while futuramente


	
	print(matriz);
	
	printf("\n\n\t Jogador %c Digite qual pe�a deseja mover!",jogador);				//
	printf("\n\n\t Linha da pe�a: ");												//
	scanf("%d", &lin);																//
	printf("\n\n\t Coluna da pe�a: ");												//
	scanf("%d", &col);																//
																					// 		L� os n�meros e
	while(lin < 0 || lin >= 8 || col < 0 || col >= 8){								//
																					//			  V�
		system("cls");																//		
		print(matriz);																//		se � um numero V�lido
		printf("\n\t Numeros invalidos, tente novamentez\n\t");						//
		printf("\n\n\t Jogador %c Digite qual pe�a deseja mover!", jogador);		//
		printf("\n\n\t Linha da pe�a: ");											//
		scanf("%d", &lin);															//
		printf("\t Coluna da pe�a: ");												//
		scanf("%d", &col);															//
		
	}
	
	system("cls");
	print(matriz);
	
	printf("\n\n\t Jogador %c Digite para qual casa a pe�a vai!", jogador);
	printf("\n\n\t Linha da pe�a: ");
	scanf("%d", &linp);
	printf("\n\t Coluna da pe�a: ");
	scanf("%d", &colp);

	while(linp < 0 || linp>= 8 || colp < 0 || colp >= 8){
		
		system("cls");
		print(matriz);
		printf("\n\t Numeros invalidos, tente novamentez\n\t");
		printf("\n\n\t Jogador %c Digite qual pe�a deseja mover!", jogador);
		printf("\n\n\t Linha da pe�a: ");
		scanf("%d", &linp);
		printf("\t Coluna da pe�a: ");
		scanf("%d", &colp);
		
	}
	
	if(step(matriz,lin,col,linp,colp,jogador, oposto) == -1){
		system("cls");
		
		printf("Movimento Invalido, Tente novamente\n");
		//continue;
		
	}
	
	print(matriz);
	
	
	//Altera entre jogador Branco e Preto
	if(jogador == 'B'){					//
		jogador = 'P';					//
		oposto = 'B';					//
										//	
	} else {							//
		jogador = 'B';					//
		oposto = 'P'; 					//
	}									
	
	system("cls");
	
	print(matriz);  // apenas para teste, quando acabar apagar essa linha!!!!!!


	
}


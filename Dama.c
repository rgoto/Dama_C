#include <stdio.h>
#include <stdlib.h>
//variaveis globais
int i, j;

//prototipos das funcoes
char** initialize();
void print(char** grade);
void game_run();
int step(char** matriz, int lin, int col, int linp, int colp, char jogador, char oposto, char dama, char odama);
int restricaodama(char** matriz, int lin, int col, int linp, int colp, char oposto, char odama);
int status(char** matriz);
void mdama(char** matriz);



int main (void){
	system("color f0");
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

	
int step(char** matriz, int lin, int col, int linp, int colp, char jogador, char oposto, char dama, char odama){
	int num = 0, nump = 0;
	int teste;
	num = linp - lin;
	nump = colp - col;
	
	//Movimentos e restrições da dama
	if(matriz[lin][col] == dama){	
	
	//não deixa comer para fora da matriz
	if((linp == 7 || linp == 0) && (matriz[linp][colp] == oposto || matriz[linp][colp] == odama))
   		return -1;
   	

			//Dama só anda se for par
			if((linp+colp)%2 == 0){
				
				if(matriz[linp][colp] == oposto || matriz[linp][colp] == odama){

					//restrição para colunas
						if(colp > col){
							
								//dama: come para direita baixo
								if(matriz[linp+1][colp+1] == '-'  && matriz[linp-num][colp-num] == matriz[lin][col]){
									matriz[linp+1][colp+1] = dama;
									matriz[lin][col] = '-';
									matriz[linp][colp] = '-';
											
								return 1;	
									
								}
									
									
								//dama: come para a direita cima
								if(matriz[linp-1][colp+1] == '-' && matriz[linp+num][colp-num] == matriz[lin][col]){
									matriz[linp-1][colp+1] = dama;
									matriz[lin][col] = '-';
									matriz[linp][colp] = '-';
									
								return 1;
									
								}
						
					
						} else {
								
								
								//dama: come para a esquerda cima
								if(matriz[linp-1][colp-1] == '-' && matriz[linp-num][colp-num] == matriz[lin][col]){
									matriz[linp-1][colp-1] = dama;
									matriz[lin][col] = '-';
									matriz[linp][colp] = '-';
									
									return 1;
									
								}
								
								
								//dama: come para esquerda baixo
								if(matriz[linp+1][colp-1] == '-' && matriz[linp-num][colp+num] == matriz[lin][col]){
									matriz[linp+1][colp-1] = dama;
									matriz[lin][col] = '-';
									matriz[linp][colp] = '-';
									
								return 1;
								
								}
								
								
								
						}



				}

				//Movimento comum da dama com gambiarra!!!!
				else if(restricaodama(matriz, lin, col, linp, colp, oposto, dama) == 2){
					matriz[linp][colp] = dama;
					matriz[lin][col] = '-';
					return 1;
					
				} else
					return -1;
			
			
			}
	
	
	
	
		return -1;
	
	}
	
	//So deixa a peça andar se for par
	if((linp+colp)%2 == 0){
	
		//Não deixa comer para fora da matriz
		if((linp == 7 || linp == 0) && (matriz[linp][colp] == oposto || matriz[linp][colp] == odama))
	   		return -1;

		
		//se for peças da mesma cor, retorna false pro while
		if(matriz[lin][col] == jogador && matriz[linp][colp] == jogador)
			return -1;
	
		//Restrição de andar para trás no movimento comum
		if((jogador == 'B' && linp > lin) || (jogador == 'P' && linp < lin))
			return -1;
		 
		// Só deixa andar uma casa de cada vez;
		if((matriz[lin][col] == jogador && linp-1 == lin) || (matriz[lin][col] == jogador && linp+1 == lin)){
				
				
				//pretas e brancas: movimento comun	
				if(colp == col+1 || colp == col-1){
					
					if(matriz[linp][colp] == '-'){
						matriz[linp][colp] = jogador;
						matriz[lin][col] = '-';	
						
						return 1;
					
					}
				}
				
				//Vê se a peça que será comida é oposta ao jogador
				if(matriz[linp][colp] == oposto){
				
							//brancas: come para a direita cima
							if(matriz[linp-1][colp+1] == '-' && colp + 1 == col + 2 && jogador == 'B'){
								matriz[linp-1][colp+1] = jogador;
								matriz[lin][col] = '-';
								matriz[linp][colp] = '-';
							
							return 1;
								
							}
							
							//brancas: come para a esquerda cima
							if(matriz[linp-1][colp-1] == '-' && colp - 1 == col - 2 && jogador == 'B'){
								matriz[linp-1][colp-1] = jogador;
								matriz[lin][col] = '-';
								matriz[linp][colp] = '-';
							
							return 1;
							
							}
							
							//Preta: come para direita baixo
							if(matriz[linp+1][colp+1] == '-' && colp + 1 == col + 2 && jogador == 'P'){
								matriz[linp+1][colp+1] = jogador;
								matriz[lin][col] = '-';
								matriz[linp][colp] = '-';
									
							return 1;	
								
							}						
							
							//Preta: come para esquerda baixo
							if(matriz[linp+1][colp-1] == '-' && colp - 1 == col - 2 && jogador == 'P'){
								matriz[linp+1][colp-1] = jogador;
								matriz[lin][col] = '-';
								matriz[linp][colp] = '-';
							
							return 1;
							
							}			
			
				}			
	}	
} 

	return -1;
	
}

/*
	Função que executa o jogo, chamando todos as funções para que o loop game funcione corretamente
*/

void game_run(){
char** matriz;
char jogador = 'B';
char oposto = 'P';
char dama = 18;
char odama = 29;
int lin, col, linp, colp, game = -1;

	matriz = initialize();
	
	//game loop
	while(game == -1){

	print(matriz);
	
	printf("\n\n\t Jogador %c Digite qual peça deseja mover!",jogador);				//
	printf("\n\n\t Linha da peça: ");												//
	scanf("%d", &lin);																//
	printf("\n\n\t Coluna da peça: ");												//
	scanf("%d", &col);																//
																					// 		Lê os números e
	while(lin < 0 || lin >= 8 || col < 0 || col >= 8){								//
																					//			  Vê
		system("cls");																//		
		print(matriz);																//		se é um numero Válido
		printf("\n\t Numeros invalidos, tente novamentez\n\t");						//
		printf("\n\n\t Jogador %c Digite qual peça deseja mover!", jogador);		//
		printf("\n\n\t Linha da peça: ");											//
		scanf("%d", &lin);															//
		printf("\t Coluna da peça: ");												//
		scanf("%d", &col);															//
																					//
	}																				//
																					//
	system("cls");																	//
	print(matriz);																	//
																					//
	printf("\n\n\t Jogador %c Digite para qual casa a peça vai!", jogador);			//
	printf("\n\n\t Linha da peça: ");												//
	scanf("%d", &linp);																//
	printf("\n\t Coluna da peça: ");												//
	scanf("%d", &colp);																//
																					//
	while(linp < 0 || linp>= 8 || colp < 0 || colp >= 8){							//
																					//
		system("cls");																//
		print(matriz);																//
		printf("\n\t Numeros invalidos, tente novamentez\n\t");						//
		printf("\n\n\t Jogador %c Digite qual peça deseja mover!", jogador);		//
		printf("\n\n\t Linha da peça: ");											//
		scanf("%d", &linp);															//
		printf("\t Coluna da peça: ");												//
		scanf("%d", &colp);															//
																					//
	}																				//	
	//Verefica se foi valida a jogada e movimenta
	if(step(matriz,lin,col,linp,colp,jogador, oposto, dama, odama) == -1){
		system("cls");
		
		printf("Movimento Inválido, Tente novamente\n");
		continue;
		
	}
	
	mdama(matriz);
	print(matriz);
	game = status(matriz);
	
	
	//Altera entre jogador Branco e Preto
	if(jogador == 'B'){	
		jogador = 'P';					
		oposto = 'B';					
		dama = 29;						
		odama = 18;						
											
	} else {							
		jogador = 'B';					
		oposto = 'P'; 					
		dama = 18;						
		odama = 29;						
	}									

	system("cls");
		

}										

	switch(game){
		
		case 1:
			system("color 40");
			printf("\n\n\n\n\t\t O jogador --> P <-- VENCEU!!!!!!!!!!\n\n\n\n\t\t");
			break;
			
		case 2:
			system("color 27");
			printf("\n\n\n\n\t\t O jogador --> B <-- VENCEU!!!!!!!!!!\n\n\n\n\t\t");
			break;
	}



}

/*
	Função Verifica se algum jogador comeu todas as peças e ganhou
*/

int status(char** matriz){
	int brancas = 12, pretas = 12;
	
		for(i = 0; i < 8; i++){
			for(j = 0; j < 8; j++){	
				
				if(matriz[i][j] == 'B' || matriz[i][j] == 18)
					brancas--;
					
				if(matriz[i][j] == 'P' || matriz [i][j] == 29)
					pretas--;
					
			}
		}
		
		if(brancas == 12)
			return 1;
			
		if(pretas == 12)
			return 2;		
				
	return -1;
	
	
}


//Função reconhece
void mdama(char** matriz){
	
	for(i = 0; i < 8; i++){
		
		if(matriz[0][i] == 'B')
			matriz[0][i] = 18;
			
		if(matriz[7][i] == 'P')
			matriz[7][i] = 29;
		
	}
		
	
}

int restricaodama(char** matriz, int lin, int col, int linp, int colp, char oposto, char odama){
	
	if(matriz[linp][colp] == '-'){
		
		if(linp == colp && linp > lin){
			
			for(i = lin; i < linp; i++){
				if(matriz[i][i] == oposto || matriz[i][j] == odama)
					return -1;
					
			}
		}
		
		
		if(linp == colp && linp < lin){
			for(i = lin; i > linp; i--){
				if(matriz[i][i] == oposto || matriz[i][j] == odama)
					return -1;
					
			}	
		}
		
		
		if(lin > linp){
			for(i = lin; i > linp; i--){
				for(j = col; j < colp; j++){
					if(matriz[i][j] == oposto || matriz[i][j] == odama)
						return -1;
						
				}
			}
		}
		
		
		if(lin < linp){
			for(i = lin; i < linp; i++){
				for(j = col; j > colp; j--){
					if(matriz[i][j] == oposto || matriz[i][j] == odama)
						return -1;
						
				}
			}	
		}	
	}
	
	return 2;
}


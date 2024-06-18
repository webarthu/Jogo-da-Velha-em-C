#include <stdio.h>
#include <stdbool.h> //PARA VARIAVEIS BOLEANAS QUE RETORNAM UM VALOR VERDADEIRO(TRUE) OU FALSO(FALSE)
#include <stdlib.h> //BIBLIOTECA PARA LIMPAR O TERMINAL; ex: SYSTEM("CLS") e SYSTEM("PAUSE")


int linha, coluna, number, cont=0;
char velha[3][3]= {{'0', '1', '2',}, {'3', '4', '5'}, {'6', '7','8'}};;
char SIMB, position, X='X';
char O = 'O';
bool WINNER=false;


void mostra_velha(){ //FUNÇÃO PRA CHAMAR A MATRIZ

    for(linha=0;linha<=2;linha++){
        for(coluna=0;coluna<=2;coluna++){
            printf("%c|",velha[linha][coluna],"|");
        }
        printf("\n");
    }
}

bool WIN_SCAN (){ //FUNÇAO PARA ANALISE DAS JOGADAS
    bool win=false;
        
    for(linha=0;linha<3;linha++){ //VERIFICA TODAS AS LINHAS DA MATRIZ
      if (velha[linha][0] == velha[linha][1] && velha[linha][1] == velha[linha][2]){
        win=true;
        printf("\no jogo terminou!");
        }  
    }

    for(coluna=0;coluna<3;coluna++){ //VERIFICA TODAS AS COLUNAS DA MATRIZ
      if (velha[0][coluna] == velha[1][coluna] && velha[1][coluna] == velha[2][coluna]){
        win=true;
        printf("\no jogo terminou!");
        }  
    }


    if(velha[0][0]==velha[1][1] && velha[1][1]==velha[2][2]){ //VERIFICA A DIAGONAL PRINCIPAL DA MATRIZ
        win=true;
        printf("\no jogo terminou!");
    }

     if(velha[0][2]==velha[1][1] && velha[1][1]==velha[2][0]){ //VERIFICA A DIAGONAL SECUNDARIA DA MATRIZ
        win=true;
        printf("\no jogo terminou!");
    }


    return(win);
}

void jogo(){ //FUNÇÃO PRINCIPAL DO CODIGO, ONDE BASICAMENTE RODA TODA A LÓGICA DO JOGO
 
 while(WINNER==false){
       
    while(cont%2==0){ //LAÇO DE REPETIÇÃO PARA VEZ DO JOGADOR 'X'
        system("cls"); //COMANDO PARA LIMPAR O TERMINAL
        mostra_velha();
        SIMB='X';
        printf(" \n onde deseja jogar %c",SIMB);
        printf("? ");
        scanf(" %d", &number);  
        
        if (number >= 0 && number <= 8) {
            
            if(velha[0][number]=='O'||velha[0][number]=='X'){
                printf("este lugar esta ocupado");
                printf("\n");
                system("pause");
            }else{
                velha[0][number]=SIMB;
                cont=cont+1;
                if(cont==9){
                    printf("\no jogo deu velha!");
                    WINNER=true;
                }else{
                    WINNER=WIN_SCAN();
                }
            }
        
        }else{
            printf("\nposicao invalida");
            printf("\n");
            system("pause");
        }
       }
        
       
        if(WINNER==false){

            while(cont%2==1){ //LAÇO DE REPETIÇÃO PARA VEZ DO JOGADOR 'O'
                system("cls"); //COMANDO PARA LIMPAR O TERMINAL
                mostra_velha();
                SIMB='O';
                printf(" \n onde deseja jogar %c",SIMB);
                printf("? ");
                scanf(" %d", &number);  
        
                if (number >= 0 && number <= 8) {
            
                    if(velha[0][number]=='X'||velha[0][number]=='O'){
                        printf("este lugar esta ocupado");
                        printf("\n");
                        system("pause");
                    }else{
                        velha[0][number]=SIMB;
                        cont=cont+1;   
                    
                        if(cont==9){
                            printf("\no jogo deu velha!");
                            WINNER=true;
                        }else{
                            WINNER=WIN_SCAN(); 
                    
                        }    
                    }
                
                }else{
                    printf("\nposicao invalida");
                    printf("\n");
                    system("pause");
                }
            }   
        }     
        
        printf("\n");
        mostra_velha();
    }
}

int main() {
    mostra_velha();
    jogo();
    return 0;
}

//made by webarthu

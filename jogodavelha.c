#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int linha, coluna, col, numbero, cont=0;
char velha[3][3]= {{'0', '1', '2',}, {'3', '4', '5'}, {'6', '7','8'}};;
char SIMB, position, X='X';
char O = 'O';
bool WINNER=false;


void mostra_velha(){

    for(linha=0;linha<=2;linha++){
        for(coluna=0;coluna<=2;coluna++){
            printf("%c|",velha[linha][coluna],"|");
        }
        printf("\n");
    }
}

bool win (){
    bool ganhou=false;
        
    for(col=0;col<3;col++){
      if (velha[col][0] == velha[col][1] && velha[col][1] == velha[col][2]){
        ganhou=true;
        printf("\no jogo terminou!");
        }  
    }

    for(col=0;col<3;col++){
      if (velha[0][col] == velha[1][col] && velha[1][col] == velha[2][col]){
        ganhou=true;
        printf("\no jogo terminou!");
        }  
    }


    return(ganhou);

}

void jogo(){
 
 while(WINNER==false){
       
       while(cont%2==0){
        system("cls");
        mostra_velha();
        SIMB='X';
        printf(" \n onde deseja jogar %c",SIMB);
        printf("? ");
        scanf(" %d", &numbero);  
        
        if (numbero >= 0 && numbero <= 8) {
            if(velha[0][numbero]=='O'||velha[0][numbero]=='X'){
                printf("este lugar esta ocupado");
               printf("\n");
                system("pause");
            }else{
                velha[0][numbero]=SIMB;
                cont=cont+1;
                WINNER=win();
            }
        
        }else{
            printf("\nposicao invalida");
            printf("\n");
            system("pause");
        }
       }
        
       
        if(WINNER==false){

        while(cont%2==1){
            system("cls");
            mostra_velha();
            SIMB='O';
            printf(" \n onde deseja jogar %c",SIMB);
            printf("? ");
            scanf(" %d", &numbero);  
        
            if (numbero >= 0 && numbero <= 8) {
                if(velha[0][numbero]=='X'||velha[0][numbero]=='O'){
                    printf("este lugar esta ocupado");
                    printf("\n");
                    system("pause");
                }else{
                    velha[0][numbero]=SIMB;
                    cont=cont+1;
                    WINNER=win();
                }
                
            } else {
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
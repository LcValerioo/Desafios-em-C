#include <stdio.h>
//procedimento do movimento da Rainha
void rainha(int i)
{
    if(i > 0)
    {
        printf("Esquerda.\n");//Impressão do movimento
        rainha(i - 1);
    }
}
//procedimento do movimento da Torre
void torre(int i)
{
    if(i > 0)
    {
        printf("Direita.\n");//Impressão do movimento
        torre(i - 1);
    }
}
//procedimento do movimento do Bispo
void bispo(int i)
{
    if(i > 0)
    {
        int j = i;
        printf("Cima.\n"); //Impressão do movimento
        if(j == i){
            printf("Direita.\n"); //Impressão do movimento
        }
        bispo(i - 1);
        
    }

}

int main()
{
    //Declarando as Variaveis.
   int i = 8, j = 5, z = 5;
   
   //Chamando os procedimentos do movimento das peças
   printf("Movendo o Bispo...\n");
   bispo(z);
   printf("\n");//Pulando linha entre as peças.
   
   printf("Movendo a Torre...\n");
   torre(j);
   printf("\n");//Pulando linha entre as peças.
   
   printf("Movendo a Rainha...\n");
   rainha(i);
   printf("\n"); //Pulando linha entre as peças.
   
    //Laço de movimento (for) do Cavalo (loop complexo)
    printf("Movendo o Cavalo...\n");
    for(i = 1; i <= 3; i++)
    {
        if(i == 3)
        {
            printf("Direita.\n");//Impressão do movimento
            break;
        }
        printf("Cima.\n");//Impressão do movimento
         
    }
    return 0;
}
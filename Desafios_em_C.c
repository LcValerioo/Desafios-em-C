#include <stdio.h>

int main () {
    printf("Olá, mundo!\n");
    int idade = 18;
    float altura = 1.76;
    char opcao = 'S';
    char nome[20] = "Lucas";

    printf("%d\n", idade);
    printf("%.2f\n", altura);
    printf("%c\n", opcao);
    printf("%s\n", nome);
    
    /*
        printf("%formato", variavel 1);

        %d: imprime um inteiro no formato decimal
        %i: Equivalente a %d
        %f: imprime um numero de ponto flutuante no formato padrão
        %e: imprime um numero de ponto flutuante no formato de notação cientifica
        %c: imprime um unico caracteres
        %s: imprime uma cadeia (string) de caracteres.
    */
    return 0;

}
#include <stdio.h>

int main() 
{
    //Inicialização do programa
    printf("Olá, vamos calcular a média dos alunos ?\n");

    //Inicializando as variaveis
    int matricula = 0;
    float n1, n2, n3, media = 0;
    char nome[50];

    //Pegando as informações do usuario
    printf("Digite o nome do aluno: \n");
    scanf(" %s", &nome);
    printf("Digite a matricula: \n");
    scanf("%d", &matricula);
    printf("Digite as notas da p1, p2 e p3, sucessivamente: \n");
    scanf("%f %f %f", &n1, &n2, &n3);

    //Calculando a média
    media = (n1 + n2 + n3)/3;

    //Imprimindo os resultados
    printf("O Aluno %s, cuja matricula é: %d, teve media: %.2f.\n", nome, matricula, media);

    //Fim do programa
    return 0;
}
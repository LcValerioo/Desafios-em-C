#include <stdio.h>

int main(){
    int idade;
    float altura;
    //sintaxe do scanf
    //scanf("formato 1" "formato2", &formato1, &formato2);

    printf("%d\n", idade);
    printf("Digite sua idade: \n");
    scanf("%d", &idade);
    printf("Digite sua altura: \n");
    scanf("%f", &altura);
    printf("Sua idade é %d e sua altura é %.2f\n", idade, altura);


}
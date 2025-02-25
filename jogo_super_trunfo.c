#include <stdio.h>
#include <stdlib.h>

int main() {
    //Início do programa
    printf("Olá, vamos cadastrar uma carta?\n");

    //Inicializando as variáveis
    char nome1[50], nome2[50];
    char estado1, estado2;
    int pTuristico1, codCarta1, pTuristico2, codCarta2, opcao1, opcao2, res1, res2, empt1, empt2 = 0;
    float area1, pib1, pibper1, dpop1, area2, pib2, pibper2, dpop2 = 0.0;
    unsigned long int pop1, pop2 = 0;

    //Cadastrando as cartas (input de dados)
    //Cadastro da Primeira Carta
    printf("Digite o Estado (letra) da Primeira Carta: \n");
    scanf(" %c", &estado1);

    printf("Digite o Código da cidade da Primeira Carta: \n");
    scanf("%d", &codCarta1);

    getchar(); //Limpa o buffer antes de usar fgets
    printf("Digite o nome da cidade da Primeira Carta: \n");
    fgets(nome1, 50, stdin);
    nome1[strcspn(nome1, "\n")] = '\0'; // Remove o '\n' do final da string capturada por fgets

    printf("Digite o número de habitantes da cidade da Primeira Carta: \n");
    scanf("%lu", &pop1);

    printf("Digite a área da cidade da Primeira Carta: \n");
    scanf("%f", &area1);

    printf("Digite o PIB da cidade (em bilhões) da Primeira Carta: \n");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turísticos da cidade da Primeira Carta: \n");
    scanf("%d", &pTuristico1);

    // Fazendo o cálculo do PIB per capita e da densidade populacional
    pibper1 = (float) pib1 * 1000000000 / (pop1 * 1000000); // Convertendo unidades
    dpop1 = (float) pop1 / area1;
    
    printf("\nCarta cadastrada com sucesso!");//Confirmação de cadastro da carta

    // Exibindo as informações (output de dados)
    printf("\n--- Dados das Cartas ---\n");
    printf("\n--- Primeira Cartas ---\n");
    printf("Estado: %c\n", estado1);
    printf("Código da carta: %c0%d\n", estado1, codCarta1);
    printf("Nome da Cidade: %s\n", nome1);
    printf("População: %lu habitantes\n", pop1);
    printf("Área: %.2f km²\n", area1);
    printf("Densidade Populacional: %.2f hab/km²\n", dpop1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("PIB per Capita: %.2f reais\n", pibper1);
    printf("Número de pontos turísticos: %d\n", pTuristico1);
     
    //Cadastro da Segunda Carta
    printf("\n--Agora cadastre a Segunda Carta--\n");
    printf("\nDigite o Estado (letra) da Segunda Carta: \n");
    scanf(" %c", &estado2);

    printf("Digite o Código da cidade da Segunda Carta: \n");
    scanf("%d", &codCarta2);

    getchar(); // Limpa o buffer antes de usar fgets
    printf("Digite o nome da cidade da Segunda Carta: \n");
    fgets(nome2, 50, stdin);
    nome2[strcspn(nome2, "\n")] = '\0'; // Remove o '\n' do final da string capturada por fgets

    printf("Digite o número de habitantes da cidade da Segunda Carta: \n");
    scanf("%lu", &pop2);

    printf("Digite a área da cidade da Segunda Carta: \n");
    scanf("%f", &area2);

    printf("Digite o PIB da cidade (em bilhões) da Segunda Carta: \n");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos da cidade da Segunda Carta: \n");
    scanf("%d", &pTuristico2);

    // Fazendo o cálculo do PIB per capita e da densidade populacional
    pibper2 = (float) pib2 * 1000000000 / (pop2 * 1000000); // Convertendo unidades
    dpop2 = (float) pop2 / area2;
   
    printf("\nCarta cadastrada com sucesso!\n"); //Confirmação de cadastro da carta
    // Exibindo as informações (output de dados)
    printf("\n--- Dados das Cartas ---\n");
    printf("\n--- Segunda Cartas ---\n");
    printf("Estado: %c\n", estado2);
    printf("Código da carta: %c0%d\n", estado2, codCarta2);
    printf("Nome da Cidade: %s\n", nome2);
    printf("População: %lu habitantes\n", pop2);
    printf("Área: %.2f km²\n", area2);
    printf("Densidade Populacional: %.2f hab/km²\n", dpop2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("PIB per Capita: %.2f reais\n", pibper2);
    printf("Número de pontos turísticos: %d\n", pTuristico2);

    printf("\n--- Hora do Duelo ---\n");
    printf("\nEscolha Dois Atributo para Duelar: \n");
    printf("1. População \n2. Área \n3. Densidade Populacional \n4. PIB \n5. PIB per Capita  \n6. Número de Pontos Turisticos \n");
    printf("Escolha: ");
    scanf("%d %d", &opcao1, &opcao2);

    //Fazendo a comparação entre as cartas para ver quem tem o maior atributo e menor ponto turistico e imprimindo o resultado na tela
    switch (opcao1)
    {
    case 1:
        printf("Carta 1 - Estado: %s, Código: %c0%d, População: %lu, Pontos Turisticos: %d\n", nome1, estado1, codCarta1, pop1, pTuristico1);
        printf("Carta 2 - Estado: %s, Código: %c0%d, População: %lu, Pontos Turisticos: %d\n", nome2, estado2, codCarta2, pop2, pTuristico2);
        res1 = pop1 > pop2 ? 1 : 0;
        //empt1 = pop1 == pop2 ? 1 : 0;
        break;
    case 2:
        printf("Carta 1 - Estado: %s, Código: %c0%d, Área: %d, Pontos Turisticos: %d\n", nome1, estado1, codCarta1, area1, pTuristico1);
        printf("Carta 2 - Estado: %s, Código: %c0%d, Área: %d, Pontos Turisticos: %d\n", nome2, estado2, codCarta2, area2, pTuristico2);
        res1 = area1 > area2 ? 1 : 0;
        //empt1 = area1 == area2 ? 1 : 0;
        break;
    case 3:
        printf("Carta 1 - Estado: %s, Código: %c0%d, Densidade Populacional: %.2f hab/km², Pontos Turisticos: %d\n", nome1, estado1, codCarta1, dpop1, pTuristico1);
        printf("Carta 2 - Estado: %s, Código: %c0%d, Densidade Populacional: %.2f hab/km², Pontos Turisticos: %d\n", nome2, estado2, codCarta2, dpop2, pTuristico2);
        res1 = dpop1 < dpop2 ? 1 : 0;
        //empt1 = dpop1 == dpop2 ? 1 : 0;
        break;
    case 4:
        printf("Carta 1 - Estado: %s, Código: %c0%d, PIB: %.2f bilhões de reais, Pontos Turisticos: %d\n", nome1, estado1, codCarta1, pib1, pTuristico1);
        printf("Carta 2 - Estado: %s, Código: %c0%d, PIB: %.2f bilhões de reais, Pontos Turisticos: %d\n", nome2, estado2, codCarta2, pib2, pTuristico2);
        res1 = pib1 > pib2 ? 1 : 0;
        //empt1 = pib1 == pib2 ? 1 : 0;
        break;
    case 5:
        printf("Carta 1 - Estado: %s, Código: %c0%d, PIB per Capita: %.2f reais: %.2f, Pontos Turisticos: %d\n", nome1, estado1, codCarta1, pibper1, pTuristico1);
        printf("Carta 2 - Estado: %s, Código: %c0%d, PIB per Capita: %.2f reais, Pontos Turisticos: %d\n", nome2, estado2, codCarta2, pibper2, pTuristico2);
        res1 = pibper1 > pibper2 ? 1 : 0;
        //empt1 = pibper1 == pibper2 ? 1 : 0;
        break;
    case 6:
        printf("Carta 1 - Estado: %s, Código: %c0%d, Pontos Turisticos: %d\n", nome1, estado1, codCarta1, pTuristico1);
        printf("Carta 2 - Estado: %s, Código: %c0%d, Pontos Turisticos: %d\n", nome2, estado2, codCarta2, pTuristico2);
        res1 = pTuristico1 > pTuristico2 ? 1 : 0;
        //empt1 = pTuristico1 == pTuristico2 ? 1 : 0;
        break;
    
    default:
    printf("Opção Inválida\n");
        break;
    }

    switch (opcao2)
    {
    case 1:
        printf("Carta 1 - Estado: %s, Código: %c0%d, População: %lu, Pontos Turisticos: %d\n", nome1, estado1, codCarta1, pop1, pTuristico1);
        printf("Carta 2 - Estado: %s, Código: %c0%d, População: %lu, Pontos Turisticos: %d\n", nome2, estado2, codCarta2, pop2, pTuristico2);
        res2 = pop1 > pop2 ? 1 : 0;
        //empt2 = pop1 == pop2 ? 1 : 0;
        break;
    case 2:
        printf("Carta 1 - Estado: %s, Código: %c0%d, Área: %d, Pontos Turisticos: %d\n", nome1, estado1, codCarta1, area1, pTuristico1);
        printf("Carta 2 - Estado: %s, Código: %c0%d, Área: %d, Pontos Turisticos: %d\n", nome2, estado2, codCarta2, area2, pTuristico2);
        res2 = area1 > area2 ? 1 : 0;
        //empt2 = area1 == area2 ? 1 : 0;
        break;
    case 3:
        printf("Carta 1 - Estado: %s, Código: %c0%d, Densidade Populacional: %.2f hab/km², Pontos Turisticos: %d\n", nome1, estado1, codCarta1, dpop1, pTuristico1);
        printf("Carta 2 - Estado: %s, Código: %c0%d, Densidade Populacional: %.2f hab/km², Pontos Turisticos: %d\n", nome2, estado2, codCarta2, dpop2, pTuristico2);
        res2 = dpop1 < dpop2 ? 1 : 0;
        //empt2 = dpop1 == dpop2 ? 1 : 0;
        break;
    case 4:
        printf("Carta 1 - Estado: %s, Código: %c0%d, PIB: %.2f bilhões de reais, Pontos Turisticos: %d\n", nome1, estado1, codCarta1, pib1, pTuristico1);
        printf("Carta 2 - Estado: %s, Código: %c0%d, PIB: %.2f bilhões de reais, Pontos Turisticos: %d\n", nome2, estado2, codCarta2, pib2, pTuristico2);
        res2 = pib1 > pib2 ? 1 : 0;
        //empt2 = pib1 == pib2 ? 1 : 0;
        break;
    case 5:
        printf("Carta 1 - Estado: %s, Código: %c0%d, PIB per Capita: %.2f reais: %.2f, Pontos Turisticos: %d\n", nome1, estado1, codCarta1, pibper1, pTuristico1);
        printf("Carta 2 - Estado: %s, Código: %c0%d, PIB per Capita: %.2f reais, Pontos Turisticos: %d\n", nome2, estado2, codCarta2, pibper2, pTuristico2);
        res2 = pibper1 > pibper2 ? 1 : 0;
        //empt2 = pibper1 == pibper2 ? 1 : 0;
        break;
    case 6:
        printf("Carta 1 - Estado: %s, Código: %c0%d, Pontos Turisticos: %d\n", nome1, estado1, codCarta1, pTuristico1);
        printf("Carta 2 - Estado: %s, Código: %c0%d, Pontos Turisticos: %d\n", nome2, estado2, codCarta2, pTuristico2);
        res2 = pTuristico1 > pTuristico2 ? 1 : 0;
        //empt2 = pTuristico1 == pTuristico2 ? 1 : 0;
        break;
    
    default:
    printf("Opção Inválida\n");
        break;
    }

    /*if(empt1 == 1 && empt2 == 1){
        printf("\n----Empate entre as Cartas!----\n");
    }
    */
    if((res1 == 1) && (res2 == 0) || (res1 == 0) && (res2 == 1)){
        printf("\n----Empate entre as Cartas!----\n");
    } else if((res1 == 1) && (res2 == 1)) {
        printf("\n----A carta 1 venceu----\n");
    } else {
        printf("\n----A carta 2 venceu----\n");
    }
    // Fim do programa
    return 0;
}
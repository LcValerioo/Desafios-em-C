#include <stdio.h>
#include <string.h>

#define MAX 20
#define TAM 7

// ANÁLISE DE ALGORITMO - Desafio Chef Sort
// Este é o arquivo inicial para o desafio. 
// Dependendo do nível escolhido (Novato, Aventureiro ou Mestre), 
// descomente e utilize as estruturas e funções correspondentes.

// ====================================================================
// ESTRUTURAS DE DADOS (Para Níveis Aventureiro e Mestre)
// ====================================================================

// Struct para o Nível Aventureiro

typedef struct {
    char nome[50];
    int qtd_ingredientes;
} Prato;


// Struct para o Nível Mestre

typedef struct {
    char nome_prato[50];
    int numero_comanda;
} Comanda;



// ====================================================================
// PROTÓTIPOS DAS FUNÇÕES DE ORDENAÇÃO
// ====================================================================

// Nível Novato: Bubble Sort para strings
// Dica: Use strcmp() da biblioteca <string.h> para comparar strings.
// Dica: Passe ponteiros para contadores de comparações e trocas se quiser alterá-los dentro da função.
// Função para imprimir os ingredientes
void imprimir(char ingredientes[TAM][MAX]){
    for(int i = 0; i < TAM; i++){
        printf("%s\n", ingredientes[i]);
    }
}

// Bubble Sort para strings
void bubbleSort(char ingredientes[TAM][MAX], int *comp, int *trocas){
    int i, j;
    char temp[MAX];
    int trocou;

    for(i = 0; i < TAM - 1; i++){
        trocou = 0;

        for(j = 0; j < TAM - i - 1; j++){
            (*comp)++;

            // strcmp > 0 significa que a string da esquerda é "maior"
            if(strcmp(ingredientes[j], ingredientes[j + 1]) > 0){
                strcpy(temp, ingredientes[j]);
                strcpy(ingredientes[j], ingredientes[j + 1]);
                strcpy(ingredientes[j + 1], temp);

                (*trocas)++;
                trocou = 1;
            }
        }

        if(!trocou)
            break;
    }
}

// Nível Aventureiro: Selection Sort para array de structs (Prato)

void selectionSortPratos(Prato arr[], int n) {
    int i, j, min_idx;
    Prato temp;
    int comp = 0, trocas = 0;

    for(i = 0; i < n - 1; i++){
        min_idx = i;

        for(j = i + 1; j < n; j++){
            comp++;
            if(arr[j].qtd_ingredientes < arr[min_idx].qtd_ingredientes){
                min_idx = j;
            }
        }

        if(min_idx != i){
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            trocas++;
        }
    }

    printf("\nNumero de comparacoes: %d\n", comp);
    printf("Numero de trocas: %d\n", trocas);
}

void imprimePratos(Prato arr[], int n) {
    printf("\n--- Lista de Pratos ---\n");
    printf("%-25s || %-20s\n", "Nome do Prato", "Qtd Ingredientes");
    printf("=================================================\n");
    for(int i = 0; i < n; i++){
        printf("%-25s || %-20d\n", arr[i].nome, arr[i].qtd_ingredientes);
    }

    printf("=================================================\n");
}


// Nível Mestre: Recursive Insertion Sort para array de structs (Comanda)
// Dica: Lembre-se de definir o "caso base" (n <= 1) para parar a recursão!

void recursiveInsertionSort(Comanda arr[], int n) {
    // CASO BASE: Se o array tiver 1 ou 0 elementos, já está ordenado
    if (n <= 1) {
        return;
    }

    // CHAMADA RECURSIVA: Ordena os primeiros n-1 elementos
    recursiveInsertionSort(arr, n - 1);

    // TRABALHO ATUAL: Insere o último elemento na posição correta
    Comanda last = arr[n - 1];
    int j = n - 2;

    // Move os elementos maiores que 'last' para uma posição à frente
    while (j >= 0 && arr[j].numero_comanda > last.numero_comanda) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

void imprimirStatusCozinha(Comanda arr[], int n) {
    printf("\n--- Status da Cozinha (Comandas) ---\n");
    printf("%-25s || %-20s\n", "Nome do Prato", "Numero da Comanda");
    printf("===============================================\n");
    for(int i = 0; i < n; i++){
        printf("%-25s || %-20d\n", arr[i].nome_prato, arr[i].numero_comanda);
    }

    printf("===============================================\n");
}



// ====================================================================
// FUNÇÃO PRINCIPAL
// ====================================================================

int main() {
    printf("=== BEM-VINDO AO CHEF SORT ===\n\n");
    int escolha = -1;
    while(escolha != 0){
    printf("Escolha o nivel de dificuldade:\n");
    printf("1. Novato (Organizar a Despensa com Bubble Sort)\n");
    printf("2. Aventureiro (Organizar os Pratos com Selection Sort)\n");
    printf("3. Mestre (Organizar as Comandas com Recursive Insertion Sort)\n");
    printf("0. Sair\n");
    
    scanf("%d", &escolha);

    
    switch (escolha)
    {
    case  1:
    // ÁREA DO NÍVEL NOVATO (Despensa / Bubble Sort)
    //  Cenário: cozinha em caos
    char ingredientes[TAM][MAX] = {
        "Tomate",
        "Cebola",
        "Alho",
        "Cenoura",
        "Batata",
        "Pimentao",
        "Pao"
    };

    printf("COZINHA EM CAOS!\n");
    printf("Os ingredientes chegaram desorganizados...\n\n");

    printf("Ingredientes ANTES da ordenacao:\n");
    imprimir(ingredientes);
    printf("\n----------------------------------------------\n");

    int comp = 0, trocas = 0;
    bubbleSort(ingredientes, &comp, &trocas);

    printf("\nIngredientes DEPOIS da ordenacao:\n");
    imprimir(ingredientes);
    printf("\n----------------------------------------------\n");

    printf("\nMetricas do algoritmo:\n");
    printf("Comparacoes: %d\n", comp);
    printf("Trocas: %d\n", trocas);

    printf("\n");

        break;
    case  2:
        // ---------------------------------------------------------
    // ÁREA DO NÍVEL AVENTUREIRO (Pratos / Selection Sort)
    // ---------------------------------------------------------
    
    // Inicialize aqui o seu vetor de Pratos
    Prato pratos[5] = {
        {"Pizza", 5},
        {"Salada", 3},
        {"Macarrao", 4},
        {"Hamburguer", 6},
        {"Sushi", 7}
    };

    printf("\n--- Nivel Aventureiro: Organizando os Pratos ---\n");
    // Imprima antes, chame a funcao selectionSortPratos, imprima depois
    imprimePratos(pratos, 5);
    selectionSortPratos(pratos, 5);
    imprimePratos(pratos, 5);


        break;
    case  3:
        // ---------------------------------------------------------
    // ÁREA DO NÍVEL MESTRE (Comandas / Recursive Insertion Sort)
    // ---------------------------------------------------------
    
    // Inicialize aqui o seu vetor de Comandas
    Comanda pedidos[5] = {
        {"Pizza", 105},
        {"Salada", 102},
        {"Macarrao", 104},
        {"Hamburguer", 101},
        {"Sushi", 103}
    };

    int n = 5; // Número de comandas
    int comparacoes = 0, movimentacoes = 0; // Contadores para métricas

    printf("\n--- Nivel Mestre: Organizando as Comandas ---\n");
    printf("Pedidos chegando (Desordenados):\n");
    imprimirStatusCozinha(pedidos, n);

    //Colocando ordem na casa (ordenando as comandas)
    recursiveInsertionSort(pedidos, n);

    printf("Pedidos organizados (Ordenados por numero de comanda):\n");
    imprimirStatusCozinha(pedidos, n);
    printf("Metricas - Comparacoes: %d | Movimentacoes: %d\n", comparacoes, movimentacoes);
        break;
    case  0:
        printf("Saindo do Chef Sort. Ate a proxima!\n");

        printf("\n");
        break;
        //return 0;
    default:
        printf("Opcao invalida. Tente novamente.\n");
        printf("\n");
        //return 1;
    }
    }
    printf("\nObrigado por jogar o Chef Sort! Ate a proxima!\n");

    return 0;
}
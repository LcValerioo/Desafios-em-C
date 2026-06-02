#include<stdio.h>
#include<string.h>

//Requisito Funcional 1: Estrutura de Dados para a Carta
struct Carta{
    int id;
    char nome[50];
    int ataque;
    int defesa;
    int energia;
    int raridade;
};

struct Metricas{
    int comparacoes;
    int trocas;
};

//----- FUNÇÕES AUXILIARES -----

/**
 * @param titulo: Um texto para ser exibido antes da lista de cartas.
 * @param mao: O vetor de cartas a ser impresso.
 * @param n: O número de cartas na vetor.
 */
void imprimirMao(const char *titulo, struct Carta mao[], int n){
    printf("%s\n", titulo);
    printf("------------------------------------------------------------------\n");
    printf("%-5s %-30s %-10s %-10s %-10s\n", "id", "Nome", "Ataque", "Defesa","energia");
    printf("------------------------------------------------------------------\n");
    for(int i = 0; i < n; i++){
        printf("%-5d %-30s %-10d %-10d %-10d\n", mao[i].id, mao[i].nome, mao[i].ataque, mao[i].defesa, mao[i].energia);
    }
    printf("\n");
}

//----- ALGORITIMO DE ORDENAÇÃO -----
/**
*@brief: Ordena um vetor de cartas usando o algoritmo Insertion Sort.
*
*Requisitos Funcional 4: A ordenação é baseada no campo 'ataque' em ordem decrescente.
*
*@param mao: O vetor de cartas a ser ordenado.
*@param n: O número de cartas no vetor.
*/

void shellSort(struct Carta mao[], int n, struct Metricas *stats){
    int h; // 'h' representa o gap (distância) entre os elementos a serem comparados e ordenados.
    

    //Calcula o gap inicial usando a sequencia de Knuth (h = 3*h + 1)
    //Este laço apenas encontra o 'h' inicial ideal para o tamanho do vetor.
    for(h = 1; h < n / 3; h = 3 * h + 1);

    //Laço principal que começa com o maior gap e o reduz a cada passada.
    for(; h >= 1; h /= 3){
        // O laço abaixo é o InsertionSort, mas adaptado para usar o gap 'h'.
        // Em vez de comparar com o vizinho (j-1), ele compara com o elemento 'h' posições atrás (j-h).

        for(int i = h; i < n; i++){
            // 'chave' é a carta que será posicionada corretamente em seu sub-grupo.
            struct Carta chave = mao[i];
            int j = i;

            //Compara a carta 'chave' com as cartas anteriores no mesmo sub-grupo.
            while(j >= h &&
                 (mao[j-h].ataque < chave.ataque ||
                     (mao[j-h].ataque == chave.ataque &&
                         mao[j-h].energia < chave.energia) ||
                          (mao[j-h].ataque == chave.ataque &&
                             mao[j-h].energia == chave.energia &&
                              mao[j-h].raridade < chave.raridade))){
                stats->comparacoes++;
                mao[j] = mao[j - h]; //Move a carta para a direita
                j -= h; //Move 'j' para o próximo elemento do sub-grupo
                stats->trocas++;
            }
            if((mao[j-h].ataque < chave.ataque ||
                 (mao[j-h].ataque == chave.ataque &&
                     mao[j-h].energia < chave.energia))) 
            {
                stats->comparacoes++; // Contabiliza a comparação final que falhou

            }             
            //Insere a carta 'chave' na posição correta.
            mao[j] = chave;
            stats->trocas++;
        }
    }
}

//----- FUNÇÃO PRINCIPAL -----

int main(){
    //Requisito Funcional 2: Gerar um conjunto de 7 cartas desordenadas.
    struct Carta mao_inicial[40] = {
    {105, "Ogro Esmagador", 5, 4, 5, 2},
    {102, "Elfa Arqueira", 2, 1, 2, 1},
    {201, "Lobo das Sombras", 3, 2, 2, 1},
    {107, "Anjo da Furia", 6, 5, 6, 3},
    {301, "Mago de Gelo", 2, 4, 3, 2},
    {101, "Goblin Batedor", 1, 1, 1, 1},
    {205, "Ciclope Brutal", 7, 5, 6, 2},
    {103, "Guardião de Pedra", 2, 5, 4, 1},
    {305, "Hidra de Nove Cabeças", 8, 8, 9, 4}, // Lendária!
    {106, "Cavaleiro de Aco", 3, 3, 3, 2},
    {210, "Grifo Veloz", 4, 3, 4, 1},
    {104, "Dragao das Cinzas", 7, 7, 8, 3},
    {215, "Minotauro Guerreiro", 5, 6, 5, 2},
    {310, "Feiticeira Arcana", 4, 2, 5, 3},
    {220, "Basilisco Petrificante", 3, 5, 4, 2},
    {110, "Clerigo Iluminado", 1, 3, 2, 1},
    {225, "Elemental de Fogo", 6, 2, 5, 2},
    {315, "Paladino da Ordem", 5, 7, 7, 3},
    {115, "Besta Feral", 4, 1, 3, 1},
    {230, "Gargula de Granito", 3, 6, 4, 2},
    {120, "Sombra Venenosa", 2, 2, 3, 1},
    {235, "Serpente Marinha", 5, 4, 6, 3},
    {125, "Assassino Silencioso", 4, 2, 4, 2},
    {240, "Troll Regenerador", 6, 5, 7, 3},
    {130, "Bardo Encantador", 1, 2, 3, 1},
    {245, "Fenix Renascida", 7, 4, 8, 4},
    {135, "Guerreiro Tribal", 3, 3, 4, 2},
    {250, "Vampiro Sanguinário", 5, 3, 6, 3},
    {140, "Druida da Floresta", 2, 4, 5, 2},
    {255, "Gigante de Pedra", 8, 7, 9, 4},
    {145, "Ladino Astuto", 4, 2, 5, 2},
    {260, "Manticora Selvagem", 6, 5, 7, 3},
    {150, "Feiticeiro das Trevas", 5, 3, 6, 3},
    {265, "Dragao Ancião", 9, 9, 10, 5}, // Lendária!
    {155, "Paladino da Luz", 4, 6, 7, 3},
    {270, "Serpente do Abismo", 7, 6, 8, 4},
    {160, "Guerreiro do Deserto", 3, 4, 5, 2},
    {275,"Fada da Floresta Encantada",2 ,1 ,3 ,1},
    {165, "Mago do Caos", 6, 2, 5, 3},
    {280, "Titã Colossal", 8, 8, 9, 4}
    };
    int n = sizeof(mao_inicial) / sizeof(mao_inicial[0]);

    //Reqiosotp Funcional 3: Imprimir a mão de cartas antes da ordenação.
    //Requisito Não Funcional 1: Saida formatada e legível.
    imprimirMao("### Mao de Cartas Antes da Ordenacao ###", mao_inicial, n);

    //Chama a função de ordenação para organizar as cartas com base no custo_de_mana.
    //Requisito Não funcional 2: Implementação manual do algoritmo de ordenação (Insertion Sort).
    struct Metricas metricas = {0, 0};
    shellSort(mao_inicial, n, &metricas);

    //Requisito Funcional 5: Imprimir a mão de cartas após a ordenação.
    imprimirMao("### Mao de Cartas Depois da Ordenacao ###", mao_inicial, n);

    //Requisito Funcional 6: Mensagem de conclusão.
    printf("Mao organizada! Pronto para a batalha!\n");
    printf("Comparacoes: %d\n", metricas.comparacoes);
    printf("Trocas: %d\n", metricas.trocas);


    return 0;
}
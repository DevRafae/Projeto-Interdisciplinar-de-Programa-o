#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct caixa { // Estrutura que representa cada nó da lista (sapato)
    int numero;        // Número do sapato
    char cor[30];      // Cor do sapato
    struct caixa *prox; // Ponteiro para o próximo nó
} caixa;

typedef struct Infosapatos { // Estrutura que representa a lista em si
    caixa *prim; // Ponteiro para o primeiro nó da lista
} Infosapatos;

void criaLista(Infosapatos *primeirodal) { 
    // Inicializa a lista vazia (sem nenhum nó)
    primeirodal->prim = NULL;
}

void insereIni(Infosapatos *primeirodal, int n, const char *c) {
    // Cria um novo nó e insere no início da lista
    caixa *novo = (caixa*) malloc(sizeof(caixa)); // Aloca memória para o novo nó
    novo->numero = n;                             // Define o número do sapato
    strcpy(novo->cor, c);                         // Copia a cor para o novo nó
    novo->prox = primeirodal->prim;               // Aponta o novo nó para o antigo primeiro nó
    primeirodal->prim = novo;                     // Atualiza o primeiro nó da lista
}

void mostraLista(Infosapatos *primeirodal) { 
    // Percorre todos os nós da lista e imprime suas informações
    caixa *p;
    for(p = primeirodal->prim; p != NULL; p = p->prox) {
        printf("numero: %d\tcor: %s\n", p->numero, p->cor);
    }
}

int estaVazia(Infosapatos *primeirodal) {
    // Retorna 1 se a lista estiver vazia, 0 caso contrário
    return (primeirodal->prim == NULL);
}

int main() {
    Infosapatos lista;         // Declara a lista
    criaLista(&lista);         // Inicializa a lista vazia

    insereIni(&lista, 39, "azul"); // Insere sapatos na lista
    insereIni(&lista, 42, "vermelho");

    mostraLista(&lista);       // Mostra todos os sapatos da lista

    if (estaVazia(&lista))
        printf("Lista vazia\n");
    else
        printf("Lista com elementos\n");

    return 0;
}

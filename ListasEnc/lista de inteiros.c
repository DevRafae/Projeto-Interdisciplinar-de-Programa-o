#include <stdio.h>
#include <stdlib.h>

typedef struct dados {   // nó da lista
    int numero;
    struct dados *prox;
} dados;

typedef struct listaenc {  // lista em si
    dados *prim;
} listaenc;

void criaLista(listaenc *lista) {
    lista->prim = NULL;
}

void insereIni(listaenc *lista, int n) {
    dados *novo = (dados*) malloc(sizeof(dados));
    novo->numero = n;
    novo->prox = lista->prim;
    lista->prim = novo;
}

void mostraLista(listaenc *lista) {
    dados *p;
    for(p = lista->prim; p != NULL; p = p->prox) {
        printf("numero: %d\n", p->numero);
    }
}

int estaVazia(listaenc *lista) {
    return (lista->prim == NULL);
}

int main() {
    listaenc lista;         // Declara a lista
    criaLista(&lista);      // Inicializa a lista vazia

    insereIni(&lista, 2005);
    insereIni(&lista, 5);
    insereIni(&lista, 18);

    mostraLista(&lista);       // Mostra todos os elementos

    if (estaVazia(&lista))
        printf("Lista vazia\n");
    else
        printf("Lista com elementos\n");

    return 0;
}

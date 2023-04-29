/**
 * This `lista.c` file defines common methods used to create
 * linked lists defined in `lista.h`
 */
#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

lista *criaLista() {
    lista *l = malloc(sizeof(lista));
    if (!l) return NULL;

    l->cabeca = NULL;
    l->numElementos = 0;

    return l;
}

int insere(lista *l, int dado) {
    nodo *novo, *aux;

    novo = malloc(sizeof(nodo));
    if (!novo) {
        return 0;
    }

    novo->dado = dado;
    novo->prox = NULL;
    novo->lista = NULL;

    if (!l->cabeca) {
        l->cabeca = novo;
    } else {
        aux = l->cabeca;
        while (aux->prox) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    l->numElementos++;

    return 1;
}

lista *destroiLista(lista *l) {
    nodo *aux;

    if (l->cabeca) {
        while (l->cabeca->prox) {
            aux = l->cabeca;
            l->cabeca = l->cabeca->prox;
            if (aux->lista) {
                destroiLista(aux->lista);
            }
            free(aux);
        }
        if (l->cabeca->lista) {
            destroiLista(l->cabeca->lista);
        }
        free(l->cabeca);
    }

    free(l);
    return NULL;
}

int existe(lista *l, int dado) {
    nodo *aux;

    if (!l->cabeca) {
        return 0;
    }

    aux = l->cabeca;
    while (aux) {
        if (aux->dado == dado) {
            return 1;
        }
        aux = aux->prox;
    }

    return 0;
}

/**
 * Insere o inteiro 'posicao' na lista de posições do caractere 'caractere'.
 */
int insereSubLista(lista *l, char caractere, int posicao) {
    nodo *aux;

    if (l->cabeca == NULL) {
        return 0;
    }

    aux = l->cabeca;
    while (aux) {
        if (aux->dado == caractere) {
            if (aux->lista == NULL) {
                aux->lista = criaLista();
            }
            if(!insere(aux->lista, posicao)) {
                return 0;
            }
            return 1;
        }
        aux = aux->prox;
    }

    return 0;
}

void imprimeLista(lista *l) {
    nodo *aux;

    if (l->cabeca == NULL) {
        printf("Lista vazia \n");
        return;
    }

    aux = l->cabeca;
    while (aux != NULL) {
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

void imprimeSubListas(lista *l) {
    nodo *aux;

    if (l->cabeca == NULL) {
        printf("Lista vazia \n");
        return;
    }

    aux = l->cabeca;
    while (aux != NULL) {
        printf("%c: ", aux->dado);
        imprimeLista(aux->lista);
        aux = aux->prox;
    }
}

void escreveLista(lista *l, FILE *arquivo) {
    nodo *aux;

    if (l->cabeca == NULL) {
        printf("Lista vazia \n");
        return;
    }

    aux = l->cabeca;
    while (aux != NULL) {
        fprintf(arquivo, "%d", aux->dado);
        if (aux->prox != NULL) {
            fprintf(arquivo, " ");
        }
        aux = aux->prox;
    }
    fprintf(arquivo, "\n");
}

void escreveSubListas(lista *l, FILE *arquivo) {
    nodo *aux;

    if (l->cabeca == NULL) {
        printf("Lista vazia \n");
        return;
    }

    aux = l->cabeca;
    while (aux != NULL) {
        fprintf(arquivo, "%c: ", aux->dado);
        escreveLista(aux->lista, arquivo);
        aux = aux->prox;
    }
}

lista *busca(lista *l, int dado) {
    nodo *aux;

    if (l->cabeca == NULL) {
        return NULL;
    }

    aux = l->cabeca;
    while (aux) {
        if (aux->dado == dado) {
            return aux->lista;
        }
        aux = aux->prox;
    }

    return NULL;
}

void escrevePosicaoEspecifica(lista *l, int posicao, FILE *arquivo) {
    int i = 0;

    nodo *aux = l->cabeca;
    while (aux) {
        if (i == posicao) {
            fprintf(arquivo, "%d ", aux->dado);
            return;
        }
        i++;
        aux = aux->prox;
    }
}
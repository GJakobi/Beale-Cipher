#include <stdio.h>

#ifndef LISTA_H
#define LISTA_H

/**
 * Se o nodo armazenar um caractere, ele apontará para uma lista de posições.
 */
typedef struct nodo {
    int dado;
    struct nodo *prox;
    struct lista *lista;
} nodo;

typedef struct lista {
    nodo *cabeca;
    int numElementos;
} lista;

lista *criaLista();

int insere(lista *l, int data);

void imprimeLista(lista *l);

lista *destroiLista(lista *l);

int existe(lista *l, int dado);

int insereSubLista(lista *l, char caractere, int posicao);

void imprimeSubListas(lista *l);

/**
 * Escreve a lista de caracteres com suas sublistas em um arquivo.
 */
void escreveSubListas(lista *l, FILE *arquivo);

/**
 * Busca um caractere na lista e retorna a lista de posicoes dele.
 */
lista *busca(lista *l, int dado);

/**
 * Dado uma lista de posições, escreve a posição especificada no arquivo.
 */
void escrevePosicaoEspecifica(lista *l, int posicao, FILE *arquivo);

#endif
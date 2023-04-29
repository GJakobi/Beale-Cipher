#include "lista.h"

/**
 * Insere o caractere "c" no livro de chaves caso ele não exista,
 * e a sua respectiva posição.
 */
void insereLivroChave(char c, lista* lista, int posicao);

/**
 * Escreve o livro de chaves no arquivo "caminhoArquivoChaves".
 */
void escreveLivroChave(char* caminhoArquivoChaves, lista* listaDeChaves);

/**
 * Cria uma lista de chaves a partir de um livro cifra.
 */
void criaListaDeChaves(FILE* livroCifra, lista* listaDeChaves);

/**
 * Procura a posicao na lista, e retorna o char correspondente.
 */
char procuraCharNaLista(lista* lista, int posicao);

/**
 *  Cria uma lista de chaves a partir de um arquivo de chaves.
 */
void criaListaDeChavesDeTexto(FILE* arquivoChaves, lista* listaDeChaves);

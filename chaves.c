#include "chaves.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void insereLivroChave(char c, lista* lista, int posicao) {
    c = tolower(c);
    if (!existe(lista, c)) {
        if (!insere(lista, c)) {
            fprintf(stderr,
                    "Erro: não foi possível inserir na lista de caracteres.\n");
            exit(1);
        }
    }
    insereSubLista(lista, c, posicao);
}

/**
 * Retorna verdadeiro caso seja o início de uma palavra (primeira letra).
 */
int ehComecoDePalavra(char caractereAnterior, char caractereAtual) {
    return (caractereAnterior == ' ' || caractereAnterior == '\n') &&
           caractereAtual != ' ' && caractereAtual != '\n';
}

void escreveLivroChave(char* caminhoArquivoChaves, lista* listaDeChaves) {
    FILE* arquivoChaves;

    arquivoChaves = fopen(caminhoArquivoChaves, "w");
    if (!arquivoChaves) {
        perror("Erro: não foi possível criar o arquivo.\n");
        exit(1);
    }

    if (listaDeChaves->cabeca == NULL) {
        printf("Lista de chaves vazia. \n");
        return;
    }

    escreveSubListas(listaDeChaves, arquivoChaves);

    fclose(arquivoChaves);
}

void criaListaDeChaves(FILE* livroCifra, lista* listaDeChaves) {
    char caractereAnterior = ' ', c;
    int i = 0;

    while ((c = fgetc(livroCifra)) != EOF) {
        if (ehComecoDePalavra(caractereAnterior, c)) {
            insereLivroChave(c, listaDeChaves, i);
            i++;
        }
        caractereAnterior = c;
    }
}

void criaListaDeChavesDeTexto(FILE* arquivoChaves, lista* listaDeChaves) {
    char letra, temp;
    int posicao;

    while (fscanf(arquivoChaves, " %c:", &letra) == 1) {
        while (fscanf(arquivoChaves, " %d", &posicao) == 1) {
            insereLivroChave(letra, listaDeChaves, posicao);
            
            temp = getc(arquivoChaves);
            if (temp == '\n') {
                break;
            } else {
                ungetc(temp, arquivoChaves);
            }
        }
    }
}

char procuraCharNaLista(lista* lista, int posicao) {
    nodo *auxCaractere = lista->cabeca, *auxPosicao;

    if (!lista || !lista->cabeca) {
        return '?';
    }

    while (auxCaractere) {
        auxPosicao = auxCaractere->lista->cabeca;
        while (auxPosicao) {
            if (auxPosicao->dado == posicao) {
                return auxCaractere->dado;
            }
            auxPosicao = auxPosicao->prox;
        }

        auxCaractere = auxCaractere->prox;
    }

    return '?';
}
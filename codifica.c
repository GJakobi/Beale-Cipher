#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "chaves.h"
#include "lista.h"

void escreveArquivoCodificado(char* caminhoArquivoCodificado,
                              FILE* mensagemOriginal, lista* listaDeChaves) {
    FILE* arquivoCodificado;
    char c;
    int posicaoAleatoria;

    arquivoCodificado = fopen(caminhoArquivoCodificado, "w");
    if (!arquivoCodificado) {
        perror("Erro: não foi possível criar o arquivo.\n");
        exit(1);
    }

    while ((c = fgetc(mensagemOriginal)) != EOF) {
        if (c == ' ') {
            fprintf(arquivoCodificado, "-1 ");
        } else if (c == '\n') {
            fprintf(arquivoCodificado, "-2 ");
        } else {
            c = tolower(c);
            lista* listaPosicoes = busca(listaDeChaves, c);
            if (listaPosicoes) {
                posicaoAleatoria = rand() % listaPosicoes->numElementos;

                escrevePosicaoEspecifica(listaPosicoes, posicaoAleatoria,
                                         arquivoCodificado);
            } else {
                fprintf(arquivoCodificado, "-3 ");
            }
        }
    }

    fclose(arquivoCodificado);
}

void validaArgumentos(char* caminhoLivroCifra, char* caminhoMensagemOriginal,
                      char* caminhoOutput) {
    if (!caminhoLivroCifra) {
        fprintf(stderr, "Erro: caminho do livro cifra não foi informado.\n");
        exit(1);
    }

    if (!caminhoMensagemOriginal) {
        fprintf(stderr, "Erro: caminho da mensagem não informado.\n");
        exit(1);
    }

    if (!caminhoOutput) {
        fprintf(stderr,
                "Erro: caminho do arquivo de saída não foi informado.\n");
        exit(1);
    }
}

void codificar(char* caminhoLivroCifra, char* caminhoArquivoChaves,
               char* caminhoMensagemOriginal, char* caminhoOutput) {
    FILE *livroCifra, *mensagemOriginal;
    lista* listaDeChaves = criaLista();

    if (!listaDeChaves) {
        fprintf(stderr, "Erro: não foi possível criar lista de chaves.\n");
        exit(1);
    }

    validaArgumentos(caminhoLivroCifra, caminhoMensagemOriginal, caminhoOutput);

    livroCifra = fopen(caminhoLivroCifra, "r");
    if (!livroCifra) {
        perror("Erro: não foi possível abrir o arquivo.\n");
        exit(1);
    }

    criaListaDeChaves(livroCifra, listaDeChaves);

    if (caminhoArquivoChaves) {
        escreveLivroChave(caminhoArquivoChaves, listaDeChaves);
    }

    mensagemOriginal = fopen(caminhoMensagemOriginal, "r");
    if (!mensagemOriginal) {
        perror("Erro: não foi possível abrir o arquivo.\n");
        exit(1);
    }

    escreveArquivoCodificado(caminhoOutput, mensagemOriginal, listaDeChaves);

    listaDeChaves = destroiLista(listaDeChaves);
    fclose(livroCifra);
    fclose(mensagemOriginal);
}
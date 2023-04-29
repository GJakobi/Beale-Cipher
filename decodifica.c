#include <stdio.h>
#include <stdlib.h>

#include "chaves.h"
#include "lista.h"

void escreveArquivoDecodificado(FILE* mensagemCodificada,
                                FILE* arquivoDecodificado,
                                lista* listaDeChaves) {
    int posicao;
    char c;

    while (fscanf(mensagemCodificada, "%d", &posicao) != EOF) {
        if (posicao == -1) {
            fprintf(arquivoDecodificado, " ");
        } else if (posicao == -2) {
            fprintf(arquivoDecodificado, "\n");
        } else if (posicao == -3) {
            fprintf(arquivoDecodificado, "?");
        } else {
            c = procuraCharNaLista(listaDeChaves, posicao);
            fprintf(arquivoDecodificado, "%c", c);
        }
    }
}

void validaArgumentosDecodificacao(char* caminhoMensagemCodificada, char* caminhoOutput) {
    if (!caminhoMensagemCodificada) {
        fprintf(stderr,
                "Erro: caminho da mensagem codificada não informado.\n");
        exit(1);
    }

    if (!caminhoOutput) {
        fprintf(stderr, "Erro: caminho do arquivo de saída não informado.\n");
        exit(1);
    }
}

void decodificar(char* caminhoMensagemCodificada, char* caminhoOutput,
                 char* caminhoArquivoChaves, char* caminhoLivroCifra) {
    FILE *arquivoChaves, *mensagemCodificada, *arquivoDecodificado, *livroCifra;
    lista* listaDeChaves = criaLista();

    if (!listaDeChaves) {
        fprintf(stderr, "Erro: não foi possível criar lista de chaves.\n");
        exit(1);
    }

    validaArgumentosDecodificacao(caminhoMensagemCodificada, caminhoOutput);

    mensagemCodificada = fopen(caminhoMensagemCodificada, "r");
    if (!mensagemCodificada) {
        perror("Erro: não foi possível abrir o arquivo.\n");
        exit(1);
    }

    arquivoDecodificado = fopen(caminhoOutput, "w");
    if (!arquivoDecodificado) {
        perror("Erro: não foi possível criar o arquivo.\n");
        exit(1);
    }

    if (!caminhoArquivoChaves) {
        if (!caminhoLivroCifra) {
            fprintf(stderr,
                    "Erro: caminho do livro cifra não foi informado.\n");
            exit(1);
        }

        livroCifra = fopen(caminhoLivroCifra, "r");
        if (!livroCifra) {
            perror("Erro: não foi possível abrir o arquivo.\n");
            exit(1);
        }

        criaListaDeChaves(livroCifra, listaDeChaves);

        escreveArquivoDecodificado(mensagemCodificada, arquivoDecodificado,
                                   listaDeChaves);

        fclose(livroCifra);
    } else {
        arquivoChaves = fopen(caminhoArquivoChaves, "r");
        if (!arquivoChaves) {
            perror("Erro: não foi possível abrir o arquivo.\n");
            exit(1);
        }

        criaListaDeChavesDeTexto(arquivoChaves, listaDeChaves);

        escreveArquivoDecodificado(mensagemCodificada, arquivoDecodificado,
                                   listaDeChaves);

        fclose(arquivoChaves);
    }

    fclose(mensagemCodificada);
    fclose(arquivoDecodificado);
    listaDeChaves = destroiLista(listaDeChaves);
    return;
}
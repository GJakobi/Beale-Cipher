#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "chaves.h"
#include "codifica.h"
#include "lista.h"
#include "decodifica.h"

int main(int argc, char* argv[]) {
    int flagCodificar = 0, flagDecodificar = 0, option;
    char *caminhoLivroCifra = NULL, *caminhoArquivoChaves = NULL,
         *caminhoMensagemOriginal = NULL, *caminhoOutput = NULL,
         *caminhoMensagemCodificada = NULL;

    srand(time(NULL));

    while ((option = getopt(argc, argv, "eb:m:o:c:i:d")) != -1) {
        switch (option) {
            case 'e':
                flagCodificar = 1;
                break;
            case 'd':
                flagDecodificar = 1;
                break;
            case 'b':
                caminhoLivroCifra = optarg;
                break;
            case 'm':
                caminhoMensagemOriginal = optarg;
                break;
            case 'o':
                caminhoOutput = optarg;
                break;
            case 'c':
                caminhoArquivoChaves = optarg;
                break;
            case 'i':
                caminhoMensagemCodificada = optarg;
                break;
            default:
                fprintf(stderr, "Erro: opção inválida usada.\n");
                exit(1);
        }
    }

    if (flagCodificar) {
        codificar(caminhoLivroCifra, caminhoArquivoChaves,
                  caminhoMensagemOriginal, caminhoOutput);
    } else if (flagDecodificar) {
        decodificar(caminhoMensagemCodificada, caminhoOutput,
                    caminhoArquivoChaves, caminhoLivroCifra);
    } else {
        fprintf(stderr, "Erro: nenhuma opção foi selecionada.\n");
        exit(1);
    }

    return 0;
}
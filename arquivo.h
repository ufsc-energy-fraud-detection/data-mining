/*
 * arquivo.h
 *
 *  Created on: 14 de set de 2016
 *      Author: thiagordp
 */

#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdlib.h>
#include <stdio.h>

/**
 * Quantidade máxima de dígitos para o vetor de char
 */
#define QTD_DIGITOS_CHAR  12

/**
 * Máximo tamanho da linha que será linha da base de dados
 */
#define MAX_SIZE_LINE 70

/**
 * Modo de abertura de somente leitura e criação automática em caso de não existência do arquivo
 */
#define MODO_OP_BASE "r+"

/**
 * Modo de abertura de leitura e escrita e criação automática em caso de não existência do arquivo
 */
#define MODO_OP_ENTR "w+"

/**
 * Abrir um arquivo
 * @param nomeArquivo Nome do arquivo que será aberto
 * @return Ponteiro para o FILE do arquivo
 */
FILE *fileOpen(char nomeArquivo[]);

/**
 * Escrever no arquivo uma cadeia de caracteres
 * @param arq Arquivo que receberá o conteúdo
 * @param conteudo Cadeia de caracteres para escrita
 */
void fileWrite(FILE *arq, char conteudo[]);

//char* leArquivo(FILE *arq);

/**
 * Le próxima linha do arquivo e passar seu conteúdo para um vetor de char
 * @param arq Arquivo de origem do conteúdo
 * @param linha Ponteiro para o vetor de caracteres
 * @return Status da operação de leitura
 */
int readLine(FILE *arq, char *linha);

/**
 * Cria arquivo com nome especificado
 * @param nomeArquivo Nome do novo arquivo
 * @return Ponteiro para o arquivo criado.
 */
FILE *fileCreate(char nomeArquivo[]);

/**
 * Fecha o arquivo indicado
 * @param arq Ponteiro para o arquivo
 * @return Status da operação
 */
int closeFIle(FILE *arq);

/**
 * Escrever um valor em ponto flutuante em um arquivo
 * @param valor Valor que será escrito
 * @param arquivo Ponteiro para o arquivo de destino
 */
void floatToFile(float valor, FILE* arquivo);
#endif

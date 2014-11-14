/**
 * Lib de menu simples para programas cmd
 */

// Include guard
#ifndef H_GRAFO
#define H_GRAFO
#pragma once

#include <stdio.h>
#include <stdlib.h>

void inicia_grafo(int vertices[], int arestas[][], int tam) {

    int i, j;

    for (i = 0; i < tam; i++)
        for (j = 0; j < tam; j++)
            arestas[i][j] = 0;

    for(i = 0; i < tam; i++)
        vertices[i] = 0;

}

void insere_grafo(int vertice[], int arestas[][], int tam, int count, int valor) {

}

#endif /* H_GRAFO */
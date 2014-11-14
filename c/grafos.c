/**
 * @Author: Reinaldo Antonio Camargo Rauch
 * @Date:   2014-10-22 19:22:46
 * @Last Modified by:   reinaldo
 * @Last Modified time: 2014-11-05 19:13:43
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "menu.h"

 #define TAM 10

int vertice[TAM];

int arestas[TAM][TAM];

int count = 0;

void inicia_grafo() {
    int i, j;

    for (i = 0; i < tam; i++)
        for (j = 0; j < tam; j++)
            arestas[i][j] = 0;

    for(i = 0; i < tam; i++)
        vertices[i] = 0;
}

void insere_vertice(int val) {
    if(count < TAM)
        vertice[cont++] = val;
    else
        puts("Erro, etouro do tamanho do grafo");
}

void update_aresta(int orig, int dest, int stat) {
    int i = 0, j = 0;

    while (i < count && orig != vertice[i++]);

    if(i == count) {
        puts("Vérice origem não existe");
        return;
    }

    while(j < count && dest != vertice[j++]);

    if(j == count) {
        puts("Vertice de destino não encontrado");
        return;
    }

    arestas[i][j] = !!stat;
}

void insere_aresta(int orig, int dest) {
    update_aresta(orig, dest, 1);
}

void remove_aresta(int orig, int dest) {
    update_aresta(orig, dest, 0);
}

void imprime_grafo() {

    int i, j;

    for (int i = 0; i < TAM; i++) {
        printf("%d = ", vertice[i]);
        for (int j = 0; j < TAM; j++)
            if(arestas[i][j] != 0)
                printf("%d", vertice[j]);
        putchar('\n');
    }

}




/**
 * Imprime o menu do programa na tela
 */
void menu() {

    puts("|  Menu:                                      |");
    puts("+---------------------------------------------+");
    puts("|  0: Inserir valor na tabela hash            |");
    puts("|  1: Procurar valor na tabela hash           |");
    puts("|  2: Listar tabela hash                      |");
    puts("|  3: Inserir valor na tabela hash dinâmica   |");
    puts("|  4: Procurar valor na tabela hash dinâmica  |");
    puts("|  5: Listar tabela hash dinâmica             |");
    puts("|  6: Resetar tabela hash                     |");
    puts("|  7: Resetar tabela hash dinâmica            |");
    puts("+---------------------------------------------+");

}

/**
 * Printa o header do programa na tela
 * @param withMenu se é para imprimir o menu junto ou não
 */
void header(int withMenu) {

    system("clear");

    puts("+------------------------------------------------------+");
    puts("|  Programa para teste de implementação de grafo  |");

    if(withMenu) {
        puts("+---------------------------------------------+--------+");
        menu();
    } else
        puts("+------------------------------------------------------+");

    puts("\n");

}

/**
 * Função de inicialização do programa
 */
void onProgramInit() {

}

/**
 * main function
 * @return success
 */
int main() {

    onProgramInit();

    while (1) {

        header(1);

        switch(getOption()) {

            case '0':
                puts("Opção 0");
                // insertHashOption();
                break;
            default:
                puts("Opção inválida, tente novamente");
                break;

        }

        puts("\nAperte qualquer tecla para continuar");
        stopOnChar();

    }

    return 0;
}
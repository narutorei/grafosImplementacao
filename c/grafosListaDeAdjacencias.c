/**
 *
 * Grafos com lista de adjacências
 *
 * Vetor que contém somente as arestas existentes (com alocação dinâmica)
 *
 * @Author: Reinaldo Antonio Camargo Rauch
 * @Date:   2014-10-22 19:22:46
 * @Last Modified by:   reinaldo
 * @Last Modified time: 2014-11-13 02:06:40
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define TAM 10

/**
 * Array com os vértices
 */
int vertexes[TAM];

/**
 * Estrutura pra guardar as arestas
 */
struct edge {
    int dest;
    struct edge *next;
};

/**
 * Definindo o tipo para struct de aresta
 */
typedef struct edge t_edge;

/**
 * Array de arestas
 */
t_edge *edges[TAM];

/**
 * Variável para contar o número de vértices atualmente no grafo
 */
int count = 0;

void imprime_vertices() {
    int i;

    for (i = 0; i < count; i++) {
        printf("vertexes[%d] = %d", i, vertexes[i]);
        if(i < (count - 1))
            printf(", ");
    }

    putchar('\n');

}

/**
 * Função para inserir vértices
 */
void insere_vertice(int val) {
    if(count < TAM)
        vertexes[count++] = val;
    else
        puts("Erro, estouro do tamanho do grafo");
}

/**
 * Inicializa o grafo
 */
void inicia_grafo() {
    int i, j;

    for (i = 0; i < TAM; i++)
        edges[i] = NULL;

    for(i = 0; i < TAM; i++)
        vertexes[i] = 0;
}

/**
 * Verifica a posição do vértice no array de vértices
 * @param  vert vértice para verificar sua posição
 * @return      a posição do vértice
 */
int getVertexIndex(int vert) {
    int i = 0;

    while ((i < count) && (vert != vertexes[i]))
        i++;

    return i;
}

/**
 * Cria uma aresta
 * @param  dest Destino da aresta
 * @return      Struct da aresta
 */
t_edge *createEdge(int dest) {
    t_edge *edge = (t_edge*) malloc(sizeof(t_edge));

    edge->dest = dest;
    edge->next = NULL;

    return edge;
}

/**
 * Atualiza o vértice
 * @param orig vértice de origem
 * @param dest vértice de destino
 * @param stat tipo de operação
 */
void update_aresta(int orig, int dest, int stat) {
    int i = getVertexIndex(orig),
        j = getVertexIndex(dest);

    if(i == count) {
        puts("Vérice origem não existe");
        return;
    }

    if(j == count) {
        puts("Vertice de destino não encontrado");
        return;
    }

    t_edge *here, *aux, *before;

    here = aux = before = NULL;

    here = edges[i];

    while (here != NULL)
        if (here->dest == j) {
            if(stat) {
                puts("Aresta repetida");
                return;
            } else
                break;
        } else {
            before = here;
            here = here->next;
        }

    if(stat) {
        aux = createEdge(j);

        if(before == NULL)
            edges[i] = aux;
        else
            before->next = aux;

        puts("Aresta inserida com sucesso");
    } else {

        if(before == NULL) {
            aux = here;
            edges[i] = here->next;
        } else {
            aux = before->next;
            before->next = aux->next;
        }

        free(aux);
        aux = NULL;

        puts("Aresta removida com sucesso");
    }

}

/**
 * Insere aresta no grafo
 * @param orig origem da aresta
 * @param dest destino da aresta
 */
void insere_aresta(int orig, int dest) {
    update_aresta(orig, dest, 1);
}

/**
 * Remove a aresta
 * @param orig origem da aresta
 * @param dest destino da aresta
 */
void remove_aresta(int orig, int dest) {
    update_aresta(orig, dest, 0);
}

/**
 * Imprime o grafo na tela
 */
void imprime_grafo() {

    int i;
    t_edge *here;

    here = NULL;

    for (i = 0; i < count; i++) {

        here = edges[i];

        printf("--> %d", vertexes[i]);

        if(here != NULL)
            printf(": ");

        while(here != NULL) {
            printf("%d", vertexes[here->dest]);
            if(here->next != NULL)
                printf(", ");
            here = here->next;
        }

        putchar('\n');
    }

}

int main(int argc, char const *argv[])
{

    insere_vertice(1);
    insere_vertice(10);
    insere_vertice(100);
    insere_vertice(1000);
    insere_vertice(10000);

    insere_aresta(1, 10);
    insere_aresta(1, 100);
    insere_aresta(1, 1000);
    insere_aresta(10, 100);
    insere_aresta(100, 1000);
    insere_aresta(1000, 100);
    insere_aresta(1000, 100);
    insere_aresta(10000, 100);
    insere_aresta(10000, 10);
    insere_aresta(10000, 1);

    imprime_grafo();

    remove_aresta(10000, 100);
    imprime_grafo();

    remove_aresta(1000, 100);
    imprime_grafo();

    remove_aresta(1, 10);
    imprime_grafo();

    return 0;
}
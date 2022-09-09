/*
 * Tarefa 05 - Grafo - Algortimo de Prim
 *
 * GEN254 - Grafos - 2022/1
 *
 * Nome:      LUIZ ROBERTO DENDENA
 * Matricula: 1721101027
 */

#include <stdio.h>
#include "grafo.h"

int main () {
    int numeroVertices;
    int numeroArestas;
    int x, y, p;

    scanf("%d %d", &numeroVertices, &numeroArestas);
    
    Grafo *g = GRAFOconstroi(numeroVertices);

    for (int i=0; i<numeroArestas; i++) {
      scanf("%d %d %d", &x, &y, &p);
      Aresta aresta = ARESTA(x, y, p);
      GRAFOinsere_aresta(g, aresta);
    }

    GRAFOimprime_caminhos_arv_ger_pes_min(g);

    GRAFOdestroi(g);

  return 0;
}

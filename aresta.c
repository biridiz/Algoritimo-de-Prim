#include "aresta.h"

Aresta ARESTA(int v1, int v2, int peso) {
    Aresta aresta;
    aresta.v1 = v1;
    aresta.v2 = v2;
    aresta.peso = peso;
    return aresta;
}

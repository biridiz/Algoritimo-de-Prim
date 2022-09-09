#ifndef ARESTA_H

#define ARESTA_H

struct aresta {
    int v1;
    int v2;
    int peso;
};
typedef struct aresta Aresta;

Aresta ARESTA(int v1, int v2, int p);

#endif /* ARESTA_H */

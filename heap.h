#ifndef HEAP_H

#define HEAP_H

typedef struct elementoHeap {
    int vertice;
    int peso;
} ElementoHeap;

typedef struct heap {
    ElementoHeap *arr;
    int count;
    int capacity;
    int heap_type;
} Heap;

Heap *HEAPconstroi(int capacity);

void HEAPinsere(Heap *h, ElementoHeap i);

ElementoHeap HEAPremove(Heap *h);

int HEAPvazia(Heap *h);

void HEAPdestroi(Heap *h);

ElementoHeap HEAPbusca(Heap *h, int v);

int HEAPtem_vertice(Heap *h, int v);

void HEAPaltera_peso(Heap *h, int v, int p);

#endif /* HEAP_H */
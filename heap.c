#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void heapify_bottom_top(Heap *h, int index){
    ElementoHeap temp;
    int parent_node = (index-1)/2;

    if (parent_node >= 0 && h->arr[parent_node].peso > h->arr[index].peso){
        temp = h->arr[parent_node];
        h->arr[parent_node] = h->arr[index];
        h->arr[index] = temp;
        heapify_bottom_top(h, parent_node);
    }
}

void heapify_top_bottom(Heap *h, int parent_node) {
    int left = parent_node*2+1;
    int right = parent_node*2+2;
    int min;
    ElementoHeap temp;

    if ((left >= h->count) || (left < 0)) {
        left = -1;
    }
    if ((right >= h->count) || (right < 0)) {
        right = -1;
    }

    if ((left != -1) && (h->arr[left].peso < h->arr[parent_node].peso)) {
        min = left;
    } else {
        min = parent_node;
    }

    if (right != -1 && h->arr[right].peso < h->arr[min].peso) {
        min = right;
    }

    if (min != parent_node) {
        temp = h->arr[min];
        h->arr[min] = h->arr[parent_node];
        h->arr[parent_node] = temp;
        heapify_top_bottom(h, min);
    }
}

Heap *HEAPconstroi(int capacity) {
    Heap *h = (Heap * ) malloc(sizeof(Heap));
    h->count = 0;
    h->capacity = capacity;
    h->arr = (ElementoHeap *) malloc(capacity * sizeof(ElementoHeap));
    return h;
}

void HEAPinsere(Heap *h, ElementoHeap item) {
    if (h->count < h->capacity) {
        h->arr[h->count] = item;
        heapify_bottom_top(h, h->count);
        h->count++;
    }
}

ElementoHeap HEAPremove(Heap *h) {
    ElementoHeap pop;
    pop = h->arr[0];
    h->arr[0] = h->arr[h->count-1];
    h->count--;
    heapify_top_bottom(h, 0);
    return pop;
}

int HEAPvazia(Heap *h) {
    if (h->count == 0) {
        return 1;
    }
    return 0;
}

ElementoHeap HEAPbusca(Heap *h, int vertice) {
    for (int i=0; i<h->count; i++) {
        if (h->arr[i].vertice == vertice) {
            return h->arr[i];
        }
    }
    return h->arr[0];
}

int HEAPtem_vertice(Heap *h, int vertice) {
    for (int i=0; i<h->count; i++) {
        if (h->arr[i].vertice == vertice) {
            return 1;
        }
    }
    return 0;
}

void HEAPaltera_peso(Heap *h, int vertice, int peso) {
    int i; 
    for (i=0; i<h->count; i++) {
        if (h->arr[i].vertice == vertice) {
            h->arr[i].peso = peso;
            break;
        }
    }
    heapify_bottom_top(h, i);
}
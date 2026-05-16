#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"

Cola* crearCola() {
    Cola* c = (Cola*) malloc(sizeof(Cola));
    c->frente = NULL;
    c->final = NULL;
    return c;
}

void enqueue(Cola* c, void *dato, size_t size) {
    NodoCola* nuevo = (NodoCola*) malloc(sizeof(NodoCola));
    nuevo->dato = malloc(size);
    memcpy(nuevo->dato, dato, size);
    nuevo->siguiente = NULL;

    if (c->final == NULL) {
        c->frente = nuevo;
        c->final = nuevo;
    } else {
        c->final->siguiente = nuevo;
        c->final = nuevo;
    }
}

char dequeue(Cola* c) {
    if (colaVacia(c)) return '\0';

    NodoCola* temp = c->frente;
    char valor = *((char*)temp->dato);

    c->frente = temp->siguiente;
    if (c->frente == NULL)
        c->final = NULL;

    free(temp->dato);
    free(temp);

    return valor;
}

int colaVacia(Cola* c) {
    return c->frente == NULL;
}

void imprimirCola(Cola* c) {
    NodoCola* aux = c->frente;
    while (aux != NULL) {
        printf("%c ", *((char*)aux->dato));
        aux = aux->siguiente;
    }
    printf("\n");
}

void destruirCola(Cola* c) {
    while (!colaVacia(c)) {
        dequeue(c);
    }
    free(c);
}

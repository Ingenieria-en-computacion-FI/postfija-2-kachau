#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/pila.h"

Pila* crearPila() {
    Pila* p = (Pila*) malloc(sizeof(Pila));
    p->tope = NULL;
    return p;
}

void push(Pila* p, void *dato, size_t size) {
    NodoPila* nuevo = (NodoPila*) malloc(sizeof(NodoPila));
    nuevo->dato = malloc(size);
    memcpy(nuevo->dato, dato, size);

    nuevo->siguiente = p->tope;
    p->tope = nuevo;
}

char pop(Pila* p) {
    if (pilaVacia(p)) return '\0';

    NodoPila* temp = p->tope;
    char valor = *((char*)temp->dato);

    p->tope = temp->siguiente;

    free(temp->dato);
    free(temp);

    return valor;
}

char peek(Pila* p) {
    if (pilaVacia(p)) return '\0';
    return *((char*)p->tope->dato);
}

int pilaVacia(Pila* p) {
    return p->tope == NULL;
}

void destruirPila(Pila* p) {
    while (!pilaVacia(p)) {
        pop(p);
    }
    free(p);
}

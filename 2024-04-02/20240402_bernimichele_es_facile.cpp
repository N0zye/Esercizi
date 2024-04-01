#include <iostream>

using namespace std;

#define CONTAINER_MAX_SIZE 100

// Lista: e' possibile accedere solo all'elemento successivo
class Lista {
private:
    int container[CONTAINER_MAX_SIZE] = {NULL};
    int real_size;
public:
    Lista() : real_size(0) {}

    int front() {
        if (real_size == 0) {
            return NULL;
        }
        return container[0];
    }
    int back() {
        if (real_size == 0) {
            return NULL;
        }
        return container[real_size-1];
    }
    void push_back(int value){
        if (real_size == CONTAINER_MAX_SIZE) {
            cout << "Raggiunta la capienza massima, impossibile aggiungere elementi" << endl;
            return;
        }
        container[real_size++] = value;
    }
    void pop_back() {
        if (real_size == 0) {
            cout << "La lista e' vuota, impossibile rimuovere altri elementi" << endl;
            return;
        }
        container[--real_size] = NULL;
    }
    int size() {
        return real_size;
    }
};

// Coda: first in first out (FIFO)
class Coda {
private: 
    int container[CONTAINER_MAX_SIZE] = {NULL};
    int real_size;
public:
    Coda() : real_size(0) {}

    int front() {
        if (real_size == 0) {
            return NULL;
        }
        return container[0];
    }
    int back() {
        if (real_size == 0) {
            return NULL;
        }
        return container[real_size-1];
    }
    void push(int value) {
        if (real_size == CONTAINER_MAX_SIZE) {
            cout << "Raggiunta la capienza massima, impossibile aggiungere elementi" << endl;
            return;
        }
        container[real_size++] = value;
    }
    void pop() {
        if (real_size == 0) {
            cout << "La lista e' vuota, impossibile rimuovere altri elementi" << endl;
            return;
        }
        real_size--;
        for (int i = 0; i < real_size; i++) container[i] = container[i+1];
        container[real_size] = NULL;
    }
    int size() {
        return real_size;
    }
};

// Pila: first in last out (FILO)
class Pila {
private: 
    int container[CONTAINER_MAX_SIZE] = {NULL};
    int real_size;
public:
    Pila() : real_size(0) {}

    int top() {
        if(real_size == 0) {
            return NULL;
        }
        return container[real_size-1];
    }
    void push(int value) {
        if (real_size == CONTAINER_MAX_SIZE) {
            cout << "Raggiunta la capienza massima, impossibile aggiungere elementi" << endl;
            return;
        }
        container[real_size++] = value;
    }
    void pop() {
        if (real_size == 0) {
            cout << "La lista e' vuota, impossibile rimuovere altri elementi" << endl;
            return;
        }
        container[--real_size] = NULL;
    }
    int size() {
        return real_size;
    }
};

int main() {

    Lista l;

    Coda c;

   Pila p;

    return 0;
}
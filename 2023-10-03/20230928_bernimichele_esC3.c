#include <stdio.h>

//**Ordinamento di un array di numeri:
//Scrivi un programma che ordini un array di numeri interi in ordine crescente. Usa una funzione per la lettura dell'array, una per l'ordinamento e una per la stampa del risultato. La funzione `main` dovrebbe gestire queste funzioni.

#define MAXN 10

int arr[MAXN];

void inputArray()
{
    for (int i = 0; i < MAXN; i++) {
        printf("Inserisci l'elemento numero %d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void ordinaArray()
{
    int temp, contatore;
    do {
        contatore = 0;
        for (int i = 1; i < MAXN; i++) {
            if(arr[i-1] > arr[i]) {
                temp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = temp;
                contatore++;
            }
        } 
    } while (contatore > 0);
}

void outputArray()
{
    printf("Array ordinato:\n");
    for (int i = 0; i < MAXN; i++) {
        printf("%d ", arr[i]);
    }
}

int main() 
{
    inputArray();
    ordinaArray();
    outputArray();

    return 0;
}
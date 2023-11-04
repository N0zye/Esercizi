#include <stdio.h>

//Stampa la somma di 5 numeri interi richiesti in ingresso (for)

int main() 
{
    int n, sum = 0;
    for (int i = 0; i < 5; i++) {
        printf("Inserisci un numero intero: ");
        scanf("%d", &n);
        sum += n;
    }
    printf("Somma = %d", sum);

    return 0;
}
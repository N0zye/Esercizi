#include <stdio.h>

//Stampa la media di 5 numeri interi richiesti in ingresso (fattibile col for ma questo o voglio col while)

int main() 
{
    int n, sum = 0, c = 0;
    
    while (c < 5)
    {
        printf("Inserisci un numero intero: ");
        scanf("%d", &n);
        sum += n;
        c++;
    }
    printf("Media = %.1f", (float)sum / c);

    return 0;
}
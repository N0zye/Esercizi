#include <stdio.h>

//Legge un intero dalla tastiera e lo stampa a video (scanf, printf)

int main() 
{
    int n;
    printf("Inserisci un numero intero: ");
    scanf("%d", &n);
    printf("Numero inserito: %d", n);

    return 0;
}
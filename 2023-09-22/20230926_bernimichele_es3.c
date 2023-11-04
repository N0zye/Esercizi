#include <stdio.h>

//Legge un intero da tastiera maggiore di zero e lo stampa. Se il numero immesso non è valido viene scartato e ne viene richiesto un altro (do while)

int main() 
{
    int n;
    
    do{
        printf("Inserisci un numero intero maggiore di 0: ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Numero inserito: %d", n);

    return 0;
}
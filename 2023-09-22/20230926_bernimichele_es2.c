#include <stdio.h>

//Legge un intero da tastiera e stampa se è pari "pari" o dispari "dispari" (if then else)

int main() 
{
    int n;
    printf("Inserisci un numero intero: ");
    scanf("%d", &n);
    if (n%2 == 0) {
        printf("Pari");
    }else {
        printf("Dispari");
    }

    return 0;
}
#include <stdio.h>

// **Calcolo della potenza di un numero:
//Crea un programma che calcoli la potenza di un numero usando una funzione ricorsiva. La funzione `main` dovrebbe richiedere all'utente di inserire la base e l'esponente, quindi chiamare la funzione ricorsiva per calcolare la potenza.

int pot(int base, int esponente)
{
    int ris = 1;
    for (;esponente > 0; esponente--) {
        ris *= base;
    }
    return ris;
}

int main()
{
    int b, e;
    printf("Inserisci la base: ");
    scanf("%d", &b);
    printf("Inserisci l'esponente: ");
    scanf("%d", &e);

    printf("%d elevato alla %d = %d", b, e, pot(b, e));

    return 0;
}
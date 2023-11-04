#include <stdio.h>
#include <stdlib.h>

//Stampa la media dei numeri contenuti in una struttura dati statica a 3 dimensioni alimentata con generati automaticamente (indici i, j e k -  3 for annidati)

int main() 
{
    int sum = 0, N1 = 3, N2 = 3, N3 = 3, ten[N1][N2][N3];

    for (int i = 0; i < N1; i++) {
        for (int j = 0; j < N2; j++) {
            for (int k = 0; k < N3; k++) {
                ten[i][j][k] = rand();
                sum += ten[i][j][k];
            } 
        }
    }
    printf("Media = %.2f", (float)sum / (N1 * N2 * N3));

    return 0;
}
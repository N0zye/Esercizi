#include <stdio.h>

//Stampa il numero di 0 contenuti in una matrice 3x3 riempita da voi nel codice sorgente (indici i e j - 2 for annidati)

int main() 
{
    int tot0 = 0, mat[3][3] = {{0, 0, 2}, {4, 0, 0}, {0, 3, 9}};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] == 0) {
                 tot0++;
            }
        }
    }
    printf("Numero di 0: %d", tot0);
    
    return 0;
}
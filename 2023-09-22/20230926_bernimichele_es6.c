#include <stdio.h>
#include <stdlib.h>

//Stampa la somma di N numeri generati casualmente dal computer e mantenuti in un array (srand, rand, array)

int main() 
{
    int N;
    printf("Quanti numeri deve contenere l'array? ");
    scanf("%d", &N);
    int arr[N], sum = 0;
    for (int i = 0; i < N; i++) {
        arr[i] = rand();
        sum += arr[i];
    }
    printf("Somma = %d", sum);
    


    return 0;
}
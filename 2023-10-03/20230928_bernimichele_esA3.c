#include <stdio.h>

//**Copia il contenuto di un file:
//Scrivi un programma che copi il contenuto di un file di testo chiamato "source.txt" in un nuovo file di testo chiamato "destination.txt".

int main()
{
    FILE *fps, *fpd;  //File pointer source & file pointer destination
    char str[100];
    if (fopen("source.txt", "r") == NULL) {  // Verifica dell'esistenza del file sorgente
        printf("File sorgente non trovato");
        return 1;
    }
    fps = fopen("source.txt", "r");
    fpd = fopen("destination.txt", "w");
    while (fscanf(fps, "%s ", str) != EOF) {  // Copia e incolla parola per parola da source a destination fino alla fine del file (EOF)
        fprintf(fpd, "%s ", str);
    }    
    fclose(fps);
    fclose(fpd);

    return 0;
}
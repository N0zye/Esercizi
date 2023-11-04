#include <stdio.h>
#include <string.h>

//**Sostituisci una parola:
//Crea un programma che legga un file di testo chiamato "documento.txt" e sostituisca ogni occorrenza di una parola specifica (ad esempio, "vecchia") con un'altra parola (ad esempio, "nuova"). Il file modificato deve essere scritto in un nuovo file chiamato "documento_modificato.txt".

int main() 
{
    FILE *fps, *fpd; //File pointer source & file pointer destination (In questo caso documento e documento_modificato)
    char str[100], occ[100], npr[100]; //str è la stringa usata per copiare e incollare mentre occ è per gestire la parola da sostituire mentre npr è la parora con cui sostiruire
    if (fopen("documento.txt", "r") == NULL) { // Verifica dell'esistenza del file documento
        printf("File \"documento\" non trovato");
        return 1;
    }
    printf("Inserisci la parola da sostituire: ");
    scanf("%s", occ);
    printf("inserisci la parola con la quale sostituire le occorrenze: ");
    scanf("%s", npr);
    fps = fopen("documento.txt", "r");
    fpd = fopen("documento_modificato.txt", "w");
    while (fscanf(fps, "%s ", str) != EOF) {  // Il while percorre tutto il file e per ogni occorrenza della parola "vecchia" inserita in input da utente
        if (strcmp(str, occ) == 0) {          // la sostituisce con quella da usare come sostituzione
            fprintf(fpd, "%s ", npr);         
        }else {
            fprintf(fpd, "%s ", str);  
        }
    }
    fclose(fps);
    fclose(fpd);

    return 0;
}
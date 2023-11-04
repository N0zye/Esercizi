#include <stdio.h>
#include <string.h>

//**Conta le occorrenze delle parole:
//Scrivi un programma che legga un file di testo chiamato "testo.txt" e conti quante volte ciascuna parola appare nel file. Deve generare un elenco di parole e delle relative frequenze in un nuovo file di testo chiamato "conteggio_parole.txt".

int parolaGiaTrovata(char *str, int max) //Restituisce 0 se la parola era gia stata precedentemente trovata e 1 se non era ancora stata trovata
{
    FILE *fp;
    fp = fopen("testo.txt", "r");
    char temp[25];
    int c = 0;
    while ((fscanf(fp, "%s ", temp) != EOF) && c < max) {
        if (strcmp(temp, str) == 0){
            return 0;
        }
        c++;
    }
    return 1;
}
int contaOccorrenze(char *str) //Conta le occorrenze della stringa data allinterno del file
{
    FILE *fp;
    fp = fopen("testo.txt", "r");
    char temp[25];
    int occorrenze = 0;
    while ((fscanf(fp, "%s ", temp) != EOF)) {
        if (strcmp(temp, str) == 0) {
            occorrenze++;
        }
    }
    return occorrenze;
}

int main() 
{
    FILE *fps, *fpd;
    char str[25];
    int contatore = 0;
    if (fopen("testo.txt", "r") == NULL) { // Verifica dell'esistenza del file di testo
        printf("File \"testo\" non trovato");
        return 1;
    }
    fps = fopen("testo.txt", "r");
    fpd = fopen("conteggio_parole.txt", "w");

    while (fscanf(fps, "%s ", str) != EOF) {
        if (parolaGiaTrovata(str, contatore) == 1) { // La parola non era ancora stata trovata
            fprintf(fpd, "\"%s\" trovata %d volte\n", str, contaOccorrenze(str));
        }
        contatore++; // Per mantenere il conto di dove si è arrivati nel testo
    }

    return 0;
}
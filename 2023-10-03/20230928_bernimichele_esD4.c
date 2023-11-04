#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include<stdlib.h>

//**Sistema di gestione di file:
//Crea un programma che consenta all'utente di gestire una serie di file. Le operazioni dovrebbero includere la creazione di un nuovo file, la modifica di un file esistente e la visualizzazione del contenuto di un file. Suddividi il codice in funzioni per ciascuna operazione e una funzione `main` per il menu principale.

#define ENTER 13

void printText(char *string, int SleepDuration)
{
	for(unsigned int i = 0;i <= strlen(string); i++){
		Sleep(SleepDuration);
		(SleepDuration % 2 == 0) ? printf("%c",string[i]) : printf(" %c",string[i]);
	}
}
void menu();

void crea()
{
    char nomeFile[100];
    system("cls");
    printText("\t\t\t\tCREA UN NUOVO FILE", 31);
    printf("\n\nInserisci il nome del file che vuoi creare (senza il .txt): ");
    scanf("%s", nomeFile);
    strcat(nomeFile, ".txt");
    FILE *fp = fopen(nomeFile, "w");
    fclose(fp);
    printf("E' stato creato il file: %s", nomeFile);
    getchar();
    getchar();
    menu();  
}

void elimina()
{
    char nomeFile[100];
    system("cls");
    printText("\t\t\t\tELIMINAZIONE DI UN FILE", 31);
    printf("\n\nInserisci il nome del file che vuoi eliminare (senza il .txt): ");
    scanf("%s", nomeFile);
    strcat(nomeFile, ".txt");
    remove(nomeFile);
    printf("E' stato rimosso il file: %s", nomeFile);
    getchar();
    getchar();
    menu();  
}

void visualizza()
{
    FILE *fp;
    char str[100], nomeFile[100];
    system("cls");
    printText("\t\t\t\tVISUALIZZAZIONE DI UN FILE", 31);
    printf("\n\nInserisci il nome del file del quale vuoi visualizzare il contenuto (senza il .txt): ");
    scanf("%s", nomeFile);
    strcat(nomeFile, ".txt");
    if (fopen(nomeFile, "r") == NULL){
        printf("File non trovato\n");
        getchar();
        getchar();
        menu();
        return;
    }
    fp = fopen(nomeFile, "r");
    while (fscanf(fp, "%s ", str) != EOF) {
        printf("%s ", str);
    }
    fclose(fp);
    getchar();
    getchar();
    menu();
}

void modifica()
{
    FILE *fp;
    char frase[1000], nomeFile[100];
    system("cls");
    printText("\t\t\t\tMODIFICA DI UN FILE", 31);
    printf("\n\nInserisci il nome del file del che vuoi modificare (senza il .txt): ");
    scanf("%s", nomeFile);
    strcat(nomeFile, ".txt");
    fp = fopen(nomeFile, "w");
    printf("Stai modificando il file: ");
    getchar();
    fgets(frase, sizeof(frase), stdin);
    fprintf(fp, "%s", frase);
    fclose(fp);
    printf("Frase scritta nel file.\n");
    menu();
}

void menu()
{
    int numAzione;
    system("cls");
    printText("\t\t\t\t\tMENU PRINCIPALE", 31);
    printf("\n\n\nSeleziona l'azione da eseguire:\n\n1: Crea un nuovo file\n\n2: Elimina un file\n\n3: Visualizza il contenuto di un file\n\n4: Modifica il contenuto di un file\n\n5: Chiudi il programma\n\n");
    scanf("%d", &numAzione);
    switch (numAzione) {
        case 1:
            crea();
            break;
        case 2:
            elimina();
            break;
        case 3:
            visualizza();
            break;
        case 4:
            modifica();
            break;
        case 5:
            return;
            break;
        default:
            printf("%d non valido", numAzione);
    }
}

int main()
{
    menu();
    return 0;
}
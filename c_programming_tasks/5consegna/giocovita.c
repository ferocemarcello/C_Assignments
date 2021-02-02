/*
    0: cellula viva
    (spazio vuoto): cellula morta

    Decido di lasciare vuoti i bordi

*/

#include<stdio.h>
#include<stdlib.h>
#define N 20
#define M 50

int main ()
{

    srand(time(NULL));

    char matrice[N][M], matricetemp[N][M];
    int i, j, vicini, ciclo = 0, cicli;

    //inizializzo le due matrici come cellule morte
    for (i = 0; i < N; i++)
        for(j = 0; j < M; j++) {
            matrice[i][j] = ' ';
            matricetemp[i][j] = ' ';
        }

    //genero la prima matrice casualmente
    for (i = 1; i < N-1; i++)
        for (j = 1; j < M-1; j++) {
            matrice[i][j] = rand() % 2; //genero o 0 o 1
            if (matrice[i][j] == 1)
                matrice[i][j] =' ';
            else
                matrice[i][j]='0';
        }

    //stampo la matrice
    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++) 
            printf("%c", matrice[i][j]);
        printf("\n");
    }


    //se si vuole fare inserire all'utente da tastiera il numero di generazioni da vedere
//    printf("Inserisci quante generazioni vuoi vedere: ");
//    scanf("%d", &cicli);

    system("cls");

//    while (ciclo<cicli) {

    //altrimenti pongo una condizione sempre vera per fare continuare il ciclo all'infinito
    while (0 < 1) {
    //controllo i vicini
        for (i = 1; i < N-1; i++)
            for (j = 1; j < M-1; j++) {
                vicini = 0;
                if (matrice[i-1][j-1] == '0')
                    vicini++;
                if (matrice[i-1][j] == '0')
                    vicini++;
                if (matrice[i-1][j+1] == '0')
                    vicini++; 
                if (matrice[i][j-1] == '0')
                    vicini++;
                if (matrice[i][j+1] == '0')
                    vicini++;
                if (matrice[i+1][j-1] == '0')
                    vicini++;
                if (matrice[i+1][j] == '0')
                    vicini++;
                if (matrice[i+1][j+1] == '0')
                    vicini++;

                //controllo le tre condizioni di sopravvivenza o estinzione imposte alla base del gioco della vita
                if (vicini == 2 || vicini == 3 && matrice[i][j] == '0')
                    matricetemp[i][j] = '0';
                else if (vicini < 2 || vicini > 3 && matrice[i][j] == '0')
                    matricetemp[i][j] = ' ';
                else if (vicini == 3 && matrice[i][j] == ' ')
                    matricetemp[i][j] = '0';
                else
                    matricetemp[i][j] = matrice[i][j];
            }

        //riassegno i valori delle matrici
        for(i = 0; i < N; i++)
            for(j = 0; j < M; j++){
                matrice[i][j] = matricetemp[i][j];
                matricetemp[i][j] = ' ';
            }

        //stampo la matrice
        for (i = 0; i < N; i++){
            for (j = 0; j < M; j++) 
                printf("%c", matrice[i][j]);
            printf("\n");
        }
    
    // system("pause");

    //ripulisco la schermata
    system("cls"); 
    //ciclo++;
    
    }

    return 0;

}

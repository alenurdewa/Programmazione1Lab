#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

const int N_COL = 4;
const int N_ROW = 3;

void initMat(int matrix[][N_COL], int nRow){
    for (int r = 0; r < nRow; r++){
        for(int c = 0; c < N_COL; c++){
            matrix[r][c] = rand() %10;
        }
    }

}

void trasposta(int matrix[][N_COL], int nRow, int matriceTrasposta[][N_ROW]){

    
    for(int r = 0; r<N_COL; r ++){
        for (int c = 0; c<nRow; c++){
            matriceTrasposta[r][c] = matrix[c][r];
        }
    }

}

// Funzione generica per stampare una matrice con un numero qualsiasi di colonne
void stampaArray(int *m, int nRow, int nCol){
    for (int r = 0; r < nRow; r++){
        cout << "{ [ ";
        for(int c = 0; c < nCol; c++){
            // Usiamo l'aritmetica degli indirizzi per m[r][c]
            cout << *(m + r * nCol + c) << " ";
        }
        cout << "] }\n";
    }
    cout << endl;
}

int calcolaTriangoloSuperiore(int *m, int nRow, int nCol){
    int somma = 0;
    
    for(int r = 0; r < nRow; r++){
        // Facciamo partire c da r: in questo modo prendiamo 
        // solo la diagonale principale e tutto ciò che sta a destra
        for(int c = r; c < nCol; c++){
            somma += *(m + r * nCol + c);
        }
    }
    
    return somma;
}

int main(){
    srand(time(NULL));

    
    int matrix [N_ROW][N_COL];
    int matriceTrasposta [N_COL][N_ROW];

    initMat(matrix, N_ROW);
    trasposta(matrix, N_ROW, matriceTrasposta);

    stampaArray(*matrix, N_ROW,N_COL);
    stampaArray(*matriceTrasposta, N_COL, N_ROW);
    int somma = calcolaTriangoloSuperiore(*matrix, N_ROW, N_COL);
    cout << "Somma triangolo superiore = " << somma << endl;
    



    return 0;
}
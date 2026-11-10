#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N_COL = 4;

// 1. Firma corretta per la matrice statica
void stampaArray(int m[][N_COL], int nRow){
    for (int r = 0; r < nRow; r++){
        cout << "{ [ ";
        for(int c = 0; c < N_COL; c++){
            cout << m[r][c] << " ";
        }
        cout << "] }\n";
    }
    cout << endl;
}

// 2. Funzione corretta per int** (array di puntatori dinamici)
void stampaPuntMatrice(int **pMatrice, int nRow, int nCol){
    for (int r = 0; r < nRow; r++){
        cout << "{ [ ";
        for (int c = 0; c < nCol; c++){
            // Con int** si naviga con l'accesso standard a due livelli
            cout << pMatrice[r][c] << " ";
        }
        cout << "] }\n";
    }
    cout << endl;
}

int main(){
    srand(time(NULL));
    int nRow = 3;
    
    // --- PARTE 1: Matrice statica ---
    int matrice[3][N_COL];
    for (int r = 0; r < nRow; r++){
        for(int c = 0; c < N_COL; c++){
            matrice[r][c] = rand() % 100;
        }    
    }
    stampaArray(matrice, nRow);

    
    int *matrice2[nRow]; 
    for (int r = 0; r < nRow; r++){
        matrice2[r] = new int[N_COL];
        for (int c = 0; c < N_COL; c++){
            matrice2[r][c] = matrice[r][c];
        }

    }

    stampaPuntMatrice(matrice2, nRow, N_COL);


    return 0;
}
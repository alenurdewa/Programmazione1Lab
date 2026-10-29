#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <ctime>
using namespace std;

/*
Scrivere una procedura C++ che, presi come parametri un array di numeri
interi, la sua dimensione e un altro numero intero, inizializzi l’array con
valori random, il cui massimo sia il terzo parametro. Scrivere poi una
procedura C++ che stampi a video tutti gli elementi di un array di numeri
interi ricevuto come parametro insieme alla sua dimensione. Scrivere una
funzione C++ che permetta, ricevuti come parametri due array di interi e la
loro dimensione (la stessa per entrambi), conti quante volte gli elementi
con lo stesso indice sono uguali. Si scriva, infine, un programma che testi
*/

int countSameValue(int arr[], int arr2[], int dimensione){

    int contatore = 0;
    for(int i = 0; i<dimensione; i++){
        if(arr[i] == arr2[i]){
            contatore+=1;
        }

    }
    return contatore;

}

void generateRandomArray(int array[], int dimensione, int max){
    
    for (int i = 0; i < dimensione; i++){
        array[i] = rand() % (max+1);
    }
}

void stampaArray(int arr[], int dimensione){

    for(int i=0; i<dimensione; i++){
        cout << "array[" << i << "] = " << arr[i]<<endl;
    }
    cout << endl;

}



int main(){
    srand(time(NULL));
    int dimensione = 10;
    int arr[dimensione];
    generateRandomArray(arr,dimensione,10);

    int arr2[dimensione];
    generateRandomArray(arr2,dimensione,10);

    stampaArray(arr, dimensione);
    stampaArray(arr2, dimensione);

    cout << "Ci sono " << countSameValue(arr, arr2, dimensione) << " elementi uguali nei due array\n";




    return 0;
}


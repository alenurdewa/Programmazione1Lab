#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

void initArr(int arr[], int d){

    for(int i = 0; i < d; i++){
        arr[i] = rand() % (10);
    }

}

void stampaArray(int arr[], int d){

    for(int i = 0; i<d; i++){
        cout << "arr[" << i << "] = " << arr[i]<<endl;
    }
}

double maxMediaMin(int arr[], int &max, int &min, int d){

    double media;
    int somma = 0;
    max = arr[0];
    min = arr[0];

    for (int i = 0; i < d; i++){
        somma+= arr[i];
        if(arr[i]<min){
            min = arr[i];
        }

        if(arr[i] > max){
            max = arr[i];
        }
    }

    media = (double)somma/d;
    return media;

}

int main(){
    srand(time(NULL));

    int arr[10];
    int max, min;
    initArr(arr, 10);
    stampaArray(arr, 10);

    double media = maxMediaMin(arr, max, min, 10);

    cout << "Media = " << media<<endl;
    cout << "Max = " << max<<endl;
    cout << "Min = " << min<<endl;

    return 0;
}
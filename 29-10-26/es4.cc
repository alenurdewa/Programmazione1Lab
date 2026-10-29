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
        cout << "array = [" << i << "] = " << arr[i]<<endl;
    }
    cout << endl;
}

void invertiArray(int arr[], int d){

    int arrAppoggio[d];
    for (int i = 0; i<d; i++){
        arrAppoggio[d-i-1] = arr[i];
    }

    for (int i = 0; i<d; i++){
        arr[i] = arrAppoggio[i];
    }
    

}

int main(){
    srand(time(NULL));
    
    int dimensione = 10;
    int arr[dimensione];
    initArr(arr,dimensione);
    stampaArray(arr,dimensione);

    invertiArray(arr,dimensione);
    stampaArray(arr,dimensione);



    
    return 0;
}
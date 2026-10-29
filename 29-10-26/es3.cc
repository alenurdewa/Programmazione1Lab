#include <iostream>
using namespace std;


int isInInterval (int arr[], int d, int x, int y){

    int contatore = 0;
    if(y < x ){
        contatore = -1;
    }else{
        for (int i = 0; i<d; i++){

            if(arr[i]>y || arr[i] < x){
                arr[i] = 0;
                contatore += 1;
            }        
        }
    }
    
    return contatore;

}

void stampaArray(int arr[], int d){

    for(int i = 0; i<d; i++){
        cout << "arr[" << i << "] = " << arr[i]<<endl;
    }
}

int main(){


    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int x, y;

    cout << "Inserire x ";
    cin >> x;

    cout << "Inserire y ";
    cin >> y;

    int numNonInIntervallo = isInInterval (arr, 10, x, y);
    cout << "Numeri non nell'intervallo = " << numNonInIntervallo << endl;
    stampaArray(arr, 10);

    return 0;
}
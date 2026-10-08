#include <iostream>
#include <cmath>

using namespace std;

int main(){


    int n = 0;
    cout << "Inserire n, numero di righe della ASCII ART ";
    cin >> n;


    
    for (int i= 0; i<n ; i++){

        for (int j = 0; j <n-i ; j++){
            cout << " ";
        }

        for (int j = 0; j < i*2+1; j++){
            cout << "*";
        }

        cout << endl;
        

    }

    return 0;
}
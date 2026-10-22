#include <iostream>

using namespace std;



void stampaBin(int n){

    
    if(n == 1){
        cout << "1";
    }else if(n%2 == 0){
        stampaBin(n/2);
        cout << "0";
    }else{
        
        stampaBin(n/2);
        cout << "1";
    }

}

int main(){


    int n = 0;
    cout << "Inserire un num intero positivo ";
    cin >> n;

    stampaBin(n);
    cout << endl;

    return 0;
}
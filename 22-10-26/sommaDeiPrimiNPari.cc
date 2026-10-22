#include <iostream>
using namespace std;

int stampaPrimiNPari(int n){

    if(n%2 == 1){
        n--;
    }

    int somma = 0;
    if(n==0){
        return somma;
    }

    somma = n + stampaPrimiNPari(n-2);

    return somma;


}

int main(){

    int n = 0;
    cout << "Inserire n ";
    cin >> n;

    int somma = stampaPrimiNPari(n);
    cout << somma << endl;
    return 0;
}
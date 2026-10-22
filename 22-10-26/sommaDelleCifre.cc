#include <iostream>

using namespace std;

int sommaRicorsiva(int n){

    int somma = 0;
    if(n==0){
        return somma;
    }else{
        somma = n%10 + sommaRicorsiva(n/10);
    }
    return somma;

}

int main (){

    int n = 0;

    cout << "Inserire n ";
    cin >> n;

    int somma = sommaRicorsiva(n);

    cout << "Somma delle cifre = " << somma << endl;

    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

int potenza (int m, int n){

    int risultato = m;
    if(n == 1){
        return m;
    }else if (n == 0){
        return 1;
    }else{
        risultato *= potenza(m, n-1);
    }
    return risultato;


}

int main(){

    int m, n;

    cout << "Inserire m ";
    cin >> m;
    cout << "Inserire n ";
    cin >> n;

    cout << m << "^" << n << "=" << potenza (m,n)<< endl;



    return 0;
}
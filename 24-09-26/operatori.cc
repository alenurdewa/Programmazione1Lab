#include <iostream>
using namespace std;

int main(){
    //post e pre incremento
    int val1 = 6, val2=6;
    int i1 = ++val1, i2 = val2++; 
    int j1 = ++val1, j2 = val2++; 

    // Pre-incremento (++x): prima incrementa la variabile e poi usa il nuovo valore.
    // Post-incremento (x++): prima usa il valore attuale e poi incrementa la variabile.

    cout << "Val1 = " << val1 << endl;
    cout << "Val2 = " << val2 << endl;
    cout << "i1 = " << i1 << endl;
    cout << "j1 = " << j1 << endl;


    //operatori misti
    int x = 1, y= 2;
    int risultato = x+=y;
    int risultato = x-=y;
    int risultato = x*=y;
    int risultato = x/=y;
    int risultato = x%=y;


    return 0;
}
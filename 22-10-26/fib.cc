#include <iostream>
#include <cmath>
using namespace std;

int conta(int n, int cifra) {
int risultato = 0;
if (n%10 == cifra){
    risultato = 1;
}
if (n == 0)
return risultato;
else
risultato += conta(n / 10, cifra);
return risultato;}

int main(){

    int n = 0, cifra = 0;

    cin >> n >> cifra;
    cout << "Nel numero n " << n << " la cifra " << cifra << " appare " << conta(n, cifra) << " volte\n";

    return 0;
}




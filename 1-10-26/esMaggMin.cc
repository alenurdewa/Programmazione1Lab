#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int a = 0, b=0;

    cout << "Inserire in input a e b\n";

    cin >> a >> b;

    int massimo = (a+b) - ((a>b) * b + (a<b) * a) - (a==b)*a;
    int minimo = (a+b) - ((a<b) * b + (a>b) * a) - (a==b)*a;


    //Con l'utilizzo della libreria di cmath
    massimo = max(a,b);
    minimo = min(a,b);

    cout << "Max = " << massimo << endl;
    cout << "Min = " << minimo << endl;

    return 0;
}
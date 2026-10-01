#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int a = 0, b=0;

    cout << "Inserire in input a e b\n";

    cin >> a >> b;

    int max = (a+b) - ((a>b) * b + (a<b) * a) - (a==b)*a;
    int min = (a+b) - ((a<b) * b + (a>b) * a) - (a==b)*a;


    //Con l'utilizzo della libreria di cmath
    max = max(a,b);
    min = min(a,b);

    cout << "Max = " << max << endl;
    cout << "Min = " << min << endl;

    return 0;
}
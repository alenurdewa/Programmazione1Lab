#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int a,b;
    cout << "Inserisci a e b: \n";
    cin >> a >> b;

    cout << "\nValori iniziali: \n";
    cout << "a = "<< a << endl;
    cout << "b = "<< b << endl;

    a= a+b;
    b = a-b;
    a = a-b;

    cout << "\nValori scambiati: \n";
    cout << "a = "<< a << endl;
    cout << "b = "<< b << endl;

}
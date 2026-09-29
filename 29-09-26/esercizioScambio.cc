#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int a,b;
    int c;
    cout << "Inserisci a e b: \n";
    cin >> a >> b;

    cout << "\nValori iniziali: \n";
    cout << "a = "<< a << endl;
    cout << "b = "<< b << endl;

    c= a;
    a= b;
    b= c;

    cout << "\nValori scambiati: \n";
    cout << "a = "<< a << endl;
    cout << "b = "<< b << endl;

}
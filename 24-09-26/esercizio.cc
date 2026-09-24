//Dato in input un carattere maiuscolo, ritorna lo stesso carattere minuscolo
#include <iostream>
using namespace std;

int main(){
    char carattere;
    cout << "Inserisci un carattere minuscolo per vederlo in maiuscolo ";
    cin >> carattere;
    carattere -=('a'-'A');
    cout << "Carattere in maiuscolo = " << carattere << endl;
    cout << endl<< endl;


    char carattere2;
    cout << "Inserisci un carattere maiuscolo per vedere in minuscolo ";
    cin >> carattere2;
    carattere2 +=('a'-'A');
    cout << "Carattere in minuscolo = " << carattere2 << endl;
}
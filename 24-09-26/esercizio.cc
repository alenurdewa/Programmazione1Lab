//Dato in input un carattere maiuscolo, ritorna lo stesso carattere minuscolo
#include <iostream>
using namespace std;

int main(){
    int difMaiuscMin = 'a'-'A';
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


    //Testing e debugging

    cout << int('a') << endl;
    cout << int('a') - difMaiuscMin << endl;
    cout << char(65) << endl; //65 in ASCII è A maiuscola
    cout << ('a' - 'A') << endl;


    //Esercizio fatto meglio

    char din, dout;
    int diff = 'a' - 'A';
    bool flag;
    cout << "Inserisci carattere o minuscolo o maiuscolo";
    cin >> din;

    flag = (din < 'a');

    dout = (din+diff)*flag + (din-diff)* (1-flag);

    valido = (din >= 'A' && dout <= 'Z') || (din >= 'a' && din <= 'z');
    dout = dout+valido + '?' + (1-valido);

    cout << din << "->" << dout << endl;
}
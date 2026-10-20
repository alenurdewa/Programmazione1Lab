#include <iostream>
using namespace std;


/*
Dati in input due interi, scrivere un programma C++ che faccia la
divisione tramite una funzione chiamata divisione; la funzione
restituisce il quoziente tramite parametro e il resto per riferimento.
In questo programma non si può usare il simbolo ‘/’ per la divisione
*/

int divisione(int dividendo, int divisore, int &resto){

    bool condizione = false;
    int quoziente = 0;

    if (divisore == 0){
        cout << "Divisione per 0\n";
    }

    while(!condizione){
        if(divisore*quoziente>dividendo){
            condizione=true;
        }else{
            quoziente+=1;
        }
    }
    quoziente-=1;
    resto = dividendo - divisore * quoziente;

    return quoziente;
}




int main(){

    int dividendo, divisore, resto;
    cout << "Inserire dividendo ";
    cin >> dividendo ;
    cout << "Inserire divisore ";
    cin >>divisore;
    int quoziente = divisione (dividendo, divisore, resto);

    cout << "Quoziente = " << quoziente << endl;
    cout << "Resto = " << resto << endl;
    
    return 0;
}
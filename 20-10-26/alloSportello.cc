/*
02 – Allo sportello
Scrivere una funzione preleva in C++ che simuli il prelievo di denaro da un
conto corrente. La funzione riceve l’importo da prelevare per valore, il saldo del
conto per riferimento e il totale delle commissioni accumulate per indirizzo. 


Per ogni prelievo viene applicata una commissione pari al 2% dell’importo
richiesto, con un minimo di 1 euro. Se il saldo è sufficiente a coprire l’importo
comprensivo della commissione, la funzione aggiorna il saldo e il totale delle
commissioni accumulate, restituendo 1. In caso contrario, restituisce 0 senza
modificare queste due variabili. 


Anche le richieste di importo nullo o negativo
devono essere rifiutate senza modificare il saldo o le commissioni. La funzione
deve avere un unico punto di uscita (un solo return). 

Scrivere inoltre un
programma C++ che chieda all’utente l’importo da prelevare, chiami la funzione
e stampi l’esito dell’operazione con il saldo aggiornato e il totale delle
commissioni.
*/

#include <iostream>
#include <cmath>

using namespace std;

int prelievo(double importoDaPrel, double &saldo, double *totCommissioni){
    int operazioneCompletata = 0;
    double commissione = importoDaPrel * 2 / 100; // commissione del 2%

    if (commissione < 1){
        commissione = 1.0;
    }

    // Controlliamo che l'importo sia positivo (> 0) e che il saldo sia sufficiente
    if (importoDaPrel > 0){
        if (saldo - (commissione + importoDaPrel) >= 0){
            saldo -= (commissione + importoDaPrel);
            *totCommissioni += commissione; 
            operazioneCompletata = 1;
        }
    }
    
    // Unico punto di uscita rispettato
    return operazioneCompletata;
}

int main(){
    double saldo, importoDaPrel;
    double totCommissioni = 0; 

    cout << "Inserire saldo iniziale: ";
    cin >> saldo;

    // Esempio per testare più prelievi consecutivi e vedere l'accumulo
    char continua = 's';
    while (continua == 's' || continua == 'S') {
        cout << "Inserire l'importo da prelevare: ";
        cin >> importoDaPrel;

        if(prelievo(importoDaPrel, saldo, &totCommissioni)){
            cout << "Operazione riuscita!\n";
            cout << "Saldo aggiornato: " << saldo << endl;
            cout << "Totale commissioni accumulate: " << totCommissioni << endl;
        } else {
            cout << "Operazione rifiutata (importo non valido o saldo insufficiente).\n";
        }

        cout << "Vuoi fare un altro prelievo? (s/n): ";
        cin >> continua;
    }
    
    return 0;
}
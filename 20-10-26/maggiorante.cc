/*
03 - Maggiorante
Si scriva una funzione in C++ che riceva come parametri in ingresso due
numeri interi positivi n e b con b > 1, verifichi che tali condizioni siano
soddisfatte e calcoli la più piccola potenza di b il cui valore è maggiore di n (un
numero intero). 

La funzione dovrà restituire come parametri di uscita
l’esponente e ed il valore m della più piccola potenza di b il cui valore è
maggiore di n e, come valore di ritorno, -1 se per n o b sono stati inseriti valori
negativi o zero o se per b è stato inserito il valore 1, 0 altrimenti. Si scriva
quindi un programma C++ per verificare il corretto funzionamento della
funzione.
*/

#include <iostream>
#include <cmath>
using namespace std;


int funzione(int n, int b, int &e, int &m ){

    int operazioneValida = 0;

    if (n <= 0 || b <=1){
        operazioneValida = -1;
    }else{
        bool valoreTrovato = false;
        while (!valoreTrovato){
            
            if (m > n){
                valoreTrovato = true;
            }else{
                m*=b;
                e+=1;
                
            }
        }

    }

    return operazioneValida;


}



int main(){

    int e = 0, m = 1, n = 0, b = 0;

    cout << "Inserire n ";
    cin >> n;

    cout << "Inserire b ";
    cin >> b;

    if (funzione (n, b, e, m) == 0){
        cout << b << "^" << e << " = " << m << " > " << n << endl; 
    }else{
        cout << "L'operazione con i parametri inseriti non è valida \n";
    }

    

    return 0;
}
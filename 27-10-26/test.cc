#include <iostream>
#include <cmath>

using namespace std;

long magic(int n, int pos) {
    long somma = 0;
    int contatore = pos;
    
    while (n > 0) {
        int cifra = n % 10;        // Estrae l'ultima cifra
        long potenza = 1;
        
        // Calcola cifra^contatore
        for (int i = 0; i < contatore; ++i) {
            potenza *= cifra;
        }
        
        somma += potenza;
        n /= 10;                   // Rimuove l'ultima cifra elaborata
        contatore++;               // Incrementa la posizione per la cifra successiva
    }

    return somma;
}

int main() {
    int n, pos;
    cout << "Inserire n e pos: ";
    cin >> n >> pos;

    cout << "Risultato: " << magic(n, pos) << endl;

    return 0;
}
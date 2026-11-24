#include "sportello.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


bool Inserisci(char nomeFile[], Abbonamento abbonamenti[], int dimensioneLogica) {

    Abbonamento nuovo;

    cout << "Inserire numero abbonamento: ";
    cin >> nuovo.n;

    cout << "Inserire nome: ";
    cin >> nuovo.nome;

    cout << "Inserire cognome: ";
    cin >> nuovo.cognome;

    cout << "Inserire tipo (a/m/s/g): ";
    cin >> nuovo.tipo;

    // Determino il costo in base alla tipologia
    switch(nuovo.tipo) {

        case 'a':
            nuovo.costo = 500;
            break;

        case 'm':
            nuovo.costo = 150;
            break;

        case 's':
            nuovo.costo = 50;
            break;

        case 'g':
            nuovo.costo = 10;
            break;

        default:
            cout << "Tipologia non valida!\n";
            return false;
    }

    // Apro il file in modalità append
    fstream output(nomeFile, ios::app);

    if(!output) {
        cout << "Errore nell'apertura del file!\n";
        return false;
    }

    // Scrivo il nuovo abbonamento nel file
    output <<endl << nuovo.n << " "
           << nuovo.nome << " "
           << nuovo.cognome << " "
           << nuovo.tipo << " "
           << nuovo.costo;

    if(!output) {
        cout << "Errore durante la scrittura!\n";
        return false;
    }

    output.close();

    // Inserisco il nuovo abbonamento nell'array
    abbonamenti[dimensioneLogica] = nuovo;

    return true;
}

void Stampa(Abbonamento abbonamenti[], int dimensioneLogica){
    for(int i = 0; i < dimensioneLogica; i++) {

    cout << "\nAbbonamento " << i + 1 << endl;

    cout << "Numero: " << abbonamenti[i].n << endl;
    cout << "Nome: " << abbonamenti[i].nome << endl;
    cout << "Cognome: " << abbonamenti[i].cognome << endl;
    cout << "Tipo: " << abbonamenti[i].tipo << endl;
    cout << "Costo: " << abbonamenti[i].costo << endl;
    }
}
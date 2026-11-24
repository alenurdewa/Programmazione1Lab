#ifndef SPORTELLO_H
#define SPORTELLO_H

struct Abbonamento {
    int n;
    char nome[32];
    char cognome[32];
    char tipo;
    double costo;
};

bool Inserisci(char nomeFile[], Abbonamento abbonamenti[], int dimensioneLogica);

void Stampa(Abbonamento abbonamenti[], int dimensioneLogica);

#endif
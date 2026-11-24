#include <iostream>
#include <fstream>
#include "sportello.h"
#include <cstring>

using namespace std;




int main(){

    char nomeFile[] = "Abbonamenti2026.txt";
    fstream input;
    input.open(nomeFile, ios::in);
    int num;
    char nome[32];
    char cognome[32];
    char tipo;
    double costo;
    char riga[256];
    

    int numAbbonamenti = 0;

    while(input.getline(riga, 256)){
        numAbbonamenti++;
    }
    input.clear();
    input.seekg(0, ios::beg);

    Abbonamento* abbonamenti = new Abbonamento[numAbbonamenti * 2];

    int i = 0;

    while(input >> num >> nome >> cognome >>tipo >> costo){
        abbonamenti[i].n = num;
        strcpy(abbonamenti[i].nome, nome);
        strcpy(abbonamenti[i].cognome,cognome);
        abbonamenti[i].tipo = tipo;
        abbonamenti[i].costo = costo;
        i++;
    }

    

    int menu = 0;
    do{

        cout << "\nMenu:\n";
        cout << "0: Esci dal programma\n";
        cout << "1: Emetti un nuovo abbonamento\n";
        cout << "2: Calcola il guadagno totale\n";
        cout << "3: Calcola il ricavo\n";
        cout << "4: Stampa gli abbonamenti\n";
        cin >> menu;

        switch(menu){
            case 0: 
                cout << "Uscita dal programma in corso...\n";
                break;
            case 1:
                
                if(Inserisci(nomeFile, abbonamenti, numAbbonamenti)){
                    cout << "Abbonamento inserito correttamente\n";
                    numAbbonamenti++;
                }else{
                    cout << "L'abbonamento non è stato inserito per un errore\n";
                };
                break;
            case 4:
                Stampa(abbonamenti, numAbbonamenti);
                break;

            default:
                cout << "Il numero inserito non è valido\n";
        }

    }while(menu!=0);



}
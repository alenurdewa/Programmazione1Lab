#include <iostream>
#include <fstream>
#include <cstdlib>
#include "prime.h"

using namespace std;

struct nodo{
    int value;
    nodo* next;
};
typedef nodo* lista;


lista creaLista(char *inputFile ){

    fstream input;
    lista testa = NULL;
    input.open(inputFile, ios::in);
    if(input.fail()){
        cout << "Errore apertura file" << endl;
    }else{
        int numero;
        nodo* coda = NULL;
        
        while(input >> (numero)){
            nodo *nuovo = new nodo{numero, NULL};
            if(testa == NULL){
                testa = nuovo;
            } else{
                coda->next = nuovo;
            }
            coda = nuovo;
        }
        

    }

    return testa;
}

void stampaLista (lista testa){
    nodo* nodoSelezionato = testa;
    while(nodoSelezionato!= NULL){
        cout << nodoSelezionato -> value << " ";
        nodoSelezionato = nodoSelezionato ->next;
    }
}

void stampaInverita (lista listaDiNumeri){

    
    if(listaDiNumeri != NULL){
        stampaInverita(listaDiNumeri -> next);
    }
    if(listaDiNumeri != NULL){
        cout << listaDiNumeri -> value << " ";
    }
    
}

void distruggiLista (lista &listaDiNumeri){
    nodo* nodoSelezionato = listaDiNumeri;

    while(nodoSelezionato != NULL){
        nodo* nodoSuccessivo = nodoSelezionato -> next;
        delete nodoSelezionato;
        nodoSelezionato = nodoSuccessivo;
    }
    listaDiNumeri = NULL;
    cout << "Lista eliminata correttamente\n";
}

void primizzaLista(lista &listaDiNumeri){

    nodo* nodoSelezionato = listaDiNumeri;
    nodo* nodoPrecedente = NULL;
    while(nodoSelezionato !=NULL){
        if(nodoPrecedente == NULL && !numeroPrimo(nodoSelezionato->value)){
            listaDiNumeri = nodoSelezionato ->next;
            delete nodoSelezionato;
            nodoSelezionato = listaDiNumeri;
            nodoPrecedente = NULL;
        }else if(!numeroPrimo(nodoSelezionato->value)){
            nodoPrecedente->next = nodoSelezionato ->next;
            delete nodoSelezionato;
            nodoSelezionato = nodoPrecedente ->next;
        }else{
            nodoPrecedente = nodoSelezionato;
            nodoSelezionato = nodoSelezionato ->next;
        }
    }
}





int main( int argc, char *argv[]){
    int returnValue=0;
    lista listaDiNumeri = NULL;

    if(argc !=2){
        cout << "chiamata giusta: ./a.out <nome_file>" << endl;
        returnValue = 1;
    }else{

        listaDiNumeri = creaLista(argv[1]);
        if (listaDiNumeri == NULL){
            cout << "File vuoto o non leggibile " << endl;
            returnValue=2;
        }else{
            cout << "Lista creata correttamente" << endl;
        };

    }

    cout<< "Stampa lista normale: ";
    stampaLista(listaDiNumeri);

    cout<< "\nStampa lista invertita: ";
    stampaInverita(listaDiNumeri);



    cout << "\nPrimizza lista: ";
    primizzaLista(listaDiNumeri);
    stampaLista(listaDiNumeri);

    cout << "\n";
    distruggiLista(listaDiNumeri);
    return returnValue;
}
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Studente{

    char nome[30] ;
    char cognome[30];
    int matricola;
    float media;

};


Studente* genera_studente(char nome[], char cognome[], int matricola, float media_ponderata){
    Studente* stud = new Studente;
    strcpy(stud->nome, nome);
    strcpy(stud->cognome, cognome);
    
    stud->matricola = matricola;
    stud->media = media_ponderata;

    return stud;
}

void stampa_studente(Studente * studente){

    cout << endl;
    cout << "Nome: " << studente->nome << endl;
    cout << "Cognome: " << studente->cognome << endl;
    cout << "Matricola: " << studente->matricola << endl;
    cout << "Media: " << studente->media << endl;


   
}




int main(){
    char nome[30];
    char cognome[30];
    int matricola;
    float media;

    cout << "Inserire nome dello studente ";
    cin >> nome;

    cout << "Inserire nome dello cognome ";
    cin >> cognome;

    cout << "Inserire nome dello matricola ";
    cin >> matricola;

    cout << "Inserire la media ";
    cin >> media;

    Studente* stud = genera_studente(nome, cognome, matricola, media);

    stampa_studente(stud);
    delete stud;
    return 0;


}
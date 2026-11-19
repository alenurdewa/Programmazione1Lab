#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Studente {
    char nome[30];
    char cognome[30];
    int matricola;
    float media;
};



Studente* genera_studente(char nome[], char cognome[], int matricola, float media_ponderata) {
    Studente* stud = new Studente;
    strcpy(stud->nome, nome);
    strcpy(stud->cognome, cognome);

    stud->matricola = matricola;
    stud->media = media_ponderata;

    return stud;
}

void stampa_studente(Studente* studente) {
    cout << endl;
    cout << "Nome: " << studente->nome << endl;
    cout << "Cognome: " << studente->cognome << endl;
    cout << "Matricola: " << studente->matricola << endl;
    cout << "Media: " << studente->media << endl;
}

Studente** caricaDatabase(char file_name[], int n_righe) {
    fstream input;
    input.open(file_name, ios::in);

    if (!input.is_open()) {
        cerr << "Errore nell'apertura del file: " << file_name << endl;
        exit(1);
    }

    Studente** database = new Studente*[n_righe];

    char nome[30];
    char cognome[30];
    int matricola;
    float media;

    int i = 0;
    while (i < n_righe && (input >> nome >> cognome >> matricola >> media)) {
        database[i] = genera_studente(nome, cognome, matricola, media);
        i++;
    }


    input.close();
    return database;
}

int main() {
    char nome_file[100];
    int n_righe;

    cout << "Inserisci il nome del file: ";
    cin >> nome_file;

    cout << "Inserisci il numero di righe: ";
    cin >> n_righe;

    Studente** database = caricaDatabase(nome_file, n_righe);
    if (database == nullptr) {
        return 1;
    }

    for (int i = 0; i < n_righe; i++) {
        if (database[i] != nullptr) {
            stampa_studente(database[i]);
        }
    }

    // Liberazione della memoria
    for (int i = 0; i < n_righe; i++) {
        delete database[i];
    }
    delete[] database;

    return 0;
}
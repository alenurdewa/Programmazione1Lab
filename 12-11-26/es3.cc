#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv[]){

    if(argc!=3){
        cout << "Utilizzo: ./a.out <nomefileIn> <nomefileOut>\n";

        exit(1);
    }

    fstream input;
    fstream output;

    char * fileIn = argv[1];
    char * fileOut = argv[2];

    input.open(fileIn, ios::in);
    output.open(fileOut, ios::out);

    // Controllo separato per l'input
    if(input.fail()){
        cout << "Errore: Il file di input non esiste o non può essere aperto.\n";
        exit(1);
    }

    // Controllo separato per l'output
    if(output.fail()){
        cout << "Errore: Impossibile creare o aprire il file di output.\n";
        input.close(); // Buona norma chiudere l'input prima di uscire
        exit(1);
    }

    cout << "File aperti con successo!\n";

    char c;
    while (input.get(c)){
        output.put(c);
    }

    cout << "Copia eseguita con successo!\n";

    input.close();
    output.close();


    return 0;
}
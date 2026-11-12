#include <iostream>
#include <fstream>

using namespace std;


int main(){

    char  nomeFile[20];
    cout << "Inserire il nome di un file ";
    cin >> nomeFile;
    cout << nomeFile << endl;

    char l;
    cout << "Inserire lettera da sostituire ";
    cin >> l;

    fstream input;
    input.open(nomeFile, ios::in);
    if(input.fail()){
        cout << "Il file inserito non esiste\n";
        exit(1);
    }
    char c;
    while(input.get(c)){
        if(c==l){
            cout << '?';
        }else{
            cout << c;
        }
    }
    input.close();
    cout << endl;

    return 0;
}
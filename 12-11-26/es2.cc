#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


int main(int argc, char * argv[]){

    if(argc != 2){
        cout << "Utilizzo: ./a.out <input_file>\n";
        exit(0);
    }

    char* nomeFile= argv[1]; 

    fstream input;

    input.open(nomeFile, ios::in);


    if(input.fail()){

        cout << "Il nome del file inserito non esiste\n";

        exit(1);
    }

    char c;
    while(input.get(c)){
        cout << c;
    }
    input.close();
    return 0;

}
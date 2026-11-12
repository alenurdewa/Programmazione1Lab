#include <iostream>
#include <cstdlib>
using namespace std;

int calcola (int a, int b, char operatore){

    int risultato = 0;
    switch(operatore){
        case '+': 
            risultato = a + b;
            break;
        case '-': 
            risultato =  a - b;
            break;
        case '*': 
            risultato = a * b;
            break;
        case '/':
            if (b != 0) return a / b;
                else { cout << "Errore: Divisione per zero!\n"; return -1; }
            break;
        default: 
            cout << "Operatore non valido!\n"; 
            return -1;
    }
    return risultato;

}

int main(int argc, char* argv[]){

    if(argc!=4){
        cout << "Utilizzo: ./calcolatrice <n1> <n2> operatore\n";
        exit(1);
    }


    int n1 = atoi(argv[1]);
    int n2 = atoi(argv[2]);
    char* strOp = argv[3];
    char operatore = strOp[0];
    

    int risultato = calcola(n1,n2, operatore);
    
    cout<< "Risultato = " << risultato << endl;


}
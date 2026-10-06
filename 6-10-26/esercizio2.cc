#include <iostream>
using namespace std;

/*
Scrivere un programma C++ che riceve in input da tastiera tre numeri
interi a, b, c, di cui b e c siano rispettivamente l’estremo inferiore e
superiore di un intervallo. Se b è maggiore o maggiore uguale di c, il
programma segnala un errore e chiede di inserire di nuovo b e c. Il
progamma stampi a video un numero, seguendo il comportamento
della funzione rappresentata sotto, a seconda della posizione di a
nell’intervallo b, c.
*/

int main(){
    
    int a = 0, b=0, c=0;
    cout << "Inserire in input 3 numeri interi ";

    bool condizioneVerificata = 0;


    do{
        cout << "Inserire in input 3 numeri interi ";
        cin >> a >> b >> c;
        if(b < c ){
            condizioneVerificata = 1;
        }
    } while (!condizioneVerificata);

    if(b <= a && a <= c){
        cout << "f(a,b,c) = -1\n";
    }else if (a<b){
        cout << "f(a,b,c) = 1\n";
    }else{
        cout << "f(a,b,c) = 0\n";
    }


    


    return 0;
}
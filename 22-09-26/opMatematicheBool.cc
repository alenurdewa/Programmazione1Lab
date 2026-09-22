#include <iostream>
using namespace std;

int main(){
    //operazione matematiche e booleane

    float result = 5.0+10/5-2;
    bool maggiore = 5>6;  //maggiore è false


    //Casting, del tipo
    cout << (int) 'a' << endl; // stampa 97 perché char a interpretato come intero è 97 (in ASCII credo)
    cout << (char) 97 << endl; //stampa a
    cout << (char) ('a' + 4)<<endl; // quando ci sono tipi differenti, la somma forza come risultato un intero
    //quindi farà 97 + 4 = 101, castato come char 101 = 'e' quindi stamperà e
}
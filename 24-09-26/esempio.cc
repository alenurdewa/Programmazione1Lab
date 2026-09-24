#include <iostream>
using namespace std;

int main(){

    int intera = 7/3; //divisione tra interi forza un valore intero
    float decimale = 7/3;  //risultato intero perché 7 e 3 sono int. Dovrei scrivere 7.0 e 3.0 per ottenere risultato decimale
    float decimale2 = 7.5/3; //uno dei due valore decimale quindi viene risultato decimale
    int intera2 = 7.5/3; //risultato tipo int quindi viene int


    cout << "Div intera 7/3 = " << intera << endl; //stampa 2

    cout << "Div float 7/3 = " << decimale << endl; //stampa 2
    cout << "Div float 2 7.5/3 = " << decimale2 << endl; // stampa 2.5 
    cout << "Div intera 7.5/3 = " << intera2 << endl; // stampa 2

    return 0;
}

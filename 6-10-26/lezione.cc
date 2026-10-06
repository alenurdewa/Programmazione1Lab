//Tipi di errori
//Errori di sintassi: errori che il compilatore riesce a capire e quindi segnala
//Errori concettuali: errori che il compilatore non riesce a capire, ma che portano a risultati sbagliati


//attenzione
//errori piu comuni includono utilizzare = al posto di == nell'istruzione if
//NON si deve utilizzare == per confrontare due numeri reali (perch sono approssimazioni)



#include <iostream>
using namespace std;

int main(){
    //istruzione iterativa while

    int i = 5;
    while (i>0){
        cout << i << endl;
        i--;
    }

}
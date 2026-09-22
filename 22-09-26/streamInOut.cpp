#include <iostream> //per permettere input e output. Con parentesi angolari si riferisce a una libreria
//da qualche parte nel computer
using namespace std; //permette di non scrivere std:: davanti a cout e cin

int main(){
    char carattere;

    //std:: si può togliere quando si scrive using namespace std all'inizio
    std::cout << "Inserisci un carattere: "; //metti nello stream di output la stringa tra virgolette
    std::cin >> carattere; //prendi in input dall'utente un char e mettilo in carattere
    std::cout << "Il carattere inserito: " << carattere << endl; //prende carattere e lo mette nello stream di output, endl è a capo


    char carattere2;
    cout << "Inserere carattere 2: ";
    cin >> carattere2;
    cout << "Il carattere 2 inserito: " << carattere2 << endl; //endl = end line = a capo
    cout << "\n"; //stessa cosa di endl
    cout << "\tCiao";// tab, fa una tabulazione

    /* 
    Per fare commenti su più righe
    Miao miao
    */

    //g++ -o streamInOut.out streamInOut.cpp per generare l'eseguibile con un nome diverso da a.out

}
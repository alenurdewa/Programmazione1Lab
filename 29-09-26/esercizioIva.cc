#include <iostream>
#include <cmath>
using namespace std;

int main(){

    float prezzo, iva, lordo;

    cout << "\n--- Calcolo del lordo ---\n";
    cout << "Inserire prezzo netto ";
    cin >> prezzo;
    

    cout << "Inserire iva percentuale ";
    cin >> iva;

   
    lordo = prezzo + prezzo * (iva / 100);
    cout << "Lordo = " << "Prezzo " << prezzo << " + iva " << iva << " = " << lordo << endl;


    float prezzoLordo, iva2, netto;

    cout << "\n--- Calcolo del netto ---\n";
    cout << "Inserire prezzo lordo ";
    cin >> prezzoLordo;
    

    cout << "Inserire iva percentuale ";
    cin >> iva2;

    netto = prezzoLordo * 100/(iva2 +100);
    cout << "Netto = " << netto << endl;

    
    return 0;
}
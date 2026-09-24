#include <iostream>
using namespace std;

int main(){

    int secIn;
    cout << "Inserisci i secondi da mezzanotte ";
    cin >> secIn;

    int ore = secIn / (60*60); 
    int minuti = (secIn / 60) %60;
    int secondi = secIn%60;


    cout << "\nOrario: " << ore << ":";
    cout << minuti << ":";
    cout << secondi << endl;
    
    return 0;
}
#include <iostream>
using namespace std;
int main(){
    
    int vero_int = 12, falso_int=0;
    cout << "risultato:" << (vero_int && falso_int) << endl; // stampa 0
    cout << "risultato:" << (vero_int || falso_int) << endl; /* stampa 1 (ogni int che)
    che non è 0 viene considerato true come bool*/


    //operatore and
    bool a1 =false , b1= false, a2=true, b2=false; //e cosi via
    cout << "_______________\n";
    cout << "|     AND     |\n";
    cout << "|_____________|\n";
    cout << "| A | B | Out | \n";
    cout << "| 0 | 0 |  " << (a1 && b1) << "  |\n";
    cout << "| 1 | 0 |  " << (a2 && b2) << "  |\n";
    cout << "| 1 | 1 |  " << (1 && 1) << "  |\n";
    cout << "| 0 | 1 |  " << (0 && 1) << "  |\n";


    //operatore xor = ((notA) and B)) or ((notB) and A))

    bool a = 0, b= 1;
    bool xor_operation = a^b;
    cout << "Risultato xor con a = 0 e b = 1: " << xor_operation << endl;

    cout << "_______________\n";
    cout << "|     XOR     |\n";
    cout << "|_____________|\n";
    cout << "| A | B | Out | \n";
    cout << "| 0 | 0 |  " << (0 ^ 0) << "  |\n";
    cout << "| 1 | 0 |  " << (1 ^ 0) << "  |\n";
    cout << "| 1 | 1 |  " << (1 ^ 1) << "  |\n";
    cout << "| 0 | 1 |  " << (0 ^ 1) << "  |\n";



    return 0;
}
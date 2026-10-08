#include <iostream>
#include <cmath>
using namespace std;


int main(){

    int cifre, dividendo, divisore;
    int temp, quoto, resto, fattore;

    cout << "Imetti dividendo, divisore e cifre: ";

    cin >> dividendo >> divisore >> cifre;

    fattore = pow(10,cifre);

    temp = dividendo * fattore /divisore;

    quoto = temp / fattore;
    resto = temp%fattore;

    cout << dividendo << " : " << divisore <<  " = ";
    cout << quoto  << "," << resto << endl;


    //clear ; g++ divprec.cc && ./a.out (fa clear, poi compila e se ha successo esegue l'eseguibile)

}
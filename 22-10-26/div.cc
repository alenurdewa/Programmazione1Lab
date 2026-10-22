#include <iostream>


using namespace std;

int divisioneReal (int dividendo, int divisore, int &resto, int divisoreStart){

    int quoziente = 0;

    if (divisore == dividendo){
        quoziente = 1;
        return quoziente;
        
    }else if (divisore > dividendo) {
        resto = divisore - dividendo;  
        return quoziente;
    }else{
        quoziente = 1+ divisioneReal (dividendo, divisore+divisoreStart, resto, divisoreStart);
    }
    return quoziente;

}
int divisione (int dividendo, int divisore, int &resto){

    return divisioneReal (dividendo, divisore, resto, divisore);

}

int main(){

    int dividendo = 0, divisore = 0, resto = 0;


    cout << "Inserire dividendo ";
    cin >> dividendo;

    cout << "Inserire divisore ";
    cin >> divisore;

    int quoziente = divisione (dividendo, divisore, resto);

    cout << "Quoziente = " << quoziente << ". Resto = " << resto<< endl;


    return 0;
}
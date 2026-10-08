#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int n = 0;
    bool condizione = false;

    cout << "Inserire un valore intero n ";
    cin >> n;
    
    int contatore = 1;   //0+1= 1 1+0 =1 1+1 = 2 2+1 = 3 3+
    int nMenoUno = 0;
    int risultato = 0;
    while (!condizione){
        if(risultato >= n){
            condizione = true;
        }


        if(condizione){
            cout << risultato << endl;
        }else{
            cout << risultato << ",";
        }
        

        risultato = contatore + nMenoUno;
        nMenoUno = contatore;
        contatore = risultato;   
    };

    return 0;
}
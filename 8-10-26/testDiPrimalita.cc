#include <iostream>
#include <cmath>

using namespace std;

int main(){


    int n = 0;
    bool isPrimo = true;

    do{

        cout << "Inserire un numero n per determinare se sia un numero primo ";
        cin >> n;
    }while (n < 0);
    

    int contatore = 2;

    while (isPrimo && contatore != n){

        if (n % contatore == 0){
            isPrimo = false;
        }else{
            contatore+=1;
        }

    }

    if (isPrimo){
        cout << n << " è un numero primo \n";
    }else{
        cout << n << " non è un numero primo perché e divisibile per " << contatore << endl;
    }

    return 0;
}
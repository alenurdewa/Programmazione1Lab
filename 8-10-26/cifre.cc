#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int n = 0;
    int contacifre = 0;


    do{
        cout << "Imetti un intero positivo ";
        cin >> n;
    }while(n<=0);

    while (n >0){
        n = n/10;
        contacifre++;
    }

    if (contacifre == 1){
        cout <<  "Il numero ha 1 cifra" << endl;
    }else{
        cout << "Il numero ha "<< contacifre << " cifre"<< endl;
    }
    

    return 0;
}
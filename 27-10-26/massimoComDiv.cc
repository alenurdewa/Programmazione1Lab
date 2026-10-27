#include <iostream>
using namespace std;


int mcd(int a, int b){

    int div = 0;
    int resto = 0;
    if (b == 0){
        return a;
    }else{
        div = a/b;
        resto = a%b;
    }

    return mcd(b, resto);

}

int mcdIterativo(int a, int b){

    int resto = 0;


    while (b!=0){
        resto = a%b;
        a = b;
        b = resto;
    }
    return a;

}


int main(){

    int a, b;
    
    cout << "Inserire a ";
    cin >> a;
    cout << "Inserire b ";
    cin >> b;

    cout << "MCD = " << mcd(a,b) << endl;
    cout << "MCD iterativo = " << mcdIterativo(a,b) << endl;
    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

int fatt(int n) {
    int value = 1;
    if (n == 1 || n == 0){
        value = 1;
    }
    else {
        value = n*fatt(n-1);
    }
    return value;
}

int main(){

    int n = 0;
    cout << "Inserisci n ";
    cin >> n;
    int f = fatt (n);
    cout << "Fatt = " << f << endl;
    
}
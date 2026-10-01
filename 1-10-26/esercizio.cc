#include <iostream>
using namespace std;

int main(){


    //Calcolare il val assoluto della differenza di a-b
    int a = 0,b = 0;

    
    cout << "Inserire due valore a e b \n"; 
    cin >> a >> b;

    int dif = a-b;

    int absDif = dif * ((-1)*(dif < 0)) + dif * ((1)*(dif > 0));

    cout << "Differenza, con valore assoluto : " << absDif<< endl;

    return 0;
}
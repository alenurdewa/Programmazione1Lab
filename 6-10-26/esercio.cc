#include <iostream>
using namespace std;

int main(){

    //Es trovare il minore tra tre numeri
    int a, b,c;
    cout << "Inserire in input a, b e c ";
    cin >> a >> b >> c;

    int min = a;

    if (min > b){
        min = b;
    }
    if (min > c){
        min = c;
    }

    cout << "Min = " << min << endl;


    return 0;
}
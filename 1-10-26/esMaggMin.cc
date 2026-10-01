#include <iostream>
using namespace std;

int main(){

    int a = 0, b=0;

    cout << "Inserire in input a e b\n";

    cin >> a >> b;

    int max = (a+b) - ((a>b) * b + (a<b) * a) - (a==b)*a;
    int min = (a+b) - ((a<b) * b + (a>b) * a) - (a==b)*a;

    cout << "Max = " << max << endl;
    cout << "Min = " << min << endl;

    return 0;
}
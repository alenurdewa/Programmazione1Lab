#include <iostream>
using namespace std;

int main(){

    int a = 0, n = 0;
    do{
        cout << "Inserire due numeri interi a ed n ";
        cin >> a >> n;
    }while (n < 1);

    int base = a;

    cout << "Output: ";
    for (int i = 0; i<n; i++){
        if (i==n-1){
            cout << a << endl;
        }else{
            cout << a << ", ";
        }
        a *= base;
    }
    
    return 0;
}
#include <iostream>
using namespace std;

int main(){
    bool y, z;
    y= (1==0);
    z= (7>3);
    cout << "(int)y= " << (int) y << "  (bool)y=" << (bool)y << endl;
    cout << "(int)z= " << (int) z << "  (bool)z=" << (bool)z << endl;
    return 0;
}
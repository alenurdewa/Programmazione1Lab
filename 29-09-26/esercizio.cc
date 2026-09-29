#include <iostream>
#include <cmath>

using namespace std;

int main(){

    float a, b, c;

    cout << "Inserire in input a, b, c dell'equazione di secondo grado ax^2 + bx + c\n";
    cin >> a >> b >> c;

    float deltaTest = (b * b) - (4 * a * c);
    float delta = pow(b,2) - (4*a*c); // pow per la potenza, pow(base, grado)
    // delta = -1; debug per vedere che cosa succede nel caso di delta negativo
    cout << "Delta = "<<delta << endl;

    float x1 = (-b + sqrt(delta)) / (2*a);
    float x2 = (-b - sqrt(delta)) / (2*a);

    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;

    return 0;

}
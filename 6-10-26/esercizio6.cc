#include <iostream>
#include <cmath>

using namespace std;

int main() {

    const double EPS = 0.0000000001;
    double a, b, c, delta;

    cout << "Equazione di secondo grado ax^2 + bx + c = 0\n";

    cout << "Inserisci a: ";
    cin >> a;

    cout << "Inserisci b: ";
    cin >> b;

    cout << "Inserisci c: ";
    cin >> c;

    // Controllo che sia effettivamente un'equazione di secondo grado
    // se a è 0 NON è una equazione di secondo grado
    if (abs(a) < EPS) {
        cout << "Non e' un'equazione di secondo grado.";
        return 0;
    }

    delta = pow(b, 2) - 4 * a * c;

    if (delta < -EPS) {
        cout << "Non esistono soluzioni reali.";
    }
    else if (abs(delta) < EPS) {
        double x = -b / (2 * a);

        cout << "Esiste una soluzione reale doppia: x = " << x;
    }
    else {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);

        cout << "Esistono due soluzioni reali:\n";
        cout << "x1 = " << x1 << "\n";
        cout << "x2 = " << x2 << "\n";
    }

    return 0;
}

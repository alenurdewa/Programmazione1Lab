#include <iostream>
using namespace std;

// Funzione unica: il terzo parametro (acc) ha un valore di default = 1
int potenzaTailRecursive(int m, int n, int acc = 1) {
    // Caso base: se n è 0, restituiamo l'accumulatore
    if (n == 0) {
        return acc;
    }

    // Chiamata tail-recursive: aggiorniamo l'accumulatore e scaliamo n
    return potenzaTailRecursive(m, n - 1, acc * m);
}

int main(){
    int m, n;
    cout << "Inserire m: ";
    cin >> m;
    cout << "Inserire n: ";
    cin >> n;

    // La chiamata pulita richiede esattamente 2 parametri!
    cout << m << "^" << n << " = " << potenzaTailRecursive(m, n) << endl;

    return 0;
}
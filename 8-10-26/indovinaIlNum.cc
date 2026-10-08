#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


/*
Scrivere un programma che generi un numero tra 1 e 10
L'utente deve indovinare che numero è uscito
*/

int main(){

    int n = 0;
    int userWon = false;

    //per generare numero random;
    srand(time(NULL));
    int random_number = rand() % 10 +1;


    while (!userWon){
        //todo
        cin >> n;
    }

}
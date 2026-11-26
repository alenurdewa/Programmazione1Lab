#include <iostream>
#include "prime.h"

using namespace std;

bool numeroPrimo(int n ){
    int i ;
    for(i = 2; i<=n/2; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
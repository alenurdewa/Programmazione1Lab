#include <iostream>
#include <ctype.h>
#include <cstdlib>

using namespace std;

int contieneSoloLettereToLower(char str[]){

    int i = 0;
    while (str[i] != '\0'){
        if(!isalpha(str[i])){
            cout << "La stringa non contiene solo caratteri!\n";
            return false;
        }else{
            if(isupper(str[i])){
                str[i] = tolower(str[i]);
            }
            
        }
        i++;
    }
    return true;
}

int calcolaSommaDifAbs(char str[]){

    int somma = 0;
    if(!contieneSoloLettereToLower(str)){
        return -1;
    }

    int i = 0;
    while(str[i] != '\0'){
        if(str[i+1] != '\0'){
            somma+= abs(str[i]-str[i+1]);
        }
        i+=1;
    }
    return somma;

}


int main(){

    char str[31];
    
    cout << "Inserire una stringa di caratteri ";
    cin >> str;
    int somma = calcolaSommaDifAbs(str);

    if (somma != -1){
        cout << "Somma = " << somma << endl;
    }else{
        cout << "Stringa non valida\n";
    }

    return 0;
}
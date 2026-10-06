#include <iostream>

using namespace std;

int main(){

    char carattere = 'a';
    bool isVocale = false;

    cout << "Inserire un carattere ";
    cin >> carattere;

    if (carattere == 'a' || carattere == 'e'|| carattere == 'i' || carattere == 'o' || carattere == 'u' || carattere == 'A' || carattere == 'E' || carattere == 'I' || carattere == 'O' || carattere == 'U'){
        isVocale = true;
    }

    if (isVocale){
        cout << "Il carattere inserito è una vocale\n";
    }else if (int (carattere) < 65 || int(carattere) > 122  ){
        cout << "Il carattere inserito non è una lettera\n";
    }else{
        cout << "Il carattere inserito è una consonante\n";
    }

    return 0;

}
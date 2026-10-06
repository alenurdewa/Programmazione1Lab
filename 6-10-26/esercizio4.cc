#include <iostream>
using namespace std;

int main(){


    const float EPS = 0.000001; // "Accetta anche una piccola differenza, perché potrebbe essere dovuta all'approssimazione."
    float x = 0,y = 0;

    cout << "Inserire x e y di un punto ";
    cin >> x >> y;

    float a = 0, b= 0, c=0, d = 0;

    cout << "Inserire x e y del vertice in alto a sinistra del rettangolo ";
    cin >> a >> b;

    cout << "Inserire x e y del vertice in basso a destra del rettangolo ";

    cin >> c >> d;


    if ( x >= a - EPS && x <= c + EPS && y <= b + EPS && y >= d - EPS){
        cout << "Il punto si trova all'interno del rettangolo\n ";
    }else{
        cout << "Il punto si trova fuori dal rettangolo \n";
    }

    return 0;
}
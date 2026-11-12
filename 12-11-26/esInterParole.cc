#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;

int main(int argc, char * argv[]){
    if(argc != 3){
        cout << "Utilizzo: ./a.out <fileA> <fileB>\n";
        exit(1);
    }

    char * fileA = argv[1];
    char * fileB = argv[2];
    char fileC[] = {"FileC"};

    fstream inFileA;
    fstream inFileB;
    fstream outFileC;

    inFileA.open(fileA, ios::in);
    inFileB.open(fileB, ios::in);
    outFileC.open(fileC, ios::out);

    if(inFileA.fail() ||inFileB.fail() ||outFileC.fail()){
        cout << "Errore nell'apertura dei file\n";
        exit(1);
    }


    char paroleA[1000][101];
    int nParoleA = 0;

    char paroleB[1000][101];
    int nParoleB = 0;

    while(nParoleA<1000 && inFileA >> paroleA[nParoleA]){
        nParoleA ++;
    }
    inFileA.close();

    while(nParoleB<1000 && inFileB >> paroleB[nParoleB]){
        nParoleB ++;
    }
    inFileB.close();

    for (int i = 0; i < nParoleA ; i++){
        for(int j= 0; j < nParoleB; j++){
            if(strcmp(paroleA[i], paroleB[j]) == 0){
                outFileC << paroleA[i] << endl;
            }
        }
    }

    outFileC.close();


    return 0;
}
# Riassunto della lezione di C++ - 29/10/2026

La lezione lavora sugli array e sulle funzioni che li elaborano: inizializzazione casuale, stampa, conteggio, ricerca di massimo e minimo, media, filtro per intervallo e inversione dell'ordine degli elementi.

## Indice

1. [Compilazione ed esecuzione](#1-compilazione-ed-esecuzione)
2. [Array e funzioni](#2-array-e-funzioni)
3. [Numeri casuali](#3-numeri-casuali)
4. [Media, massimo e minimo](#4-media-massimo-e-minimo)
5. [Controllo di un intervallo](#5-controllo-di-un-intervallo)
6. [Invertire un array](#6-invertire-un-array)
7. [Confrontare due array](#7-confrontare-due-array)
8. [Riepilogo dei file e attenzioni](#8-riepilogo-dei-file-e-attenzioni)

## 1. Compilazione ed esecuzione

Per compilare un sorgente con `g++` e creare un eseguibile con un nome scelto:

```bash
g++ -std=c++17 es2.cc -o es2
./es2
```

Sostituire `es2.cc` con il nome del file che si vuole provare. Gli esercizi con numeri casuali possono mostrare valori diversi a ogni esecuzione.

## 2. Array e funzioni

Un array contiene più valori dello stesso tipo, raggiungibili tramite un indice che parte da `0`. In questi esercizi l'array e la sua dimensione vengono passati separatamente alle funzioni:

```cpp
void stampaArray(int arr[], int dimensione) {
    for (int i = 0; i < dimensione; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}
```

Il ciclo visita gli indici da `0` a `dimensione - 1`. Quando un array viene passato a una funzione in questo modo, la funzione può modificarne gli elementi: per questo `isInInterval` e `invertiArray` cambiano l'array ricevuto.

## 3. Numeri casuali

Nei file che generano valori casuali viene usato `rand()` insieme a `srand(time(NULL))`:

```cpp
srand(time(NULL)); // inizializza il generatore con l'ora corrente
arr[i] = rand() % 10;
```

`rand() % 10` produce un intero da `0` a `9`. Nel file `array.cc` l'espressione `rand() % (max + 1)` produce valori da `0` a `max`, estremi inclusi, se `max` è non negativo.

La sequenza dipende dal generatore e dal seme, quindi gli output casuali riportati qui sono esempi: non è garantito che coincidano con quelli di ogni esecuzione. Inoltre, l'operatore `%` può rendere alcuni valori leggermente più probabili di altri; per gli esercizi introduttivi è una tecnica semplice, ma non adatta a generare casualità rigorosa.

## 4. Media, massimo e minimo

In `es2.cc`, `maxMediaMin` calcola la somma, aggiorna massimo e minimo durante la scansione e restituisce la media:

```cpp
double maxMediaMin(int arr[], int &max, int &min, int dimensione) {
    int somma = 0;
    max = arr[0];
    min = arr[0];

    for (int i = 0; i < dimensione; i++) {
        somma += arr[i];
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    return static_cast<double>(somma) / dimensione;
}
```

`max` e `min` sono parametri passati per riferimento (`int &`): la funzione assegna loro i risultati, che restano disponibili nel chiamante. La media, invece, viene restituita con `return`.

La conversione a `double` prima della divisione è importante: altrimenti una divisione tra interi scarterebbe la parte decimale. Ad esempio, `7 / 2` tra interi dà `3`, mentre `static_cast<double>(7) / 2` dà `3.5`.

Il programma crea dieci valori tra `0` e `9`, quindi l'output cambia a ogni esecuzione. Ecco un possibile esempio con valori casuali ipotetici:

```text
arr[0] = 2
arr[1] = 7
arr[2] = 4
arr[3] = 1
arr[4] = 9
arr[5] = 3
arr[6] = 5
arr[7] = 0
arr[8] = 6
arr[9] = 3
Media = 4
Max = 9
Min = 0
```

Per questo esempio la somma è `40`, quindi la media è `40 / 10 = 4`.

## 5. Controllo di un intervallo

In `es3.cc`, `isInInterval` verifica quali elementi sono fuori dall'intervallo `[x, y]`. Gli estremi sono inclusi: un valore è fuori solo se è minore di `x` oppure maggiore di `y`.

```cpp
if (y < x) {
    contatore = -1; // segnala che l'intervallo è stato indicato al contrario
} else {
    for (int i = 0; i < d; i++) {
        if (arr[i] > y || arr[i] < x) {
            arr[i] = 0; // sostituisce con zero il valore fuori intervallo
            contatore++;
        }
    }
}
```

La funzione restituisce il numero di elementi fuori intervallo e modifica l'array sostituendo quegli elementi con `0`. Se `y < x`, restituisce `-1` e non esegue il ciclo.

L'array del programma è inizializzato ai valori da `1` a `10`. Con `x = 3` e `y = 7`:

```text
Inserire x 3
Inserire y 7
Numeri non nell'intervallo = 5
arr[0] = 0
arr[1] = 0
arr[2] = 3
arr[3] = 4
arr[4] = 5
arr[5] = 6
arr[6] = 7
arr[7] = 0
arr[8] = 0
arr[9] = 0
```

I valori `1`, `2`, `8`, `9` e `10` sono fuori dall'intervallo e vengono sostituiti con zero.

## 6. Invertire un array

In `es4.cc`, `invertiArray` copia gli elementi in ordine inverso in un array di appoggio e poi li ricopia nell'array originale:

```cpp
for (int i = 0; i < d; i++) {
    arrAppoggio[d - i - 1] = arr[i];
}

for (int i = 0; i < d; i++) {
    arr[i] = arrAppoggio[i];
}
```

L'indice `d - i - 1` parte dall'ultima posizione e arretra. Per esempio, l'array `[2, 4, 6, 8]` diventa `[8, 6, 4, 2]`.

Il programma stampa l'array prima e dopo l'inversione. I numeri cambiano a ogni esecuzione, ma la seconda sequenza deve essere la prima letta al contrario. Il sorgente dichiara `int arrAppoggio[d]`: gli array a lunghezza variabile non fanno parte dello standard C++, anche se alcuni compilatori li accettano come estensione. In C++ standard si può usare, ad esempio, `std::vector<int>` oppure un array di dimensione fissa.

Esempio di output con una sequenza casuale:

```text
array = [0] = 0
array = [1] = 6
array = [2] = 8
array = [3] = 2
array = [4] = 2
array = [5] = 0
array = [6] = 0
array = [7] = 4
array = [8] = 6
array = [9] = 6

array = [0] = 6
array = [1] = 6
array = [2] = 4
array = [3] = 0
array = [4] = 0
array = [5] = 2
array = [6] = 2
array = [7] = 8
array = [8] = 6
array = [9] = 0
```

La prima sequenza è quella iniziale; la seconda è la stessa sequenza rovesciata.

## 7. Confrontare due array

In `array.cc`, `generateRandomArray` riempie due array con valori tra `0` e `max`, mentre `stampaArray` mostra gli elementi. `countSameValue` confronta gli elementi nelle stesse posizioni e conta le corrispondenze:

```cpp
int countSameValue(int arr[], int arr2[], int dimensione) {
    int contatore = 0;
    for (int i = 0; i < dimensione; i++) {
        if (arr[i] == arr2[i]) {
            contatore++;
        }
    }
    return contatore;
}
```

Non cerca un valore in qualunque posizione dell'altro array: confronta `arr[0]` con `arr2[0]`, `arr[1]` con `arr2[1]` e così via.

Entrambi gli array vengono generati casualmente, quindi valori stampati e conteggio possono cambiare. Esempio abbreviato per mostrare come si confrontano gli indici:

```text
array[0] = 2
array[1] = 5
array[2] = 3

array[0] = 2
array[1] = 1
array[2] = 3

Ci sono 2 elementi uguali nei due array
```

Qui coincidono gli elementi negli indici `0` e `2`.

## 8. Riepilogo dei file e attenzioni

- `array.cc`: genera e stampa due array casuali e conta le posizioni in cui i valori coincidono.
- `es2.cc`: calcola media, massimo e minimo; usa parametri per riferimento per restituire massimo e minimo.
- `es3.cc`: conta e azzera gli elementi fuori da un intervallo, oppure restituisce `-1` se gli estremi sono invertiti.
- `es4.cc`: inverte un array usando un array di appoggio.

Attenzioni generali:

- Le funzioni ricevono anche la dimensione dell'array; va sempre passata correttamente.
- `maxMediaMin` parte da `arr[0]`, quindi presuppone che la dimensione sia maggiore di zero.
- Lo scambio di valori casuali in `array.cc` presuppone un `max` non negativo.
- L'uso di `rand() % n` è utile per gli esercizi, ma non produce una distribuzione perfettamente uniforme.
- L'array a lunghezza variabile di `es4.cc` è un'estensione del compilatore, non C++ standard.
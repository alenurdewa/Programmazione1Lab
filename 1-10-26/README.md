# Recap della lezione di C++ - 01/10/2026

Questa cartella raccoglie esempi ed esercizi su input e output, incremento e decremento, confronti tra numeri, calcolo di massimo e minimo, valore assoluto e possibili errori durante l'esecuzione.

## Indice

1. [Mappa dei file](#mappa-dei-file)
2. [Input, output e incremento](#input-output-e-incremento)
3. [Confronti e massimo/minimo](#confronti-e-massimominimo)
4. [Valore assoluto della differenza](#valore-assoluto-della-differenza)
5. [Errori a runtime](#errori-a-runtime)
6. [Problemi presenti nei sorgenti](#problemi-presenti-nei-sorgenti)
7. [Compilazione ed esecuzione](#compilazione-ed-esecuzione)

## Mappa dei file

| File | Argomento | Stato |
|---|---|---|
| [`lezione.cc`](lezione.cc) | Esempi di errori a runtime: divisione per zero, input errati e overflow | Compilabile; contiene appunti nei commenti |
| [`esStampa.cc`](esStampa.cc) | Lettura e stampa di un intero; decremento e incremento | Compilabile |
| [`esMaggMin.cc`](esMaggMin.cc) | Calcolo di massimo e minimo tramite confronti e funzioni di libreria | Da correggere: `max` e `min` sono usati sia come variabili sia come funzioni |
| [`esercizio.cc`](esercizio.cc) | Valore assoluto della differenza tra due interi | Compilabile |

## Input, output e incremento

Il file [`esStampa.cc`](esStampa.cc) legge un intero con `cin` e lo visualizza con `cout`:

```cpp
int a = 0;
cin >> a;
cout << "a = " << a << endl;
```

`--a` diminuisce `a` di uno e restituisce il nuovo valore. Il codice poi usa `++++a`, che equivale a due incrementi prefissi consecutivi (`++(++a)`). Dopo il decremento, questi due incrementi portano il valore iniziale di `a` a `a + 1`.

Per esempio, inserendo `5`, il programma stampa:

```text
a = 5
a-1 = 4
a+1 = 6
```

La forma `++++a` è valida qui, ma poco leggibile. In programmi più chiari conviene scrivere gli incrementi separatamente e stamparli con un'etichetta che descriva il valore ottenuto.

## Confronti e massimo/minimo

Nel file [`esMaggMin.cc`](esMaggMin.cc), confronti come `a > b` producono un valore booleano: `true` oppure `false`. In un'espressione aritmetica questi valori vengono convertiti rispettivamente in `1` e `0`.

Per questo si può selezionare il massimo con una formula basata sui confronti:

```cpp
int massimo = (a + b)
    - ((a > b) * b + (a < b) * a)
    - (a == b) * a;
```

Quando `a` e `b` sono diversi, la formula sottrae dalla somma il valore più piccolo. Quando sono uguali, sottrae uno dei due valori, lasciando il valore comune. La formula del minimo segue lo stesso ragionamento, sottraendo il maggiore.

In un programma ordinario il calcolo è più semplice da leggere con `std::max` e `std::min`, dichiarate nell'header `<algorithm>`:

```cpp
#include <algorithm>

int massimo = std::max(a, b);
int minimo = std::min(a, b);
```

## Valore assoluto della differenza

Il file [`esercizio.cc`](esercizio.cc) calcola la differenza `a - b` e ne determina il valore assoluto, cioè la distanza tra i due valori senza considerare il segno.

La versione compatta usa i confronti, che valgono `1` o `0`:

```cpp
int differenzaAssoluta = (a - b) * ((a > b) - (a < b));
```

- Se `a > b`, la parentesi vale `1`, quindi il risultato è `a - b`.
- Se `a < b`, la parentesi vale `-1`, quindi il risultato cambia segno.
- Se `a == b`, la parentesi vale `0`, quindi il risultato è zero.

Per esempio, con `a = 3` e `b = 8`, `a - b` vale `-5`; il fattore tra parentesi vale `-1`, perciò il risultato è `5`.

## Errori a runtime

Il file [`lezione.cc`](lezione.cc) raccoglie nei commenti alcuni esempi di problemi che possono verificarsi mentre il programma viene eseguito:

- **Divisione per zero:** il programma tenta di dividere un valore per `0`.
- **Input non valido:** il programma riceve dati diversi da quelli attesi, per esempio testo quando si aspetta un numero.
- **Overflow:** un risultato supera l'intervallo rappresentabile dal tipo numerico usato.

Questi sono diversi dagli errori di compilazione: un errore di compilazione impedisce di generare l'eseguibile, mentre un problema a runtime emerge durante l'esecuzione.

## Problemi presenti nei sorgenti

### [`esMaggMin.cc`](esMaggMin.cc)

Il programma dichiara le variabili `max` e `min`, poi prova a usarle anche come funzioni:

```cpp
int max = ...;
int min = ...;

max = max(a, b);
min = min(a, b);
```

I nomi delle variabili nascondono quelli delle funzioni, quindi il compilatore segnala che `max` e `min` non possono essere chiamate come funzioni. Inoltre, queste funzioni si dichiarano includendo `<algorithm>`, non `<cmath>`. Una correzione è usare nomi diversi per le variabili e chiamare le funzioni in modo esplicito:

```cpp
#include <algorithm>

int massimo = std::max(a, b);
int minimo = std::min(a, b);
```

## Compilazione ed esecuzione

Dalla cartella `1-10-26`, compilare un sorgente specificando il nome dell'eseguibile con `-o`:

```bash
g++ -Wall -Wextra esStampa.cc -o esStampa
./esStampa
```

Per provare un altro esercizio si possono sostituire il nome del file e quello dell'eseguibile. `-Wall -Wextra` attiva avvisi utili, ma non è obbligatorio per compilare. Il file `esMaggMin.cc`, nello stato attuale, non compila finché non si corregge il conflitto tra i nomi.
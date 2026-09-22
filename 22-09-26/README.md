# Riassunto della lezione di C++ - 22/09/2026

Questa lezione introduce la struttura minima di un programma C++, la compilazione, le variabili numeriche e booleane, il casting e gli stream di input e output.

## Indice

1. [Struttura minima di un programma](#1-struttura-minima-di-un-programma)
2. [Compilazione ed esecuzione](#2-compilazione-ed-esecuzione)
3. [Librerie e namespace](#3-librerie-e-namespace)
4. [Variabili e tipi di dato](#4-variabili-e-tipi-di-dato)
5. [Operatori matematici](#5-operatori-matematici)
6. [Operatori booleani](#6-operatori-booleani)
7. [Casting](#7-casting)
8. [Input e output con `cin` e `cout`](#8-input-e-output-con-cin-e-cout)
9. [Caratteri speciali e commenti](#9-caratteri-speciali-e-commenti)
10. [Esempio completo](#10-esempio-completo)
11. [Output dei programmi della lezione](#11-output-dei-programmi-della-lezione)
12. [Osservazioni sui file della lezione](#12-osservazioni-sui-file-della-lezione)

## 1. Struttura minima di un programma

Ogni programma C++ eseguibile deve avere una funzione chiamata `main`. L'esecuzione del programma inizia proprio da questa funzione.

```cpp
int main() {
    // Le istruzioni del programma vengono scritte qui.

    return 0;
}
```

### Significato degli elementi

- `int` indica che `main` restituisce un numero intero.
- `main` è il nome speciale della funzione di ingresso del programma.
- Le parentesi graffe delimitano il corpo della funzione.
- `return 0;` segnala che il programma è terminato correttamente.

Il valore restituito può essere controllato in Bash con il comando `echo $?` dopo l'esecuzione.

Il programma minimo non contiene istruzioni di stampa, quindi non mostra testo sul terminale. Dopo l'esecuzione, `echo $?` stampa:

```text
0
```

## 2. Compilazione ed esecuzione

Il compilatore `g++` trasforma il codice sorgente in un programma eseguibile.

### Compilazione con nome predefinito

```bash
g++ esempio.cc
./a.out
```

Il comando `g++ esempio.cc` crea normalmente un eseguibile chiamato `a.out`. Il comando `./a.out` lo esegue dalla cartella corrente.

### Compilazione con un nome scelto

```bash
g++ -o streamInOut.out streamInOut.cpp
./streamInOut.out
```

L'opzione `-o` permette di specificare il nome dell'eseguibile prodotto.

## 3. Librerie e namespace

Per usare input e output è necessario includere la libreria `<iostream>`.

```cpp
#include <iostream>
```

Le parentesi angolari indicano una libreria cercata dal compilatore tra quelle disponibili nel sistema o nell'ambiente di sviluppo.

Gli oggetti `cout` e `cin` appartengono al namespace `std`. Si possono usare in due modi.

### Scrittura esplicita di `std::`

```cpp
#include <iostream>

int main() {
    std::cout << "Ciao" << std::endl;
    return 0;
}
```

### Uso di `using namespace std`

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Ciao" << endl;
    return 0;
}
```

`using namespace std;` evita di dover scrivere `std::` ogni volta. Nei programmi più grandi è spesso preferibile usare esplicitamente `std::`, perché rende più chiara l'origine dei nomi.

## 4. Variabili e tipi di dato

Una variabile è uno spazio in memoria a cui viene assegnato un nome e che contiene un valore.

```cpp
float risultato = 5.0;
bool maggiore = false;
char carattere = 'A';
```

I tipi usati nei file della lezione sono:

- `float`: contiene numeri con la virgola, come `3.14`.
- `bool`: contiene un valore logico, cioè `true` oppure `false`.
- `char`: contiene un singolo carattere, scritto tra apici singoli, come `'A'`.

Le stringhe di testo, come `"Ciao"`, sono invece scritte tra virgolette doppie.

## 5. Operatori matematici

Gli operatori matematici principali sono:

| Operatore | Significato |
|---|---|
| `+` | Addizione |
| `-` | Sottrazione |
| `*` | Moltiplicazione |
| `/` | Divisione |
| `%` | Resto della divisione intera |

Esempio tratto da `opMatematicheBool.cc`:

```cpp
float risultato = 5.0 + 10 / 5 - 2;
```

Il calcolo viene eseguito rispettando l'ordine delle operazioni:

1. `10 / 5` produce `2`.
2. `5.0 + 2` produce `7.0`.
3. `7.0 - 2` produce `5.0`.

Poiché è presente `5.0`, il risultato viene trattato come numero reale e viene memorizzato in una variabile `float`.

## 6. Operatori booleani

Gli operatori di confronto producono un valore di tipo `bool`.

```cpp
bool maggiore = 5 > 6;
```

Poiché `5` non è maggiore di `6`, la variabile `maggiore` vale `false`.

I principali confronti sono:

| Operatore | Significato |
|---|---|
| `>` | Maggiore di |
| `<` | Minore di |
| `>=` | Maggiore o uguale a |
| `<=` | Minore o uguale a |
| `==` | Uguale a |
| `!=` | Diverso da |

Esempio:

```cpp
int eta = 20;
bool maggiorenne = eta >= 18; // true, perché 20 è maggiore o uguale a 18
```

Attenzione: `=` assegna un valore, mentre `==` confronta due valori.

## 7. Casting

Il casting converte temporaneamente un valore da un tipo a un altro.

Nel file `opMatematicheBool.cc` vengono convertiti un carattere e un numero intero:

```cpp
cout << (int)'a' << endl;
cout << (char)97 << endl;
```

- `(int)'a'` interpreta il carattere `'a'` come numero intero e stampa il suo codice numerico.
- `(char)97` interpreta il numero `97` come carattere e stampa `a` nei sistemi che usano la codifica ASCII.

Nel file della lezione è presente anche questo esempio:

```cpp
cout << (char)('a' + 4) << endl;
```

Prima `'a'` viene promosso a `int`, poi viene sommato `4`: il codice numerico passa da `97` a `101`. Il cast finale a `char` converte `101` nel carattere `e` in ASCII.

L'output delle tre istruzioni di casting è quindi:

```text
97
a
e
```

Le variabili `result` e `maggiore` vengono calcolate, ma non vengono stampate perché nel sorgente non compare nessun `cout` che le utilizzi.

Una forma più moderna e leggibile del casting è:

```cpp
cout << static_cast<int>('a') << endl;
cout << static_cast<char>(97) << endl;
```

Il casting non modifica necessariamente la variabile originale: converte il valore nell'espressione in cui viene utilizzato.

## 8. Input e output con `cin` e `cout`

`cout` invia dati allo stream di output, normalmente il terminale. L'operatore `<<` inserisce i dati nello stream.

```cpp
cout << "Inserisci un carattere: ";
```

`cin` legge dati dallo stream di input, normalmente la tastiera. L'operatore `>>` estrae il dato e lo salva nella variabile indicata.

```cpp
char carattere;
cin >> carattere;
```

Esempio completo per leggere e ristampare un carattere:

```cpp
#include <iostream>
using namespace std;

int main() {
    char carattere;

    cout << "Inserisci un carattere: ";
    cin >> carattere;
    cout << "Il carattere inserito: " << carattere << endl;

    return 0;
}
```

È possibile concatenare più elementi nello stesso `cout` usando più operatori `<<`.

    Se l'utente inserisce `A`, l'output è:

    ```text
    Inserisci un carattere: A
    Il carattere inserito: A
    ```

    La `A` nella prima riga è il carattere digitato dall'utente.

## 9. Caratteri speciali e commenti

### A capo e tabulazione

`endl` manda a capo l'output:

```cpp
cout << "Prima riga" << endl;
cout << "Seconda riga";
```

Anche `\n` inserisce un a capo:

```cpp
cout << "Prima riga\nSeconda riga";
```

Il carattere speciale `\t` inserisce una tabulazione:

```cpp
cout << "\tTesto indentato";
```

Il risultato visivo è una riga con `Testo indentato` spostato in avanti da una tabulazione.

Esempio:

```text
    Testo indentato
```

### Commenti su una riga

Un commento iniziato con `//` termina alla fine della riga e viene ignorato dal compilatore.

```cpp
// Questo testo spiega l'istruzione successiva.
cout << "Ciao";
```

### Commenti su più righe

I commenti tra `/*` e `*/` possono occupare più righe.

```cpp
/*
   Questo è un commento
   su più righe.
*/
```

## 10. Esempio completo

Il seguente programma riunisce input, output, confronto e casting.

```cpp
#include <iostream>

int main() {
    char carattere;

    std::cout << "Inserisci un carattere: ";
    std::cin >> carattere;

    bool eMinuscolo = carattere >= 'a' && carattere <= 'z';

    std::cout << "Hai inserito: " << carattere << '\n';
    std::cout << "Codice numerico: "
              << static_cast<int>(carattere) << '\n';
    std::cout << "E' minuscolo? " << eMinuscolo << '\n';

    return 0;
}
```

In questo esempio:

- `char` memorizza il carattere inserito.
- `&&` richiede che entrambe le condizioni siano vere.
- Il confronto determina se il carattere è compreso tra `'a'` e `'z'`.
- `static_cast<int>` mostra il codice numerico del carattere.
- `\n` manda a capo senza usare `endl`.

Con input `g`, l'output è:

```text
Inserisci un carattere: g
Hai inserito: g
Codice numerico: 103
E' minuscolo? 1
```

Il valore booleano viene stampato come `1` per `true` e `0` per `false`. Per ottenere le parole `true` e `false`, si può aggiungere `std::boolalpha` allo stream.

## 11. Output dei programmi della lezione

### `esempio.cc`

Non stampa nulla. Il valore di ritorno del programma è `0`:

```bash
./a.out
echo $?
0
```

### `opMatematicheBool.cc`

Stampa soltanto i tre risultati dei cast, perché le variabili `result` e `maggiore` non vengono inviate a `cout`:

```text
97
a
e
```

### `streamInOut.cpp`

Ad esempio, inserendo prima `A` e poi `B`, il terminale mostra un risultato equivalente a:

```text
Inserisci un carattere: A
Il carattere inserito: A
Inserere carattere 2: B
Il carattere 2 inserito: B

    Ciao
```

La tabulazione prima di `Ciao` può avere una larghezza diversa a seconda del terminale. I caratteri inseriti dall'utente compaiono sulla stessa riga del prompt perché il prompt non termina con `endl` o `\n`. Anche `Ciao` non è seguito da un a capo, quindi il prompt della shell può comparire subito dopo la parola.

## 12. Osservazioni sui file della lezione

- `esempio.cc` mostra la funzione minima `main`, il valore di ritorno e i comandi base per compilare ed eseguire.
- `opMatematicheBool.cc` mostra un'espressione matematica, un confronto booleano, la promozione di `char` a `int` durante una somma e il casting tra `char` e `int`.
- `streamInOut.cpp` mostra l'inclusione di `<iostream>`, l'uso di `cin` e `cout`, la lettura di due caratteri, gli a capo, le tabulazioni e i commenti.
- In `streamInOut.cpp` la riga `std:cout << ...` contiene un refuso: la forma corretta è `std::cout << ...`. In questo file il compilatore può comunque accettarla perché `cout` è già disponibile tramite `using namespace std;`, ma `std:cout` non esprime correttamente l'accesso al namespace. La versione con `using namespace std;` può anche essere scritta semplicemente come `cout << ...`.
- Per stampare un valore booleano come `true` o `false` invece di `1` o `0`, si può usare `boolalpha`:

```cpp
std::cout << std::boolalpha << eMinuscolo << '\n';
```

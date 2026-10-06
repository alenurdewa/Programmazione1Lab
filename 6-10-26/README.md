# Lezione del 06/10/2026

Questa cartella raccoglie esempi e esercizi di programmazione in C++ dedicati a:

- cicli `while` e `do-while`;
- decisioni con `if`/`else`;
- confronto tra valori e intervalli;
- controllo di caratteri e vocali;
- punti e rettangoli nel piano;
- successioni numeriche;
- equazioni di secondo grado con tolleranza numerica.

## Indice

1. [Mappa dei file](#mappa-dei-file)
2. [Argomenti principali](#argomenti-principali)
   1. [Cicli while e do-while](#cicli-while-e-do-while)
   2. [Minore tra tre numeri](#minore-tra-tre-numeri)
   3. [Funzione nell'intervallo](#funzione-nellintervallo)
   4. [Vocali e consonanti](#vocali-e-consonanti)
   5. [Punto all'interno di un rettangolo](#punto-allinterno-di-un-rettangolo)
   6. [Successione geometrica](#successione-geometrica)
   7. [Equazione di secondo grado](#equazione-di-secondo-grado)
3. [Note e problemi da tenere presenti](#note-e-problemi-da-tenere-presenti)
4. [Compilazione](#compilazione)

## Mappa dei file

| File | Argomento | Stato |
|---|---|---|
| [lezione.cc](lezione.cc) | Errori comuni e cicli `while`/`do-while` | Compilabile |
| [esercizio.cc](esercizio.cc) | Trova il minimo tra tre numeri | Compilabile |
| [esercizio2.cc](esercizio2.cc) | Funzione definita su un intervallo | Compilabile |
| [esercizio3.cc](esercizio3.cc) | Controllo di vocale/consonante/non-lettera | Compilabile |
| [esercizio4.cc](esercizio4.cc) | Punto dentro un rettangolo | Compilabile |
| [esercizio5.cc](esercizio5.cc) | Successione geometrica | Compilabile |
| [esercizio6.cc](esercizio6.cc) | Equazione di secondo grado | Compilabile |

## Argomenti principali

### Cicli while e do-while

Il file [lezione.cc](lezione.cc) introduce i due cicli più usati in C++.

```cpp
int i = 5;
while (i > 0) {
    cout << i << endl;
    i--;
}

int j = 5;

do {
    cout << i << endl;
    i--;
} while (i > 0);
```

La differenza fondamentale è questa:

- `while`: controlla la condizione prima di eseguire il corpo;
- `do-while`: esegue almeno una volta il corpo, poi controlla la condizione.

Nel codice, dopo il primo `while`, la variabile `i` arriva a `0`. Nel `do-while` viene stampato ancora `i`, cioè `0`, perché il corpo viene eseguito anche quando la condizione è già falsa.

#### Output reale del programma

```text
5
4
3
2
1
0
0
```

Nota: la seconda parte usa `i` invece di `j`, quindi non è un esempio pulito di `do-while`; dimostra però il comportamento del ciclo con test post-condizionale.

### Minore tra tre numeri

Il file [esercizio.cc](esercizio.cc) legge tre numeri e trova il minimo.

```cpp
int a = 0, b = 0, c = 0;
cin >> a >> b >> c;

int min = a;

if (min > b) {
    min = b;
}
if (min > c) {
    min = c;
}

cout << "Min = " << min << endl;
```

L'idea è semplice:

1. inizializziamo `min` con `a`;
2. confrontiamo con `b` e `c`;
3. se troviamo un valore più piccolo, lo sostituiamo.

#### Esempio

Input:

```text
3 1 10
```

Output:

```text
Inserire in input a, b e c Min = 1
```

### Funzione nell'intervallo

Il file [esercizio2.cc](esercizio2.cc) riceve tre interi `a`, `b`, `c` e poi decide il valore di una funzione a seconda della posizione di `a` rispetto all'intervallo `[b, c]`.

```cpp
if (b <= a && a <= c) {
    cout << "f(a,b,c) = -1\n";
} else if (a < b) {
    cout << "f(a,b,c) = 1\n";
} else {
    cout << "f(a,b,c) = 0\n";
}
```

La logica è la seguente:

- se `a` è dentro l'intervallo chiuso `[b, c]`, stampa `-1`;
- se `a` è più piccolo di `b`, stampa `1`;
- altrimenti stampa `0`.

Questo programma usa un `do-while` per richiedere i valori finché `b < c` non è verificato.

#### Esempio

Input:

```text
5 2 8
```

Output:

```text
Inserire in input 3 numeri interi Inserire in input 3 numeri interi f(a,b,c) = -1
```

L'output ha una doppia stampa iniziale del prompt perché nel codice il messaggio viene scritto sia prima del ciclo che dentro al ciclo stesso.

### Vocali e consonanti

Il file [esercizio3.cc](esercizio3.cc) legge un carattere e determina se è:

- vocale;
- consonante;
- non-lettera.

```cpp
char carattere = 'a';
bool isVocale = false;

cin >> carattere;

if (carattere == 'a' || carattere == 'e' || carattere == 'i' || carattere == 'o' || carattere == 'u' ||
    carattere == 'A' || carattere == 'E' || carattere == 'I' || carattere == 'O' || carattere == 'U') {
    isVocale = true;
}

if (isVocale) {
    cout << "Il carattere inserito è una vocale\n";
} else if (int(carattere) < 65 || int(carattere) > 122) {
    cout << "Il carattere inserito non è una lettera\n";
} else {
    cout << "Il carattere inserito è una consonante\n";
}
```

Le condizioni usano un controllo esplicito delle vocali e poi un controllo sugli intervalli ASCII per distinguere lettere da altri caratteri.

#### Esempio

Input:

```text
a
```

Output:

```text
Inserire un carattere Il carattere inserito è una vocale
```

### Punto all'interno di un rettangolo

Il file [esercizio4.cc](esercizio4.cc) verifica se un punto `(x, y)` è all'interno di un rettangolo definito dai suoi vertici in alto a sinistra e in basso a destra.

```cpp
const double EPS = 0.000001;

if (x >= a - EPS && x <= c + EPS &&
    y <= b + EPS && y >= d - EPS) {
    cout << "Il punto si trova all'interno del rettangolo\n";
} else {
    cout << "Il punto si trova fuori dal rettangolo\n";
}
```

L'uso di `EPS` serve a gestire piccoli errori di approssimazione numerica dovuti ai numeri in virgola mobile.

#### Esempio

Input:

```text
2 3
3 1
```

Il programma interpreta i dati così:

- punto: `(2, 3)`
- angolo in alto a sinistra: `(3, 1)`
- angolo in basso a destra: `(3, 1)`

La logica del programma è un po' rigida, perché in questo caso il punto è fuori dal rettangolo considerato. Output reale:

```text
Inserire x e y di un punto Inserire x e y del vertice in alto a sinistra del rettangolo Inserire x e y del vertice in basso a destra del rettangolo Il punto si trova fuori dal rettangolo
```

### Successione geometrica

Il file [esercizio5.cc](esercizio5.cc) legge un numero `a` e un valore `n` e stampa i primi `n` termini della successione:

```cpp
int base = a;

for (int i = 0; i < n; i++) {
    if (i == n - 1) {
        cout << a << endl;
    } else {
        cout << a << ", ";
    }
    a *= base;
}
```

L'espressione `a *= base` fa crescere il valore come una proporzione geometrica: il passo successivo è il precedente moltiplicato per il primo termine.

#### Esempio

Input:

```text
2 4
```

Output:

```text
Inserire due numeri interi a ed n Output: 2, 4, 8, 16
```

### Equazione di secondo grado

Il file [esercizio6.cc](esercizio6.cc) risolve un'equazione di secondo grado:

```cpp
if (abs(a) < EPS) {
    cout << "Non e' un'equazione di secondo grado.";
    return 0;
}

delta = pow(b, 2) - 4 * a * c;
```

Quindi:

- se `a` è zero, non è una quadratica;
- se `delta < 0`, non ci sono soluzioni reali;
- se `delta` è circa zero, c'è una soluzione doppia;
- altrimenti ci sono due radici reali.

Usa una soglia `EPS` per evitare problemi di approssimazione numerica.

#### Esempio

Input:

```text
1 -3 2
```

Output:

```text
Equazione di secondo grado ax^2 + bx + c = 0
Inserisci a: Inserisci b: Inserisci c: Esistono due soluzioni reali:
x1 = 2
x2 = 1
```

## Note e problemi da tenere presenti

### 1. Errori di sintassi e di logica

Nel file [lezione.cc](lezione.cc) sono riportati i principali tipi di errore:

- errori di sintassi: il compilatore li segnala subito;
- errori concettuali: il programma compila, ma produce risultati sbagliati.

Un esempio classico è usare `=` invece di `==` in un controllo.

### 2. Numeri reali e approssimazione

I numeri in virgola mobile non sono sempre rappresentati con precisione esatta. Per questo motivo, in [esercizio4.cc](esercizio4.cc) e [esercizio6.cc](esercizio6.cc) il codice usa una costante `EPS` per tollerare piccole differenze.

### 3. Bug nel ciclo do-while

In [lezione.cc](lezione.cc), il secondo ciclo usa `i` invece di `j`:

```cpp
int j = 5;

do {
    cout << i << endl;
    i--;
} while (i > 0);
```

Questo è un esempio didattico del comportamento del `do-while`, ma non è la forma più chiara dal punto di vista del codice.

## Compilazione

Per compilare un file della cartella, si usa `g++`:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic esercizio6.cc -o esercizio6
./esercizio6
```

Per compilare tutti i programmi della cartella:

```bash
for file in *.cc; do
    g++ -std=c++17 -Wall -Wextra -pedantic "$file" -o "${file%.cc}";
done
```

I sorgenti presenti in questa cartella sono tutti compilabili e hanno comportamenti coerenti con i risultati mostrati in questa guida.

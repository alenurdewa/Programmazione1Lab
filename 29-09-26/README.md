# Riassunto della lezione di C++ - 29/09/2026

Questa lezione esercita condizioni booleane, operatori logici, calcolo delle soluzioni di un'equazione di secondo grado, calcolo dell'IVA e scambio dei valori di due variabili.

## Indice

1. [Compilare ed eseguire i programmi](#1-compilare-ed-eseguire-i-programmi)
2. [Valori booleani e operatori logici](#2-valori-booleani-e-operatori-logici)
3. [Equazione di secondo grado](#3-equazione-di-secondo-grado)
4. [Calcolo dell'IVA](#4-calcolo-delliva)
5. [Scambio di due variabili con una temporanea](#5-scambio-di-due-variabili-con-una-temporanea)
6. [Scambio senza una terza variabile](#6-scambio-senza-una-terza-variabile)
7. [Riepilogo dei file](#7-riepilogo-dei-file)

## 1. Compilare ed eseguire i programmi

Con `g++` si compila un file C++ e si crea un eseguibile. Per esempio:

```bash
g++ esempio.cc -o esempio
./esempio
```

L'opzione `-o esempio` assegna il nome `esempio` al programma eseguibile. Per gli altri file basta sostituire il nome del sorgente e dell'eseguibile.

Nei programmi che leggono dati con `cin`, i valori di prova vanno digitati nel terminale nello stesso ordine in cui il programma li richiede. Negli esempi qui sotto, gli input sono indicati separatamente dall'output.

## 2. Valori booleani e operatori logici

Un valore di tipo `bool` può essere `true` (vero) o `false` (falso). Quando vengono stampati direttamente con `cout`, in assenza di `boolalpha`, appaiono rispettivamente come `1` e `0`.

Gli operatori usati in `esempio.cc` sono:

| Operatore | Nome | Risultato |
|---|---|---|
| `&&` | AND logico | Vero solo se entrambi gli operandi sono veri |
| `||` | OR logico | Vero se almeno uno degli operandi è vero |
| `^` | XOR | Vero se gli operandi sono diversi |

Esempio dal programma:

```cpp
int vero_int = 12;
int falso_int = 0;

cout << "risultato:" << (vero_int && falso_int) << endl;
cout << "risultato:" << (vero_int || falso_int) << endl;
```

In un'espressione logica, `0` viene considerato falso e un intero diverso da `0`, come `12`, viene considerato vero. Perciò AND produce `0` e OR produce `1`.

Output:

```text
risultato:0
risultato:1
```

### Tavola di verità di AND

L'esempio stampa anche una tavola di verità. Ogni riga mostra i valori di ingresso `A` e `B` e il risultato di `A && B`.

```text
_______________
|     AND     |
|_____________|
| A | B | Out |
| 0 | 0 |  0  |
| 1 | 0 |  0  |
| 1 | 1 |  1  |
| 0 | 1 |  0  |
```

AND è vero solo nell'ultima combinazione in cui entrambi gli ingressi sono `1`.

### Tavola di verità di XOR

In C++, `^` è l'operatore XOR bit a bit. Con gli operandi `0` e `1` usati in questo esercizio, produce la tavola XOR mostrata sotto: il risultato è `1` quando gli ingressi sono diversi.

```cpp
bool a = 0;
bool b = 1;
bool xor_operation = a ^ b;

cout << "Risultato xor con a = 0 e b = 1: "
     << xor_operation << endl;
```

Output:

```text
Risultato xor con a = 0 e b = 1: 1
```

La tabella stampata dal programma è:

```text
_______________
|     XOR     |
|_____________|
| A | B | Out |
| 0 | 0 |  0  |
| 1 | 0 |  1  |
| 1 | 1 |  0  |
| 0 | 1 |  1  |
```

## 3. Equazione di secondo grado

Il programma `esercizio.cc` calcola le soluzioni dell'equazione:

```text
ax^2 + bx + c = 0
```

Prima legge i coefficienti `a`, `b` e `c`. Poi calcola il discriminante, chiamato delta:

```cpp
float delta = pow(b, 2) - (4 * a * c);
```

La funzione `pow(base, esponente)`, fornita dalla libreria `<cmath>`, calcola una potenza. Qui `pow(b, 2)` equivale a $b^2$. Il programma usa poi `sqrt(delta)` per calcolare la radice quadrata di delta e applica le formule:

```cpp
float x1 = (-b + sqrt(delta)) / (2 * a);
float x2 = (-b - sqrt(delta)) / (2 * a);
```

Esempio con `a = 1`, `b = -3`, `c = 2`:

```text
Inserire in input a, b, c dell'equazione di secondo grado ax^2 + bx + c
1 -3 2
Delta = 1
x1 = 2
x2 = 1
```

Infatti $x^2 - 3x + 2 = 0$ ha soluzioni $2$ e $1$.

### Condizioni da controllare

Il sorgente applica direttamente la formula, ma non controlla tutti i casi. Le soluzioni reali calcolate con `sqrt(delta)` richiedono `delta >= 0`; se delta è negativo, la radice quadrata non è un numero reale. Inoltre `a` deve essere diverso da `0`, altrimenti il denominatore `2 * a` è zero e l'equazione non è di secondo grado.

`deltaTest` calcola lo stesso discriminante usando `b * b`, ma non viene utilizzato. Per un programma più robusto si può conservare un solo calcolo di delta e controllare i casi prima di chiamare `sqrt`.

## 4. Calcolo dell'IVA

Il programma `esercizioIva.cc` calcola sia il prezzo lordo a partire dal prezzo netto, sia il prezzo netto a partire dal lordo.

### Dal netto al lordo

La percentuale IVA viene trasformata in frazione dividendo per `100`:

```cpp
lordo = prezzo + prezzo * (iva / 100);
```

Per un prezzo netto di `100` e IVA al `22%`, il calcolo è `100 + 100 * 0.22`, quindi il lordo è `122`.

### Dal lordo al netto

La formula inversa è:

```cpp
netto = prezzoLordo * 100 / (iva2 + 100);
```

Con lordo `122` e IVA al `22%`, il netto risulta `100`.

Esempio completo di esecuzione con questi valori:

```text
--- Calcolo del lordo ---
Inserire prezzo netto 100
Inserire iva percentuale 22
Lordo = Prezzo 100 + iva 22 = 122

--- Calcolo del netto ---
Inserire prezzo lordo 122
Inserire iva percentuale 22
Netto = 100
```

L'output effettivo include i prompt; i numeri sulla stessa riga dei prompt sono i valori inseriti dall'utente.

## 5. Scambio di due variabili con una temporanea

In `esercizioScambio.cc` una terza variabile conserva temporaneamente il valore di `a`:

```cpp
int c = a; // conserva il valore iniziale di a
 a = b;     // copia b in a
 b = c;     // copia il vecchio valore di a in b
```

L'esempio scambia i valori `3` e `8`:

```text
Inserisci a e b:
3 8

Valori iniziali:
a = 3
b = 8

Valori scambiati:
a = 8
b = 3
```

La variabile temporanea rende il procedimento facile da seguire e funziona con valori interi senza rischiare di perdere uno dei due valori durante lo scambio.

## 6. Scambio senza una terza variabile

`esScambioSenzaC.cc` esegue lo scambio con somme e sottrazioni:

```cpp
a = a + b;
b = a - b;
a = a - b;
```

Con `a = 3` e `b = 8`:

1. Dopo `a = a + b`, `a` vale `11`.
2. Dopo `b = a - b`, `b` vale `3`.
3. Dopo `a = a - b`, `a` vale `8`.

Output del programma:

```text
Inserisci a e b:
3 8

Valori iniziali:
a = 3
b = 8

Valori scambiati:
a = 8
b = 3
```

Questa tecnica mostra come riutilizzare i valori, ma con gli interi può causare overflow se la somma `a + b` supera il valore massimo rappresentabile. In codice normale, la variante con una variabile temporanea è generalmente più chiara e sicura.

## 7. Riepilogo dei file

- `esempio.cc`: valori interi usati come vero/falso, operatori `&&` e `||`, operatore XOR `^` e relative tavole di verità.
- `esercizio.cc`: calcolo del discriminante e delle soluzioni di un'equazione di secondo grado.
- `esercizioIva.cc`: calcolo del prezzo lordo dal netto e del netto dal lordo.
- `esercizioScambio.cc`: scambio dei valori di due variabili usando una variabile temporanea.
- `esScambioSenzaC.cc`: scambio dei valori usando somme e sottrazioni, senza una terza variabile.

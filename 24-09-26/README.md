# Lezione del 24/09/2026

Questa cartella raccoglie esempi ed esercizi sui tipi fondamentali del C++, sugli operatori e sulle conversioni tra caratteri e numeri.

## Indice

1. [Mappa dei file](#mappa-dei-file)
2. [Concetti principali](#concetti-principali)
   1. [Valori booleani](#valori-booleani)
   2. [Divisione intera e divisione reale](#divisione-intera-e-divisione-reale)
   3. [Caratteri, ASCII e conversioni maiuscolo-minuscolo](#caratteri-ascii-e-conversioni-maiuscolo-minuscolo)
   4. [Pre-incremento e post-incremento](#pre-incremento-e-post-incremento)
   5. [Operatori di assegnamento composto](#operatori-di-assegnamento-composto)
   6. [Conversione dei secondi in orario](#conversione-dei-secondi-in-orario)
3. [Problemi presenti nei sorgenti](#problemi-presenti-nei-sorgenti)
4. [Compilazione ed esecuzione](#compilazione-ed-esecuzione)

## Mappa dei file

| File | Argomento | Stato |
|---|---|---|
| [`lezione.cc`](lezione.cc) | Variabili `bool`, confronti e conversioni | Compilabile |
| [`esempio.cc`](esempio.cc) | Divisione intera e divisione con valori decimali | Compilabile |
| [`esercizio.cc`](esercizio.cc) | Conversione tra lettere maiuscole e minuscole | Da correggere |
| [`esercizioSecDaMezzanotte.cc`](esercizioSecDaMezzanotte.cc) | Conversione di secondi da mezzanotte in ore, minuti e secondi | Compilabile |
| [`operatori.cc`](operatori.cc) | Pre/post incremento e assegnamento composto | Da correggere |

## Concetti principali

### Valori booleani

Il file [`lezione.cc`](lezione.cc) mostra il tipo `bool`, che può assumere soltanto due valori:

- `false`, rappresentato normalmente dal valore intero `0`;
- `true`, rappresentato normalmente dal valore intero `1`.

```cpp
bool y, z;
y = (1 == 0); // false
z = (7 > 3);  // true

cout << (int)y << endl; // 0
cout << (int)z << endl; // 1
```

Le espressioni `1 == 0` e `7 > 3` sono confronti. Il risultato di un confronto è sempre booleano.

#### Output dell'esempio

```text
(int)y= 0  (bool)y=0
(int)z= 1  (bool)z=1
```

La conversione esplicita `(int)y` rende evidente il valore numerico del booleano. La conversione `(bool)y` mantiene invece il valore booleano, che `cout` stampa normalmente come `0` oppure `1` se non è stato attivato `boolalpha`.

### Divisione intera e divisione reale

Il file [`esempio.cc`](esempio.cc) evidenzia che il tipo dell'operazione dipende dagli operandi, non soltanto dal tipo della variabile che riceve il risultato.

```cpp
int intera = 7 / 3;       // 2
float decimale = 7 / 3;   // 2, non 2.333...
float decimale2 = 7.5 / 3; // 2.5
int intera2 = 7.5 / 3;     // 2, con troncamento della parte decimale
```

`7 / 3` è una divisione tra due interi, quindi produce `2`. Assegnare successivamente quel valore a un `float` non recupera la parte decimale già persa.

Per ottenere una divisione reale è sufficiente che almeno uno degli operandi sia reale:

```cpp
float risultato = 7.0 / 3;
// risultato vale circa 2.33333
```

Quando un valore reale viene assegnato a un intero, la parte frazionaria viene eliminata:

```cpp
int valore = 7.5 / 3;
// 7.5 / 3 vale 2.5, ma valore diventa 2
```

#### Output dell'esempio

```text
Div intera 7/3 = 2
Div float 7/3 = 2
Div float 2 7.5/3 = 2.5
Div intera 7.5/3 = 2
```

### Caratteri, ASCII e conversioni maiuscolo-minuscolo

Il file [`esercizio.cc`](esercizio.cc) usa il fatto che un `char` può essere interpretato anche come un valore numerico. Nella codifica ASCII:

```text
'A' = 65
'a' = 97
'a' - 'A' = 32
```

Per questo motivo, la conversione di una lettera minuscola in maiuscola può essere scritta così:

```cpp
char carattere;
cin >> carattere;
carattere -= ('a' - 'A');
cout << carattere << endl;
```

La conversione opposta aggiunge la stessa differenza:

```cpp
char carattere;
cin >> carattere;
carattere += ('a' - 'A');
cout << carattere << endl;
```

#### Esempio di esecuzione

```text
Inserisci un carattere minuscolo per vederlo in maiuscolo m
Carattere in maiuscolo = M

Inserisci un carattere maiuscolo per vedere in minuscolo Q
Carattere in minuscolo = q
97
65
A
32
```

Le stampe numeriche finali sono prove di debugging: `int('a')` mostra il codice numerico del carattere, mentre `char(65)` converte il numero 65 nel carattere `A`.

#### Controllo dell'intervallo valido

La conversione tramite `+32` o `-32` è corretta soltanto per lettere dell'alfabeto. Un programma più robusto controlla prima l'intervallo:

```cpp
char input;
cin >> input;

if (input >= 'A' && input <= 'Z') {
    cout << char(input + ('a' - 'A')) << endl;
} else if (input >= 'a' && input <= 'z') {
    cout << char(input - ('a' - 'A')) << endl;
} else {
    cout << '?' << endl;
}
```

### Pre-incremento e post-incremento

Il file [`operatori.cc`](operatori.cc) introduce due forme di incremento:

```cpp
int valore = 6;
int prima = ++valore; // incrementa prima: prima vale 7
int dopo = valore++;  // usa prima il valore: dopo vale 7, poi valore diventa 8
```

- `++valore` è il pre-incremento: modifica la variabile e poi restituisce il nuovo valore;
- `valore++` è il post-incremento: restituisce il valore corrente e poi incrementa la variabile.

Nel codice della lezione:

```cpp
int val1 = 6, val2 = 6;
int i1 = ++val1; // i1 = 7, val1 = 7
int i2 = val2++; // i2 = 6, val2 = 7
int j1 = ++val1; // j1 = 8, val1 = 8
int j2 = val2++; // j2 = 7, val2 = 8
```

Le variabili `i2` e `j2` vengono calcolate ma nel sorgente originale non vengono stampate.

#### Output delle variabili stampate

```text
Val1 = 8
Val2 = 8
i1 = 7
j1 = 8
```

### Operatori di assegnamento composto

Gli operatori composti eseguono un'operazione e assegnano il risultato alla stessa variabile:

```cpp
x += y; // x = x + y
x -= y; // x = x - y
x *= y; // x = x * y
x /= y; // x = x / y
x %= y; // x = x % y
```

Esempio completo, con una sola operazione per volta:

```cpp
int x = 10;
int y = 3;

x += y; // 13
x -= y; // 10
x *= y; // 30
x /= y; // 10, divisione intera
x %= y; // 1
```

Il valore restituito dall'espressione è anche il nuovo valore della variabile:

```cpp
int x = 1;
int y = 2;
int risultato = (x += y);
// x vale 3 e risultato vale 3
```

### Conversione dei secondi in orario

Il file [`esercizioSecDaMezzanotte.cc`](esercizioSecDaMezzanotte.cc) converte il numero di secondi trascorsi dalla mezzanotte in ore, minuti e secondi.

```cpp
int ore = secIn / (60 * 60);
int minuti = (secIn / 60) % 60;
int secondi = secIn % 60;
```

Le operazioni usano la divisione intera e il resto (`%`):

- le ore sono i gruppi completi di `3600` secondi;
- i minuti sono i gruppi completi di 60 secondi rimasti nell'ora corrente;
- i secondi sono il resto della divisione per 60.

#### Esempio di esecuzione

Con `3661` secondi da mezzanotte:

```text
Inserisci i secondi da mezzanotte 3661
Orario: 1:1:1
```

La formula produce `1` ora, `1` minuto e `1` secondo. Per visualizzare sempre due cifre, ad esempio `01:01:01`, si può usare `iomanip`:

```cpp
#include <iomanip>

cout << setfill('0') << setw(2)
     << ore << ":" << setw(2)
     << minuti << ":" << setw(2)
     << secondi << endl;
```

## Problemi presenti nei sorgenti

### [`esercizio.cc`](esercizio.cc)

Il sorgente non compila perché usa `valido` senza dichiararla:

```cpp
valido = (din >= 'A' && dout <= 'Z') || (din >= 'a' && din <= 'z');
```

Inoltre, il controllo usa `dout <= 'Z'` nella prima parte, mentre dovrebbe controllare il carattere di ingresso. Una dichiarazione minima sarebbe:

```cpp
bool valido;
```

La logica più leggibile resta comunque quella mostrata nella sezione [Controllo dell'intervallo valido](#controllo-dellintervallo-valido), basata su `if` e sugli intervalli ASCII.

### [`operatori.cc`](operatori.cc)

Il sorgente dichiara cinque volte la stessa variabile nello stesso blocco:

```cpp
int risultato = x += y;
int risultato = x -= y;
int risultato = x *= y;
int risultato = x /= y;
int risultato = x %= y;
```

In C++ una variabile può essere dichiarata una sola volta nello stesso scope. Per provare le cinque operazioni si può dichiarare `risultato` una volta sola e poi riassegnarlo:

```cpp
int risultato = (x += y);
risultato = (x -= y);
risultato = (x *= y);
risultato = (x /= y);
risultato = (x %= y);
```

## Compilazione ed esecuzione

Dalla cartella `24-09-26`:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic lezione.cc -o lezione
./lezione
```

Per un altro file, sostituire il nome del sorgente e dell'eseguibile:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic esempio.cc -o esempio
./esempio
```

Le opzioni `-Wall -Wextra -pedantic` attivano avvisi utili durante lo studio. Con il codice originale, la compilazione di `esercizio.cc` e `operatori.cc` segnala i problemi descritti nella sezione precedente.
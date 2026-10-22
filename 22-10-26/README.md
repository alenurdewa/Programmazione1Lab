# Lezione del 22/10/2026

Questa cartella contiene esercizi di C++ su funzioni ricorsive, conversione binaria, fattoriale, divisione e operazioni sulle cifre.

## Indice

1. [Stato degli esercizi](#stato-degli-esercizi)
2. [Mappa dei file](#mappa-dei-file)
3. [Concetti e programmi](#concetti-e-programmi)
   1. [Divisione ricorsiva](#divisione-ricorsiva)
   2. [Conteggio di una cifra](#conteggio-di-una-cifra)
   3. [Fattoriale](#fattoriale)
   4. [Somma dei numeri pari fino a n](#somma-dei-numeri-pari-fino-a-n)
   5. [Somma delle cifre](#somma-delle-cifre)
   6. [Stampa binaria](#stampa-binaria)
4. [Esercizi da completare o correggere](#esercizi-da-completare-o-correggere)
5. [Compilazione](#compilazione)

## Stato degli esercizi

I sei sorgenti compilano, ma alcuni richiedono correzioni per soddisfare pienamente l'obiettivo o gestire gli input limite.

- [x] `ricorsione.cc`: fattoriale, corretto per interi non negativi nei limiti del tipo `int`.
- [x] `sommaDeiPrimiNPari.cc`: somma dei numeri pari positivi fino a `n`; da proteggere per input negativi.
- [x] `sommaDelleCifre.cc`: somma delle cifre per input non negativi.
- [x] `stampaBin.cc`: stampa in binario per interi positivi; non gestisce zero o numeri negativi.
- [ ] `div.cc`: correggere il calcolo del resto e gestire il divisore zero e i segni.
- [ ] `fib.cc`: il programma conta quante volte una cifra compare in `n`; il nome suggerisce Fibonacci, ma il sorgente non calcola la successione. Chiarire l'obiettivo e rinominare oppure implementare Fibonacci.

## Mappa dei file

| File | Comportamento attuale | Stato |
|---|---|---|
| [div.cc](div.cc) | Calcola quoziente e resto ricorsivamente senza `/` | Da correggere: resto errato e casi limite non gestiti |
| [fib.cc](fib.cc) | Conta le occorrenze della cifra richiesta in un intero | Funziona sui casi positivi ordinari; nome non coerente |
| [ricorsione.cc](ricorsione.cc) | Calcola il fattoriale ricorsivo | Svolto |
| [sommaDeiPrimiNPari.cc](sommaDeiPrimiNPari.cc) | Somma i numeri pari positivi minori o uguali a `n` | Svolto per `n >= 0` |
| [sommaDelleCifre.cc](sommaDelleCifre.cc) | Somma le cifre decimali ricorsivamente | Svolto per `n >= 0` |
| [stampaBin.cc](stampaBin.cc) | Stampa la rappresentazione binaria ricorsivamente | Svolto per `n > 0` |

## Concetti e programmi

### Divisione ricorsiva

[div.cc](div.cc) prova a calcolare quoziente e resto senza usare l'operatore `/`. La funzione ricorsiva somma ripetutamente il divisore finché il valore accumulato supera il dividendo. Il parametro `divisoreStart` conserva il divisore originale.

```cpp
int divisione(int dividendo, int divisore, int &resto){
    return divisioneReal(dividendo, divisore, resto, divisore);
}
```

Il quoziente viene restituito normalmente; il resto dovrebbe essere scritto nel parametro per riferimento.

#### Esempio verificato

Input:

```text
10
3
```

Output attuale:

```text
Inserire dividendo Inserire divisore Quoziente = 3. Resto = 2
```

Il quoziente è giusto, ma il resto è sbagliato: $10 = 3 \cdot 3 + 1$, quindi dovrebbe essere `1`. Nel caso non divisibile il codice assegna `divisore - dividendo` al resto al termine della ricorsione, invece di calcolare il residuo corretto. Se la divisione è esatta, la funzione non assegna `resto`.

### Conteggio di una cifra

[fib.cc](fib.cc) definisce `conta(n, cifra)`: confronta l'ultima cifra con quella cercata e poi richiama la funzione sul numero senza l'ultima cifra.

```cpp
int conta(int n, int cifra) {
    int risultato = 0;
    if (n % 10 == cifra) {
        risultato = 1;
    }
    if (n == 0)
        return risultato;
    else
        risultato += conta(n / 10, cifra);
    return risultato;
}
```

#### Esempio verificato

Input:

```text
120303 3
```

Output:

```text
Nel numero n 120303 la cifra 3 appare 2 volte
```

Nota: il file si chiama `fib.cc`, ma non contiene un algoritmo di Fibonacci. Inoltre, per numeri positivi che terminano con uno o più zeri, lo zero finale ricorsivo può essere contato una volta in più; per esempio, il conteggio di `0` in `1000` risulta errato. Occorre trattare il caso base prima del controllo della cifra oppure usare una struttura che non elabori due volte lo zero terminale.

### Fattoriale

[ricorsione.cc](ricorsione.cc) calcola $n!$ ricorsivamente, con i casi base $0! = 1$ e $1! = 1$.

```cpp
int fatt(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    return n * fatt(n - 1);
}
```

#### Esempio verificato

Input:

```text
5
```

Output:

```text
Inserisci n Fatt = 120
```

L'input deve essere non negativo. Per `n < 0` la ricorsione non raggiunge il caso base. Inoltre, i fattoriali crescono rapidamente e superano presto il limite di `int`.

### Somma dei numeri pari fino a n

[sommaDeiPrimiNPari.cc](sommaDeiPrimiNPari.cc) somma i numeri pari positivi minori o uguali a `n`. Se `n` è dispari, lo decrementa per iniziare dal pari precedente.

```cpp
if (n % 2 == 1) {
    n--;
}
if (n == 0) {
    return 0;
}
return n + stampaPrimiNPari(n - 2);
```

#### Esempio verificato

Input:

```text
10
```

Output:

```text
Inserire n 30
```

Il calcolo è $10 + 8 + 6 + 4 + 2 = 30$. Il nome della funzione può trarre in inganno: il programma somma i pari fino a `n`, non i primi `n` numeri pari. Input negativi non terminano correttamente la ricorsione e vanno rifiutati o gestiti.

### Somma delle cifre

[sommaDelleCifre.cc](sommaDelleCifre.cc) somma l'ultima cifra con il risultato della chiamata ricorsiva sul numero privato dell'ultima cifra.

```cpp
int sommaRicorsiva(int n) {
    if (n == 0) {
        return 0;
    }
    return n % 10 + sommaRicorsiva(n / 10);
}
```

#### Esempio verificato

Input:

```text
12345
```

Output:

```text
Inserire n Somma delle cifre = 15
```

L'implementazione è adatta a numeri non negativi. Per gli input negativi, `% 10` produce cifre negative; per sommare le cifre del valore assoluto serve gestire il segno.

### Stampa binaria

[stampaBin.cc](stampaBin.cc) stampa prima ricorsivamente le cifre più significative, poi stampa il resto della divisione per 2. Questo ordine produce la rappresentazione binaria da sinistra verso destra.

```cpp
void stampaBin(int n) {
    if (n == 1) {
        cout << "1";
    } else if (n % 2 == 0) {
        stampaBin(n / 2);
        cout << "0";
    } else {
        stampaBin(n / 2);
        cout << "1";
    }
}
```

#### Esempio verificato

Input:

```text
13
```

Output:

```text
Inserire un num intero positivo 1101
```

La funzione funziona per interi strettamente positivi. Per `n == 0` richiama sé stessa all'infinito perché il caso base è soltanto `n == 1`; gli input negativi non sono supportati.

## Esercizi da completare o correggere

1. **Correggere `div.cc`**: impostare sempre `resto` anche quando la divisione è esatta e calcolarlo correttamente nei casi non esatti. Rifiutare `divisore == 0`; definire anche come comportarsi con dividendi o divisori negativi.
2. **Chiarire `fib.cc`**: se l'obiettivo è contare una cifra, rinominare il file e correggere il caso dei numeri che terminano con zero. Se invece l'obiettivo è Fibonacci, implementare la successione e spostare il conteggio delle cifre in un esercizio distinto.
3. **Proteggere gli input ricorsivi**: `ricorsione.cc` deve rifiutare `n < 0`; `sommaDeiPrimiNPari.cc` deve definire un caso base anche per input negativi; `stampaBin.cc` deve aggiungere il caso base `n == 0` e gestire o rifiutare i negativi.
4. **Validare la cifra in `fib.cc`**: per il conteggio decimale, accettare solo una cifra da `0` a `9`.

## Compilazione

Compilare un file alla volta, perché ogni sorgente contiene il proprio `main`:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic stampaBin.cc -o stampaBin
./stampaBin
```

Tutti i sorgenti compilano con `g++ -std=c++17 -Wall -Wextra -pedantic`; la compilazione non rileva però errori di logica come il resto errato in `div.cc` o i casi base mancanti per alcuni input.

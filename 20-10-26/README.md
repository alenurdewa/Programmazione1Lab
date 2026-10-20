# Lezione del 20/10/2026

Questa cartella raccoglie tre esercizi in C++ dedicati a:

- funzioni con parametri per valore, riferimento e puntatore;
- divisione senza usare l'operatore `/`;
- calcolo della più piccola potenza di un numero maggiore di un valore dato.

## Indice

1. [Mappa dei file](#mappa-dei-file)
2. [Esercizio 1: prelievo allo sportello](#esercizio-1-prelievo-allo-sportello)
3. [Esercizio 2: divisione intera tramite funzione](#esercizio-2-divisione-intera-tramite-funzione)
4. [Esercizio 3: maggiorante](#esercizio-3-maggiorante)
5. [Note di logica e casi limite](#note-di-logica-e-casi-limite)
6. [Compilazione](#compilazione)

## Mappa dei file

| File | Argomento | Stato |
|---|---|---|
| [alloSportello.cc](alloSportello.cc) | Prelievo con commissione e saldo | Completato |
| [divisione.cc](divisione.cc) | Quoziente e resto senza `/` | Completato |
| [maggiorante.cc](maggiorante.cc) | Più piccola potenza di `b` maggiore di `n` | Completato |

## Esercizio 1: prelievo allo sportello

Il file [alloSportello.cc](alloSportello.cc) implementa una funzione `prelievo` che riceve:

- l'importo da prelevare per valore;
- il saldo del conto per riferimento;
- il totale delle commissioni tramite puntatore.

Il requisito importante è che la commissione sia pari al 2% dell'importo, con un minimo di 1 euro.

```cpp
int prelievo(double importoDaPrel, double &saldo, double *totCommissioni){
    int operazioneCompletata = 0;
    double commissione = importoDaPrel * 2 / 100;

    if (commissione < 1){
        commissione = 1.0;
    }

    if (importoDaPrel > 0){
        if (saldo - (commissione + importoDaPrel) >= 0){
            saldo -= (commissione + importoDaPrel);
            *totCommissioni += commissione; 
            operazioneCompletata = 1;
        }
    }

    return operazioneCompletata;
}
```

La funzione:

- rifiuta importi nulli o negativi;
- controlla la disponibilità del saldo;
- applica la commissione;
- aggiorna saldo e commissioni solo se l'operazione è valida.

### Esempio di esecuzione

Input:

```text
1000
200
n
```

Output reale:

```text
Inserire saldo iniziale: Inserire l'importo da prelevare: Operazione riuscita!
Saldo aggiornato: 796
Totale commissioni accumulate: 4
```

Qui il saldo iniziale è 1000, il prelievo è 200, la commissione è 4, quindi il saldo finale è:

$$
1000 - (200 + 4) = 796
$$

Il programma continua a chiedere prelievi finché l'utente risponde `s` o `S`.

## Esercizio 2: divisione intera tramite funzione

Il file [divisione.cc](divisione.cc) mostra come calcolare quoziente e resto senza usare l'operatore `/`.

```cpp
int divisione(int dividendo, int divisore, int &resto){
    bool condizione = false;
    int quoziente = 0;

    if (divisore == 0){
        cout << "Divisione per 0\n";
    }

    while(!condizione){
        if(divisore*quoziente > dividendo){
            condizione = true;
        }else{
            quoziente += 1;
        }
    }
    quoziente -= 1;
    resto = dividendo - divisore * quoziente;

    return quoziente;
}
```

L'idea è semplice:

- si parte da `quoziente = 0`;
- si aggiunge 1 finché il prodotto `divisore * quoziente` non supera il dividendo;
- si annulla l'ultimo incremento e si calcola il resto con:

```cpp
resto = dividendo - divisore * quoziente;
```

### Esempio di esecuzione

Input:

```text
10
3
```

Output reale:

```text
Inserire dividendo Inserire divisore Quoziente = 3
Resto = 1
```

Questo corrisponde a:

$$
10 = 3 \cdot 3 + 1
$$

### Nota importante

Il programma controlla `divisore == 0`, ma non esce subito. Nel caso di divisione per zero, il comportamento è comunque solo un messaggio di warning: la funzione prosegue e può produrre risultati incoerenti. In un programma più robusto, bisognerebbe tornare subito.

## Esercizio 3: maggiorante

Il file [maggiorante.cc](maggiorante.cc) risolve il problema della più piccola potenza di `b` maggiore di `n`.

Il testo dell'esercizio richiede:

- `n` e `b` devono essere interi positivi;
- `b > 1`;
- la funzione deve restituire:
  - `-1` se i dati non sono validi;
  - `0` se l'operazione è valida;
- medianti parametri di uscita `e` ed `m`, calcolare l'esponente e il valore della minima potenza di `b` che supera `n`.

```cpp
int funzione(int n, int b, int &e, int &m ){
    int operazioneValida = 0;

    if (n <= 0 || b <= 1){
        operazioneValida = -1;
    }else{
        bool valoreTrovato = false;
        while (!valoreTrovato){
            if (m > n){
                valoreTrovato = true;
            }else{
                m *= b;
                e += 1;
            }
        }
    }

    return operazioneValida;
}
```

### Esempio di esecuzione

Input:

```text
8
2
```

Output reale:

```text
Inserire n Inserire b 2^4 = 16 > 8
```

La potenza minima maggiore di 8 è:

$$
2^4 = 16
$$

Perciò `e = 4` e `m = 16`.

## Note di logica e casi limite

### 1. Uso dei riferimenti e dei puntatori

Questa lezione è importante perché mostra come passa il valore e come si modifica lo stato esterno:

- `&saldo`: modifica il valore della variabile esterna;
- `*totCommissioni`: modifica la variabile puntata;
- `return`: restituisce un risultato intero di controllo.

### 2. Input del programma di sportello

Il programma [alloSportello.cc](alloSportello.cc) lavora in loop, chiedendo all'utente di effettuare più prelievi. Ogni operazione si basa sul saldo corrente aggiornato. Per questo motivo è importante tenere traccia del saldo e delle commissioni accumulate in ogni ciclo.

### 3. Divisione senza `/`

Il metodo usato in [divisione.cc](divisione.cc) è pedagogico: dimostra come si può costruire il quoziente tramite incremento e confronto. Non è il metodo più efficiente, ma è perfetto per capire il concetto di divisione come conteggio di quante volte il divisore contiene il dividendo.

### 4. Potenze e controllo valido

In [maggiorante.cc](maggiorante.cc), la variabile `m` parte da 1 e viene moltiplicata per `b` finché non supera `n`. La formalizzazione corretta è:

$$
m = b^e
$$

con `e` il più piccolo esponente tale che:

$$
b^e > n
$$

## Compilazione

Per compilare i file della cartella:

```bash
cd 20-10-26

g++ -std=c++17 -Wall -Wextra -pedantic alloSportello.cc -o alloSportello
g++ -std=c++17 -Wall -Wextra -pedantic divisione.cc -o divisione
g++ -std=c++17 -Wall -Wextra -pedantic maggiorante.cc -o maggiorante
```

Esempio di esecuzione:

```bash
./alloSportello
./divisione
./maggiorante
```

Tutti e tre i sorgenti sono compilabili e mostrano i comportamenti descritti in questa guida.

# Lezione del 27/10/2026

Questa cartella contiene esercizi su funzioni ricorsive, ricorsione in coda, massimo comune divisore ed algoritmi numerici su cifre e potenze.

## Indice

1. [Mappa dei file](#mappa-dei-file)
2. [Concetti principali](#concetti-principali)
   1. [MCD ricorsivo e iterativo](#mcd-ricorsivo-e-iterativo)
   2. [Potenza ricorsiva classica](#potenza-ricorsiva-classica)
   3. [Potenza tail-recursive](#potenza-tail-recursive)
   4. [Funzione di test numerico](#funzione-di-test-numerico)
3. [Esercizi da completare o correggere](#esercizi-da-completare-o-correggere)
4. [Compilazione](#compilazione)

## Mappa dei file

| File | Tema | Stato |
|---|---|---|
| [massimoComDiv.cc](massimoComDiv.cc) | MCD ricorsivo e iterativo | Completato |
| [potenzaRicorsiva1.cc](potenzaRicorsiva1.cc) | Potenza con ricorsione classica | Completato |
| [potenzaTailRecursive.cc](potenzaTailRecursive.cc) | Potenza tail-recursive | Completato |
| [test.cc](test.cc) | Esercizio numerico sul valore delle cifre elevate per posizione | Completato, ma da interpretare come esercizio specifico |

## Concetti principali

### MCD ricorsivo e iterativo

Il file [massimoComDiv.cc](massimoComDiv.cc) implementa due versioni del massimo comune divisore:

- una ricorsiva;
- una iterativa.

```cpp
int mcd(int a, int b){
    int div = 0;
    int resto = 0;
    if (b == 0){
        return a;
    }else{
        div = a/b;
        resto = a%b;
    }

    return mcd(b, resto);
}
```

La ricorsione usa l'identità:

$$
MCD(a, b) = MCD(b, a \bmod b)
$$

La versione iterativa usa la stessa idea in un ciclo:

```cpp
int mcdIterativo(int a, int b){
    int resto = 0;

    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}
```

#### Esempio verificato

Input:

```text
48
18
```

Output reale:

```text
Inserire a Inserire b MCD = 6
MCD iterativo = 6
```

### Potenza ricorsiva classica

Il file [potenzaRicorsiva1.cc](potenzaRicorsiva1.cc) calcola la potenza usando una chiamata ricorsiva con decremento dell'esponente.

```cpp
int potenza(int m, int n){
    int risultato = m;
    if (n == 1) {
        return m;
    } else if (n == 0) {
        return 1;
    } else {
        risultato *= potenza(m, n - 1);
    }
    return risultato;
}
```

La logica è:

- $m^0 = 1$
- $m^1 = m$
- $m^n = m \cdot m^{n-1}$

#### Esempio verificato

Input:

```text
2
5
```

Output reale:

```text
Inserire m Inserire n 2^5=32
```

### Potenza tail-recursive

Il file [potenzaTailRecursive.cc](potenzaTailRecursive.cc) usa una versione tail recursive. L'accumulatore `acc` tiene il risultato parziale e viene aggiornato ad ogni chiamata.

```cpp
int potenzaTailRecursive(int m, int n, int acc = 1) {
    if (n == 0) {
        return acc;
    }
    return potenzaTailRecursive(m, n - 1, acc * m);
}
```

Questa forma è interessante perché il risultato viene costruito progressivamente, senza dover tornare indietro con calcoli da completare. In pratica:

- inizialmente `acc = 1`
- ogni passo moltiplica `acc` per `m`
- quando `n` raggiunge 0, viene restituito il valore completo

#### Esempio verificato

Input:

```text
2
5
```

Output reale:

```text
Inserire m: Inserire n: 2^5 = 32
```

### Funzione di test numerico

Il file [test.cc](test.cc) implementa una funzione `magic(int n, int pos)`, che calcola una somma di potenze delle cifre del numero in base `10`.

```cpp
long magic(int n, int pos) {
    long somma = 0;
    int contatore = pos;

    while (n > 0) {
        int cifra = n % 10;
        long potenza = 1;

        for (int i = 0; i < contatore; ++i) {
            potenza *= cifra;
        }

        somma += potenza;
        n /= 10;
        contatore++;
    }

    return somma;
}
```

La logica è: per ogni cifra, elevare la cifra alla posizione giusta e sommare i risultati.

#### Esempio verificato

Input:

```text
123
1
```

Output reale:

```text
Inserire n e pos: Risultato: 8
```

Per `123` con posizione iniziale `1`:

- cifra `3` elevata a `1` => $3^1 = 3$
- cifra `2` elevata a `2` => $2^2 = 4$
- cifra `1` elevata a `3` => $1^3 = 1$

Totale:

$$
3 + 4 + 1 = 8
$$

## Esercizi da completare o correggere

- [ ] `massimoComDiv.cc`: gestire correttamente input negativi e zero, in modo da evitare comportamenti non definiti o risultati non attesi.
- [ ] `potenzaRicorsiva1.cc`: aggiungere una verifica su `n < 0` e definire un comportamento esplicito per casi non validi.
- [ ] `potenzaTailRecursive.cc`: gestire anche input negativi e decidere se si desidera consentire che l'esponente sia zero o negativo.
- [ ] `test.cc`: chiarire il nome dell'esercizio e documentare esattamente la formula matematica implementata, perché il nome `magic` non è autodocumentante.

## Compilazione

Per compilare un singolo file:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic potenzaTailRecursive.cc -o potenzaTailRecursive
./potenzaTailRecursive
```

Per compilare tutti i sorgenti della cartella:

```bash
for file in *.cc; do
    g++ -std=c++17 -Wall -Wextra -pedantic "$file" -o "${file%.cc}"
done
```

Tutti i file della cartella compilano correttamente con `g++` e i risultati mostri nel README sono quelli verificati nel terminale.

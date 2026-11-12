# Riassunto della lezione di C++ - 12/11/2026

Questa lezione introduce concetti molto pratici: passare parametri da riga di comando, leggere e scrivere file, lavorare con stringhe e usare gli array di caratteri. La parte centrale è la gestione di file e testo in C++, insieme a piccoli esercizi di elaborazione delle stringhe.

## Indice

1. [Argomenti da riga di comando](#1-argomenti-da-riga-di-comando)
2. [Lettura di un file](#2-lettura-di-un-file)
3. [Copia da un file a un altro](#3-copia-da-un-file-a-un-altro)
4. [Parole in comune tra due file](#4-parole-in-comune-tra-due-file)
5. [Sostituzione di una lettera in un file](#5-sostituzione-di-una-lettera-in-un-file)
6. [Stringhe e punteggio tra lettere consecutive](#6-stringhe-e-punteggio-tra-lettere-consecutive)
7. [Calcolatrice semplice](#7-calcolatrice-semplice)
8. [Riepilogo dei file](#8-riepilogo-dei-file)

## 1. Argomenti da riga di comando

Un programma C++ può ricevere informazioni quando viene eseguito da terminale. La funzione `main` riceve due parametri:

```cpp
int main(int argc, char * argv[])
```

- `argc`: numero di argomenti
- `argv`: array di stringhe, cioè gli argomenti passati

Esempio:

```cpp
int main(int argc, char * argv[]) {
    if (argc != 3) {
        cout << "Utilizzo: ./a.out <fileA> <fileB>\n";
        return 1;
    }
}
```

Se esegui:

```bash
./a.out file1.txt file2.txt
```

allora `argv[1]` contiene `file1.txt` e `argv[2]` contiene `file2.txt`.

### Output tipico

```text
Utilizzo: ./a.out <fileA> <fileB>
```

Questo output appare se l'utente non passa il numero corretto di argomenti.

## 2. Lettura di un file

Il file `es2.cc` apre un file in lettura e stampa man mano i caratteri a schermo.

```cpp
fstream input;
input.open(nomeFile, ios::in);

char c;
while (input.get(c)) {
    cout << c;
}
```

### Come funziona

- `fstream` serve per aprire file
- `ios::in` indica lettura
- `input.get(c)` legge un carattere alla volta
- il ciclo continua finché ci sono dati da leggere

### Esempio

Se il file `testo.txt` contiene:

```text
Ciao
```

il programma stampa:

```text
Ciao
```

Se il file contiene più righe, ne stampa tutte senza perdere niente.

## 3. Copia da un file a un altro

Il file `es3.cc` apre un file di input e uno di output, poi copia tutto il contenuto del primo nel secondo.

```cpp
fstream input;
fstream output;

input.open(fileIn, ios::in);
output.open(fileOut, ios::out);

char c;
while (input.get(c)) {
    output.put(c);
}
```

### Cosa fa

- legge carattere per carattere dal file `fileIn`
- lo scrive nel file `fileOut`
- permette di creare una copia identica

### Esempio di input

`input.txt`:

```text
Hello
World
```

Comando:

```bash
./a.out input.txt output.txt
```

`output.txt` diventa:

```text
Hello
World
```

### Output sul terminale

```text
File aperti con successo!
Copia eseguita con successo!
```

## 4. Parole in comune tra due file

Il file `esInterParole.cc` legge le parole contenute in due file, confronta le parole e salva nel file `FileC` quelle presenti in entrambi.

```cpp
char paroleA[1000][101];
char paroleB[1000][101];

while (nParoleA < 1000 && inFileA >> paroleA[nParoleA]) {
    nParoleA++;
}

while (nParoleB < 1000 && inFileB >> paroleB[nParoleB]) {
    nParoleB++;
}

for (int i = 0; i < nParoleA; i++) {
    for (int j = 0; j < nParoleB; j++) {
        if (strcmp(paroleA[i], paroleB[j]) == 0) {
            outFileC << paroleA[i] << endl;
        }
    }
}
```

### Spiegazione

- `paroleA` e `paroleB` sono array di stringhe
- `inFileA >> paroleA[nParoleA]` legge la prossima parola dal file
- `strcmp` confronta due stringhe
- se sono uguali, la parola viene scritta nel file di output

### Esempio

File A:

```text
cane gatto topo cane
```

File B:

```text
gatto cane cane
```

Output in `FileC`:

```text
cane
gatto
```

Se una parola compare più volte, può essere ripetuta anche nel file di output, perché il programma non la deduplica.

## 5. Sostituzione di una lettera in un file

Il programma `esSostLettera.cc` legge un file e, per ogni carattere, se coincide con la lettera scelta, stampa `?` al posto del carattere.

```cpp
while (input.get(c)) {
    if (c == l) {
        cout << '?';
    } else {
        cout << c;
    }
}
```

### Esempio

File di input:

```text
banana
```

Se l'utente inserisce:

```text
a
```

l'output sarà:

```text
b?n?n?
```

In pratica ogni `a` viene sostituito con `?`.

## 6. Stringhe e punteggio tra lettere consecutive

Il file `esPunteggio.cc` prende una stringa, verifica che sia composta solo da lettere e poi calcola la somma delle differenze in valore assoluto tra lettere consecutive.

```cpp
int calcolaSommaDifAbs(char str[]) {
    int somma = 0;
    if (!contieneSoloLettereToLower(str)) {
        return -1;
    }

    int i = 0;
    while (str[i] != '\0') {
        if (str[i + 1] != '\0') {
            somma += abs(str[i] - str[i + 1]);
        }
        i++;
    }
    return somma;
}
```

### Come funziona

- `contieneSoloLettereToLower` controlla che tutti i caratteri siano lettere
- se ci sono lettere maiuscole, vengono trasformate in minuscole
- `abs(str[i] - str[i+1])` è la differenza in valore assoluto tra due caratteri consecutivi
- la somma di queste differenze è il risultato finale

### Esempio

Input:

```text
abc
```

Calcolo:

- `a` e `b` differiscono di `1`
- `b` e `c` differiscono di `1`
- totale = `2`

Output:

```text
Somma = 2
```

### Caso di errore

Se si inserisce:

```text
ab1
```

il programma stampa:

```text
La stringa non contiene solo caratteri!
Stringa non valida
```

## 7. Calcolatrice semplice

Il file `escalc.cc` usa argomenti della riga di comando per fare operazioni aritmetiche.

```cpp
int calcola(int a, int b, char operatore) {
    switch (operatore) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b != 0) return a / b;
            else {
                cout << "Errore: Divisione per zero!\n";
                return -1;
            }
        default:
            cout << "Operatore non valido!\n";
            return -1;
    }
}
```

### Esempio di esecuzione

Comando:

```bash
./calcolatrice 10 4 +
```

Output:

```text
Risultato = 14
```

Con divisione per zero:

```bash
./calcolatrice 10 0 /
```

Output:

```text
Errore: Divisione per zero!
Risultato = -1
```

## 8. Riepilogo dei file

- `es2.cc`: legge un file e stampa i caratteri a video
- `es3.cc`: copia il contenuto di un file in un secondo file
- `esInterParole.cc`: trova le parole in comune tra due file e le scrive in `FileC`
- `esSostLettera.cc`: sostituisce una lettera scelta con `?`
- `esPunteggio.cc`: controlla che la stringa contenga solo lettere e somma le differenze tra lettere consecutive
- `escalc.cc`: calcolatrice semplice da riga di comando

## Note importanti

- In C++, gli array di caratteri sono stringhe in stile C e vanno terminati con `\0`.
- `fstream` serve per leggere o scrivere file.
- `argc` e `argv` sono utili per far interagire il programma con l'utente senza chiedere dati con `cin`.
- Quando si confrontano stringhe, usare `strcmp` e non `==` direttamente.
- Per i file, bisogna sempre controllare se l'apertura è andata a buon fine con `fail()`.

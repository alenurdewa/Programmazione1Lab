# Riassunto della lezione di C++ - 19/11/2026

Questa lezione introduce le strutture (`struct`), i puntatori a strutture, l'allocazione dinamica della memoria e il caricamento di un database da file di testo.

## Indice

1. [Strutture](#1-strutture)
2. [Puntatori alle strutture](#2-puntatori-alle-strutture)
3. [Allocazione dinamica con `new`](#3-allocazione-dinamica-con-new)
4. [La classe `Studente` nei programmi](#4-la-classe-studente-nei-programmi)
5. [Caricamento del database da file](#5-caricamento-del-database-da-file)
6. [Ricerca per matricola](#6-ricerca-per-matricola)
7. [Ricerca per nome e cognome](#7-ricerca-per-nome-e-cognome)
8. [Liberazione della memoria](#8-liberazione-della-memoria)
9. [Riepilogo dei file](#9-riepilogo-dei-file)

## 1. Strutture

Una `struct` permette di raggruppare informazioni diverse sotto un unico nome.

```cpp
struct Studente {
    char nome[30];
    char cognome[30];
    int matricola;
    float media;
};
```

La struttura `Studente` contiene:

- `nome`: nome dello studente
- `cognome`: cognome dello studente
- `matricola`: numero intero identificativo
- `media`: voto medio

## 2. Puntatori alle strutture

Una variabile normale contiene direttamente i dati:

```cpp
Studente studente;
```

Un puntatore contiene invece l'indirizzo di memoria della struttura:

```cpp
Studente *studente;
```

Per accedere ai campi attraverso un puntatore si usa `->`:

```cpp
studente->nome
studente->matricola
```

Con una normale variabile si usa invece il punto:

```cpp
studente.nome
studente.matricola
```

## 3. Allocazione dinamica con `new`

La funzione `genera_studente` crea dinamicamente una struttura nello heap:

```cpp
Studente *genera_studente(char nome[], char cognome[],
                          int matricola, float media_ponderata) {
    Studente *stud = new Studente;

    strcpy(stud->nome, nome);
    strcpy(stud->cognome, cognome);
    stud->matricola = matricola;
    stud->media = media_ponderata;

    return stud;
}
```

L'operatore `new Studente` riserva memoria per una struttura. La funzione restituisce il puntatore alla struttura appena creata.

Quando l'oggetto non serve più, bisogna liberarlo:

```cpp
delete stud;
```

Questo è necessario per evitare perdite di memoria.

## 4. La classe `Studente` nei programmi

Nel primo esercizio, `es1.cc`, l'utente inserisce i dati dello studente da tastiera.

Input:

```text
Mario
Rossi
12345
27.5
```

Esecuzione:

```bash
./es1
```

Output:

```text
Inserire nome dello studente Mario
Inserire nome dello cognome Rossi
Inserire nome dello matricola 12345
Inserire la media 27.5

Nome: Mario
Cognome: Rossi
Matricola: 12345
Media: 27.5
```

I nomi dei prompt contengono alcuni refusi lessicali, ma i dati vengono letti nell'ordine corretto: nome, cognome, matricola e media.

## 5. Caricamento del database da file

Il file `es2.cc` legge da `studenti.txt` righe nel formato:

```text
Nome Cognome Matricola Media
```

La funzione `caricaDatabase` crea un array dinamico di puntatori:

```cpp
Studente **database = new Studente *[n_righe];
```

Questa dichiarazione crea uno spazio in memoria che può contenere `n_righe` puntatori a `Studente`.

Durante la lettura:

```cpp
while (i < n_righe &&
       (input >> nome >> cognome >> matricola >> media)) {
    database[i] = genera_studente(nome, cognome, matricola, media);
    i++;
}
```

Ogni riga viene letta, convertita in una struttura `Studente` e salvata in una posizione del database.

Esecuzione di esempio:

```bash
g++ es2.cc -o es2
./es2
```

Input:

```text
studenti.txt
30
```

Nel file ci sono trenta studenti. Per risultati affidabili, il numero inserito deve corrispondere alle righe disponibili o essere minore del numero totale delle righe.

## 6. Ricerca per matricola

La funzione `cerca_matricola` scorre l'array e confronta il campo `matricola` di ogni studente:

```cpp
if (database[i]->matricola == matricola) {
    isFound = true;
}
```

Se trova una corrispondenza restituisce l'indice. Se non trova nulla restituisce `-1`.

Nel programma viene cercata la matricola `64727`:

```cpp
int numStud = cerca_matricola(database, 64727, n_righe);
```

Il file contiene questa matricola associata ad Arianna Richards. Output atteso:

```text
Studente con matricola == 64727: Arianna Richards
```

Se la matricola non è presente:

```text
Non è stato trovato nessuno studente con matricola == 64727
```

## 7. Ricerca per nome e cognome

Per confrontare testo si usa `strcmp` invece dell'operatore `==`:

```cpp
strcmp(database[i]->nome, nome) == 0
strcmp(database[i]->cognome, cognome) == 0
```

`strcmp` restituisce `0` quando le due stringhe sono uguali.

La funzione cerca sia il nome sia il cognome:

```cpp
int cerca_nome_e_cognome(Studente **database,
                         const char *nome,
                         const char *cognome,
                         int len);
```

Nel programma viene cercato `Sofia Hamilton`. Nel file `studenti.txt`, Sofia Hamilton ha matricola `57426` e media `28.9`.

Output atteso:

```text
Profilo dello studente con nome cognome == Sofia Hamilton

Nome: Sofia
Cognome: Hamilton
Matricola: 57426
Media: 28.9
```

Se lo studente non viene trovato:

```text
Non è stato trovato nessuno studente con nome cognome == Sofia Hamilton
```

## 8. Liberazione della memoria

Nel programma vengono allocate dinamicamente molte strutture `Studente` e l'array di puntatori `database`.

La memoria va liberata in due passaggi:

```cpp
for (int i = 0; i < n_righe; i++) {
    delete database[i];
}
delete[] database;
```

Il primo ciclo elimina ogni singolo studente. Il secondo elimina l'array che contiene i puntatori.

Si deve evitare di usare:

```cpp
delete database[i];
```

in seguito a una lettura incompleta con puntatori non inizializzati. Per questo, il database dovrebbe inizializzare tutti i puntatori a `nullptr` prima della lettura e controllare che il puntatore sia valido.

## 9. Riepilogo dei file

- `es1.cc`: crea un singolo `Studente`, legge i dati da tastiera e li stampa.
- `es2.cc`: carica molti studenti da file, li salva in un array dinamico di puntatori e permette ricerche per matricola e per nome/cognome.
- `studenti.txt`: contiene trenta righe di studenti nel formato nome, cognome, matricola e media.

## Attenzioni

- `char nome[30]` può contenere al massimo 29 caratteri utili più il terminatore `\0`.
- `cin >> nome` smette di leggere alla prima spaziatura.
- `strcmp` si usa con stringhe in stile C; non va sostituito con `==` per confrontare due `char[]`.
- Con `new` si usa `delete` e con `new[]` si usa `delete[]`.
- Il numero di righe richiesto al programma deve essere compatibile con il file letto.

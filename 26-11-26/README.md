# Riassunto della lezione di C++ - 26/11/2026

Questa lezione introduce le liste concatenate dinamiche in C++. Un elenco non viene memorizzato in un array continuo: ogni nodo contiene un valore e un puntatore al nodo successivo.

## Indice

1. [Struttura di una lista concatenata](#1-struttura-di-una-lista-concatenata)
2. [Creazione della lista da file](#2-creazione-della-lista-da-file)
3. [Stampa normale della lista](#3-stampa-normale-della-lista)
4. [Stampa ricorsiva inversa](#4-stampa-ricorsiva-inversa)
5. [Rimozione dei numeri non primi](#5-rimozione-dei-numeri-non-primi)
6. [Distruzione della lista](#6-distruzione-della-lista)
7. [Funzione `numeroPrimo`](#7-funzione-numeroPrimo)
8. [Output del programma](#8-output-del-programma)
9. [Compilazione ed esecuzione](#9-compilazione-ed-esecuzione)
10. [Riepilogo dei file](#10-riepilogo-dei-file)

## 1. Struttura di una lista concatenata

Ogni elemento della lista è un nodo:

```cpp
struct nodo {
    int value;
    nodo *next;
};

typedef nodo *lista;
```

Ogni nodo contiene:

- `value`: il numero memorizzato;
- `next`: il puntatore al nodo successivo;
- `NULL` in `next` indica che non esistono altri nodi.

Per comodità `lista` è l'alias di `nodo *`. Una variabile `lista` contiene quindi l'indirizzo del primo nodo, chiamato testa.

```text
lista/t testa
     |
     v
+-------+    +-------+    +-------+
| 1     | -> | 2     | -> | 3     | -> NULL
| next  |    | next  |    | next  |
+-------+    +-------+    +-------+
```

## 2. Creazione della lista da file

La funzione `creaLista` apre il file ricevuto come argomento e legge un intero alla volta:

```cpp
lista creaLista(char *inputFile) {
    fstream input;
    lista testa = NULL;
    input.open(inputFile, ios::in);

    if (input.fail()) {
        cout << "Errore apertura file" << endl;
    } else {
        int numero;
        nodo *coda = NULL;

        while (input >> numero) {
            nodo *nuovo = new nodo{numero, NULL};

            if (testa == NULL) {
                testa = nuovo;
            } else {
                coda->next = nuovo;
            }

            coda = nuovo;
        }
    }

    return testa;
}
```

Per ogni numero:

1. viene allocato un nuovo nodo con `new`;
2. `value` riceve il numero letto;
3. `next` viene inizializzato a `NULL`;
4. se la lista è vuota, il nodo diventa la testa;
5. altrimenti viene collegato alla fine della lista tramite la coda.

Il file `numbers.txt` contiene, nell'ordine:

```text
1 2 3 6 562 45 31 6 4 51 6 7 87 365 4 6 765 43 45 73 34
```

## 3. Stampa normale della lista

La funzione `stampaLista` parte dalla testa e visita tutti i nodi seguendo `next`:

```cpp
void stampaLista(lista testa) {
    nodo *nodoSelezionato = testa;

    while (nodoSelezionato != NULL) {
        cout << nodoSelezionato->value << " ";
        nodoSelezionato = nodoSelezionato->next;
    }
}
```

Il ciclo termina quando `nodoSelezionato` vale `NULL`, cioè quando si supera l'ultimo nodo.

Per la lista creata da `numbers.txt`, l'output normale è:

```text
1 2 3 6 562 45 31 6 4 51 6 7 87 365 4 6 765 43 45 73 34
```

## 4. Stampa ricorsiva inversa

La funzione `stampaInverita` si richiama sul nodo successivo prima di stampare il valore corrente:

```cpp
void stampaInverita(lista listaDiNumeri) {
    if (listaDiNumeri != NULL) {
        stampaInverita(listaDiNumeri->next);
    }

    if (listaDiNumeri != NULL) {
        cout << listaDiNumeri->value << " ";
    }
}
```

Il comportamento è:

1. si visita il nodo successivo;
2. si arriva alla fine della lista;
3. durante il ritorno vengono stampati i valori dalla coda verso la testa.

Per `numbers.txt`, l'output inverso è:

```text
34 73 45 43 765 6 4 365 87 7 6 51 4 6 31 45 562 6 3 2 1
```

## 5. Rimozione dei numeri non primi

La funzione `primizzaLista` modifica la lista conservando soltanto i nodi che contengono numeri primi:

```cpp
nodo *nodoSelezionato = listaDiNumeri;
nodo *nodoPrecedente = NULL;

while (nodoSelezionato != NULL) {
    if (nodoPrecedente == NULL &&
        !numeroPrimo(nodoSelezionato->value)) {

        listaDiNumeri = nodoSelezionato->next;
        delete nodoSelezionato;
        nodoSelezionato = listaDiNumeri;
        nodoPrecedente = NULL;

    } else if (!numeroPrimo(nodoSelezionato->value)) {

        nodoPrecedente->next = nodoSelezionato->next;
        delete nodoSelezionato;
        nodoSelezionato = nodoPrecedente->next;

    } else {

        nodoPrecedente = nodoSelezionato;
        nodoSelezionato = nodoSelezionato->next;
    }
}
```

Sono gestiti due casi:

- il nodo non primo è in testa: viene aggiornata la testa;
- il nodo non primo è nel resto della lista: viene collegato il precedente al successivo.

Nel caso attuale, i numeri conservati da `primizzaLista` sono:

```text
1 2 3 31 7 43 73
```

In base alla definizione matematica, `1` non è primo. Nel codice attuale viene però conservato perché `numeroPrimo(1)` esegue zero iterazioni e restituisce `true`. Per ottenere l'output matematico corretto:

```text
2 3 31 7 43 73
```

bisogna modificare `numeroPrimo` affinché restituisca `false` per `n < 2`, incluso `1`.

Nota: per numeri negativi il ciclo attuale non inizia e la funzione restituisce `true`, quindi la correzione `n < 2` evita anche questo problema.

## 6. Distruzione della lista

Quando la lista non serve più, occorre liberare ogni nodo:

```cpp
void distruggiLista(lista &listaDiNumeri) {
    nodo *nodoSelezionato = listaDiNumeri;

    while (nodoSelezionato != NULL) {
        nodo *nodoSuccessivo = nodoSelezionato->next;
        delete nodoSelezionato;
        nodoSelezionato = nodoSuccessivo;
    }

    listaDiNumeri = NULL;
}
```

La sequenza è importante:

1. salvo il puntatore al nodo successivo;
2. elimino il nodo corrente con `delete`;
3. passo al nodo successivo salvato;
4. imposto la testa a `NULL` alla fine.

Eliminare i nodi senza salvare prima `next` può impedire di raggiungere il resto della lista.

## 7. Funzione `numeroPrimo`

La funzione `numeroPrimo` prova i divisori da `2` fino a `n/2`:

```cpp
bool numeroPrimo(int n) {
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
```

Per esempio:

- `7 % 2`, `7 % 3` non danno resto zero;
- viene raggiunto il termine del ciclo;
- la funzione restituisce `true`.

La funzione è dichiarata in `prime.h` e implementata in `prime.cc`:

```cpp
#ifndef PRIME_H
#define PRIME_H

bool numeroPrimo(int n);

#endif
```

## 8. Output del programma

Esecuzione con `numbers.txt`:

```bash
g++ liste.cc prime.cc -o liste
./liste numbers.txt
```

Output atteso con il codice attuale:

```text
Lista creata correttamente
Stampa lista normale: 1 2 3 6 562 45 31 6 4 51 6 7 87 365 4 6 765 43 45 73 34
Stampa lista invertita: 34 73 45 43 765 6 4 365 87 7 6 51 4 6 31 45 562 6 3 2 1
Primizza lista: 1 2 3 31 7 43 73
Lista eliminata correttamente
```

Con una correzione di `numeroPrimo` che restituisca `false` quando `n < 2`, l'ultima riga diventerebbe:

```text
Primizza lista: 2 3 31 7 43 73
```

La stampa della lista filtrata contiene anche `1` se si usa l'implementazione attuale di `numeroPrimo`, che non verifica esplicitamente `n >= 2`. Questo README mostra il risultato matematicamente atteso dai numeri primi; controllare anche l'effettivo correzione del codice prima di presentarlo come risultato finale.

Se viene chiamato senza argomenti:

```bash
./liste
```

L'output è:

```text
chiamata giusta: ./a.out <nome_file>
Stampa lista normale:
Stampa lista invertita:
Primizza lista:
Lista eliminata correttamente
```

Il valore di ritorno è `1`.

## 9. Compilazione ed esecuzione

Per compilare i due file C++ separati:

```bash
g++ liste.cc prime.cc -o liste
```

`liste.cc` contiene il programma e usa `numeroPrimo`, dichiarata in `prime.h`. `prime.cc` contiene l'implementazione della funzione.

L'eseguibile viene avviato passando il file dei numeri:

```bash
./liste numbers.txt
```

## 10. Riepilogo dei file

- `liste.cc`: crea la lista da file, la stampa in ordine normale e inverso, filtra i numeri primi e distrugge la lista.
- `prime.cc`: contiene l'implementazione della funzione `numeroPrimo`.
- `prime.h`: contiene la dichiarazione della funzione per renderla disponibile agli altri file.
- `numbers.txt`: contiene i numeri da inserire nella lista.

## Attenzioni

- Quando si usa `new`, ogni nodo deve essere rimosso con `delete`.
- Prima di accedere a `coda->next`, è necessario controllare che la lista non sia vuota.
- Quando si elimina un nodo diverso dalla testa, bisogna collegare il nodo precedente al successivo.
- Durante la stampa inversa ricorsiva, il caso base è `listaDiNumeri == NULL`.
- `numeroPrimo` dovrebbe essere corretto anche per `n < 2`; l'implementazione attuale non gestisce `1` correttamente.

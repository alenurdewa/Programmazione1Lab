# Lezione del 08/10/2026

Questa cartella raccoglie esercizi sui cicli, sulle cifre dei numeri, sulle successioni e sugli algoritmi numerici. La guida distingue gli esercizi già svolti da quelli ancora da completare.

## Indice

1. [Stato degli esercizi](#stato-degli-esercizi)
2. [Mappa dei file](#mappa-dei-file)
3. [Spiegazione dei programmi](#spiegazione-dei-programmi)
   1. [Disegno ASCII](#disegno-ascii)
   2. [Conteggio delle cifre](#conteggio-delle-cifre)
   3. [Conversione binario-decimale](#conversione-binario-decimale)
   4. [Divisione con precisione](#divisione-con-precisione)
   5. [Successione di Fibonacci](#successione-di-fibonacci)
   6. [Indovina il numero](#indovina-il-numero)
   7. [Approssimazione di pi greco](#approssimazione-di-pi-greco)
   8. [Test di primalità](#test-di-primalità)
4. [Note sui limiti attuali](#note-sui-limiti-attuali)
5. [Compilazione](#compilazione)

## Stato degli esercizi

### Da completare

- [ ] **`conversioneBinDec.cc`**: implementare la conversione di un numero binario in base 10. Il commento nel file descrive già l'obiettivo; il `main` è vuoto.
- [ ] **`indovinaIlNum.cc`**: completare il gioco. Il programma genera un numero casuale da 1 a 10 e legge tentativi, ma manca tutta la logica di confronto, feedback e terminazione.
- [ ] **`seriePi.cc`**: scrivere il programma per approssimare pi greco con la serie scelta durante la lezione. Il file contiene soltanto il commento e non ha ancora un `main` né la formula della serie.

### Svolti, da rivedere nei casi limite

- [x] `ASCIIART.cc`
- [x] `cifre.cc`
- [x] `divprec.cc`
- [x] `fibonacci.cc`
- [x] `testDiPrimalita.cc`

Il segno di spunta indica che esiste una soluzione nel sorgente, non che siano già gestiti tutti gli input limite o le condizioni di errore. Le correzioni consigliate sono descritte in [Note sui limiti attuali](#note-sui-limiti-attuali).

## Mappa dei file

| File | Obiettivo | Stato |
|---|---|---|
| [ASCIIART.cc](ASCIIART.cc) | Stampare un triangolo di asterischi | Svolto |
| [cifre.cc](cifre.cc) | Contare le cifre di un intero positivo | Svolto |
| [conversioneBinDec.cc](conversioneBinDec.cc) | Convertire un numero binario in decimale | Da completare |
| [divprec.cc](divprec.cc) | Calcolare una divisione con un numero di cifre decimali richiesto | Svolto, con limiti |
| [fibonacci.cc](fibonacci.cc) | Generare termini della successione di Fibonacci fino al valore limite | Svolto, controllo del limite da rivedere |
| [indovinaIlNum.cc](indovinaIlNum.cc) | Gioco di indovinamento di un numero da 1 a 10 | Da completare |
| [seriePi.cc](seriePi.cc) | Approssimare pi greco tramite una serie | Da completare |
| [testDiPrimalita.cc](testDiPrimalita.cc) | Verificare se un intero è primo | Svolto, casi 0 e 1 da correggere |

## Spiegazione dei programmi

### Disegno ASCII

`ASCIIART.cc` legge `n` e stampa un triangolo centrato composto da `n` righe. La riga `i` (a partire da zero) contiene `n-i` spazi e `2*i+1` asterischi.

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
        cout << " ";
    }

    for (int j = 0; j < i * 2 + 1; j++) {
        cout << "*";
    }
    cout << endl;
}
```

#### Esempio

Input:

```text
3
```

Output (gli spazi iniziali sono significativi):

```text
   *
  ***
 *****
```

Il programma stampa un ulteriore spazio iniziale rispetto a un triangolo con base centrata su `n` colonne, perché il ciclo degli spazi parte da `n` invece che da `n-1`.

### Conteggio delle cifre

`cifre.cc` chiede un intero positivo e lo divide ripetutamente per 10. Ogni divisione intera elimina l'ultima cifra decimale; il numero di iterazioni è quindi il numero di cifre.

```cpp
while (n > 0) {
    n = n / 10;
    contacifre++;
}
```

Il ciclo `do-while` iniziale ripete la richiesta finché l'input non è positivo.

#### Esempio

Input:

```text
12345
```

Output:

```text
Imetti un intero positivo Il numero ha 5 cifre
```

### Conversione binario-decimale

`conversioneBinDec.cc` è da completare. L'obiettivo dichiarato è leggere un numero binario e convertirlo in base 10, ma al momento `main` non contiene istruzioni.

Un metodo possibile è elaborare le cifre da destra verso sinistra, moltiplicando ogni cifra per una potenza di 2. Per esempio:

```text
1101₂ = 1*2^0 + 0*2^1 + 1*2^2 + 1*2^3 = 13₁₀
```

L'esercizio completo dovrebbe anche rifiutare cifre diverse da `0` e `1`, e decidere come rappresentare input troppo grandi per il tipo intero scelto.

### Divisione con precisione

`divprec.cc` legge dividendo, divisore e numero di cifre richieste. Moltiplica il dividendo per $10^{cifre}$, esegue la divisione intera e separa parte intera e resto.

```cpp
fattore = pow(10, cifre);
temp = dividendo * fattore / divisore;

quoto = temp / fattore;
resto = temp % fattore;
```

#### Esempio

Input:

```text
10 3 2
```

Output:

```text
Imetti dividendo, divisore e cifre: 10 : 3 = 3,33
```

Il risultato è una rappresentazione approssimata a due cifre dopo la virgola. Il programma stampa la virgola ma non garantisce che la parte decimale abbia sempre il numero di cifre richiesto: per esempio, eventuali zeri iniziali del resto non vengono aggiunti.

### Successione di Fibonacci

`fibonacci.cc` genera e stampa i valori della successione partendo da `0` e `1`. Le variabili `risultato`, `nMenoUno` e `contatore` vengono aggiornate per costruire il termine successivo.

```cpp
risultato = contatore + nMenoUno;
nMenoUno = contatore;
contatore = risultato;
```

Con l'input `10`, il programma stampa anche `13`, il primo termine maggiore di 10.

#### Esempio

Input:

```text
10
```

Output:

```text
Inserire un valore intero n 0,1,2,3,5,8,13
```

Se l'intento è stampare solo i termini non superiori a `n`, il controllo va eseguito sul prossimo termine prima di stamparlo. Il programma attuale, inoltre, non inserisce spazi dopo le virgole e non tratta separatamente input negativi.

### Indovina il numero

`indovinaIlNum.cc` dichiara l'obiettivo: generare un intero casuale tra 1 e 10 e farlo indovinare all'utente.

```cpp
srand(time(NULL));
int random_number = rand() % 10 + 1;

while (!userWon) {
    // TODO: leggere un tentativo e confrontarlo con random_number
    cin >> n;
}
```

Il corpo del ciclo legge `n`, ma non confronta il tentativo con il numero estratto e non modifica `userWon`. Di conseguenza, il ciclo non termina. Da completare: messaggi per tentativi troppo alti/bassi (se richiesti dall'esercizio), riconoscimento della risposta corretta e uscita dal ciclo.

### Approssimazione di pi greco

`seriePi.cc` contiene soltanto il commento che richiede di calcolare un'approssimazione di pi greco a partire da un limite inserito dall'utente. Mancano formula, input, accumulatore, ciclo e stampa del risultato; il file non è ancora un programma compilabile.

Prima di implementarlo, occorre specificare quale serie usare e che cosa rappresenti il limite `n` (numero di termini, indice massimo o precisione). Una volta fissata la serie, il programma dovrà sommare i termini richiesti e mostrare il valore approssimato.

### Test di primalità

`testDiPrimalita.cc` prova a dividere `n` per i valori da 2 in poi. Se trova un divisore, imposta `isPrimo` a `false`; se arriva a `n` senza trovarne, considera il numero primo.

```cpp
int contatore = 2;
while (isPrimo && contatore != n) {
    if (n % contatore == 0) {
        isPrimo = false;
    } else {
        contatore++;
    }
}
```

#### Esempio: numero primo

Input:

```text
7
```

Output:

```text
Inserire un numero n per determinare se sia un numero primo 7 è un numero primo
```

Il caso `1` non è gestito: il ciclo prosegue cercando divisori fino a un overflow del contatore, quindi il comportamento non è corretto. Anche `0` viene accettato dall'input e classificato come non primo solo dopo aver trovato un divisore. La definizione corretta richiede di trattare tutti i valori minori di 2 come non primi prima di avviare il ciclo.

## Note sui limiti attuali

- **Input non validato:** `ASCIIART.cc` non controlla `n`; un valore nullo o negativo produce semplicemente nessuna riga.
- **Numeri negativi:** `cifre.cc` accetta solo positivi. Se si volessero contare le cifre di un intero con segno, andrebbe gestito il segno senza rischiare overflow sul minimo intero rappresentabile.
- **Divisione:** `divprec.cc` non controlla divisore zero, cifre negative o overflow nel prodotto `dividendo * fattore`. `pow` restituisce un valore floating-point convertito poi a `int`.
- **Fibonacci:** stampa un valore che supera `n` e usa `int`, che può andare in overflow per termini grandi.
- **Numero casuale:** `rand() % 10` è adeguato per un esercizio introduttivo, ma non fornisce distribuzione perfettamente uniforme. Il sorgente usa `time(NULL)` e dovrebbe includere esplicitamente `<ctime>` per dichiarare `time` in modo portabile.
- **Primalità:** l'input consente `0` e `1`, ma nessuno dei due è primo. Per input grandi si può anche ridurre il numero di tentativi fermandosi a `contatore * contatore > n`.

## Compilazione

Dalla cartella `8-10-26`, un singolo sorgente si compila così:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic cifre.cc -o cifre
./cifre
```

Per compilare tutti i programmi già completi:

```bash
for file in ASCIIART.cc cifre.cc conversioneBinDec.cc divprec.cc fibonacci.cc indovinaIlNum.cc testDiPrimalita.cc; do
    g++ -std=c++17 -Wall -Wextra -pedantic "$file" -o "/tmp/${file%.cc}" || break
done
```

`seriePi.cc` è escluso perché al momento non contiene un `main` e non può essere compilato come programma autonomo. `conversioneBinDec.cc` e `indovinaIlNum.cc` compilano, ma restano funzionalmente incompleti.

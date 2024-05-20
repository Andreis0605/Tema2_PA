# Mentiune: Toate implmementarile pleaca de la algoritmi prezentati in cadrul cursului sau laboratorului

# Tema 2 PA

## Problema 1: Numarare

### Principiu de rezolvare

> Am citit dimensiunile problemei si am citit primul graf. Dupa aceea, am construit al doile graf doar cu muchiile comune in cele doua grafuri. La fel ca la problema 2 (pe care am rezolvat-o prima), am generat o sortare topologica a celui de-al doile graf.

> Folosind programarea dinamoica, am numarat numarul de drumuri care intra in fiecare nod, plecand de la nodul sursa. Formula de recurenta este urmatoarea: numar cai prin nod = suma(numar cailor care trec prin nodurile care au o muchie catre nodul curent) % 1000000007. La final afisez numarul de drumuri prin nodul considerat destinatie.
### Functii declarate si folosite la rezolvarea problemei

- `vector<int> toposort(int nr_vertexes, vector<vector<int>> graph, vector<int> in_degree)`
    > Functie care realizeaza o sortare topologica a grafului folosind algoritmul lui Khan. Conform descrierii algoritmului de pe OCW, complexitatea acestei functii este O(V + E).

### Complexitatea algoritmului

> Fie N numarul de servere. Complexitatea citirii este O(N). Cautarea binara se efectueaza in O(N * logN). Complexitatea intregului algoritm este O(N * logN).

## Problema 2:

### Principiu de rezolvare

>Se observa ca numarul total de combinatii de culori este dat de o formula. Aceasta depinde de tipul primei zone si de trecerile de la o zona la alta (in special de la orizontal la vertical si invers). Pentru a putea calcula numarul de zone, folosim ridicarea la putere in timp logaritmic, deoarece valorile exponentilor pot fi foarte mari, iar o ridicare la puterere liniara nu ar fi eficienta. In plus, aceasta metoda usureaza limitarea valorilor la maximul impus de problema.

### Functii declarate si folosite la rezolvarea problemei

- `unsigned long long logarithmic_power(unsigned long long base, int exponent`
    >Functia primeste o baza si un exponet. Aceasta efectueaza ridicarea la putere in timp logaritmic, asa cum a fost prezentata la curs si la laborator. Valoarea rezultatului este limitata de valoarea 10<sup>9</sup> + 7 data de problema. Complexitatea acestei functii este O(log exponent).

### Complexitatea algoritmului

> Fie N numarul de zone si exp lungimea unei zone oarecare. Complexitate algoritmului este O(N * max(exp)), unde max(exp) este valoarea maxima a unui exponent. 

## Problema 3: Compresie

### Principiu de rezolvare

> Pentru a putea rezolva problema, am ales sa parcurg cele doua siruri in paralel (similar cu interclasarea), folosind doua sume (una pentru fiecare sir). Iinitial, cele doua sume au valoarea primului element din fiecare sir. Apoi, principiul de rezolvare este urmatorul: daca cele doua sume sunt egale, am gasit o zona care se poate compresa, o numar, resetez sumele si trec la urmatorul element in ambele siruri; daca nu, adun la cea mai mica suma elementul urmator din sirul respectiv. La final, verific ca am terminat de parcurs ambele siruri. Daca nu, inseamna ca nu se poate efectua compresia.

### Complexitatea algoritmului

> Fie N dimensiunea primului sir si M dimensiunea celui de-al doilea sir. Complexitatea citirii sirurilor este O(N + M). Complexitatea parcurgerii celor doi vectori este O(N + M). Complexitatea algoritmului este O(N + M).

## Problema 4: Criptat

### Principiu de rezolvare

> La citire, prelucrez cuvintele pentru a le retine doar frecventa literelor si lungimea. Folosesc un vector de codificari pentru a da fiecarei din cele 8 litere o valoare pentru a le putea marca mai usor in vectorii de frecventa.

> Dupa aceea, calculez lungimea celei mai mari parole posibile si marchez intr-un vector toate lungimile posibile ale parolei

> Pentru fiecare litera in parte, folosesc un vector cu semnificatia dp[i] = frecventa literei curente in parola de lungimea i. La fiecare pas trebuie sa verific ca o parola de acesata lungime este posibila. La sfarsit, parcurg vectorul si caut cea mai lunga parola posibila care are litera curenta dominanta. Dupa ce efectuez aceasta operatiune pentru fiecare litera in parte, voi gasi cea mai lunga parola posibila.

### Structuri de date declarate si folosite la rezolvarea problemei

- `typedef struct word { int frq[10]; int len; } word;`

    > Structura care va retine frecventa literelor unui cuvant si lungimea acesuia

### Complexitatea algoritmului

> Fie N numarul de cuvinte si len lungimea unui cuvant. Complexitatea citirii este O(N * max(len)), unde max(len) este lungimea celui mai mare cuvant. Complexitatea calcului lungimilor posibile este O(N * tot_len), unde tot_len este lungimea celei mai lungi parole posibile. Complexitatea cautarii este O(k * N * tot_len), unde k este numarul de litere distincte. Cum k ∈ {1,2,..,8}, putem spune ca acesasta complexitate este O(N * tot_len). Astfel, complexitatea algoritmului este O(N * max(len)).

## Problema 5: Oferta

### Pirncipiu de rezolvare
> Initial, tratez cele trei cazuri de baza: cand am un singur produs, doua produse sau trei produse. In continuare, tratez cazul general. Folosesc un vector cu semnificatia dp[i] = pretul cel mai mic pe care il putem obtine folosind i produse. Marchez cazurile de baza si incep sa calculez valorile din vector folosind formula de recurenta(in care p1, p2, p3 este o secventa de produse, in aceasta ordine) : dp[i] = min(dp[i-1] + p3, dp[i-2] + oferta_doua(p2, p3), dp[i-3] + oferta_trei(p1, p2, p3)). La final, valoarea cautata se gaseste in dp[N].

### Functii declarate si folosite la rezolvarea problemei

- `double two_discount(int product1, int product2)`
    > Functia primeste pretul a doua produse si returneaza pretul total dupa aplicarea ofertei pentru doua produse. Complexitatea acestei functii este O(1).

- `double three_discount(int product1, int product2, int product3)`
    > Functia primeste pretul a trei produse si returneaza pretul total dupa aplicarea ofertei pentru trei produse. Complexitatea acestei functii este O(1).

### Complexitatea algoritmului
> Complexitatea verificarii cazurilor de baza este O(1). Complexitatea cazului general este O(N). Complexitatea intregului algoritm este O(N). 

# Punctaj pe local: 137p
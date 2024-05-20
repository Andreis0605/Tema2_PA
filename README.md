# Mentiune: Toate implmementarile pleaca de la algoritmi prezentati in cadrul cursului sau laboratorului

# Tema 2 PA

## Problema 1: Numarare

### Mentiune:

> Am rezolvat problema asta dupa ce am rezolvat a doua problema.

### Principiu de rezolvare

> Am citit dimensiunile problemei si am citit primul graf. Dupa aceea, am construit al doile graf doar cu muchiile comune in cele doua grafuri. La fel ca la problema 2 (pe care am rezolvat-o prima), am generat o sortare topologica a celui de-al doile graf.

> Folosind programarea dinamoica, am numarat numarul de drumuri care intra in fiecare nod, plecand de la nodul sursa. Formula de recurenta este urmatoarea: numar cai prin nod = suma(numar cailor care trec prin nodurile care au o muchie catre nodul curent) % 1000000007. La final afisez numarul de drumuri prin nodul considerat destinatie.
### Functii declarate si folosite la rezolvarea problemei

- `vector<int> toposort(int nr_vertexes, vector<vector<int>> graph, vector<int> in_degree)`
    > (La fel ca la a doua problema) Functie care realizeaza o sortare topologica a grafului folosind algoritmul lui Khan. Conform descrierii algoritmului de pe OCW, complexitatea acestei functii este O(V + E).

### Complexitatea algoritmului

> Fie V numarul de noduri si E numarul de muchii date in fisierul de intrare. Complexitatea citirii este O(2E) = O(E). Complexitatea sortarii topologice este O(V + E). Complexitatea partii de programare dinamica este O(V + E). In total, complexitatea este O(E + V + E + V + E) = O(2V + 3E) = O(V + E).

## Problema 2: Trenuri

### Bibliografie:
- https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/


### Principiu de rezolvare

>Initial, citim datele de intrare si mapam fiecare nume de oras cu un numar care reprezinta nodul din graf. In acelasi timp, construim graful. Dupa aceea, realizam sortarea topologica a grafului. Folosind programarea dinamica, calculam cea mai lunga ruta posibila de la start la destinatie. Formula de recurenta este: distanta nod = max(distanta oricarui nod care intra in nodul curent + 1). La final afisez cea mai mare distanta pentru nodul considerat destinatie.

### Functii declarate si folosite la rezolvarea problemei

- `vector<int> toposort(int nr_vertexes, vector<vector<int>> graph, vector<int> in_degree)`
    > Functie care realizeaza o sortare topologica a grafului folosind algoritmul lui Khan. Conform descrierii algoritmului de pe OCW, complexitatea acestei functii este O(V + E).

### Complexitatea algoritmului

> Fie V numarul de noduri si E numarul de muchii date in fisierul de intrare. Citirea se realizeaza in O(E). Sortarea topologica se realizeaza in O(V + E). Partea de programare dinamica se realizeaza in O(V + E). In total, avem O(E + V + E + V + E) = O(2V + 3E) = O(V + E).

## Problema 3: Drumuri

### Principiu de rezolvare

> Initial, citesc datele problemei si imi generez 2 grafuri: unul cu muchiile in sensul in care au fost date si unul cu muchiile in sens invers. Apoi aplic dijkstra din nodurile x si y pe graful cu muchiile in sens normal si pe graful invers plecand din z. Astfel, calculez distanta de la x la toate nodurile, de la y la toate nodurile si de la toate nodurile la z. Dupa aceea, caut nodurile in care converg drumul de la x la z si de la y la z, incercand astfel sa dirijez drumurile prin graf. Daca cele 2 drumuri converg in acel nod, verific daca costul acela este cel minim. La final, afisez costul minim.


### Functii declarate si folosite la rezolvarea problemei

- `vector<pair<unsigned long long, int>> dijkstra(int start,vector<map<int, int>> graph)`
    > Functie care calculeaza distanta de la un un nod la toate nodurile din graf folosind dijkstra. Intoarce un vector cu distante si noduri parinte. Complexitatea acestei functii este O(E * logV).

### Complexitatea algoritmului

> Fie V numarul de noduri din graf si E numarul de muchii. Complexitatea citirii este O(E). Complexitatea aplicarii dijkstra pe graf este O(3 * E * logV) = O(E * logV). Calculul minimului se realizeaza in O(V). Complexitatea totala este O(E + E * logV + V) = O(E * logV).

## Problema 4: Scandal 

### Principiu de rezolvare

> Nu am rezolvat aceasta problema.

# Punctaj pe local: 137p
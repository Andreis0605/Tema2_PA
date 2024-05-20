#include <bits/stdc++.h>

using namespace std;

// https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/

// function that returns a topological sorting of a graph as a vector
// recerives the number of vertexes in a graph, the graph as an
// adjency list and a vector that contains the in degree each vertex
vector<int> toposort(int nr_vertexes, vector<vector<int>> graph,
                     vector<int> in_degree) {
    // initialize the structures for the sorting
    vector<int> order;
    queue<int> q;

    // enqueue the vertexes that have no edegs that go into them
    for (int i = 0; i < nr_vertexes; i++) {
        if (in_degree[i] == 0)
            q.push(i);
    }

    // process the graph
    while (!q.empty()) {
        // dequeue an element from the queue
        // and add it in the result
        int vertex = q.front();
        q.pop();
        order.push_back(vertex);

        // process the neighbours of the vertex (decrease their in degree)
        for (auto &vert : graph[vertex]) {
            in_degree[vert]--;
            if (in_degree[vert] == 0)
                q.push(vert);
        }
    }

    // return the topological order of the graph
    return order;
}

int main() {
    // open the files
    ifstream in("trenuri.in");
    ofstream out("trenuri.out");

    // define the map which can store a corespondence
    // between the names of a city and it's number
    map<string, int> translation;
    map<string, int>::iterator itr1, itr2;
    int counter = 0, N;

    // read the source and destination
    string source, dest, aux1, aux2;
    in >> source >> dest;

    // add the first nodes in the map
    translation.insert(pair<string, int>(source, 0));
    translation.insert(pair<string, int>(dest, 1));
    counter = 2;

    // read the number of vertexes
    in.get();
    in >> N;

    // declare the vector for the adjency list
    vector<vector<int>> adj_list(N + 1);

    // declare a vector to find the in degree of a vertex
    vector<int> in_degree(N + 1, 0);

    // read the graph
    for (int i = 0; i < N; i++) {
        // translate the strings read from files to numbers
        in >> aux1 >> aux2;
        itr1 = translation.find(aux1);
        if (itr1 == translation.end()) {
            translation.insert(pair<string, int>(aux1, counter));
            counter++;
        }

        itr2 = translation.find(aux2);
        if (itr2 == translation.end()) {
            translation.insert(pair<string, int>(aux2, counter));
            counter++;
        }

        // add the edge in the grapf
        adj_list[translation.find(aux1)->second]
            .push_back(translation.find(aux2)->second);

        // increase the in degree of the destination of the edge
        in_degree[translation.find(aux2)->second]++;
    }

    // generate a topological sort of the graph
    vector<int> sorted = toposort(translation.size(), adj_list, in_degree);

    // calculate the maximum distance using dynamic programming

    // declare a vector for the maximum distances
    vector<int> distances(translation.size(), INT_MIN);

    // base case for dp
    distances[0] = 0;

    // go through each vertex in topological order
    for (int i = 0; i < sorted.size(); i++) {
        // find the vertexes that are alreay discovered
        if (distances[sorted[i]] != INT_MIN) {
            // go through their neighbours
            for (int j = 0; j < adj_list[sorted[i]].size(); j++) {
                // check if the path for the neighbour is longer
                // if we go through the current vertex
                if (distances[adj_list[sorted[i]][j]] <
                    distances[sorted[i]] + 1)
                    distances[adj_list[sorted[i]][j]] =
                        distances[sorted[i]] + 1;
            }
        }
    }

    // print the longest way for the destination vertex
    out << distances[1] + 1 << "\n";

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

// function that implements the dijkstra algorithm
// it recceives the start vertex and the graph and
// returns a vector of pairs that contains the distance and the parent vertex
// of each vertex
vector<pair<unsigned long long, int>> dijkstra(int start,
                                               vector<map<int, int>> graph) {
    // declare the vector that will store the distances and the parent vertex
    vector<pair<unsigned long long, int>> dij(graph.size() + 1);

    // initialize the distances and the parent vertex
    for (long unsigned int i = 0; i < graph.size() + 1; i++) {
        dij[i].first = ULLONG_MAX;
        dij[i].second = -1;
    }

    // declare the queue for the algorithm
    queue<int> q;

    // initialize the first vertex and add it in the queue
    dij[start].first = 0;
    dij[start].second = -1;
    q.push(start);

    // start processing the queue
    while (!q.empty()) {
        // get the first vertex from the queue
        int vertex = q.front();
        q.pop();

        // go through all the neighbours of the vertex
        for (auto &elem : graph[vertex]) {
            // if the distance to the neighbour is smaller
            // than the current distance
            if (dij[vertex].first + (unsigned long long)elem.second <
                dij[elem.first].first) {
                // update the distance and the parent vertex and
                // add the neighbour in the queue
                dij[elem.first].first = dij[vertex].first + elem.second;
                dij[elem.first].second = vertex;
                q.push(elem.first);
            }
        }
    }

    // return the distances and the parent vertex vector
    return dij;
}

int main() {
    // open the files
    ifstream in("drumuri.in");
    ofstream out("drumuri.out");

    // read the number of vertexes and edges
    int N, M;
    in >> N >> M;

    // declare an adjency list for the graph and one for the reverse graph
    vector<map<int, int>> adj_list(N + 2), reverse_adj_list(N + 2);

    // read the graph
    for (int i = 0; i < M; i++) {
        int x, y, z;
        in >> x >> y >> z;
        adj_list[x].insert({y, z});

        // create the reevrse graph
        reverse_adj_list[y].insert({x, z});
    }

    // read the nodes in the problem
    int x, y, z;
    in >> x >> y >> z;

    // calculate the dijkstra for the x and y vertexes
    vector<pair<unsigned long long, int>> dij_from_x, dij_from_y, dij_to_z;
    dij_from_x = dijkstra(x, adj_list);
    dij_from_y = dijkstra(y, adj_list);

    // calculate the dijkstra for the z vertex on the reversed graph
    dij_to_z = dijkstra(z, reverse_adj_list);

    // calculate the minimum distance between the 3 vertexes
    unsigned long long minn = ULLONG_MAX;
    unsigned long long sum = 0;

    // force the way between x and y to go through each vertex in the graph
    for (int i = 1; i <= N; i++) {
        // if all the ways exist and the ways between x and y to z
        // meet exactry at the vertex i
        if (dij_from_x[i].first != ULLONG_MAX &&
            dij_from_y[i].first != ULLONG_MAX &&
            dij_to_z[i].first != ULLONG_MAX &&
            dij_from_x[i].second != dij_from_y[i].second) {
            // calculate the cost of the way and update the minimum
            sum = dij_from_x[i].first + dij_from_y[i].first + dij_to_z[i].first;
            minn = min(minn, sum);
        }
    }

    // print the cost of the minimum way
    out << minn;

    return 0;
}

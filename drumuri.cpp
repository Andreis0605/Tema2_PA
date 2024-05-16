#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> dijkstra(int start, vector<vector<pair<int, int>>> graph)
{
    vector<pair<int, int>> dij(graph.size() + 1);

    for (long unsigned int i = 0; i < graph.size() + 1; i++)
    {
        dij[i].first = INT_MAX;
        dij[i].second = -1;
    }

    // declare the queue for the
    queue<int> q;

    // initialize the first vertex and add it in the queue
    dij[start].first = 0;
    dij[start].second = -1;
    q.push(start);

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();

        for (long unsigned int i = 0; i < graph[vertex].size(); i++)
        {
            if (dij[vertex].first + graph[vertex][i].second < dij[graph[vertex][i].first].first)
            {
                dij[graph[vertex][i].first].first = dij[vertex].first + graph[vertex][i].second;
                dij[graph[vertex][i].first].second = vertex;

                q.push(graph[vertex][i].first);
            }
        }
    }

    return dij;
}

int get_edge_cost(int source, int dest, vector<vector<pair<int,int>>> graph)
{
    for(long unsigned int i = 0; i < graph[source].size(); i++)
    {
        if(graph[source][i].first == dest)
        {
            return graph[source][i].second;
        }
    }

    return -1;
}

// function that removes the common edges from two paths that lead to the same vertex
void remove_common_edges_from_sum(int source1, int source2, int dest,
                                  unsigned long long &sum, vector<pair<int, int>> dij_source1,
                                  vector<pair<int, int>> dij_source2,
                                  vector<vector<pair<int, int>>> graph)
{
    int current = dest;
    while(dij_source1[current].second == dij_source2[current].second)
    {
        sum -= get_edge_cost(dij_source1[current].second, current, graph);
        current = dij_source1[current].second;
    }

}

int main()
{

    // open the files
    ifstream in("drumuri.in");
    ofstream out("drumuri.out");

    // read the number of vertexes and edges
    int N, M;
    in >> N >> M;

    // declare the adjency list for the graph
    vector<vector<pair<int, int>>> adj_list(N + 2), reverse_adj_list(N + 2);

    // read the graph
    for (int i = 0; i < M; i++)
    {
        int x, y, z;
        in >> x >> y >> z;
        adj_list[x].push_back({y, z});
        reverse_adj_list[y].push_back({x, z});
    }

    // read the nodes in the problem
    int x, y, z;
    in >> x >> y >> z;
    //out << x << " " << y << " " << z << "\n";

    // sort the edges by cost for each vertex

    for (int i = 1; i <= N; i++)
    {
        sort(adj_list[i].begin(), adj_list[i].end(), [](pair<int, int> a, pair<int, int> b)
             { return a.second < b.second; });
    }

    // print the graph
    /*for (int i = 1; i <= N; i++)
    {
        cout << i << ": ";
        for (long unsigned int j = 0; j < adj_list[i].size(); j++)
        {
            cout << adj_list[i][j].first << " " << adj_list[i][j].second << " ";
        }
        cout << endl;
    }*/

    // calculate the dijkstra for the x and y vertexes
    vector<pair<int, int>> dij_from_x, dij_from_y, dij_to_z;
    dij_from_x = dijkstra(x, adj_list);
    dij_from_y = dijkstra(y, adj_list);
    dij_to_z = dijkstra(z, reverse_adj_list);

    // print the dijkstra for the x ,y and z vertexes
    /*for (int i = 1; i <= N; i++)
    {
        out << i << " " << dij_from_x[i].first << " " << dij_from_x[i].second << "\n";
    }

    out << "\n";

    for (int i = 1; i <= N; i++)
    {
        out << i << " " << dij_from_y[i].first << " " << dij_from_y[i].second << "\n";
    }

    out << "\n";

    for (int i = 1; i <= N; i++)
    {
        out << i << " " << dij_to_z[i].first << " " << dij_to_z[i].second << "\n";
    }

    out << "\n";*/

    unsigned long long minn = ULLONG_MAX;
    unsigned long long sum = 0;

    for (int i = 1; i <= N; i++)
    {
        if (dij_from_x[i].first != INT_MAX && dij_from_y[i].first != INT_MAX && dij_to_z[i].first != INT_MAX)
        {
            sum = dij_from_x[i].first + dij_from_y[i].first + dij_to_z[i].first;
            remove_common_edges_from_sum(x, y, i, sum, dij_from_x, dij_from_y, adj_list);
            minn = min(minn, sum);
        }
    }

    out << minn;

    return 0;
}
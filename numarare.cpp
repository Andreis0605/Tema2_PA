#include <bits/stdc++.h>

#define LIMIT 1000000007

using namespace std;

// function that counts all the paths found during a DFS traversal
/*void dfs_count(int current, int stop, vector<vector<int>> graph, vector<bool> &visited, int &counter)
{
    if (current == stop)
    {
        counter++;
        counter = counter % LIMIT;
    }
    else
    {
        for (long unsigned int i = 0; i < graph[current].size(); i++)
        {
            if (visited[graph[current][i]] == false)
            {
                visited[graph[current][i]] = true;
                dfs_count(graph[current][i], stop, graph, visited, counter);
                visited[graph[current][i]] = false;
            }
        }
    }
}*/

// function that returns a topological sorting of a graph as a vector
// recerives the number of vertexes in a graph, the graph as an
// adjency list and a vector that contains the in degree each vertex
vector<int> toposort(int nr_vertexes, vector<vector<int>> graph,
                     vector<int> in_degree)
{

    // initialize the structures for the sorting
    vector<int> order;
    queue<int> q;

    // enqueue the vertexes that have no edegs that go into them
    for (int i = 0; i < nr_vertexes; i++)
    {
        if (in_degree[i] == 0)
            q.push(i);
    }

    // process the graph
    while (!q.empty())
    {
        // dequeue an element from the queue
        // and add it in the result
        int vertex = q.front();
        q.pop();
        order.push_back(vertex);

        // process the neighbours of the vertex (decrease their in degree)
        for (auto &vert : graph[vertex])
        {
            in_degree[vert]--;
            if (in_degree[vert] == 0)
                q.push(vert);
        }
    }

    return order;
}

int main()
{

    // open the files
    ifstream in("numarare.in");
    ofstream out("numarare.out");

    // read the number of vertexes and edges
    int N, M;
    in >> N >> M;

    // declare the adjency lists for the two graphs
    vector<vector<int>> adj_list1(N + 2), adj_list2(N + 2);
    vector<int> in_degree(N + 2, 0);

    //

    // read the first graph
    for (int i = 0; i < M; i++)
    {
        int x, y;
        in >> x >> y;
        adj_list1[x].push_back(y);
    }

    // read the second graph
    for (int i = 0; i < M; i++)
    {
        int x, y;
        in >> x >> y;

        // if we have an edge in the first graph, add it to the second one
        if (find(adj_list1[x].begin(), adj_list1[x].end(), y) != adj_list1[x].end())
        {
            adj_list2[x].push_back(y);
            in_degree[y]++;
        }
    }

    // generate the toposort of the second graph
    vector<int> sorted = toposort(N, adj_list2, in_degree);

    // declare a vector to count the number of paths that go into each vertex
    vector<unsigned long long> nr_paths(N + 2, 0);

    nr_paths[1] = 1;

    for (auto &ver : sorted)
    {
        for (auto &child : adj_list2[ver])
        {
            nr_paths[child] += nr_paths[ver];
            nr_paths[child] = nr_paths[child] % LIMIT;
        }
    }

    out << nr_paths[N];

    return 0;
}
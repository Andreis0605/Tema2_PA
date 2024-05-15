#include <bits/stdc++.h>

#define LIMIT 1000000007

using namespace std;

// function that counts all the paths found during a DFS traversal
void dfs_count(int current, int stop, vector<vector<int>> graph, vector<bool> &visited, int &counter)
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
            adj_list2[x].push_back(y);
    }

    // define the elements needed for the dfs of the second graph

    vector<bool> visited(N + 2, false);
    stack<int> stack;
    int counter = 0;
    visited[1] = true;

    dfs_count(1, N, adj_list2, visited, counter);

    out << counter;

    return 0;
}
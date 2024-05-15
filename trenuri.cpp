#include <bits/stdc++.h>

using namespace std;

// https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/

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

    in.get();
    in >> N;

    // declare the vector for the adjency list
    vector<vector<int>> adj_list(N + 1);

    // declare a vector to find the in degree of a vertex
    vector<int> in_degree(N + 1, 0);

    for (int i = 0; i < N; i++)
    {
        in >> aux1 >> aux2;
        itr1 = translation.find(aux1);
        if (itr1 == translation.end())
        {
            translation.insert(pair<string, int>(aux1, counter));
            counter++;
        }

        itr2 = translation.find(aux2);
        if (itr2 == translation.end())
        {
            translation.insert(pair<string, int>(aux2, counter));
            counter++;
        }

        adj_list[translation.find(aux1)->second].push_back(translation.find(aux2)->second);
        in_degree[translation.find(aux2)->second]++;
    }

    /*for (int i = 0; i < adj_list.size(); ++i)
    {
        out << "Node " << i << " connected to: ";
        for (int j = 0; j < adj_list[i].size(); ++j)
        {
            out << adj_list[i][j] << " ";
        }
        out << endl;
    }

    for (int i = 0; i < in_degree.size(); ++i)
    {
        out << "In-degree of node " << i << ": " << in_degree[i] << endl;
    }*/

    vector<int> sorted = toposort(translation.size(), adj_list, in_degree);
    vector<int> distances(translation.size(), INT_MIN);

    /*for(int i=0;i<sorted.size();i++)
    {
        out << sorted[i] << " ";
    }*/

    // out << "\n";

    distances[0] = 0;

    for (int i = 0; i < sorted.size(); i++)
    {
        if (distances[sorted[i]] != INT_MIN)
        {
            for (int j = 0; j < adj_list[sorted[i]].size(); j++)
            {
                if (distances[adj_list[sorted[i]][j]] < distances[sorted[i]] + 1)
                    distances[adj_list[sorted[i]][j]] = distances[sorted[i]] + 1;
            }
        }
    }

    out << distances[1] + 1 << "\n";

    /*for (int i = 0; i < adj_list.size(); ++i)
    {
        out << "Node " << i << " connected to: ";
        for (int j = 0; j < adj_list[i].size(); ++j)
        {
            out << adj_list[i][j] << " ";
        }
        out << endl;
    }*/

    /*for(itr = translation.begin();itr!= translation.end();itr++)
    {
        out << itr->first << " " << itr->second << "\n";
    }
    */
    return 0;
}
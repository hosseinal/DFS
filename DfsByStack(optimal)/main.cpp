#include <bits/stdc++.h>
#include "time.h"
using namespace std;

class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;
    stack<int> m_stack;
    void addEdge(int v, int w);
    void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS(int v)
{
    m_stack.push(v);
    while (!m_stack.empty()){
        int item = m_stack.top();
        m_stack.pop();
        if(visited[item])
            continue;
        visited[item] = true;
        cout<<item<<" ";
        list<int>::reverse_iterator i;
        for (i = adj[item].rbegin(); i != adj[item].rend(); ++i)
            m_stack.push(*i);
    }
}

int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 6);
    g.addEdge(6, 5);
    g.addEdge(7, 5);
    g.addEdge(7, 4);
    g.addEdge(6, 8);
    g.addEdge(8, 3);
    g.addEdge(8, 2);
    g.addEdge(0, 7);
    g.addEdge(6, 8);
    g.addEdge(8, 7);
    g.addEdge(8, 9);
    g.addEdge(8, 10);
    g.addEdge(8, 11);
    g.addEdge(11, 12);
    g.addEdge(12, 13);
    g.addEdge(13, 14);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);
    return 0;
}


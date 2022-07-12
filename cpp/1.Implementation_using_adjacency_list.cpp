#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph
{
    public:
    unordered_map<int, list<int> > adj;

    void addEdge(int u, int v, bool direction)
    {
        // Direction = 0 -> Undirected Graph
        // Direciton = 1 -> Directed Graph

        // Create an edge from u to v
        adj[u].push_back(v);

        if(direction == 0)  // Graph is Undirected
        {
            adj[v].push_back(u);
        }
    }

    void print()
    {
        for(auto i:adj)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }

};

int main()
{
    graph g;

    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;

    int u, v;
    cout<<"Creating the edges between the nodes\n";
    cin>>u>>v;

    while(u != -1 && v != -1)       // -1 and -1 will be the terminating condition
    {
        // Creating an Undirected Graph
        g.addEdge(u, v, 0);
        cin>>u>>v;
    }

    // Printing the graph
    cout<<"\nThe Adjacency List of the graph\n";
    g.print();

    return 0;
}
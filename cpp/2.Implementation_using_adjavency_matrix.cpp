#include<iostream>
#include<vector>
using namespace std;

class graph
{
    public:
    int arr[100][100];

    graph(int n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v, bool direction)
    {
        arr[u][v] = 1;

        if(direction == 0)
        {
            arr[v][u] = 1;
        }
    }

    void print(int n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<< arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;

    graph g(n);

    int u, v;
    cout<<"Enter the edges in graph\n";
    cin>>u>>v;

    // Creating an Undirected Graph
    while(u != -1 && v != -1)
    {
        g.addEdge(u, v, 0);
        cin>>u>>v;
    }

    // Printing the graph
    g.print(n);

    return 0;
}
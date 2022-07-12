/*
BFS traversal for undirected graph.
*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class graph
{
    public:
    unordered_map<int, list<int> > adj;

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> BFS(int startingNode)
    {
        vector<int> ans;
        unordered_map<int, bool> visited;
        queue<int> q;

        if(!visited[startingNode])
        {
            q.push(startingNode);
            visited[startingNode] = true;
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            // Store node to ans
            ans.push_back(node);

            // Traversing all the neighbours of node
            for(auto i:adj[node])
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }

        return ans;
    }
};

int main()
{
    int vertex;
    cout<<"Enter the number of vertices: ";
    cin>>vertex;

    graph g;

    int u, v;
    cout<<"Enter the edges\n";
    cin>>u>>v;

    while(u != -1 && v != -1)
    {
        g.addEdge(u, v);
        cin>>u>>v;
    }

    // Printing the BFS
    int startingNode;
    cout<<"Enter the starting node: ";
    cin>>startingNode;
    vector<int> ans = g.BFS(startingNode);

    cout<<"\nThe BFS traversal is\n";
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}
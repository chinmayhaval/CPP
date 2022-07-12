/*
DFS for undirected Graph
*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<stack>
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

    void dfs(int startingNode, unordered_map<int, bool> &visited, unordered_map<int, list<int> > adj, vector<int> &ans)
    {
        ans.push_back(startingNode);
        visited[startingNode] = true;

        for(auto i:adj[startingNode])
        {
            if(!visited[startingNode])
            {
                dfs(i, visited, adj, ans);
            }
        }
    }

    vector<int> DFS(int startingNode)
    {
        vector<int> ans;
        unordered_map<int, bool> visited;

        if(!visited[startingNode])
        {
            dfs(startingNode, visited, adj, ans);
        }

        return ans;
    }
};

int main()
{
    int vertex;
    cout<<"Enter the number of nodes you want: ";
    cin>>vertex;

    graph g;

    int u, v;
    cout<<"Enter Edges\n";
    cin>>u>>v;

    while(u != -1 && v != -1)
    {
        g.addEdge(u, v);
        cin>>u>>v;
    }

    // Printing DFS
    int startingNode;
    cout<<"Enter the starting node: ";
    cin>>startingNode;

    vector<int> ans = g.DFS(startingNode);

    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}
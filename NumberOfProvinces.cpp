#include<bits/stdc++.h>
using namespace std;

void addVertex(vector<int> list[], int src,int dest)  
{
    list[src].push_back(dest);
}

void DFS(int src,vector<int> adj[],vector<int> &vis)
{
    //cout<<src;
    vis[src]=true;
    for(auto it:adj[src])
    {
        if(!vis[it])
        {
            DFS(it,adj,vis);
        }
    }
    
}
int NumberofProvinces(vector<int> adj[],int v)
{
    vector<int> visited(v,false);
    int count=0;
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            DFS(i,adj,visited);
            count++;
        }
    }
    return count;
}
    
int main()
{
    int vertices=6;
    vector<int> adj[vertices];

    addVertex(adj,0,1);
    addVertex(adj,1,2);
    addVertex(adj,3,4);
    cout<<NumberofProvinces(adj,vertices);
    return 0;

}

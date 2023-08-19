#include<bits/stdc++.h>
using namespace std;

void printBFSGraph(vector<int> adj[],int src,int v)
{
    std::queue<int> q;
    vector<bool> visited;
    visited.resize(v,false);
    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        int next=q.front();
        cout<<endl;
        cout<<next<<" ";
        q.pop();
        
            for(int i=0;i<adj[next].size();i++)
            {
                if(!visited[adj[next][i]])
                {
                    q.push(adj[next][i]);
                    visited[adj[next][i]]=true;
                }
            }
        
        
    }
    
}
    
int main()
{
    int vertices=4;
    vector<int> adj[vertices];
    
    addVertex(adj,0,1);
    addVertex(adj,0,2);
    addVertex(adj,1,2);
    addVertex(adj,2,0);
    addVertex(adj,2,3);
    addVertex(adj,3,3);
    printBFSGraph(adj,2,4);
    return 0;

}

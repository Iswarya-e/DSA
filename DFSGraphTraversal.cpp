#include<bits/stdc++.h>
using namespace std;

void addVertex(vector<int> list[], int src,int dest)  
{
    list[src].push_back(dest);
}
void printDFSGraph(vector<int> adj[],int src,int v)
{
    std::stack<int> s;
    map<int,bool> visited;
    s.push(src);
    visited[src]=true;
    while(!s.empty())
    {
        int next=s.top();
        cout<<next<<" ";
        s.pop();
        for(auto adjacent:adj[next])
        {
            if(!visited[adjacent])
            {
                s.push(adjacent);
                visited[adjacent]=true;
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
    printDFSGraph(adj,2,4);
    return 0;

}

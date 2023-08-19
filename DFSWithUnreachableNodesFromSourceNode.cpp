#include<bits/stdc++.h>
using namespace std;

void addVertex(vector<int> list[], int src,int dest)  
{
    list[src].push_back(dest);
}
void printDFSGraph(vector<int> adj[],int src,vector<bool> &visited)
{
    std::stack<int> s;

    s.push(src);
    visited[src]=true;

    while(!s.empty())
    {
        int next=s.top();
        s.pop();
        cout<<next<<" ";
        
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
void printDFSGraphUtil(vector<int> adj[],int v)
{
   vector<bool> visited(v,false);
   for(int i=0;i<v;i++)
   {
       if(!visited[i])
       {
           printDFSGraph(adj,i,visited);
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
    addVertex(adj,2,3);
    addVertex(adj,3,3);
    printDFSGraphUtil(adj,vertices);
    return 0;

}

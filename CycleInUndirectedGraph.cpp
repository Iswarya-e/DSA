//TC:N times we are doing BFS 
In BFS we are visiting adjacent nodes
summation of adjacent nodes=Total degree= 2 X Edges (Only applicable in undirected graph)
BFS calls are not made for each node

So, O(N + 2E) +O(N) (for for loop )

Space Complexity :O(N)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool BFSCycle(vector<int> adj[],vector<int> &visited,int node)
    {
        queue<pair<int,int>> q;
        q.push({node,-1});
        visited[node]=1;
        while(!q.empty())
        {
            int n=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it:adj[n])
            {
                if(visited[it]!=1)
                {
                    q.push({it,n});
                    visited[it]=1;
                }
                else if(parent!=it) return true;
            }
        }
        return false;
    }
bool DFSCycle(vector<int> adj[],vector<int> &visited,int node,int parent){
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(visited[it]!=1) 
            {
                if(DFSCycle(adj,visited,it,node)) return true;
            }
            else if(parent!=it) return true;
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(BFSCycle(adj,visited,i)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends

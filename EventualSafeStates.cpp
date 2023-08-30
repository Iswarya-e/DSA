//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
  public:
    bool isCyclic(vector<int> &visited, vector<int> &path,vector<int> adj[],int node)
    {
        path[node]=1;
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(visited[it]==0)
            {
                if(isCyclic(visited,path,adj,it))
                {
                    return true;
                }
            }
            else if(path[it]!=0)
            {
                return true;
            }
            
        }
        path[node]=0;
        return false;
        
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        vector<int> path(V,0);
        vector<int> safeNodes;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                isCyclic(visited,path,adj,i);
            }
        }
        for(int i=0;i<V;i++)
        {
            if(path[i]==0)
            {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends

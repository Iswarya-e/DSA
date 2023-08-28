//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   bool isCyclicDFSUsingPath(vector<int> adj[],vector<int> &visited,vector<int> &path,int start )
   
   {
       visited[start]=1;
       path[start]=1;
       for(auto it:adj[start])
       {
           if(visited[it]==0)
           {
               if(isCyclicDFSUsingPath(adj,visited,path,it)==true)
               {
                   return true;
               }
           }
           else if (visited[it]==1 && path[it]==1)
           {
               return true;
           }
       }
       path[start]=0;
       return false;
   }
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V,0);
        vector<int> path(V,0);

        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                if(isCyclicDFSUsingPath(adj,visited,path,i))
                {
                    return true;
                }
            }
        }
        return false;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends

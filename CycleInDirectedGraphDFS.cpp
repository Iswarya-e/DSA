//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   bool isCyclicDFS(vector<int> adj[],vector<int> &visited,int start)
   {
       visited[start]=2;
       for(auto it:adj[start])
       {
           if(visited[it]==0)
           {
               if(isCyclicDFS(adj,visited,it)==true)
               {
                   return true;
               }
           }
           else if (visited[it]==2)
           {
               return true;
           }
       }
       visited[start]=1;
       return false;
   }
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V,0);
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                if(isCyclicDFS(adj,visited,i))
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

A linear grapgh can be biparti te
A graph with even length cycle  can be bipartite
A graph with odd length cycle  can not be bipartite


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> coloured(V,-1);
	    queue<int> q;
	    q.push(0);
	    coloured[0]=0;
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        for(auto it:adj[node])
	        {
	            if(coloured[it]==-1)
	            {
	                coloured[it]=!coloured[node];
	                q.push(it);
	            }
	            else if(coloured[it]==coloured[node])
	            {
	                return false;
	            }
	        }
	    }
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends

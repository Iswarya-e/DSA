//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void DFS(vector<vector<int>> &visited, vector<vector<int>> &grid, vector<pair<int,int>> &islands,int sr,int sc,
    int br,int bc)
    {
        visited[sr][sc]=1;
        int m=grid.size();
        int n=grid[0].size();
        islands.push_back({sr-br,sc-bc});

        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        for(int i=0;i<4;i++)
        {
            int newrow=sr+dr[i];
            int newcol=sc+dc[i];
            if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && visited[newrow][newcol]!=1
            && grid[newrow][newcol]==1)
            {
                DFS(visited,grid,islands,newrow,newcol,br,bc);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j]!=1 && grid[i][j]==1)
                {
                    vector<pair<int,int>> islands;
                    DFS(visited,grid,islands,i,j,i,j);
                    st.insert(islands);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends

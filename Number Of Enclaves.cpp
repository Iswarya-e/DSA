///TC:NXMX4


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
  private:
  void DFSLand(vector<vector<int>> &grid, vector<vector<int>> &visited,int sr, int sc,int n,int m)
  {
      visited[sr][sc]=1;
      int dr[]={0,0,1,-1};
      int dc[]={1,-1,0,0};
      for(int i=0;i<4;i++)
      {
          int newrow=sr+dr[i];
          int newcol=sc+dc[i];
          if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && visited[newrow][newcol]!=1 && grid[newrow][newcol]==1)
          {
              DFSLand(grid,visited,newrow,newcol,n,m);
          }
      }
  }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1 && visited[i][0]!=1)
            {
                DFSLand(grid,visited,i,0,n,m);
            }
            if(grid[i][m-1]==1 && visited[i][m-1]!=1)
            {
                DFSLand(grid,visited,i,m-1,n,m);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1 && visited[0][i]!=1)
            {
                DFSLand(grid,visited,0,i,n,m);

            }
            if(grid[n-1][i]==1 && visited[n-1][i]!=1)
            {
               DFSLand(grid,visited,n-1,i,n,m);  
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]!=1 && grid[i][j]==1)
                {
                    count++;
                }
            }
        }
        return count;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends

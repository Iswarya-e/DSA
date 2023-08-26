//TC
O(NXM)
	
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int m=grid.size();
	    int n=grid[0].size();
	    vector<vector<int>> visited(m,vector<int>(n,0));
	    vector<vector<int>> ans(m,vector<int>(n,0));
	    queue<pair<pair<int,int>,int>> q;
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({{i,j},0});
	                ans[i][j]=0;
	                visited[i][j]=1;
	            }
	        }
	    }
	   int dr[]={1,-1,0,0};
	   int dc[]={0,0,1,-1};
	    while(!q.empty())
	    {
	        int r=q.front().first.first;
	        int c=q.front().first.second;
	        int dis=q.front().second;
	        q.pop();
	        ans[r][c]=dis;
	        for(int k=0;k<4;k++)
	        {
	            int newrow=r+dr[k];
	            int newcol=c+dc[k];
	            if(newrow>=0 && newrow<m and newcol>=0 && newcol<n && visited[newrow][newcol]!=1)
	            {
	                visited[newrow][newcol]=1;
	                q.push({{newrow,newcol},dis+1});
	            }
	        }
	        
	        
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends

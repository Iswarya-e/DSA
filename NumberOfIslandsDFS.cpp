class Solution {
 private:
 void DFSIslands(vector<vector<int>>& visited,vector<vector<char>>& grid, int row, int col)
 {
     int m=grid.size();
     int n=grid[0].size();
     visited[row][col]=1;
     int dr[]={0,0,-1,1};
     int dc[]={-1,1,0,0};
     for(int i=0;i<4;i++)
     {
         int nr=row+dr[i];
         int nc=col+dc[i];
         if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]=='1' && visited[nr][nc]==0)
         {
             DFSIslands(visited,grid,nr,nc);
         }

     }
 }

public:
    int numIslands(vector<vector<char>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       vector<vector<int>> visited(m,vector<int>(n,0));
       int islands=0;
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(visited[i][j]==0 and grid[i][j]=='1')
               {
                   islands++;
                   DFSIslands(visited,grid,i,j);
               }
           }
       }
       return islands;

    }
};

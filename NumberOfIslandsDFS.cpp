class Solution {
 private:
    
 void BFS(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &grid)
 {
    vis[row][col]=1;
    queue<pair<int,int>> q;
    q.push({row,col});
    int maxr=grid.size();
    int maxc=grid[0].size();
    while(!q.empty())
    {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if((abs(i)==abs(j))) continue;
                int currrow=r+i;
                int currcol=c+j;
                if(currrow>=0 && currcol>=0 && currrow<maxr && currcol<maxc 
                && grid[currrow][currcol]=='1' && !vis[currrow][currcol])
                {
                    vis[currrow][currcol]=1;
                    q.push({currrow,currcol});
                }
            }
        }
            
    }
}
void DFS(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &grid)
{
    vis[row][col]=1;
    stack<pair<int,int>> q;
    q.push({row,col});
    int maxr=grid.size();
    int maxc=grid[0].size();
    while(!q.empty())
    {
        int r=q.top().first;
        int c=q.top().second;
        q.pop();
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if((abs(i)==abs(j))) continue;
                int currrow=r+i;
                int currcol=c+j;
                if(currrow>=0 && currcol>=0 && currrow<maxr && currcol<maxc 
                && grid[currrow][currcol]=='1' && !vis[currrow][currcol])
                {
                    vis[currrow][currcol]=1;
                    q.push({currrow,currcol});
                }
            }
        }
            
    }
}
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>> vis(row,vector<int>(col,0));
        int count=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    count++;
                    //BFS(i,j,vis,grid);
                    DFS(i,j,vis,grid);

                }
            }
        }
        return count;
    }
};

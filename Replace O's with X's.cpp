class Solution {
    void DFSXO(vector<vector<int>> &visited,vector<vector<char>> &board,int r,int c)
    {
        int m=board.size();
        int n=board[0].size();
        visited[r][c]=1;
        int dr[]={0,0,1,-1};
        int dc[]={1,-1,0,0};
        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nc>=0 && nr<m && nr<n && visited[nr][nc]==0 && board[nr][nc]=='O')
            {
                DFSXO(visited,board,nr,nc);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O' && visited[i][0]==0)
            {
                  DFSXO(visited,board,i,0);
            }
            if(board[i][n-1]=='O' && visited[i][n-1]==0)
            {
                DFSXO(visited,board,i,n-1);  
            }
        }
       
        for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O' && visited[0][i]==0)
            {
                DFSXO(visited,board,0,i);  
            }
            if(board[m-1][i]=='O' && visited[m-1][i]==0)
            {
                 DFSXO(visited,board,m-1,i);
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j]==0 && board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
    }
};

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
            if(nr>=0 && nc>=0 && nr<m && nc<n && visited[nr][nc]==0 && board[nr][nc]=='O')
            {
                DFSXO(visited,board,nr,nc);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {

        int m=board.size();
        int n=board[0].size();
        if(m==1 && n==1) return ;
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            if(visited[i][0]==0 && board[i][0]=='O' )
            {
                  DFSXO(visited,board,i,0);
            }
            if(visited[i][n-1]==0 && board[i][n-1]=='O' )
            {
                DFSXO(visited,board,i,n-1);  
            }
        }
       
        for(int j=0;j<n;j++)
        {
            if(visited[0][j]==0 && board[0][j]=='O' )
            {
                DFSXO(visited,board,0,j);  
            }
            if( visited[m-1][j]==0 && board[m-1][j]=='O')
            {
                 DFSXO(visited,board,m-1,j);
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

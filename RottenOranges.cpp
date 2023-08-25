class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int newtime=0;
        int cnt=0;
        int cntFresh=0;
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},newtime});
                    vis[i][j]=2;
                }
                if(grid[i][j]==1) cntFresh++;
            }
        }
        
        while(!q.empty())
        {
            int newi=q.front().first.first;
            int newj=q.front().first.second;
            newtime=q.front().second ;
            q.pop();
            for(int dr=-1;dr<=1;dr++)
            {
                for(int dc=-1;dc<=1;dc++)
                {
                    if(abs(dr)!=abs(dc)) {
                        int newrow=newi+dr;
                        int newcol=newj+dc;
                        if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && 
                        grid[newrow][newcol]==1 && vis[newrow][newcol]!=2)
                        {
                            vis[newrow][newcol]=2;
                            q.push({{newrow,newcol},newtime+1});
                            cnt++;
                        } 
                    };
                    
                }
            }
        }
        
        if(cnt!=cntFresh) return -1;
        return newtime;
    }
};

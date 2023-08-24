#include<bits/stdc++.h>
using namespace std;

class Solution {
 void DFSFloodFill(vector<vector<int>>& image,vector<vector<int>>& imageCopy,int sr,int sc,int newColour,int oldColour,int mr, int mc)
 {
     
     imageCopy[sr][sc]=newColour;
     for(int dr=-1;dr<=1;dr++)
     {
         for(int dc=-1;dc<=1;dc++)
         {
             if(abs(dc)==abs(dr)) continue;
             int nr=sr+dr;
             int nc=sc+dc;
             
             if(nr>=0 && nr<mr && nc>=0 && nc<mc &&
             imageCopy[nr][nc]!=newColour && image[nr][nc]==oldColour)
             {
                 DFSFloodFill(image,imageCopy,nr,nc,newColour,oldColour,mr,mc);
             }
         }
     }
     
 }
 void BFSFloodFill(vector<vector<int>>& image,vector<vector<int>>& imageCopy,int sr,int sc,
 int newColour,int oldColour,int mr, int mc)
 {
     imageCopy[sr][sc]=newColour;
     queue<pair<int,int>> q;
     q.push({sr,sc});
     while(!q.empty())
     {
        int nr1=q.front().first;
        int nc1=q.front().second;
        q.pop();
        for(int dr=-1;dr<=1;dr++)
        {
             for(int dc=-1;dc<=1;dc++)
             {
                 if(abs(dc)==abs(dr)) continue;
                 int nr=nr1+dr;
                 int nc=nc1+dc;
                 
                 if(nr>=0 && nr<mr && nc>=0 && nc<mc &&
                 imageCopy[nr][nc]!=newColour && image[nr][nc]==oldColour)
                 {
                     imageCopy[nr][nc]=newColour;
                     q.push({nr,nc});
                 }
             }
        }
     }

     
 }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector<vector<int>> imageCopy=image;
        
        BFSFloodFill(image,imageCopy,sr,sc,newColor,image[sr][sc],image.size(),image[0].size());
        return imageCopy;
        
        
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}


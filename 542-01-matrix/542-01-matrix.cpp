class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& g) {
        
        int n=g.size();
        int m=g[0].size();
        
        queue<vector<int>> q;
        
        vector<vector<int>> ans(n,vector<int>(m,1000000));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(g[i][j]==0)
                {
                    q.push({i,j,1});
                    ans[i][j]=0;
                }
            }
        }
        
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        
        while(!q.empty())
        {
            int l=q.size();
            
            while(l--)
            {
                auto p=q.front();
                q.pop();
                
                int i=p[0];
                int j=p[1];
                int c=p[2];
               // cout<<i<<" "<<j<<" "<<c<<endl;
                
                for(int k=0;k<4;k++)
                {
                    int x=i+dx[k];
                    int y=j+dy[k];
                    
                    if(x>=0 && x<n && y>=0 && y<m && ans[x][y]>c)
                    {
                        //cout<<1<<" ";
                        ans[x][y]=c;
                        q.push({x,y,c+1});
                    }
                }
            }
        }
        
        return ans;
    }
};
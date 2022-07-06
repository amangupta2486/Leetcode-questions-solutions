class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
       
        int n=g.size();
        int m=g[0].size();
        
        int rotten=0;
        int oranges=0;
        
        queue<vector<int>> q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(g[i][j]==2)
                {
                    q.push({i,j});
                }
                
                if(g[i][j]!=0)
                {
                    oranges++;
                }
            }
        }
        
        int days=0;
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
                
                rotten++;
                
                for(int k=0;k<4;k++)
                {
                    int x=i+dx[k];
                    int y=j+dy[k];
                    
                    if(x>=0 && x<n && y>=0 && y<m && g[x][y]==1)
                    {
                        g[x][y]=2;
                        q.push({x,y});
                    }
                }
            }
            
            if(q.size()!=0)
            {
                days++;
            }
        }
        
       // cout<<rotten<<" "<<oranges<<endl;
        
        return rotten==oranges ? days : -1;
    }
};
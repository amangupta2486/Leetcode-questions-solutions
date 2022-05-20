class Solution {
public:
    
    int solve(vector<int>& a)
    {
        int n=a.size();
        
        stack<int> s;
        int i=0;
        
        vector<int> l(n,0),r(n,0);
        
        while(i<n)
        {
            while(!s.empty() && a[s.top()]>=a[i])
            {
                s.pop();
            }
            
            if(s.empty())
            {
                l[i]=0;
            }
            else
            {
                l[i]=s.top()+1;
            }
            
            s.push(i);
            i++;
        }
        
        while(!s.empty())
        {
            s.pop();
        }
        
        i=n-1;
        
        int ans=0;
          
        while(i>=0)
        {
            while(!s.empty() && a[s.top()]>=a[i])
            {
                s.pop();
            }
            
            if(s.empty())
            {
                r[i]=n-1;
            }
            else
            {
                r[i]=s.top()-1;
            }
            
            ans=max(ans,(r[i]-l[i]+1)*a[i]);
            s.push(i);
            i--;
        }
        
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& g) {
        
        int n=g.size();
        int m=g[0].size();
        
        int ans=0;

        vector<vector<int>> d(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(g[i][j]=='1')
                {
                    d[i][j]=1;
                }
            }
        }
        
        ans=max(ans,solve(d[0]));
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(d[i][j]==1)
                {
                    d[i][j]+=d[i-1][j];
                }
                else
                {
                    d[i][j]=0;
                }
            }
            
            ans=max(ans,solve(d[i]));
        }
         
        
        return ans;
    }
};
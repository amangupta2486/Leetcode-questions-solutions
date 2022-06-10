class Solution {
public:
    
    int dp[1005][1005];
    
    int solve(string &a, string &b,int i,int j)
    {
        if(i==0 || j==0)
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(a[i-1]==b[j-1])
        {
            return dp[i][j]=1+solve(a,b,i-1,j-1);
        }
        
        return dp[i][j]=max(solve(a,b,i,j-1),solve(a,b,i-1,j));
    }
    
    int longestCommonSubsequence(string a, string b) {
        
        int n=a.size();
        int m=b.size();
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
        //return solve(a,b,n,m);
    }
};
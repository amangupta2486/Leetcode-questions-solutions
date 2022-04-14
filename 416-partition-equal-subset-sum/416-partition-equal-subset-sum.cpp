class Solution {
public:
    bool canPartition(vector<int>& a) {
        
        int n=a.size();
        int s=0;
        
        for(int i=0;i<n;i++)
        {
            s+=a[i];    
        }
        
        if(s%2!=0)
        {
            return 0;
        }
        
        else
        {
            s=s/2;
            
            bool dp[n+1][s+1];
            memset(dp,0,sizeof(dp));
            
            for(int j=0;j<n;j++)
            {
                dp[j][0]=1;
            }
            
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=s;j++)
                {
                    if(a[i-1]<=j)
                    {
                        dp[i][j]= dp[i-1][j-a[i-1]] || dp[i-1][j] ;
                    }
                    else
                    {
                        dp[i][j] =dp[i-1][j];
                    }
                }
            }
            
            return dp[n][s];
        }
    }
};
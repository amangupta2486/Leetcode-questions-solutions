class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        
        int n=a.size();
        
        sort(a.begin(),a.end());
        
        vector<vector<int>> ans;
        
        for(int i=0;i<n-2;i++)
        {
            int j=i+1,k=n-1;
            
            while(j<k)
            {
                int s=a[i]+a[j]+a[k];
                
                if(s<0)
                {
                    j++;
                }
                
                else if(s>0)
                {
                    k--;
                }
                
                else
                {
                    ans.push_back({a[i],a[j],a[k]});
                    
                    int x=a[j],y=a[k];
                    
                    while(j<k && x==a[j+1])
                    {
                        j++;
                    }
                    
                    while(j<k && y==a[k-1])
                    {
                        k--;
                    }
                    
                    j++;
                    k--;
                }
            }
            
            while(i+1<n && a[i]==a[i+1])
            {
                i++;
            }
        }
        
        return ans;
    }
};
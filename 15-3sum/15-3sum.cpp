class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        
        int n=a.size();
        vector<vector<int>> ans;
        
        sort(a.begin(),a.end());
        
        for(int i=0;i<n-2;i++)
        {
            int j=i+1,k=n-1;
            
            while(j<k)
            {
                int s=a[i]+a[j]+a[k];
                
                if(s>0)
                {
                    k--;
                }
                
                else if(s<0)
                {
                    j++;
                }
                
                else
                {
                    ans.push_back({a[i],a[j],a[k]});
                    int x=a[j];
                    int y=a[k];
                    
                    while(j+1<k && a[j+1]==x)
                    {
                        j++;
                    }
                    while(j<k-1 && a[k-1]==y)
                    {
                        k--;
                    }
                    
                    j++;
                    k--;
                }
            }
            
            while(i+1<n-2 && a[i+1]==a[i])
            {
                i++;
            }
        }
        
        return ans;
    }
};
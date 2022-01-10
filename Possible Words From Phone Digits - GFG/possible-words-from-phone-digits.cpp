// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    
    string key[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    vector<string> ans;
    void solve(int *a,int n,int i,string s)
    {
        if(i==n)
        {
            ans.push_back(s);
            return;
        }
        
        int k=a[i];
        string b=key[k];
        
        for(int j=0;j<b.size();j++)
        {
            solve(a,n,i+1,s+b[j]);
        }
    }
    vector<string> possibleWords(int a[], int n)
    {
        
        solve(a,n,0,"");
        
        return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends
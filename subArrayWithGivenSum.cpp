//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        vector<int> v;
        long long sum=0;
        int i=0;
        int j=0;
        
        while(i<n && j<n){
            sum += arr[j];
            
            if(sum == s){
                break;
            }
            
            if(sum > s){
                while(sum > s){
                    sum -= arr[i];
                    i++;
                }
            }
            
            if(sum == s){
                break;
            }
            
            j++;
        }
        
        if(i<n && j<n && i<=j){
            v.push_back(i+1);
            v.push_back(j+1);
            return v;
        }
        
        vector<int> out = {-1};
        
        return out;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *a, int n, int k)
    {
        // your code here
        
        int i=0;
        int j=0;
        int m=a[0];
        vector<int> ans;
        
        while(j<n){
            if(j<k-1){
                if(a[j]>m){
                    m=a[j];
                }
                j++;
            }else if(j==k-1){
                if(a[j]>m){
                    m=a[j];
                }
                ans.push_back(m);
                i++;
                j++;
            }else{
                if(a[i-1]==m){
                    m=0;
                    for(int t=i;t<=j;t++){
                        m=max(m,a[t]);
                    }
                }
                if(a[j]>m){
                    m=a[j];
                }
                ans.push_back(m);
                i++;
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int a[], int n)
	{
	    // Your code goes here
	    
	    int ans = 0;
	    
	    int m=0;
	    
	    for(int i=0;i<n;i++){
	        if(a[i] > m){
	            m=a[i];
	        }
	    }
	    
	    int freq[m+1]={0};
	    
	    for(int i=0;i<n;i++){
	        freq[a[i]]++;
	    }
	    
	    for(int i=0;i<n;i++){
	        for(int j=i+1;j<n;j++){
	            int sum=a[i]+a[j];
	            if(sum <= m){
    	            if((freq[a[i]] != 0) && (freq[a[j]] != 0) && (freq[sum] != 0)){
    	                ans++;
    	            }
	            }
	        }
	    }
	    
	    return ans;
	    
	}
};

//{ Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}
// } Driver Code Ends
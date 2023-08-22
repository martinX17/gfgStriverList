//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	bool binarySearch(int a[], int key, int n){
	    
	    int start=0;
	    int end=n-1;
	    
	    while(start<=end){
	        int mid=(start+end)/2;
	        if(a[mid] == key){
	            return true;
	        }else if(key < a[mid]){
	            end = mid-1;
	        }else{
	            start = mid+1;
	        }
	    }
	    
	    return false;
	}
	
	int findSwapValues(int a[], int n, int b[], int m)
	{
        sort(a,a+n);
        sort(b,b+m);
        
        int suma=0;
        int sumb=0;
        
        for(int i=0;i<n;i++){
            suma += a[i];
        }
        for(int i=0;i<m;i++){
            sumb += b[i];
        }

        // cout<<suma<<endl;
        // cout<<sumb<<endl;
        
        if((suma+sumb)%2 == 1) return -1;
        int avgsum = (suma+sumb)/2;
        // cout<<avgsum<<endl;
        int diff=avgsum-min(suma,sumb);
        // cout<<diff<<endl;
        
        for(int i=0;i<n;i++){
            if(binarySearch(b,a[i]+diff,m) || binarySearch(b,a[i]-diff,m)){
                return 1;
            }
        }
        
        return -1;
	}
 

};

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends
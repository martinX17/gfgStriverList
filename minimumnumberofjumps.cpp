//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        
        int count=0;
        int i=0;
        
        while(i<=n-1){
            if(arr[i] == 0){
                return -1;
            }else if(arr[i] == 1){
                if(i+arr[i]>=n-1){
                    return count+1;
                }
                i++;
                count++;
            }else{
                
                if(i+arr[i]>=n-1){
                    return count+1;
                }
                
                int tmp;
                int sum=i;
                
                for(int t=1;t<=arr[i];t++){
                    int p=i+t;
                    if(sum<p+arr[p]){
                        sum=p+arr[p];
                        tmp=t;
                        if(sum>=n-1){
                            count += 2;
                            return count;
                        }
                    }
                }
                i=i+tmp;
                count++;
            }
        }
        if(i>=n-1){
            return count;
        }else{
            return -1;
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
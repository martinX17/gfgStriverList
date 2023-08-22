//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> a, int n){
        // code here
        vector<vector<int>> ans;
        
        int m=0;
        int start=0;
        int end=0;
        
        for(int i=0;i<n;i++){
            if(i==0 && m==0 &&a[i]<=a[i+1]){
                start=0;
                m=1;
            }else if(i==n-1 && m==1 && a[i]>=a[i-1]){
                end=i;
                ans.push_back({start,end});
                m=0;
            }else{
                if(m==0){
                    if(a[i]<=a[i-1] && a[i]<=a[i+1]){
                        start=i;
                        m=1;
                    }
                }else{
                    if(a[i]>=a[i-1] && a[i]>=a[i+1]){
                        end=i;
                        ans.push_back({start,end});
                        m=0;
                    }
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}


// } Driver Code Ends
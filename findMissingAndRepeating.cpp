//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> a, int n) {
        // code here
        
        vector<int> out;
        int check[n+1]={0};
        
        for(int i=0;i<n;i++){
            if(check[a[i]] == 1){
                out.push_back(a[i]);
            }
            check[a[i]]=1;
        }
        
        for(int i=1;i<=n;i++){
            if(check[i] == 0){
                out.push_back(i);
                break;
            }
        }
        
        return out;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
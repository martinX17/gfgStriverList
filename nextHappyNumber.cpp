//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:

    int find(int n){
        // 1 and 7 always gives happy number
        if(n == 1 || n == 7){
            return 1;
        }
        
        int sum = n, curr = n;
        
        // if sum is single digit number break
        while(sum > 9){
            sum = 0;
            
            // calculate sum of square of numners 
            while(curr > 0){
                int tmp = curr % 10;
                sum += tmp*tmp;
                curr = curr / 10;
            }
            
            // if sum is 1 for numbers more than 9
            if(sum == 1){
                return 1;
            }
            
            curr = sum;
        }
        
        //checks if the single digit number is 7
        if(sum == 7){
            return 1;
        }
        
        return 0;
    }
    
    int nextHappy(int n){
        // code here
        
        int ans = n+1;
        
        while(1){
            if(find(ans) == 1){
                return ans;
            }
            ans++;
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
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
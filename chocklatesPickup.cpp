//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int f(int i, int j1, int j2, int n, int m, vector < vector < int >> & grid, vector < vector < vector < int >>> & dp){
        
        if(j1<0 || j2<0 || j1>=m || j2>=m) return -1e8;
    
        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        
        int maxi=-1e8;
        for(int dj1=-1; dj1<=+1; dj1++){
            for(int dj2=-1; dj2<=+1; dj2++){
                int value=0;
                if(j1==j2) value= grid[i][j1];
                else value= grid[i][j1]+grid[i][j2];
                value+= f(i+1, j1+dj1, j2+dj2, n, m, grid, dp);
                maxi= max(maxi, value);
            }
        }
        
        return dp[i][j1][j2]=maxi;
    }
    
    int solve(int n, int m, vector<vector<int>>& grid) {
        
        vector<vector<vector <int>>>dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return f(0, 0, m-1, n, m, grid, dp);
        
        // code here
        // int robo1 = 0;
        // int robo2 = 0;
        
        // int i=0;
        // int r1i=0,r1j=0,r2i=0,r2j=m-1;
        // robo1 += grid[r1i][r1j];
        // grid[r1i][r1j] = 0;
        // robo2 += grid[r2i][r2j];
        // grid[r2i][r2j] = 0;
        
        // while(r1i<n && r2i<n && r1j<m && r2j<m && i+1<n){
            
        //     int next_row = i+1;
            
        //     if((r1j+1 == r2j-1) || ((r2j+1 == r1j-1))){
                
                
                
        //     }else if((r2j-1 < r1j+1) && (r1j < r2j)){
                
                
                
        //     }else if((r2j+1 > r1j-1) && (r1j > r2j)){
                
                
                
        //     }else{
        //         int tmp1 = 0;
        //         int next1,next2;
        //         int tmp2 = 0;
                
        //         for(int k=-1;k<=1;k++){
        //             if((r1j+k < m) && (r1j+k >= 0)){
        //                 if(grid[next_row][r1j+k] > tmp1){
        //                     next1 = r1j+k;
        //                     tmp1 = grid[next_row][r1j+k];
        //                 }    
        //             }
        //             if((r1j+k < m) && (r1j+k >= 0)){
        //                 if(grid[next_row][r2j+k] > tmp2){
        //                     next2 = r2j+k;
        //                     tmp2 = grid[next_row][r2j+k];
        //                 }
        //             }
        //         }
                
        //         r1i = next_row;
        //         r1j = next1;
                
        //         r2i = next_row;
        //         r2j = next2;
            
        //     }
            
        //     robo1 += grid[r1i][r1j];
        //     grid[r1i][r1j] = 0;
        //     robo2 += grid[r2i][r2j];
        //     grid[r2i][r2j] = 0;
            
        //     i++;
        // }
        
        // return robo1+robo2;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends
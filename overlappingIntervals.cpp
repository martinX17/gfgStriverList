//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& a) {
         // Code here
         
         sort(a.begin(),a.end());
         
         vector<vector <int>> out;
         
         int start = a[0][0];
         int end = a[0][1];
         
         for(int i=1;i<a.size();i++){
            if(a[i][0] <= end && a[i][1] <= end){
                continue;
            }else if(a[i][0] <= end){
                end = max(end,a[i][1]);
            }else{
                vector<int> push = {start,end};
                out.push_back(push);
                start=a[i][0];
                end=a[i][1];
            }
         }
         
         vector<int> p = {start,end};
         out.push_back(p);
         
         return out;
         
         
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
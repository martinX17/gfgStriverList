class Solution {
public:

    void solve(vector<int>& candidates, int target, set<vector<int>>& dp, vector<int> tmp, int sum, int index){
        if(sum>=target || index>=candidates.size()){
            if(sum==target){
                sort(tmp.begin(),tmp.end());
                dp.insert(tmp);
            }
            return;
        }
        tmp.push_back(candidates[index]);
        solve(candidates,target,dp,tmp,sum+candidates[index],index);
        solve(candidates,target,dp,tmp,sum+candidates[index],index+1);
        tmp.pop_back();
        solve(candidates,target,dp,tmp,sum,index+1);
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> dp;
        vector<int> tmp;
        vector<vector<int>> ans;

        solve(candidates,target,dp,tmp,0,0);

        for(auto& ele:dp){
            ans.push_back(ele);
        }

        return ans;
    }
};
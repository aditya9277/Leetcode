class Solution {
public:
    void f(vector<int>& arr, vector<vector<int>>& res, vector<int>& temp, int idx, int target){
        if(idx == arr.size()){
            if(target==0){
                res.push_back(temp);
            }
            return;
        }

        if(arr[idx] <= target){
            temp.push_back(arr[idx]);
            f(arr, res, temp, idx, target-arr[idx]);
            temp.pop_back();
        }
        
        f(arr, res, temp, idx + 1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        vector<vector<int>> res;
        vector<int> temp;
        f(candidates, res, temp, 0, target);
        return res;
    }
};

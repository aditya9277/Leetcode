class Solution {
public:
    void combination(int idx,vector<int>& arr, int target, vector<int> &ds,vector<vector<int>> &res){
        if(idx==arr.size()){
            if(target==0){
                res.push_back(ds);
            }
            return; 
        }
        if(arr[idx]<=target){
            ds.push_back(arr[idx]);
            combination(idx,arr,target-arr[idx],ds,res);
            ds.pop_back();
        }
        combination(idx+1,arr,target,ds,res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> res;
        
        combination(0,candidates,target,ds,res);
        return res;
        
    }
};
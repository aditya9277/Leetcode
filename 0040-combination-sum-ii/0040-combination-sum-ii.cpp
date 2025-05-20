class Solution {
public:
    void f(vector<int>& arr, vector<vector<int>>& res, vector<int>& temp, int idx, int target){
       
            if(target==0){
                res.push_back(temp);
                return;
            }

        for(int i=idx;i<arr.size();i++){
            if(i>idx && arr[i]==arr[i-1]) continue;
            if(arr[i]<=target){
                temp.push_back(arr[i]);
                f(arr, res, temp, i+1, target-arr[i]);
                temp.pop_back();
            }
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());

        f(candidates,res, temp, 0, target);

        return res;
        
    }
};
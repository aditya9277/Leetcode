class Solution {
public:
    unordered_set<int> st;
    void solve(vector<int>&arr, vector<int> temp, vector<vector<int>> &res, int n){
        if(temp.size()==n){
            res.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            if(st.find(arr[i])==st.end()){
                temp.push_back(arr[i]);
                st.insert(arr[i]);
                solve(arr, temp, res, n);
                temp.pop_back();
                st.erase(arr[i]);
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        vector<vector<int>> res;
        vector<int> temp;
        int n = nums.size();

        solve(nums, temp, res, n);
        return res;


        
    }
};
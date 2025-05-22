class Solution {
public:
    vector<vector<int>> res;
    int n;

    void solve(unordered_map<int,int> &mp, vector<int> &temp){
        if(temp.size()==n){
            res.push_back(temp);
            return;
        }
        for(auto& [num,count] : mp){
            if(count==0) continue;

            //do something
            temp.push_back(num);
            mp[num]--;
            //explore it
            solve(mp, temp);
            //undo it
            temp.pop_back();
            mp[num]++;

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        unordered_map<int,int> mp;
        vector<int> temp;

        for(auto& num:nums){
            mp[num]++;
        }

        solve(mp, temp);

        return res;

        
    }
};
class Solution {
public:
    vector<vector<int>> result;

    void f(int i,vector<int> nums, vector<int> temp ){
        if(i>=nums.size()){
            result.push_back(temp);
            return;
        }

        //pick
        temp.push_back(nums[i]);
        f(i+1, nums, temp);

        //reset back
        temp.pop_back();
        //not pick
        f(i+1, nums,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        f(0, nums, temp);
        return result;
        
    }
};
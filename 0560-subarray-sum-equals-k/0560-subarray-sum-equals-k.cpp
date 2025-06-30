class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //solving through prefix sum
        unordered_map<int, int> mp; // to track the cumulative cum along with its count
        int res = 0;
        int cumsum=0;
        mp.insert({0,1}); //initially cumulative sum was zero, co counting that also as 1

        for(int i=0;i<nums.size();i++){
            cumsum+=nums[i];

            if(mp.find(cumsum-k)!=mp.end()){
                res+=mp[cumsum-k];                
            }
            mp[cumsum]++;
        }

        return res;
    }
};
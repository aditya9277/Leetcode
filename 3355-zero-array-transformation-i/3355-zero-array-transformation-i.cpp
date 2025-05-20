class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        int n= nums.size();
        vector<int> diff(n,0);

        //step 1 make difference array
        for(auto &query : queries){
            int start = query[0];
            int end = query[1];
            int x=1;
            diff[start] +=x;

            if(end+1<n){
                diff[end+1]-=x;
            }
        }
        
        //step 2 compute cumulative sum

        vector<int> result(n,0);
        int cumsum=0;

        for(int i=0;i<n;i++){
            cumsum+=diff[i];
            result[i]=cumsum;
        }

        //step 3 final check acc to question

        for(int i=0;i<n;i++){
            if(result[i]<nums[i]) return false;
        }

        return true;

    }
};
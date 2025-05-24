class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m=spells.size();
        int n=potions.size();

        int i=0, cnt=0;
        vector<int> ans;
        sort(begin(potions), end(potions));
        while(i<m){
            cnt=0;
            int l=0, r=n-1;
            while(l<=r){
                int mid = l+(r-l)/2; 
                if((long long)spells[i]*potions[mid]>=success){
                    cnt+=r-mid+1;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            ans.push_back(cnt);
            i++;
        }

        return ans;
        
        
    }
};
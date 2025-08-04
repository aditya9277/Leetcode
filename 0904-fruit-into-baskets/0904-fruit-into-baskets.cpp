class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        unordered_map<int, int> mp;
        int n=fruits.size();
        int l=0,r=0;
        int maxf=0;
        while(r<n){
            mp[fruits[r]]++;

            if(mp.size()>2 ){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;
            }

            maxf=max(maxf,r-l+1);
            r++;
        }
        return maxf;
        
    }
};
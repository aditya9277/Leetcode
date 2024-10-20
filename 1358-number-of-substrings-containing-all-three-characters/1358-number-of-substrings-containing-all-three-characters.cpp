class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0,ct=0;
        unordered_map<char,int> mp;

        while(r<s.length()){
            mp[s[r]]++;
            while(mp['a']>=1 && mp['b']>=1&& mp['c']>=1){
                ct += (s.length() - r);
                
                mp[s[l]]--;
                if (mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            r++;
        }

        return ct;
        
    }
};
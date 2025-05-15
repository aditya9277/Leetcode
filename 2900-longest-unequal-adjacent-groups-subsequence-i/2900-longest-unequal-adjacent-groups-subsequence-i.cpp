class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

        int n = words.size();
        vector<string> ans;

        for(int i=0;i<n;i++){
            if(i==0 || groups[i]!=groups[i-1]){
                ans.push_back(words[i]);
            }
        }

        return ans;
        
    }
};
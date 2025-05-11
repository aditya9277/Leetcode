class Solution {
public:
    int minDeletion(string s, int k) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        unordered_map<char,int> mp;

        for(auto &ch:s){
            mp[ch]++;
        }
        int dist = mp.size();

        if(dist<=k) return 0;

        vector<int> count;

        for(auto &pair:mp){
            count.push_back(pair.second);
        }
        sort(count.begin(),count.end());

        int del = dist-k;
        int ans=0;

        for(int i=0;i<del;i++){
            ans+=count[i];
        }

        return ans;
    }
};
class Solution {
public:
    int M = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        vector<int> mp(26,0);

        for(auto &ch: s){
            mp[ch -'a']++;
        }

        while(t--){
            vector<int> temp(26,0);

            for(int i=0;i<26;i++){
                char ch=i+'a';
                int freq = mp[i];

                if(ch!='z'){
                    temp[(ch+1)-'a']=(temp[(ch+1)-'a'] + freq)%M;
                }
                else{
                    temp['a'-'a'] = (temp['a'-'a']+ freq)%M;
                    temp['b'-'a'] = (temp['b'-'a']+ freq)%M;
                }
            }
            mp=temp;
        }

        int result=0;
        for(int i=0;i<26;i++){
            result=(result + mp[i])%M;
        }
        return result;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maxlen=0;
        //brute approach
        // for(int i=0;i<s.length();i++){
        //     int hash[256]={0};
        //     for(int j=i;j<s.length();j++){
        //         if(hash[s[j]]==1) break;
        //         maxlen=max(maxlen, j-i+1);
        //         hash[s[j]]=1;
        //     }
        // }
        // return maxlen;

        //better
        int hash[256]={0};
        while(r<s.length()){
            if(hash[s[r]]==1){
                hash[s[l]]=0;
                l++;
            }
            else{
                hash[s[r]]=1;
                maxlen=max(maxlen,r-l+1);
                r++;

            }

        }
        return maxlen;

        

        

        

        
    }
};
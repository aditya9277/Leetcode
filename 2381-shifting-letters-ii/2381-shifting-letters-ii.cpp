class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<int> diff(n+1,0);  //n+1 to avoid out of bound while line sweep

        for(auto &query : shifts){
            int left=query[0];
            int right=query[1];
            int dir=query[2];
            int x =(dir==0)?-1:1;
            //line sweep / difference array
            diff[left]+=x;
            diff[right+1]-=x;
        }
        for(int i=1;i<n;i++){
            diff[i]+=diff[i-1];
        }

        for(int i=0;i<n;i++){
            int shift = diff[i]%26;  //wrap around
            if(shift<0) shift+=26;    //wrap around if value if less than 0 , we have to make it in range [0,25];

            s[i]= ((s[i]-'a')+shift)%26+'a';   //(s[i]-'a' to get character value, %26 again to wrap around, +'a' to convert it back to character
        }

        return s;
        
    }
};
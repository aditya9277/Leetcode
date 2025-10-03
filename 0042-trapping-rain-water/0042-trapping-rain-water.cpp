class Solution {
public:
    int trap(vector<int>& ht) {
        int n = ht.size();
        int l=0, r=n-1, lmax= 0, rmax= 0, ans=0;

        while(l<r){
            lmax = max(lmax, ht[l]);
            rmax = max(rmax, ht[r]);

            if(lmax<=rmax){
                ans+= lmax - ht[l];
                l++;
            }
            else{
                ans+= rmax - ht[r];
                r--;
            }
        }

        return ans;
        
    }
};
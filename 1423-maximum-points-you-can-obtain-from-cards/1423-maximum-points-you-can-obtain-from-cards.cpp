class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int lsum=0,rsum=0,maxsum=0;

        for(int i=0;i<k;i++){
            lsum+=cp[i];
        }
        int index=cp.size()-1;
        maxsum=lsum;

        int r=index;
        for(int i=k-1;i>=0;i--){
            lsum-=cp[i];
            rsum+=cp[r];
            r--;

            maxsum=max(maxsum,lsum+rsum);
        }
        return maxsum;

        // while(i<k){
        //     lsum-=cp[k-i-1];
        //     rsum+=cp[index];
        //     index--;
        //     maxsum=max(lsum+rsum,maxsum);
        //     i++;
        // }
        // return maxsum;
        
    }
};
class Solution {
public:
    int count(vector<int>& bloomDay, int mid, int k ){
        int cnt=0, bq =0;
        for(int i : bloomDay){
            if(i<=mid){
                cnt++;
                if(cnt>=k){
                    bq++;
                    cnt=0;
                }
            }
            else cnt=0;
        }
        return bq;


    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) return -1; //i failed here, because i didnt check first, that is it even possible to make bouquets, we have enough flowers or not
        //if m*k exceeds the number of flowers, we can return -1;
        int l=1;
        int r=*max_element(begin(bloomDay),end(bloomDay));

        while(l<r){
            int mid = l +(r-l)/2;

            if(count(bloomDay,mid,k)>=m){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
        
    }
};
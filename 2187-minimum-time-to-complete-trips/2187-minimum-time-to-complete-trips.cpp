class Solution {
public:
    long long count(vector<int>& time, long long mid){
        long long cnt=0;

        for(long long t:time) cnt+=mid/t;
        return cnt;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {

        long long n = time.size();

        long long l=1, r=1e14;

        while(l<r){
            long long mid = l+(r-l)/2;

            if(count(time, mid)<totalTrips) l=mid+1;
            else{
                r=mid;
            }
        }
        return r;
        
    }
};
class Solution {
public:
    int countDays(vector<int>& weights, int mid){
    int cnt = 0;
    int dayCount = 1;  // at least one day is needed

    for(int i : weights){
        if(cnt + i <= mid){
            cnt += i;
        } else {     
            dayCount++;
            cnt = i; // start a new day with the current weight
        }
    }
    return dayCount;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(begin(weights),end(weights));
        int r=accumulate(weights.begin(),weights.end(),0);
        int ans=0;
        while(l<r){
            int mid = l+(r-l)/2;

            if(countDays(weights, mid)<=days){
          
                r=mid;
            }
            else l=mid+1;
        }

        return r;

        
        
    }
};
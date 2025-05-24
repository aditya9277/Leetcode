class Solution {
public:
    int canEat(vector<int>& piles, int mid){
        int hours=0;
        for(int i:piles){
            hours +=i/mid;
            if(i%mid!=0) hours++;
        }
        return hours; 
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1;
        int r = *max_element(begin(piles),end(piles));

        while(l<r){
            int mid=l+(r-l)/2;

            if(canEat(piles, mid)>h) l=mid+1;
            else r=mid;
        }

        return r;
        
    }
};
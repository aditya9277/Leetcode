class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        if(arr.size()<3) return false;

        for(int i=0;i<arr.size()-2;i++){
            if(arr[i] & 1 && arr[i+1]&1 && arr[i+2]&1) return true;
        }
        return false;
    }
};
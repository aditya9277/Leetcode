class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> arr(10, 0);
        int x=n;
        while(x){
            int digit = x%10;
            arr[digit]++;
            x/=10;
        }

        int mini = INT_MAX;
        int ans = -1;

        for(int d=0;d<10;d++){
            if(arr[d]>0 && arr[d]<mini){
                mini = arr[d];
                ans = d;
            }
        }

        return ans;
        
    }
};
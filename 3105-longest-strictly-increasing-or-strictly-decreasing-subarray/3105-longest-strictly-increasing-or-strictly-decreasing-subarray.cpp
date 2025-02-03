class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        int maxlen=1, incL=1, decL=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]<arr[i-1]){
                incL++;
                decL=1;
            }
            else if(arr[i]>arr[i-1]){
                decL++;
                incL=1;
            }
            else{
                incL=1;
                decL=1;
            }
        }
        maxlen=max(incL,decL);
        return maxlen;
        
    }
};
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> ans(n,0);

        int cumulativesum=0;
        int cumulativevaluesum=0;

        for(int i=0;i<n;i++){
            ans[i]=cumulativevaluesum;

            cumulativesum+=boxes[i]=='0'?0:1;

            cumulativevaluesum+=cumulativesum;
        }

        cumulativesum=0;
        cumulativevaluesum=0;

        for(int i=n-1;i>=0;i--){
            ans[i]+=cumulativevaluesum;

            cumulativesum+=boxes[i]=='0'?0:1;

            cumulativevaluesum+=cumulativesum;
        }

        return ans;
        
        
    }
};
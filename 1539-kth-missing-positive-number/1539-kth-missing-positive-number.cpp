class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int l=0;
        int r=arr.size()-1;

        while(l<=r){
            int mid = l+(r-l)/2;

            int cnt_of_missing_no = arr[mid] - (mid+1);

            if(cnt_of_missing_no<k) l=mid+1;
            else{
                r=mid-1;
            }
        }

        //we did l+k to find that number, after bs - our l is already pointing where the count of missing numbers is greater than or equal to k.
        //So the total of l existing numbers + k missing numbers gives us the k-th missing number.

        //l counts how far you've gone in real numbers, and k tells you how far you still need to go in missing numbers.




        return l+k;
        
    }
};
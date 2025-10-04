class Solution {
public:
    bool check(string s1, string s2){
        int arr[26]={0};

        for(char& ch : s1){
            if( arr[ch - 'a'] > 0) return true;
            arr[ch - 'a']++;
        }

        for(char& ch : s2){
            if( arr[ch - 'a'] > 0) return true;
            arr[ch - 'a']++;
        }

        return false;
    }
    int solve(int i, int n, string temp, vector<string> &arr){
        if(i>=n) return temp.size();

        int include = 0;
        int exclude = 0;

        if(check(temp, arr[i])){
            exclude = solve(i+1, n, temp, arr);
        } else{
            exclude = solve(i+1, n, temp, arr);
            include = solve(i+1, n, temp+arr[i], arr);
        }


        return max(include, exclude);
    }
    int maxLength(vector<string>& arr) {
        string temp = "";
        int n = arr.size();

        return solve(0, n,  temp, arr);
        
    }
};
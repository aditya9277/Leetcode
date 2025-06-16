class Solution {
public:
    bool isHappy(int n) {

        while(n>1){

            n = count(n);
            if(n==4) return false;
        }

        return true;
    }

    int count(int n){
        int total = 0;
        for(char c  : to_string(n)){
            total += (c-'0')*(c-'0');
        }
        return total;
    }
};
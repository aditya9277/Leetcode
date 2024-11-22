#include<bits/stdc++.h>

using namespace std;

class Solution {

    double powR(double x, long long n, double ans)
{
    if (n <= 0)
    {
        return ans;
    }
    if (n % 2 && n!=2)
    {
    
        --n;
        ans = ans * x;
        
    }
    else
    {
       
        x = x * x;
        n = n / 2;
       
    }
    return powR(x, n, ans);
}

public:
    double myPow(double x, int n) {

        long long nn = abs(n);
        double res = powR(x,nn,1);

        if(n<0)
        {
            return 1/res;
        }
        return res;
    }
};
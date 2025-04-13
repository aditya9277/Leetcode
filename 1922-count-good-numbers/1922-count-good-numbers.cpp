class Solution {

public:
    const int M = 1e9 + 7;
    long long findPower(int a, int b) {

        if (b == 0)
            return 1;
        long long half = findPower(a, b / 2);
        long long res = (half * half) % M;
        if (b % 2 == 1) {
            res = (res * a) % M;
        }
        return res;
    }
    int countGoodNumbers(long long n) {

        int evenIdx = (n + 1) / 2;
        int oddIdx = n / 2;

        return (long long)findPower(5, evenIdx) * findPower(4, oddIdx) %M;
    }
};
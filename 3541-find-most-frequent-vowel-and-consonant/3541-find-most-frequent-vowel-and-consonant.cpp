class Solution {
public:
    int maxFreqSum(string s) {
            
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        int maxVowelFreq = 0;
        int maxConsonantFreq = 0;

        for (int i = 0; i < 26; ++i) {
            if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20) { // a, e, i, o, u
                maxVowelFreq = max(maxVowelFreq, freq[i]);
            } else {
                maxConsonantFreq = max(maxConsonantFreq, freq[i]);
            }
        }

        return maxVowelFreq + maxConsonantFreq;
    }
};

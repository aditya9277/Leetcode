class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        unordered_set<string> seen;
        int n = words.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (words[j].find(words[i]) != string::npos) {
                    if (seen.find(words[i]) == seen.end()) {
                        ans.push_back(words[i]);
                        seen.insert(words[i]);
                    }
                    break;  // No need to check further once a match is found
                }
            }
        }
        return ans;
    }
};

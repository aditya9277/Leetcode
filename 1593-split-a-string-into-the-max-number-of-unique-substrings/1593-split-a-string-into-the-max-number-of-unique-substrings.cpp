class Solution {
public:
    unordered_set<string> st;
    int result = 0;
    
    void solve(string &s, int idx) {
        if (idx == s.size()) {
     
            result = max(result, (int)st.size());
            return;
        }

        string temp = "";
        
        for (int i = idx; i < s.size(); i++) {
            temp += s[i];
        
            if (!st.count(temp)) {
                st.insert(temp); 
                solve(s, i + 1);  
                st.erase(temp);   
            }
        }
    }

    int maxUniqueSplit(string s) {
        solve(s, 0);
        return result;
    }
};
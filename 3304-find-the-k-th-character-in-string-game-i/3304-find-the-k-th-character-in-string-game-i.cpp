class Solution {
public:
    char kthCharacter(int k) {
        string curr = "a"; 
        int len = curr.size();

        while (len < k) {
            string temp = "";
            for (char ch : curr) {
                
                temp.push_back(ch == 'z' ? 'a' : ch + 1);
            }
            curr += temp; 
            len = curr.size();
        }
        return curr[k - 1];
    }
};
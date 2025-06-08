class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i=0;i<words.size();i++){
            for(char p:words[i]){
                if(p==x){
                    ans.push_back(i);
                    break;
                } 
            }  
        }
        // ans.erase(unique(ans.begin(),ans.end()), ans.end());
        return ans;
        
    }
};
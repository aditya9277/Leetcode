class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        // Split the sentence into words
        istringstream stream(sentence);
        string word;
        int index = 1; 
        
        while (stream >> word) {
          
            if (word.find(searchWord) == 0) {
                return index;
            }
            index++;
        }
        
      
        return -1;
    }
};
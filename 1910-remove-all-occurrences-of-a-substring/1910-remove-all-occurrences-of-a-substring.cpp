class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pl=part.length();
        while(s.find(part)!=string::npos){
            int x=s.find(part);
            s.erase(x,pl);
        }
        // while( s.find(part)<s.length()){
        //     s.erase(s.find(part),part.length());
            
        // }
        return s;   
    }
};
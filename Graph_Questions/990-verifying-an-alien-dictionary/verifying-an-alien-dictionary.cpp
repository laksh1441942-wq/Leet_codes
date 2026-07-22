class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        for(int i=0; i<n-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.size(), s2.size());
            for(int ptr=0; ptr<len; ptr++){
                if(s1[ptr] != s2[ptr]){
                    if(order.find(s1[ptr]) > order.find(s2[ptr])) return false;
                    break;
                }
            }
            if(s1.size() > s2.size() && s1.substr(0, len)==s2){
                return false;
            }
        }
        return true;
    }
};
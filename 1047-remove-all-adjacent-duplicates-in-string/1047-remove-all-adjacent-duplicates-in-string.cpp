class Solution {
public:
    string removeDuplicates(string s) {
        int i = 0;
        for(auto curChar: s){
            if(i>0 && s[i-1] == curChar) i--;
            else s[i++] = curChar;
        }
        return s.substr(0,i);
    }
};
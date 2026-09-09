class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int len = 0;
        int i = n-1;
        while(i>=0){
            if(s[i]!=' '){
                len++;
                break;
            }
            i--;
        }
        while(i--){
            if(s[i] == ' ') return len;
            len++;
        }
        return len;
    }
};
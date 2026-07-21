class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.length(), m = t.length();
        int i = n-1, j = m-1;
        int skipt = 0, skips = 0;
        while(i>=0 || j>=0){
            while(i>=0){
                if(s[i]=='#'){
                    skips++;
                    i--;
                }
                else if(skips>0){
                    skips--;
                    i--;
                }
                else break;
            }
            while(j>=0){
                if(t[j]=='#'){
                    skipt++;
                    j--;
                }
                else if(skipt>0){
                    skipt--;
                    j--;
                }
                else break;
            }
            char ch1 = i<0?'$':s[i];
            char ch2 = j<0?'$':t[j];
            if(ch1!=ch2) return false;
            i--;
            j--;
        }
        return true;
    }
};
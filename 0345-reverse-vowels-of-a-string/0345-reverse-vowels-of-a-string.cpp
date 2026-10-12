class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
        if(n<=1) return s;
        int i=0, j=n-1;
        while(i<j){
            bool vowelI = false, vowelJ = false;
            while(i<n && i<j){
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'|| 
                   s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                    vowelI = true;
                    break;
                }
                i++;
            }
            while(j>=0 && i<j){
                if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || 
                   s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U'){
                    vowelJ = true;
                    break;
                }
                j--;
            }
            if(vowelI && vowelJ){
                swap(s[i], s[j]);
                i++,j--;
            }
        }
        return s;
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length(), m = t.length();
        vector<int> freqS(128,0), freqT(128,0);
        for(int i=0; i<n; i++){
            freqS[s[i]]++;
        }
        for(int i=0; i<m; i++){
            freqT[t[i]]++;
        }
        for(int i=0; i<128; i++){
            if(freqS[i] != freqT[i]) return false;
        }
        return true;
    }
};
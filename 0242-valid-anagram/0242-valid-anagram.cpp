class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length(), m = t.length();
        vector<int> freq(128,0);
        for(int i=0; i<n; i++){
            freq[s[i]]++;
        }
        for(int i=0; i<m; i++){
            freq[t[i]]--;
        }
        for(int i=0; i<128; i++){
            if(freq[i] != 0) return false;
        }
        return true;
    }
};
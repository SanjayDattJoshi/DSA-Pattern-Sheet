class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.length(), m = magazine.length();
        unordered_map<char, int> mpp1, mpp2;
        for(int i=0; i<n; i++){
            mpp1[ransomNote[i]]++;
        }
        for(int i=0; i<m; i++){
            mpp2[magazine[i]]++;
        }
        for(auto it: mpp1){
            if(mpp2.find(it.first) == mpp2.end() || it.second > mpp2[it.first]) return false;
        }
        return true;
    }
};
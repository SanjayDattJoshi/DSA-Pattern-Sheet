class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        map<char, int>mpp;
        int low=0,high,lar=0;

        for(high=0; high<n; high++){
            mpp[s[high]]++;
            while(mpp.size()<high-low+1){
                mpp[s[low]]--;
                if(mpp[s[low]] == 0) mpp.erase(s[low]);
                low++;
            }
            lar = max(lar, high-low+1);
        }
        return lar;
    }
};
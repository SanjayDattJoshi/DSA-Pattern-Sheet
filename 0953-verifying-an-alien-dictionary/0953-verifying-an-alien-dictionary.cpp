class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
                vector<int> rank(26);

        for(int i = 0; i < 26; i++) {
            rank[order[i] - 'a'] = i;
        }

        for(int i = 0; i < words.size() - 1; i++) {
            
            string a = words[i];
            string b = words[i + 1];

            int j = 0;

            while(j < a.size() && j < b.size() && a[j] == b[j]) {
                j++;
            }

            if(j == b.size() && j < a.size()) {
                return false;
            }

            if(j == a.size() || j == b.size()) {
                continue;
            }

            if(rank[a[j] - 'a'] > rank[b[j] - 'a']) {
                return false;
            }
        }

        return true;
    }
};
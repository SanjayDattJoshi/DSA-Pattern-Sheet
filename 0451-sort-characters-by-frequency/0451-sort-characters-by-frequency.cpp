class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> freq;
        for(int i=0; i<n; i++){
            freq[s[i]]++;
        }
        for(auto it: freq){
            pq.push({it.second, it.first});
        }
        string res = "";
        while(!pq.empty()){
            int f = pq.top().first;
            while(f--) res += pq.top().second;
            pq.pop();
        }
        return res;
    }
};
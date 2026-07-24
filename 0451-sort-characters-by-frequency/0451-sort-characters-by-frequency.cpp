/*
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
            auto [f, ch] = pq.top();
            pq.pop();
            while (f--) {
            res += ch;
            }
        }
        return res;
    }
};*/
class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char, int> freq;
        for(int i=0; i<n; i++){
            freq[s[i]]++;
        }
        string res = "";
        vector<vector<char>> bucket(n + 1);
        for(auto it: freq){
            bucket[it.second].push_back(it.first);
        }
        for(int i=n; i>0; i--){
            for (char ch : bucket[i]) {
                int fre = i;
                while (fre--) {
                res += ch;
                }
            }
        }
        return res;
    }
};
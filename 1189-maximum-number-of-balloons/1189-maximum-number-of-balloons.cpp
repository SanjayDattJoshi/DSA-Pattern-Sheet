class Solution {
public:
    int maxNumberOfBalloons(string text) {
    unordered_map<char,int> need, have;
    string str = "balloon";
    for(int i=0; i<7; i++) need[str[i]]++;

    for(int i=0; i<text.length(); i++) have[text[i]]++;

    int res = INT_MAX;

    for(auto it: need){
        res = min(res, have[it.first]/it.second);
    }
    return res;
    }
};
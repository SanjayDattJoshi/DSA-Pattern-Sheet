class Solution {
public:

private:
void f(string &s, int n, int ind, string &d, vector<string> &res,unordered_map<char, string> &mpp){
    if(ind == n){
        res.push_back(d);
        return;
    }
    string choice = mpp[s[ind]];
    for(int j=0; j<choice.length(); j++){
        d.push_back(choice[j]);
        f(s,n,ind+1,d,res,mpp);
        d.pop_back();
    }
    return;
}
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        unordered_map<char, string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";
        vector<string> res;
        string d = "";
        f(digits, digits.length(), 0,d, res,mpp);
        return res;
    }
};
class Solution {
public:
string finalStr(string s,int n){
    string temp = "";
    for(int i=0; i<n; i++){
        if(s[i] != '#') temp.push_back(s[i]);
        else if(!temp.empty()) temp.pop_back();
    }
    return temp;
}
    bool backspaceCompare(string s, string t) {
        int n = s.length(), m = t.length();
        string temp1 = finalStr(s, n);
        string temp2 = finalStr(t, m);
        if(temp1 == temp2) return true;
        return false;
    }
};
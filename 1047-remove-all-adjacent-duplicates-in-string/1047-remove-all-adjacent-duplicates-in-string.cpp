class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int n = s.length();
        st.push(s[0]);
        for(int i=1; i<n; i++){
            if(!st.empty() && st.top() == s[i]) st.pop();
            else st.push(s[i]);
        }
        string res="";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
class Solution {
public:
    bool isValid(string s) {\
        int n = s.length();
        stack<char> st;
        for(int i=0; i<n; i++){
            if(s[i]=='[' || s[i]=='{' || s[i]=='(') {
                st.push(s[i]);
                continue;
            }
            if(s[i]==']'){
                if(st.empty()) return false;
                if(s[i]==']' && st.top()=='[') st.pop();
                else return false;
            }
            if(s[i]==')'){
                if(st.empty()) return false;
                if(s[i]==')' && st.top()=='(') st.pop();
                else return false;
            }
            if(s[i]=='}'){
                if(st.empty()) return false;
                if(s[i]=='}' && st.top()=='{') st.pop();
                else return false;
            }
        }
        return st.empty()?true:false;
    }
};
class Solution {
public:
    string removeDuplicates(string num, int k) {
        int n = num.size();
        stack<pair<char,int>> st;
        string res = "";
        for(int i=0; i<n; i++){
            if(st.empty()) {
                st.push({num[i], 1});
                continue;
            }
            if(st.top().first != num[i]) {
                st.push({num[i], 1});
                continue;
            }
            if(st.top().second<k-1){
                pair<char, int> p = st.top();
                st.pop();
                st.push({p.first, p.second+1});
                continue;
            }
            st.pop();
        }
        while(!st.empty()){
            pair<char, int> p = st.top();
            st.pop();
            while(p.second--){
                res += p.first;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
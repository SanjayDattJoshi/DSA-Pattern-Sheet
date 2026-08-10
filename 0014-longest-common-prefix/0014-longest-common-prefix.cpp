class Solution {
public:

    string commonPrefix(string a, string b) {
        int i = 0;

        while (i < a.size() &&
               i < b.size() &&
               a[i] == b[i]) {
            i++;
        }

        return a.substr(0, i);
    }

    string solve(vector<string>& strs, int l, int r) {
        if (l == r)
            return strs[l];

        int mid = l + (r - l) / 2;

        string left = solve(strs, l, mid);
        string right = solve(strs, mid + 1, r);

        return commonPrefix(left, right);
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";

        return solve(strs, 0, strs.size() - 1);
    }
};
class BIT {
    vector<int> bit;
    int n;

public:
    BIT(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        // Coordinate Compression
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());

        unordered_map<int, int> rank;
        for (int i = 0; i < temp.size(); i++) {
            rank[temp[i]] = i + 1;    // 1-based indexing
        }

        BIT bit(temp.size());

        vector<int> ans(n);

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            int r = rank[nums[i]];
            ans[i] = bit.query(r - 1);   // count of smaller elements
            bit.update(r, 1);            // insert current element
        }

        return ans;
    }
};
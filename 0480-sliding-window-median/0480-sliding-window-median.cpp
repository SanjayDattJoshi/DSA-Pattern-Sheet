//Bruteforce Solution

// class Solution {
// public:
//     vector<double> medianSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<double> ans(n-k+1);
//         for(int i=0; i<=n-k; i++){
//             vector<int> curWin(k);
//             for(int j=i; j<i+k; j++){
//                 curWin[j-i] = nums[j];
//             }            
//             sort(curWin.begin(), curWin.end());
//             double res;
//             if(k%2==0){
//                 res = ((long long)curWin[k/2-1] + curWin[k/2])/2.0;
//             }
//             else res = curWin[k/2];
//             ans[i] = res;
//         }
//         return ans;
//     }
// };

//Optimal Solution
class Solution {
public:
    priority_queue<int> left;  // max heap

    priority_queue<int, vector<int>, greater<int>> right; // min heap

    unordered_map<int, int> delayed;

    int leftSize = 0;
    int rightSize = 0;


    // Remove invalid elements from LEFT top
    void pruneLeft() {

        while (!left.empty() && delayed[left.top()] > 0) {

            delayed[left.top()]--;

            left.pop();
        }
    }


    // Remove invalid elements from RIGHT top
    void pruneRight() {

        while (!right.empty() && delayed[right.top()] > 0) {

            delayed[right.top()]--;

            right.pop();
        }
    }


    // Balance both heaps
    void balance() {

        // Left has too many elements
        if (leftSize > rightSize + 1) {

            right.push(left.top());

            left.pop();

            leftSize--;
            rightSize++;

            pruneLeft();
        }

        // Right has more elements
        else if (rightSize > leftSize) {

            left.push(right.top());

            right.pop();

            rightSize--;
            leftSize++;

            pruneRight();
        }
    }


    // Insert new number
    void addNum(int num) {

        if (left.empty() || num <= left.top()) {

            left.push(num);
            leftSize++;
        }

        else {

            right.push(num);
            rightSize++;
        }

        balance();
    }


    // Remove outgoing number
    void removeNum(int num) {

        // mark for lazy deletion
        delayed[num]++;

        // It belongs to left half
        if (num <= left.top()) {

            leftSize--;

            // If it is already at top,
            // remove immediately
            if (num == left.top()) {
                pruneLeft();
            }
        }

        // belongs to right half
        else {

            rightSize--;

            if (!right.empty() && num == right.top()) {
                pruneRight();
            }
        }

        balance();
    }


    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        vector<double> ans;


        // Build first window
        for (int i = 0; i < k; i++) {

            addNum(nums[i]);
        }


        // Median of first window
        if (k % 2) {

            ans.push_back(left.top());
        }

        else {

            ans.push_back(
                ((long long)left.top() + right.top()) / 2.0
            );
        }


        // Slide window
        for (int i = k; i < nums.size(); i++) {

            // remove outgoing
            removeNum(nums[i - k]);

            // add incoming
            addNum(nums[i]);


            // calculate median
            if (k % 2) {

                ans.push_back(left.top());
            }

            else {

                ans.push_back(
                    ((long long)left.top() + right.top()) / 2.0
                );
            }
        }


        return ans;
    }
};
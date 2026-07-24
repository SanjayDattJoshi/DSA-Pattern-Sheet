class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        priority_queue<int>pq;
        for(auto it: arr) pq.push(it);
        
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};
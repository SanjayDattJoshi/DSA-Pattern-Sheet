class NumArray {
    vector<int> seg;
    int n;
    void build(vector<int> &nums, int node, int low, int high){
            if(low==high) {
                seg[node] = nums[low];
                return;
            }
            int mid = (low+high)/2;
            build(nums,2*node, low, mid);
            build(nums,2*node+1, mid+1, high);
            seg[node] = seg[2*node] + seg[2*node+1];
            return;
    }
    int query(int node, int start, int end, int l, int r){
            if(end < l || start > r) return 0;
            if(start >= l && end <= r) return seg[node];
            int mid = (start+end)/2;
            int left = query(2*node, start, mid, l, r);
            int right = query(2*node+1, mid+1, end, l, r);
            return left + right;
        }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);
        if(n>0) build(nums,1,0,n-1);
        
    };
    
    int sumRange(int left, int right) {
        return query(1, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
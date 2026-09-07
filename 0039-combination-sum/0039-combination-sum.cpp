class Solution {
private:
void f(vector<int> &candidates, int target, int ind,vector<int> &comb, vector<vector<int>> &res){
    if(target==0){
        res.push_back(comb);
        return;
    }
    if(ind == candidates.size()) return;

    //Not Pick
    f(candidates, target,ind+1, comb, res);

    //Pick
    if(candidates[ind] <= target){
        target -= candidates[ind];
        comb.push_back(candidates[ind]);
        f(candidates, target, ind, comb, res);
        comb.pop_back();
    }
    return;
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty()) return {};
        vector<vector<int>> res;
        vector<int> comb;
        f(candidates, target, 0, comb, res);
        return res;
    }
};
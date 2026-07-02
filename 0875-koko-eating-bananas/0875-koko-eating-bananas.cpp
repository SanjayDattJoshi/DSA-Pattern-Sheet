class Solution {
public:
long long fun(vector<int> &piles, int speed){
    long long t = 0;
    for(int i=0; i<piles.size(); i++){
       t = t + (piles[i]/speed);
       if(piles[i]%speed != 0) t++;
    }
    return t;
}
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1,high=0,res=-1;
        for(auto it: piles) high = max(high, it);
        while(low<=high){
            int mid = low + (high-low)/2;
            long long t = fun(piles, mid);
            if(t>h) low = mid+1;
            else {
                res = mid;
                high = mid-1;
            }
        }
        return res;
    }
};
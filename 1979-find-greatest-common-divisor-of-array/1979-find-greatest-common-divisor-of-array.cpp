class Solution {
public:
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    int findGCD(vector<int>& arr) {
        int n = arr.size();
        int mini = INT_MAX, maxi = INT_MIN;

        for(int i=0; i<n; i++){
            if(arr[i]<mini){
                mini = arr[i];
            }
            if(arr[i]>maxi){
                maxi = arr[i];
            }
        }
        return gcd(mini, maxi);
    }
};
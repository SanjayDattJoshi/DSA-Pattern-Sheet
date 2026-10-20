class Solution {
public:
    int findSum(int n){
        int sum = 0;
        while(n>0){
            int lastDigit = n%10;
            sum += lastDigit;
            n = n/10;
        }
        return sum;
    }
    int addDigits(int num) {
        if(num<10) return num;
        int res = 0;
        while(num>9){
            res = findSum(num);
            num =res;
        }
        return res;
    }
};
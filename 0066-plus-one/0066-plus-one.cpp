class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(digits[n-1]<9) {
            digits[n-1]++;
            return digits;
        }

        else{
            int carry = 0;
            for(int i=n-1; i>=0; i--){
                if(digits[i]==9){
                    carry = 1;
                    digits[i] = 0;
                }
                else if(digits[i]<9){
                    if(i!=0 || digits[i]<9) {
                        digits[i] = digits[i] + carry;
                        return digits;
                    }
                    else{
                        digits[i] = 0;
                    }
                }
                
            }
            if(carry==1) digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int divisor = 1;

        while (x / divisor >= 10)
            divisor *= 10;

        while (x != 0) {
            int left = x / divisor;
            int right = x % 10;

            if (left != right)
                return false;

            x = (x % divisor) / 10;
            divisor /= 100;
        }

        return true;
    }
};
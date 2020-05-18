// Given a 32-bit signed integer, reverse digits of an integer.

// Example 1:

// Input: 123
// Output: 321
// Example 2:

// Input: -123
// Output: -321
// Example 3:

// Input: 120
// Output: 21
// Note:
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
#include <climits>
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int pop = x % 10;
        while (x != 0) {
            x = x / 10;
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > INT_MAX % 10)) {
                result = 0;
                break;
            } else if ( result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < INT_MIN % 10)) {
                result = 0;
                break;
            } else {
                result = result * 10 + pop;
                pop = x % 10;
            }
        }
        return result;
    }
};

// 这里的难点是对溢出情况的处理，比较的时候比大的更大，比小的更小，就会溢出了
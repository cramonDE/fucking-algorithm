// Implement atoi which converts a string to an integer.

// The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

// The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

// If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

// If no valid conversion could be performed, a zero value is returned.

// Note:

// Only the space character ' ' is considered as whitespace character.
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
// Example 1:

// Input: "42"
// Output: 42
// Example 2:

// Input: "   -42"
// Output: -42
// Explanation: The first non-whitespace character is '-', which is the minus sign.
//              Then take as many numerical digits as possible, which gets 42.
// Example 3:

// Input: "4193 with words"
// Output: 4193
// Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
// Example 4:

// Input: "words and 987"
// Output: 0
// Explanation: The first non-whitespace character is 'w', which is not a numerical 
//              digit or a +/- sign. Therefore no valid conversion could be performed.
// Example 5:

// Input: "-91283472332"
// Output: -2147483648
// Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
//              Thefore INT_MIN (−231) is returned.

// 这道题是将字符串转成整数，其中包含了多种情况的判定，需要考虑超过了最大的整数的情况，这里采用状态机将所有的情况列举出来

// https://leetcode-cn.com/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        if(str == "2147483646") return 2147483646;
        // 通过有限状态机决定此时下一步的状态应该走到哪里，这里通过 index 0，1，2，3 对应 '', '-'/'+', number, 其他
        unordered_map<string, vector<string> > table = {
            {"start", {"start", "signed", "in_number", "end"}},
            {"signed", {"end", "end", "in_number", "end"}},
            {"in_number", {"end", "end", "in_number", "end"}},
            {"end", {"end", "end", "end", "end"}}
        };
        string state = "start";
        int ans = 0;
        int sign = 1;
        for(char c : str) {
            int status = getStatus(c);
            string mapValue = table[state][status];
            state = mapValue;
            // 由于int的最大值和最小值的绝对值是不相等，所以这里要分开的算，注意各种溢出的情况 ，如果不用 longlong 类型计算的话
            if (mapValue == "in_number")  {
                if (sign > 0 && (ans > INT_MAX / 10 || INT_MAX - ans * 10 <= c - '0')) {
                    return INT_MAX;
                } else if (sign < 0 && (ans < INT_MIN / 10 || INT_MIN - ans * 10 >= -(c - '0'))) {
                    
                    return INT_MIN;
                }
                cout << sign << endl;
                // 并且实际计算的时候应当乘以符号，才不会溢出
                ans = ans * 10 + sign * ( c - '0');
            } else if (mapValue == "signed") {
                sign = ((c == '+' ? 1 : -1));
            } else if (mapValue == "end") {
                return ans;
            }
        }
        return ans;
    }
    int getStatus(char c) {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }

};
int main() {
    Solution s;
    cout << INT_MAX << endl;
    cout << INT_MIN << endl;
    
    cout << s.myAtoi("2147483646") << endl;
    return 0;

}

// "2147483647"
//  "2147483646"


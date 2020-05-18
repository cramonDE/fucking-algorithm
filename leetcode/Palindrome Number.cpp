// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

// Example 1:

// Input: 121
// Output: true
// Example 2:

// Input: -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
// Follow up:

// Coud you solve it without converting the integer to a string?

// 回文数的处理，只是输入类型是 int
#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        int len = 1;
        if (x < 0)
            return false;
        while (x /= 10)
        {
            len++;
        };
        cout << len << endl;
        for (int i = 1; i <= len / 2; i++)
        {
            int front, end;
            int fIndex = i;
            int eIndex = len - i;
            int temp = x;
            while (fIndex--)
            {
                end = temp % 10;
                temp /= 10;
            }
            temp = x;
            while (eIndex--)
            {
                front = temp % 10;
                temp /= 10;
            }
            if (front != end)
            {
                return false;
            }
        }
        return true;
    }
};


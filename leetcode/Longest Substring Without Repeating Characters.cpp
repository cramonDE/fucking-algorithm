// Given a string, find the length of the longest substring without repeating characters.

// Example 1:

// Input: "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

// 使用滑动窗口进行求解
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> occ;
        int n = s.size();
        int ans = 0;
        int fast = -1;
        for (int i = 0; i < n; i++)
        {
            if (i != 0) {
                occ.erase(s[i - 1]);
            }
            while (fast + 1< n && !occ.count(s[fast + 1]))
            {
                occ.insert(s[fast + 1]);
                fast ++;
            }
            ans = max(ans, fast - i + 1);
        }
        return ans;
    }
};
// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

// Example 1:

// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: "cbbd"
// Output: "bb"

// 通过中心扩展法解决，注意分成单数和双数的进行子串的扩展，最后进行对比，递归的做法需要生成一个 dp[i][j] 数组保存状态，进行列表的查找

#include<iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        for (int i = 0 ; i < s.size(); i++) {
            string s1 = findPalindrome(s, i, i);
            string s2 = findPalindrome(s, i, i + 1);
            ans = s1.size() > ans.size() ? s1 : ans;
            ans = s2.size() > ans.size() ? s2 : ans;
        }
        return ans;
    }

    string findPalindrome(string& s, int l, int r) {
        while (r < s.size() && l >= 0 && s[l] == s[r]) {
                l--;
                r++;
        }
        return s.substr(l + 1, r - l -1);
    }
};
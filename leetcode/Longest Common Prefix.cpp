// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

// 找出最长的前缀

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string min = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].length() < min.length() ) {
                min = strs[i];
            }
        }
        string ans = "";
        for (int i = 0; i < min.size(); i++) {
            for (int j = 0; j < strs.size(); j++) {
                if (strs[j][i] != min[i]) {
                    return ans;
                }
            }
            ans.push_back(min[i]);
            
        }
        return ans;
    }
};
       
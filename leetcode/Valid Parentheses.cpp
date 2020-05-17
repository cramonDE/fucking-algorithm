// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.

// Example 1:

// Input: "()"
// Output: true
// Example 2:

// Input: "()[]{}"
// Output: true
// Example 3:

// Input: "(]"
// Output: false
// Example 4:

// Input: "([)]"
// Output: false
// Example 5:

// Input: "{[]}"
// Output: true

// 括号匹配

#include <string>
#include <stack>
using namespace std;

class Solution
{
  public:
    bool isValid(string s)
    {
        if (s.size() % 2 != 0)
            return false;
        stack<char> a;
        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                a.push(s[i]);
            }
            else if (!a.empty()&&((s[i] == ')' && a.top() == '(') || (s[i] == ']' && a.top() == '[') || (s[i] == '}' && a.top() == '{')))
            {
                a.pop();
            }
        }
        if (!a.empty())
            return false;
        return true;
    }
};

#include <unordered_map>
class Solution {
public:

    unordered_map<char, char> um = {
            {'{', '}'},
            {'(', ')'},
            {'[', ']'}
    };

    bool isValid(string s) {
        if (s.empty()) {
            return true;
        } else if (s.size() % 2) {
            return false;
        } else {
            stack<char> ss;
            for (int i = 0; i < s.size(); i ++) {
                if (ss.empty()) {
                    ss.push(s[i]);
                } else {
                    if (s[i] == um[ss.top()]) {
                        ss.pop();
                    } else {
                        ss.push(s[i]);
                    }
                }
            }
            return ss.empty();
        }        
    }
};

// 使用了 map 来映射，逻辑处理比较简单，将非法的输入也压入栈中